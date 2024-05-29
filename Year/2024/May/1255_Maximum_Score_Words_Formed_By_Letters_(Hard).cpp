class Solution {
public:

    int getMaxScore(vector<string>& words, unordered_map<char,int>& alphabet_count, vector<int>& score, int ind){
        if(ind == words.size()){
            return 0;
        }
        int take = 0;
        int notTake = 0;
        int wordSize = words[ind].size();
        bool takeFailed = false;
        int backIndex = wordSize-1;
        for(int i = 0 ; i < wordSize ; ++i){
            if(alphabet_count[words[ind][i]] == 0){
                takeFailed = false;
                backIndex = i-1;
                take = 0;
                break;
            }
            take += score[words[ind][i]-'a'];
            alphabet_count[words[ind][i]]--;
        }       
        while(takeFailed && backIndex >= 0){
            alphabet_count[words[ind][backIndex]]++;
            backIndex--;
        }
        take += getMaxScore(words, alphabet_count, score, ind+1);
        while(backIndex >= 0){
            alphabet_count[words[ind][backIndex]]++;
            backIndex--;
        }
        notTake += getMaxScore(words, alphabet_count, score, ind+1);
        return max(take, notTake);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // Recursive Solution: works fine.
        unordered_map<char,int> alphabet_count;
        int letters_size = letters.size();
        for(int i = 0 ; i < letters_size ; ++i){
            alphabet_count[letters[i]]++;
        }
        for(auto it = words.begin() ; it != words.end() ; ){
            bool value = false;
            for(char c : *it){
                if(alphabet_count[c] == 0){
                    value = true;
                }
            }
            if(value){
                words.erase(it);
            }
            else{
                ++it;
            }
        }
        return getMaxScore(words, alphabet_count, score, 0);
    }
};