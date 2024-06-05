class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Simple 2D Vector
        int size = words.size();
        vector<vector<int>> alphabets(size, vector<int>(26,0));
        vector<string> result;
        for(int i = 0 ; i < size ; ++i){
            int curSize = words[i].size();
            for(int j = 0 ; j < curSize ; ++j){
                alphabets[i][words[i][j]-'a']++;
            }
        }
        for(int i = 0 ; i < 26 ; ++i){
            int count = alphabets[0][i];                    // Getting the least count for the character from all the strings
            for(int j = 1 ; j < size ; ++j){
                count = min(count, alphabets[j][i]);
            }
            if(count > 0){                                  // If > 0 means that the character occurs once or more times in the strings
                char c = static_cast<char>(97+i);
                string s(1,c);
                while(count--){
                    result.emplace_back(s);
                }
            }
        }
        return result;
    }
};