class Solution {
public:

    // If parent[element] == element, then its the root node, else we find the parent of the element.
    int getParent(vector<int>& parent, int element){
        return parent[element] == element ? element : getParent(parent, parent[element]);
    }

    // Since the graph is bi-directional, we don't consider the length for getting the union of the sets.
    // We do it as parent[b] = parent[a].
    void createSet(vector<int>& parent, int src, int dest){
        if(parent[src] != parent[dest]){
            int a = getParent(parent, src);
            int b = getParent(parent, dest);
            parent[b] = parent[a];
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // // Creating adjacency matrix for both DFS and BFS
        // int size = edges.size();
        // vector<vector<int>> vertexEdges(n+1);
        // unordered_set<int> visited;
        // for(int i = 0 ; i < size ; ++i){
        //     vertexEdges[edges[i][0]+1].emplace_back(edges[i][1]+1);
        //     vertexEdges[edges[i][1]+1].emplace_back(edges[i][0]+1);
        // }
        // ++source;
        // ++destination;




        // // DFS is getting accepted since we are including all the elements for every element.
        // stack<int> st;
        // st.push(source);
        // while(!st.empty()){
        //     if(st.top() == destination){
        //         return true;
        //     }
        //     int front = st.top();
        //     visited.insert(front);
        //     size = vertexEdges[front].size();
        //     bool val = false;
        //     for(int i = 0 ; i < size ; ++i){
        //         if(vertexEdges[front][i] > 0 && visited.find(vertexEdges[front][i]) == visited.end()){
        //             st.push(vertexEdges[front][i]);
        //             visited.insert(vertexEdges[front][i]);
        //             val = true;
        //             break;
        //         }
        //     }
        //     if(!val){
        //         st.pop();
        //     }
        // }




        // // BFS is getting memory limit exceeded
        // queue<int> que;
        // que.push(source);
        // while(!que.empty()){
        //     if(que.front() == destination){
        //         return true;
        //     }
        //     int front = que.front();
        //     que.pop();
        //     size = vertexEdges[front].size();
        //     for(int i = 0 ; i < size ; ++i){
        //         if(vertexEdges[front][i] > 0 && visited.find(vertexEdges[front][i]) == visited.end()){
        //             que.push(vertexEdges[front][i]);
        //         }
        //     }
        //     visited.insert(front);
        // }


        // // For both DFS and BFS
        // return false;






        // Union Find or Disjoint sets:
        vector<int> parent(n);
        for(int i = 0 ; i < n ; ++i){
            parent[i] = i;
        }
        for(auto edge : edges){
            createSet(parent, edge[0], edge[1]);
        }
        return getParent(parent, source) == getParent(parent, destination);
    }
};