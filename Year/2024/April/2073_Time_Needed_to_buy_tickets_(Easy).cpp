class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // Parse through the entire array 'N' times based on the given conditions
        int time = 0;
        int ind = 0;
        int size = tickets.size();

        // Loop until the element tickets[k] is non-zero
        while(tickets[k] > 0){
            if(tickets[ind] > 0){       // If current element is non-zero, we have to decrement the element and increase time
                --tickets[ind];
                ++time;
            }
            ind = (ind+1)%size;         // Go to the next element (if element is already zero, then we don't increase the time)
        }
        return time;
    }
};