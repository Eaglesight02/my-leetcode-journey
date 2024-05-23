class Solution {
public:
    // Exponential TC
    void getSubsets(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, int& n, int ind){
        if(ind == n){
            result.emplace_back(temp);
            return;
        }
        temp.emplace_back(nums[ind]);
        getSubsets(nums,temp,result,n,ind+1);
        temp.pop_back();
        getSubsets(nums,temp,result,n,ind+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        int n = nums.size();
        getSubsets(nums,temp,result,n,0);
        return result;
    }
};