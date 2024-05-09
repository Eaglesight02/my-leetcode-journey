class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Simple sorting/priority queue
        long long maxHappiness = 0;
        int turn = 0;
        int size = happiness.size();
        sort(happiness.begin(), happiness.end());
        for(int i = size-1 ; i >= 0 && k > 0 ; --i){
            int temp = happiness[i] - turn;
            if(temp < 0){
                break;
            }
            maxHappiness += temp;
            ++turn;
            --k;
        }
        return maxHappiness;
    }
};