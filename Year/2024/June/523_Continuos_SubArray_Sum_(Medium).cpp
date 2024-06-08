class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // // Brute Force: T.C : O(N^2), SC: O(N)
        // int size = nums.size()-1;
        // if(size+1 < 2){
        //     return false;
        // }
        // else{
        //     vector<int> multiples(size);
        //     multiples[0] = nums[0]+nums[1];
        //     if(multiples[0] % k == 0){
        //         return true;
        //     }
        //     for(int i = 1 ; i < size ; ++i){
        //         multiples[i] = multiples[i-1] + nums[i+1];
        //         if(multiples[i] % k == 0){
        //             return true;
        //         }
        //     }
        //     int ind = 0;
        //     int temp;
        //     while(size){
        //         multiples.erase(multiples.begin());
        //         --size;
        //         temp = nums[ind];
        //         for(int i = 0 ; i < size ; ++i){
        //             multiples[i] -= nums[ind];
        //             if(multiples[i] % k == 0){
        //                 return true;
        //             }
        //         }
        //         ++ind;
        //     }
        // }
        // return false;


        // Going by the editorial solution, we take prefixSums and then take their mods. If mods are equal and distance is > 1, then return true, else false
        int size = nums.size();
        int curSum = 0;
        int mod = 0;
        if(size < 2){
            return false;
        }
        unordered_map<int,int> prefixesInd;
        for(int i = 0 ; i < size ; ++i){
            curSum += nums[i];
            mod = curSum % k;
            if(mod == 0 && i > 0){
                return true;
            }
            if(prefixesInd[mod] > 0){
                if(i+1 - prefixesInd[mod] > 1){
                    return true;
                }
            }
            else{
                prefixesInd[mod] = i+1;
            }
        }
        return false;
    }
};