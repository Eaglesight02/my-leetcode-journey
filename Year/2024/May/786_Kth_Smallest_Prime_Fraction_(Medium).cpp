class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // TC: O(N^2), SC: O(N) (priority_queue and hashmap)
        // Note: you have to convert either the numerator or denominator to float to get the float result.
        unordered_map<float,pair<int,int>> umap;
        priority_queue<float,vector<float>,greater<float>> pq;      // min heap
        int size = arr.size();
        for(int i = 0 ; i < size-1 ; ++i){
            for(int j = i+1 ; j < size ; ++j){
                float temp = float(arr[i])/arr[j];
                pq.push(temp);
                umap[temp] = make_pair(arr[i],arr[j]);              // Storing the array values of i,j for given fraction.
            }
        }
        float top;
        while(!pq.empty() && k>0){
            top = pq.top();
            pq.pop();
            --k;
        }
        return {umap[top].first,umap[top].second};                  // Getting the kth least fraction's array values
    }
};