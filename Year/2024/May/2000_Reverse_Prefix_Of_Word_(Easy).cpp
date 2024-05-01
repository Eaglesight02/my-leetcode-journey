class Solution {
public:
    string reversePrefix(string word, char ch) {
        int reverseIndex = -1;
        int size = word.size();
        for(int i = 0 ; i < size ; ++i){
            if(word[i] == ch){
                reverseIndex = i;
                break;
            }
        }
        if(reverseIndex != -1){
            int i = 0;
            while(i <= reverseIndex){
                swap(word[i], word[reverseIndex]);
                ++i;
                --reverseIndex;
            }
        }
        return word;
    }
};