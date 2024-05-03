class Solution {
public:

    // I can't believe that this piece of code worked on the first try :)

    int compareVersion(string version1, string version2) {
        int ind1 = 0, ind2 = 0;
        int size1 = version1.size();
        int size2 = version2.size();
        while(ind1 < size1 || ind2 < size2){
            int v1 = 0, v2 = 0;

            // Ignore leading zeroes (if any)
            while(ind1 < size1 && version1[ind1] == '0'){
                ++ind1;
            }
            while(ind2 < size2 && version2[ind2] == '0'){
                ++ind2;
            }

            // Take all the binary digits (0 and 1) and consider them for an integer.
            while(ind1 < size1 && version1[ind1] != '.'){
                v1 *= 10;
                v1 += version1[ind1] - '0';
                ++ind1;
            }
            while(ind2 < size2 && version2[ind2] != '.'){
                v2 *= 10;
                v2 += version2[ind2] - '0';
                ++ind2;
            }
            if(v1 < v2){
                return -1;
            }
            else if(v1 > v2){
                return 1;
            }

            // Ignore periods (if any)
            if(ind1 < size1 && version1[ind1] == '.'){
                ++ind1;
            }
            if(ind2 < size2 && version2[ind2] == '.'){
                ++ind2;
            }
        }
        return 0;
    }
};