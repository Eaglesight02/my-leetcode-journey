class Solution {
public:
    int appendCharacters(string s, string t) {
        // Easy loops
        int size1 = s.size();
        int size2 = t.size();
        int ind1 = 0;
        int ind2 = 0;
        for(ind1 = 0 ; ind1 < size1 && ind2 < size2 ; ++ind1){
            if(s[ind1] == t[ind2]){
                ++ind2;
            }
        }
        return size2 - ind2;
    }
};