class Solution {
public:
    
    // DFS: depth first search for island
    void getIsland(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0' || grid[i][j] == '2'){
            return;
        }
        grid[i][j] = '2';
        getIsland(grid, i-1, j);
        getIsland(grid, i, j-1);
        getIsland(grid, i, j+1);
        getIsland(grid, i+1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int size1 = grid.size();
        int size2 = grid[0].size();
        int count = 0;
        for(int i = 0 ; i < size1 ; ++i){
            for(int j = 0 ; j < size2 ; ++j){
                if(grid[i][j] == '1'){
                    ++count;                        // If '1' is reached, then it is on another island.
                    getIsland(grid, i, j);
                }
            }
        }
        return count;
    }
};