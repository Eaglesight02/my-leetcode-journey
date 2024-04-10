class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Reversed process(provided by Lee):
        // Take the original deck in decreasing order, take first element inside queue.
        // At each iteration: pop the back element and push into front
        // Then, push_front the element in deck

        // sort(deck.rbegin(), deck.rend());
        // deque<int> dq;
        // dq.push_back(deck[0]);
        // for(int i = 1 ; i < deck.size() ; ++i){
        //     dq.push_front(dq.back());
        //     dq.pop_back();
        //     dq.push_front(deck[i]);
        // }
        // vector<int> result(dq.begin(), dq.end());
        // return result;



        // Actual Process:
        // Take example, Deck: [17,13,11,2,3,5,7]
        // After sorting, Deck: [2,3,5,7,11,13,17]
        // Queue: [0,1,2,3,4,5,6]
        // Result: [0,0,0,0,0,0,0]
        // Passes:
            // i = 0: result[0] = deck[0], Queue: [2,3,4,5,6,1], Result: [2,0,0,0,0,0,0]
            // i = 1: result[2] = deck[1], Queue: [4,5,6,1,3],   Result: [2,0,3,0,0,0,0]
            // i = 2: result[4] = deck[2], Queue: [6,1,3,5],     Result: [2,0,3,0,5,0,0]
            // i = 3: result[6] = deck[3], Queue: [3,5,1],       Result: [2,0,3,0,5,0,7]
            // i = 4: result[3] = deck[4], Queue: [1,5],         Result: [2,0,3,11,5,0,7]
            // i = 5: result[1] = deck[5], Queue: [5],           Result: [2,13,3,11,5,0,7]
            // i = 6: result[5] = deck[6], Queue: [],            Result: [2,13,3,11,5,17,7]
        // So, we first sort the array, take the indices from 0 to n in queue.
        // Then, we iterate over all indices of the array and then: result[queue.front()] = deck[index]; then, take out the first front, push_back the second front

        sort(deck.begin(), deck.end());
        deque<int> dq;
        int size = deck.size();
        vector<int> result(size, 0);
        for(int i = 0 ; i < size ; ++i){        // Initialising the queue with indices
            dq.push_back(i);
        }
        for(int i = 0 ; i < size ; ++i){        // Performing the simulation
            result[dq.front()] = deck[i];
            dq.pop_front();
            dq.push_back(dq.front());
            dq.pop_front();
        }
        return result;
    }
};