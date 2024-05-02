class Solution {
public:
    int findMaxK(vector<int>& nums) {

        // // Using extra space for positive and negative Integers:
        // // TC: O(N), SC: O(N)
        // unordered_set<int> positiveIntegers;
        // unordered_set<int> negativeIntegers;
        // int size = nums.size();
        // for(int i = 0 ; i < size ; ++i){
        //     if(nums[i] < 0){
        //         negativeIntegers.insert(nums[i]);
        //     }
        //     else{
        //         positiveIntegers.insert(nums[i]);
        //     }
        // }
        // int max_int = -1;
        // for(auto x : positiveIntegers){
        //     if(x > max_int && negativeIntegers.find(-1*x) != negativeIntegers.end()){
        //         max_int = x;
        //     }
        // }
        // return max_int;



        // A better approach: slight variation in the above, but using two sum approach: hashset
        // TC: O(N), SC: O(N)
        int size = nums.size();
        int max_int = -1;
        unordered_set<int> counterNums;
        for(int i = 0 ; i < size ; ++i){
            if(counterNums.find(nums[i]) != counterNums.end() || counterNums.find(abs(nums[i])) != counterNums.end()){
                max_int = max(max_int, abs(nums[i]));
            }
            else{
                counterNums.insert(-1*nums[i]);
            }
        }
        return max_int;





        // // Not using extra space but sorting the array and using two-pointer approach:
        // // TC: O(N*log(N)), SC: O(1)
        // sort(nums.begin(), nums.end());
        // int left = 0;
        // int size = nums.size();
        // int right = size-1;
        // while(left < right){
        //     while(left < right && -1*nums[left] > nums[right]){
        //         ++left;
        //     }
        //     if(nums[left] == -1*nums[right]){
        //         return nums[right];
        //     }
        //     else{
        //         --right;
        //     }
        // }
        // return -1;





        // // The good 'ol brute force:
        // // TC: O(N^2), SC: O(1)
        // int max_int = -1;
        // int size = nums.size();
        // for(int i = 0 ; i < size ; ++i){
        //     for(int j = i+1 ; j < size ; ++j){
        //         if(nums[j]*-1 == nums[i] || nums[i]*-1 == nums[j]){
        //             int temp_int = nums[i];
        //             if(temp_int < 0){
        //                 temp_int*=-1;
        //             }
        //             max_int = max(max_int, temp_int);
        //             break;
        //         }
        //     }
        // }
        // return max_int;
    }
};