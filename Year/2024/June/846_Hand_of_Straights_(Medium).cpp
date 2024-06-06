class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {


        // // Intuition:
        // // Greedy
        // // TC: O(N^2), SC: O(1)
        // // 1. If size of hand is not divisible by groupSize, then groups cannot be formed.
        // // 2. Note that for given hand, consecutive for each group means that every element can be expressed as previous+1 except for the starting element.
        // // So, find the starting element for each group, then find consecutive elements while filling the groups, if you cannot, return false.
        // // If there are no more elements to be traversed, return true;
        // int size = hand.size();
        // if(size % groupSize != 0){
        //     return false;
        // }
        // sort(hand.begin(), hand.end());
        // int prev = hand[0];                     // First element of first group
        // hand[0] = -1;
        // int ind = 1;
        // int grpSize = groupSize-1;
        // while(true){
        //     if(grpSize > 0){                                                    // Group still needs elements
        //         while(ind < size && (hand[ind] == prev || hand[ind] == -1)){    // Traversing elements to find next consecutive element
        //             ++ind;
        //         }
        //         if(ind == size || hand[ind] != prev+1){                         // If there are no consecutive elements, return false
        //             return false;
        //         }
        //         else{                                                           // Else, current element is the consecutive element.
        //             prev = hand[ind];
        //             --grpSize;
        //             hand[ind] = -1;
        //         }
        //     }
        //     else{
        //         for(ind = 0 ; (ind < size) && (hand[ind] == -1) ; ++ind){};     // Finding the starting element of the next group
        //         if(ind < size){                                                 // Element is found.
        //             grpSize = groupSize-1;
        //             prev = hand[ind];
        //             hand[ind] = -1;
        //         }
        //         else{                                                           // No starting element found, so no more groups possible, return true
        //             return true;    
        //         }
        //     }
        // }
        // return true;



        // You can also use ordered_map for this:
        // TC: O(N*log(N)) SC: O(N)
        // TC: O(N) worst T.C if count of all elements is 1
        // O(log*N) to find the smallest element (TreeMap) implement
        int size = hand.size();
        if(size % groupSize != 0){
            return false;
        }
        map<int,int> nums;
        for(int x : hand){
            nums[x]++;
        }
        while(!nums.empty()){
            int prev = nums.begin()->first;             // smallest element
            for(int i = 0 ; i < groupSize ; ++i){       // consecutive elements for the group
                if(nums[prev+i] > 0){
                    nums[prev+i]--;
                    if(nums[prev+i] == 0){              // No more elements, remove the element
                        nums.erase(prev+i);
                    }
                }
                else{                                   // No consecutive element, remove
                    return false;
                }
            }
        }
        return true;
    }
};