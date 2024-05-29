// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> words;
//         for(auto word : wordDict){
//             words.insert(word);
//         }
//         vector<string> strings;
//         int size = s.size();
//         int ind = size-1;
//         string temp = "";
//         int stringsSize = 0;
//         while(ind >= 0){
//             if(words.find(temp) != words.end()){
//                 strings.insert(strings.begin(), temp);
//                 stringsSize += temp.size();
//                 temp = "";
//             }
//             string new_str(1, s[ind]);
//             new_str += temp;
//             temp = new_str;
//             --ind;
//         }
//         if(words.find(temp) != words.end()){
//             strings.insert(strings.begin(), temp);
//             stringsSize += temp.size();
//         }
//         for(auto str : strings){
//             cout << str << " ";
//         }
//         if(stringsSize != size){
//             return {};
//         }
//         return {""};
//     }
// };


class Solution {
public:
    void solve(string s, vector<string>& res, unordered_set<string>& st, vector<string>&temp){
        if(s.length() == 0){
            string str = "";
            for(auto it:temp){
                str += it + " ";
            }
            str.pop_back();
            res.push_back(str);
            return;
        }
        for(int i=0;i<s.length(); i++){
            if(st.count(s.substr(0, i+1))){
                temp.push_back(s.substr(0, i+1));
                solve(s.substr(i+1), res, st, temp);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res, temp;
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        
        solve(s, res, st, temp);
        return res;
    }
};