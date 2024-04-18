class Solution {
public:

    int dfs(vector<vector<int>>& grid, int i, int j){
        // Boundary element, return 1 for perimeter. Also for water element
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == 0){
            return 1;
        }
        if(grid[i][j] == 2){
            return 0;           // Already visited
        }
        grid[i][j] = 2;
        return dfs(grid, i-1, j) + dfs(grid, i, j-1) + dfs(grid, i+1, j) + dfs(grid, i, j+1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        // // Brute-force for every element that is non-zero, getting all the four directions 
        // // TC: O(N^2)
        // int perimeter = 0;
        // for(int i = 0 ; i < grid.size() ; ++i){
        //     for(int j = 0 ; j < grid[i].size() ; ++j){
        //         if(grid[i][j] == 1){
        //             int left = 0, right = 0, top = 0, bottom = 0;
        //             // Either boundary or water element for every direction, then we increase the perimeter by one.
        //             if(j - 1 < 0 || grid[i][j-1] == 0){                 
        //                 left = 1;
        //             }
        //             if(i - 1 < 0 || grid[i-1][j] == 0){
        //                 top = 1;
        //             }
        //             if(j + 1 == grid[i].size() || grid[i][j+1] == 0){
        //                 right = 1;
        //             }
        //             if(i + 1 == grid.size() || grid[i+1][j] == 0){
        //                 bottom = 1;
        //             }
        //             perimeter += top + bottom + left + right;
        //         }
        //     }
        // }
        // return perimeter;











        // // Brute force: but only considering the left and top elements.
        // // TC: O(N^2)
        // // Here, we are considering the edges twice, so while removing, we remove them twice.
        // int perimeter = 0;
        // int m = grid.size();
        // int n = grid[0].size();
        // for(int i = 0 ; i < m ; ++i){
        //     for(int j = 0 ; j < n ; ++j){
        //         if(grid[i][j]){
        //             perimeter += 4;                 // We consider extra edges (bottom and right also here).
        //             if(i > 0 && grid[i-1][j]){      // We remove 2 edges where there's adjacent element.
        //                 perimeter -= 2;
        //             }
        //             if(j > 0 && grid[i][j-1]){      // We remove 2 edges where there's adjacent element.
        //                 perimeter -= 2;
        //             }
        //         }
        //     }
        // }
        // return perimeter;














        // DFS solution: TC: O(N*M)
        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0 ; j < grid[0].size() ; ++j){
                if(grid[i][j]){
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
};