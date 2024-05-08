class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        // // Using HashMap for storing elements with indexes and another copy of scores for sorting.
        // // TC: O(N*log(N)) SC: O(N)
        // unordered_map<int,int> umap;
        // int size = score.size();
        // for(int i = 0 ; i < size ; ++i){
        //     umap[score[i]] = i;
        // }
        // vector<int> score_new = score;
        // sort(score_new.begin(), score_new.end(), greater<int>());
        // vector<string> result(size);
        // for(int i = 0 ; i < size && i < 3 ; ++i){
        //     int position = umap[score_new[i]];
        //     if(i == 0){
        //         result[position] = "Gold Medal";
        //     }
        //     else if(i == 1){
        //         result[position] = "Silver Medal";
        //     }
        //     else if(i == 2){
        //         result[position] = "Bronze Medal";
        //     }
        // }
        // for(int i = 3 ; i < size ; ++i){
        //     int position = umap[score_new[i]];
        //     result[position] = to_string(i+1);
        // }
        // return result;





        // // Using normalization method: Sorting the indexes based on the values given.
        // // Using an extra O(N) space, no hashmap required and no priority queue required.
        // short size = score.size();
        // vector<short> index(size);
        // vector<string> result(size);
        // iota(index.begin(), index.end(), 0);
        // sort(index.begin(), index.end(), [&score](int i, int j){
        //     return score[i] > score[j];
        // });
        // for(short i = 0 ; i < size ; ++i){
        //     result[index[i]] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal" : i == 2 ? "Bronze Medal" : to_string(i+1);
        // }
        // return result;






        // Using priority queue:
        // Default priority queue in C++ is a max heap
        priority_queue<int> pq;
        unordered_map<int,int> umap;
        int size = score.size();
        vector<string> result(size);
        for(int i = 0 ; i < size ; ++i){
            umap[score[i]] = i;
            pq.push(score[i]);
        }
        for(int i = 0 ; i < size ; ++i){
            int top = pq.top();
            pq.pop();
            result[umap[top]] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal" : i == 2 ? "Bronze Medal" : to_string(i+1);
        }
        return result;
    }
};