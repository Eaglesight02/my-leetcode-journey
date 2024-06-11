class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // // Using map to store count and sort simulatenously.
        // // TC: O(N*log(N) + M + log(N))    SC: O(log(N)) + O(N)
        // vector<int> result;
        // map<int, int> integers;
        // int size1 = arr1.size();
        // int size2 = arr2.size();
        // for(int i = 0 ; i < size1 ; ++i){        // Freq of elements
        //     integers[arr1[i]]++;
        // }
        // for(int i = 0 ; i < size2 ; ++i){        // Get elemens from arr2
        //     while(integers[arr2[i]]){
        //         result.emplace_back(arr2[i]);
        //         --integers[arr2[i]];
        //     }
        // }
        // for(auto it : integers){                 // Get remaining elements from arr1
        //     while(it.second){
        //         result.emplace_back(it.first);
        //         --it.second;
        //     }
        // }
        // return result;


        // Brute force: use two nested loops TC: O(N*M + log(N)) SC: O(N) for result



        // Use count sort
        // TC: O(m+n) SC: O(N) + O(N) (for result)
        vector<int> count(1001);
        int size1 = arr1.size();
        int size2 = arr2.size();
        vector<int> result;
        for(int i = 0 ; i < size1 ; ++i){           // Freq of elements
            count[arr1[i]]++;
        }
        for(int i = 0 ; i < size2 ; ++i){           // Unique elements from arr2
            while(count[arr2[i]] > 0){
                result.emplace_back(arr2[i]);
                count[arr2[i]]--;                
            }
        }
        for(int i = 0 ; i <= 1000 ; ++i){           // Remaining elements from arr1
            while(count[i] > 0){
                result.emplace_back(i);
                count[i]--;
            }
        }
        return result;
    }
};