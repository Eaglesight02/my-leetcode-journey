class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // Optimized Brute Force (O(N^3))
        int size = arr.size();
        if(size < 3){
            if(size == 1){
                return 0;
            }
            return arr[0] == arr[1];
        }
        int totalXOR = 0;
        for(int i = 0 ; i < size ; ++i){
            totalXOR ^= arr[i];
        }
        int left = 0;
        int right = 0;
        int count = 0;
        // Taking the XOR from current index of 'i' to 'j', then taking XOR from 'j' to 'k'.
        for(int i = 0 ; i <= size-2 ; ++i){
            right = 0;
            left = 0;
            for(int j = i+1 ; j < size ; ++j){
                left ^= arr[j-1];                       // XOR from i to j
                right = totalXOR ^ left;                // Remaining XOR of the array
                for(int k = size-1 ; k >= j ; --k){
                    if(left == right){
                        ++count;
                    }
                    right ^= arr[k];                    // Removing XOR of elements from end(k to j)
                }
            }
            totalXOR ^= arr[i];
        }
        return count;
    }
};