class Solution {
public:

    // // DFS function to get the farmland indices.
    // void getFarmLand(vector<vector<int>>& land, vector<int>& temp, int i, int j){
    //     if(i == land.size() || j == land[0].size() || land[i][j] == 0){             // Boundary element or zero element.
    //         return;
    //     }
    //     temp[2] = max(temp[2], i);
    //     temp[3] = max(temp[3], j);
    //     land[i][j] = 0;                                                             // Take the right and bottom elements.
    //     getFarmLand(land, temp, i+1, j);
    //     getFarmLand(land, temp, i, j+1);
    // }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        // // Simple DFS for right and bottom elements.
        // vector<vector<int>> result;
        // int m = land.size();
        // int n = land[0].size();
        // for(int i = 0 ; i < m ; ++i){
        //     for(int j = 0 ; j < n ; ++j){
        //         if(land[i][j] == 1){                                                // If land element, then call the DFS function.
        //             vector<int> temp = {i, j, i, j};
        //             getFarmLand(land, temp, i, j);
        //             result.emplace_back(temp);
        //         }
        //     }
        // }
        // return result;









        // // BFS using queue:
        // vector<vector<int>> result;
        // queue<pair<int,int>> que;
        // int m = land.size();
        // int n = land[0].size();
        // vector<int> offset = {0, 1, 0};                     // offset to calculate the indexes.
        // for(int i = 0 ; i < m ; ++i){
        //     for(int j = 0 ; j < n ; ++j){
        //         if(land[i][j] == 1){
        //             vector<int> temp = {i, j, i, j};
        //             pair<int,int> p = make_pair(i,j);
        //             que.push(p);
        //             while(!que.empty()){
        //                 int r = que.front().first;
        //                 int s = que.front().second;
        //                 land[r][s] = 0;
        //                 que.pop();
        //                 for(int t = 0 ; t < 2 ; ++t){
        //                     if(r + offset[t] < m && s + offset[t + 1] < n && land[r+offset[t]][s+offset[t+1]] == 1){
        //                         temp[2] = max(temp[2], r+offset[t]);
        //                         temp[3] = max(temp[3], s+offset[t+1]);
        //                         que.push(make_pair(r+offset[t], s+offset[t+1]));
        //                         land[r+offset[t]][s+offset[t+1]] = 0;           // marking land element to zero to avoid recalculation
        //                     }
        //                 }
        //             }
        //             result.emplace_back(temp);
        //         }
        //     }
        // }
        // return result;











        // // Using two-pointers: it doesn't work yet
        // int m = land.size();
        // int n = land[0].size();
        // vector<vector<int>> result;
        // for(int i = 0 ; i < m ; ++i){
        //     for(int j = 0 ; j < n ; ++j){
        //         if(land[i][j] == 1){
        //             vector<int> temp = {i, j, i, j};
        //             land[i][j] = 0;
        //             for(int k = j + 1 ; k < n && land[i][k] == 1 ; ++k){
        //                 temp[3] = k;
        //                 land[i][k] = 0;
        //             }
        //             for(int k = i + 1 ; k < m && land[k][j] == 1 ; ++k){
        //                 temp[2] = k;
        //                 land[k][j] = 0;
        //             }
        //             result.emplace_back(temp);
        //         }
        //     }
        // }
        // return result;
    }
};