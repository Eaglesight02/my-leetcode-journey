class Solution {
public:
    // Accepted Brute force solution: TC: O(2^N), SC: O(N)
    void getBeautifulSubsets(vector<int>& nums, unordered_map<int, int>& umap, int& count, int& k, int ind){
        if(ind == nums.size()){
            if(umap.size() > 0){
                ++count;
            }
            return;
        }
        if(umap[nums[ind]+k] == 0 && umap[nums[ind]-k] == 0){
            umap[nums[ind]]++;
            getBeautifulSubsets(nums, umap, count, k, ind+1);
            umap[nums[ind]]--;
        }
        getBeautifulSubsets(nums, umap, count, k, ind+1);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int> umap;
        getBeautifulSubsets(nums, umap, count, k, 0);
        return count-1;
    }
};