class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // For maximum  number of people in a boat, include a higher with a lower one.
        sort(people.begin(), people.end());
        int sum = 0;
        int left = 0;
        int right = people.size()-1;
        while(left <= right){
            if(people[left] + people[right] <= limit) {
                ++left;
                --right;
            }
            else {
                --right;
            }
            ++sum;
        }
        return sum;
    }
};