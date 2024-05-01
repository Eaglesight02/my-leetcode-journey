class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Intuition: we flip digits wherever the resultant XOR is different from the actual required one.
        for(auto it : nums){
            k ^= it;
        }
        return __builtin_popcount(k);
    }
};