class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        int size = s.size();
        for(int i = 1 ; i < size ; ++i){
            score += abs(s[i] - s[i-1]);
        }
        return score;
    }
};