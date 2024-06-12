class Solution {
public:
    void sortColors(vector<int>& nums) {
        // // CountSort
        // // TC: O(N), SC: O(N)
        // vector<int> count(3,0);
        // int size = nums.size();
        // for(int i = 0 ; i < size ; ++i){
        //     count[nums[i]]++;
        // }
        // int ind = 0;
        // for(int i = 0 ; i < size ; ){
        //     while(i < size && count[ind] > 0){
        //         nums[i] = ind;
        //         ++i;
        //         --count[ind];
        //     }
        //     ++ind;
        // }



        // The Dutch National Flag Problem by Dijkstra
        // Triple partitioning of three similar groups
        // TC: O(N), SC: O(1)
        int size = nums.size();
        int red = 0, white = 0, blue = size-1;
        while(white <= blue){
            if(nums[white] == 0){
                swap(nums[red], nums[white]);
                ++red;
                ++white;
            }
            else if(nums[white] == 1){
                ++white;
            }
            else{
                swap(nums[blue], nums[white]);
                --blue;
            }
        }
        
    }
};