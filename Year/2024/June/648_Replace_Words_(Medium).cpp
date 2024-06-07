class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Simple Parsing through the string:
        // TC: O(N), SC: O(N) (unordered_set)
        unordered_set<string> words;
        for(auto a : dictionary){
            words.insert(a);
        }
        string result = "";
        int ind = 0;
        int size = sentence.size();
        string temp = "";
        while(ind < size && sentence[ind] != ' '){          // To get the first root word
            if(words.find(temp) != words.end()){
                break;
            }
            temp += sentence[ind];
            ++ind;
        }
        while(ind < size && sentence[ind] != ' '){          // If first word is bigger than root word, then go to the next word
            ++ind;
        }
        ++ind;                                              // Disregard the space
        result += temp;
        while(ind < size){
            temp = "";
            while(ind < size && sentence[ind] != ' '){      // Get the root word
                if(words.find(temp) != words.end()){
                    break;
                }
                temp += sentence[ind];
                ++ind;
            }
            while(ind < size && sentence[ind] != ' '){      // If still characters left, then go to the next space
                ++ind;
            }
            if(ind < size && sentence[ind] == ' '){         // If space found, then go to the next root word
                ++ind;
            }
            if(temp != ""){                                 // Root found, add it to the result
                result += ' ';
                result += temp;
            }
        }
        return result;
    }
};