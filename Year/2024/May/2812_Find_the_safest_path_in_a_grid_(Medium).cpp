static auto _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    // // BFS function
    // bool pathPossible(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& n, int& minDist, int i, int j){
    //     if(i < 0 || j < 0 || i == n || j == n || visited[i][j] || grid[i][j] < minDist){
    //         return false;
    //     }
    //     if(i == n-1 && j == n-1){
    //         return true;
    //     }
    //     visited[i][j] = true;
    //     bool up = pathPossible(grid,visited,n,minDist,i-1,j);
    //     bool left = pathPossible(grid,visited,n,minDist,i,j-1);
    //     bool down = pathPossible(grid,visited,n,minDist,i+1,j);
    //     bool right = pathPossible(grid,visited,n,minDist,i,j+1);
    //     return up || left || down || right;
    // }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // // My solution: T.C: O(N*N*log(N)) S.C: O(N*N)
        // unordered_map<int,vector<int>> indices;
        // int minDistance = INT_MAX;
        // int n = grid.size();
        // for(int i = 0 ; i < n ; ++i){
        //     for(int j = 0 ; j < n ; ++j){
        //         if(grid[i][j] == 1){
        //             indices[i].emplace_back(j);
        //         }
        //     }
        // }
        
        // for(int i = 0 ; i < n ; ++i){
        //     for(int j = 0 ; j < n ; ++j){
        //         if(grid[i][j] == 0){
        //             int minDist = INT_MAX;
        //             for(auto it : indices){
        //                 int size = it.second.size();
        //                 for(int k = 0 ; k < size ; ++k){
        //                     minDist = min(minDist, abs(i-it.first) + abs(j-it.second[k]));
        //                 }
        //             }
        //             grid[i][j] = minDist;
        //         }
        //         else{
        //             grid[i][j] = 0;
        //         }
        //         minDistance = min(minDistance, grid[i][j]);
        //     }
        // }
        
        // int left = minDistance, right = min(grid[0][0],grid[n-1][n-1]);
        // vector<vector<bool>> visited(n,vector<bool>(n, false));
        // while(left <= right){
        //     int mid = left + (right-left)/2;
        //     for(int i = 0; i < n; ++i) {
        //         fill(visited[i].begin(), visited[i].end(), false);
        //     }
        //     if(pathPossible(grid, visited, n, mid, 0, 0)){
        //         left = mid + 1;
        //     }
        //     else{
        //         right = mid - 1;
        //     }
        // }
        // return right;



        // Copied solution
        queue<array<int, 2>> q;
        int dir[5] = {1, 0, -1, 0, 1}, n = grid.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    q.push({i, j});
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && max(x, y) < n && grid[x][y] == 0) {
                    grid[x][y] = grid[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
        priority_queue<array<int, 3>> pq;
        pq.push({grid[0][0], 0, 0});
        while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
            auto [sf, i, j] = pq.top(); pq.pop();
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && max(x, y) < n && grid[x][y] > 0) {
                    pq.push({min(sf, grid[x][y]), x, y});
                    grid[x][y] *= -1; 
                }
            }
        }
        return pq.top()[0] - 1;
    }
};
