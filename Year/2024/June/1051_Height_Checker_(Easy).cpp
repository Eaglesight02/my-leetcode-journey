class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // SImple sort and compare
        // TC: O(N*Log(N)) SC: O(N)
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int count = 0;
        int size = heights.size();
        for(int i = 0 ; i < size ; ++i){
            if(heights[i] != expected[i]){
                ++count;
            }
        }
        return count;
    }
};