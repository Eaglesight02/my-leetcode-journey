class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        // // Optimized Approach: TC: O(N), SC:O(1) 
        // // We take the XOR of all values, this gives us the XOR of the single numbers.
        // // Now, we have to know that if there is a set bit in the XOR value, it means one number has set bit at that position and the other doesn't.
        // // So, we take either the lest significant or most significant set bit and then...
        // // do repeated AND on all numbers again, if result is zero, then for that number, that particular bit is not set, but if non-zero, then it is set.
        // // So we got two different groups, then in each group, do repeated XOR again(to eliminate the numbers that occur twice).
        // long int xor_value = 0;                 // For border bitwise AND of 2^31
        // int size = nums.size();
        // for(int i = 0 ; i < size ; ++i){
        //     xor_value ^= nums[i];
        // }

        // // To get the least significant set bit, we can use: value & -value
        // // -value can be found by 2's complement method:
        // // Eg: value = 6(0110), -value = 1's complement of value + 1 = 1001 + 1 = 1010
        // xor_value &= -xor_value;

        // vector<int> result = {0,0};

        // for(auto num : nums){
        //     if((num & xor_value) == 0){       // bit is unset for current num
        //         result[0] ^= num;           // Repeated XOR for unset bit numbers
        //     }
        //     else{
        //         result[1] ^= num;           // Repeated XOR for set bit numbers
        //     }
        // }

        // return result;





        // Brute force by sorting: TC: O(N*log(N)) SC: O(1)
        sort(nums.begin(), nums.end());
        vector<int> result;
        int count = 1;
        int size = nums.size();
        for(auto n : nums){
            cout << n << " ";
        }
        for(int i = 1 ; i < size ; ++i){
            if(nums[i] == nums[i-1]){
                ++count;
            }
            else{
                if(count == 1){
                    result.emplace_back(nums[i-1]);
                }
                count = 1;
            }
        }
        if(result.size() == 1){
            result.emplace_back(nums[size-1]);
        }
        return result;
    }
};
