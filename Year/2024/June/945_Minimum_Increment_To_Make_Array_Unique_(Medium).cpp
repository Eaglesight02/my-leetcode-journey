class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // // Using sorting and map, TC: O(N*log(N)), SC: O(N)
        // int size = nums.size();
        // int minValue = INT_MAX;
        // int result = 0;
        // map<int,int> counts;
        // for(int i = 0 ; i < size ; ++i){
        //     counts[nums[i]]++;
        //     minValue = min(minValue, nums[i]);
        // }
        // for(auto it : counts){
        //     while(it.second > 1){
        //         while(counts.find(minValue) != counts.end() || minValue <= it.first){
        //             minValue++;
        //         }
        //         counts[minValue] = 1;
        //         result += (minValue - it.first);
        //         --it.second;
        //     }
        // }
        // return result;



        // See the editorial approach 2, TC: O(N), SC: O(N)
        // The maximum size for the array is found by: worst case: all are same: [2,2,2,2,2,2]
        // Size = 6, max_element = 2, result = [2,3,4,5,6,7]
        // So, maxSize = Size + max_element
        int size = nums.size();
        int maxValue = INT_MIN;
        int result = 0;
        for(int i = 0 ; i < size ; ++i){
            maxValue = max(maxValue, nums[i]);
        }
        double newSize = maxValue + size + 1;
        vector<int> array(newSize, 0);
        for(int i = 0 ; i < size ; ++i){
            array[nums[i]]++;
        }
        for(int i = 0 ; i < newSize ; ++i){
            if(array[i] > 1){
                int temp = array[i]-1;
                result += temp;
                array[i] = 1;
                array[i+1] += temp;
            }
        }
        return result;

    }
};