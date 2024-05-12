class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        // four loops
        // TC: O(N^4)
        // SC: O(1)
        int n = grid.size();
        vector<vector<int>> res(n-2,vector<int>(n-2,0));
        for(int i = 0 ; i <= n-3 ; ++i){
            for(int j = 0 ; j <= n-3 ; ++j){
                for(int k = i ; k < i+3 ; ++k){
                    for(int l = j ; l < j+3 ; ++l){
                        res[i][j] = max(res[i][j], grid[k][l]);
                    }
                }
            }
        }
        return res;
    }
};