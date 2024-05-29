class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if(nums[0] >= size){
            return size;
        }
        for(int i = 1 ; i < size ; ++i){
            if(size-i <= nums[i] && size-i > nums[i-1]){
                return size-i;
            }
        }
        return -1;
    }
};