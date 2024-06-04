class Solution {
public:
    int longestPalindrome(string s) {
        // This is a greedy, hashmap problem.
        // Since we have both Upper and Lowercase alphabets, I am taking two vectors for each.
        vector<int> smallAlphabets(26,0);
        vector<int> bigAlphabets(26,0);
        int result = 0;
        int size = s.size();
        for(int i = 0 ; i < size ; ++i){
            if(s[i] >= 97){
                smallAlphabets[s[i]-'a']++;
            }
            else{
                bigAlphabets[s[i]-'A']++;
            }
        }
        
        // Taking the counts and then sorting them for greedy approach:
        // To take the highest counts first.
        sort(smallAlphabets.begin(),smallAlphabets.end());
        sort(bigAlphabets.begin(),bigAlphabets.end());

        // At each iteration:
        // If it is even (for both lower and uppercase), then take the count and modify the array (make it zero).
        // If odd, then we take it odd-1 (to maximize profit), then modify the array (make it 1)(since we are taking one less than the odd).
        for(int i = 25 ; i >= 0 ; --i){
            if(smallAlphabets[i] % 2 == 0){
                result += smallAlphabets[i];
                smallAlphabets[i] = 0;
            }
            else if(smallAlphabets[i] > 0){
                result += smallAlphabets[i]-1;
                smallAlphabets[i] = 1;
            }
            if(bigAlphabets[i] % 2 == 0){
                result += bigAlphabets[i];
                bigAlphabets[i] = 0;
            }
            else if(bigAlphabets[i] > 0){
                result += bigAlphabets[i]-1;
                bigAlphabets[i] = 1;
            }
        }

        // Finally, traverse through the array again and take any element that has '1'.
        for(int i = 25 ; i >= 0 ; --i){
            if(smallAlphabets[i] == 1 || bigAlphabets[i] == 1){
                ++result;
                break;
            }
        }
        return result;
    }
};