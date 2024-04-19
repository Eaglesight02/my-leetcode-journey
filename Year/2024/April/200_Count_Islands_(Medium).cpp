class Solution {
public:
    
    // // DFS: depth first search for island
    // void getIsland(vector<vector<char>>& grid, int i, int j){
    //     if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0' || grid[i][j] == '2'){
    //         return;
    //     }
    //     grid[i][j] = '2';
    //     getIsland(grid, i-1, j);
    //     getIsland(grid, i, j-1);
    //     getIsland(grid, i, j+1);
    //     getIsland(grid, i+1, j);
    // }

    int numIslands(vector<vector<char>>& grid) {
        // // DFS: TC: O(m*n) for worst case: visit every element once.
        // // SC: O(m*n) for worst case: store all the elements of the island in the queue
        // int size1 = grid.size();
        // int size2 = grid[0].size();
        // int count = 0;
        // for(int i = 0 ; i < size1 ; ++i){
        //     for(int j = 0 ; j < size2 ; ++j){
        //         if(grid[i][j] == '1'){
        //             ++count;                        // If '1' is reached, then it is on another island.
        //             getIsland(grid, i, j);
        //         }
        //     }
        // }
        // return count;







        // BFS: Using queue to get all the adjacent elements for an island.
        // Using offset vector is beneficial as we don't have to check conditions for each adjacent element.
        // We only have to iterate over the offset vector and then take the indexes.
        // TC: O(m*n) traverse all elements once.
        // SC: O(m*n) store all the elements in the queue
        int size1 = grid.size();
        int size2 = grid[0].size();
        int count = 0;
        queue<pair<int,int>> que;
        vector<int> offset = {0, -1, 0, 1, 0};
        for(int i = 0 ; i < size1 ; ++i){
            for(int j = 0 ; j < size2 ; ++j){
                if(grid[i][j] == '1'){
                    ++count;
                    que.push(make_pair(i,j));
                    while(!que.empty()){
                        int x = que.front().first;
                        int y = que.front().second;
                        grid[x][y] = '0';
                        que.pop();
                        for(int k = 0 ; k < 4 ; ++k){
                            int r = x + offset[k], s = y + offset[k+1];
                            if(r >= 0 && r < size1 && s >= 0 && s < size2 && grid[r][s] == '1'){
                                grid[r][s] = '0';
                                que.push(make_pair(r,s));
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};