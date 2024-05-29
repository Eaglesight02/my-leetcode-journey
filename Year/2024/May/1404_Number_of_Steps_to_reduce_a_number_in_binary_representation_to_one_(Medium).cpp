class Solution {
public:

    // Adding one to the string
    void addOne(string& s, int& size){
        short int carry = 1;
        for(int i = size-1 ; i >= 0 ; --i){
            if(s[i] == '0'){
                if(carry == 1){
                    s[i] = '1';
                    carry = 0;
                }
            }
            else{
                if(carry == 1){
                    s[i] = '0';
                }
            }
        }
        if(carry == 1){
            s = "1" + s;
            ++size;
        }
    }

    // Dividing by 2
    void divideEven(string& s, int& size){
        s.pop_back();
        --size;
    }

    int numSteps(string s) {
        int count = 0;
        int size = s.size();

        // // Using the functions I've written above
        // // TC: O(N^2), SC: O(1)
        // while(s[size-1] == '0' || size > 1){
        //     ++count;
        //     if(s[size-1] == '1'){
        //         addOne(s,size);
        //     }
        //     else{
        //         divideEven(s,size);
        //     }
        // }
        // return count;



        // // Using a single for-loop with even, odd and carry checking.
        short int carry = 0;
        for(int i = size-1 ; i > 0 ; --i){
            if((s[i] == '1' && carry == 0) || (s[i] == '0' && carry == 1)){
                count += 2;
                carry = 1;
            }
            else{
                ++count;
            }
        }
        return count + carry;
    }
};