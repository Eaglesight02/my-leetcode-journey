class Solution {
public:
    string removeKdigits(string num, int k) {
        // The crux here is the peak element which is the element that is greater than its previous neighbour. We need to remove it.
        // We simulate a stack on the string: we add the elements one by one. 
        // There, if current element is lesser than the stack top (string end), then we pop elements from the end until the given condition is dissatisfied.
        // After that, we remove the starting zeroes.
        string res;
        int size = num.size();
        for(int i = 0 ; i < size ; ++i){
            while(res.size() > 0 && num[i] < res.back() && k > 0){          // Remove the every back element in the string that is greater than the current element.
                res.pop_back();
                --k;
            }
            res += num[i];
        }
        while(k > 0){                                                       // For special conditions where we traverse along all elements and k is still non-zero.
            res.pop_back();
            --k;
        }
        int zeroIndex = 0;
        size = res.size();                                                  // Get indexes of the starting zeroes.
        while(zeroIndex < size && res[zeroIndex] == '0'){
            ++zeroIndex;
        }
        res.erase(0, zeroIndex);
        return zeroIndex == size ? "0" : res;
    }
};