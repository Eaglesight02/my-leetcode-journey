class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // // Brute Force:
        // // TC: O(N^2), SC: O(1)
        // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        // int size = nums.size();
        // vector<int> prefixSum(size, 0);
        // prefixSum[0] = nums[0];
        // int total = 0;
        // for(int i = 1 ; i < size ; ++i){
        //     prefixSum[i] = prefixSum[i-1] + nums[i];
        // }
        // for(int i = 0 ; i < size ; ++i){
        //     if(prefixSum[i] % k == 0){
        //         ++total;
        //     }
        //     for(int j = size-1 ; j > i ; --j){
        //         if((prefixSum[j] - prefixSum[i]) % k == 0){
        //             ++total;
        //         }
        //     }
        // }
        // return total;


        // Learn Math bitch.
        // TC: O(N), SC: O(N)
        int size = nums.size();
        int total = 0;
        vector<int> vec(k,0);
        int prefixSum = 0;
        vec[0] = 1;
        for(int i = 0 ; i < size ; ++i){
            prefixSum += nums[i];
            int remainder = prefixSum % k;
            if(remainder < 0){
                remainder += k;
            }
            total += vec[remainder];
            vec[remainder]++;
        }
        return total;
    }
};