class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // // Simple greedy solution
        // // TC: O(N*log(N))
        // // SC: O(log(N))
        // sort(seats.begin(), seats.end());
        // sort(students.begin(), students.end());
        // int count = 0;
        // int size = seats.size();
        // for(int i = 0 ; i < size ; ++i){
        //     count += abs(seats[i] - students[i]);
        // }
        // return count;


        // CountSort:
        // TC: O(N)
        // SC: O(N)
        // Here, we take the max of possible students and positions.
        // First, we take all the counts of all available seats(positions).
        // Then, we remove students counts from "positions".
        // When we encounter '-1' in positions, it means that a seat is needed, when +1 is encountered, it means that extra seat is present at that position.
        // Since we are taking the count, both extra and deficit seats must be considered (that is why abs).
        // But we do normal arithmetic addition for unmatched, because we have to balance the extra with deficit seats.
        int seatMax = *max_element(seats.begin(), seats.end());
        int studentMax = *max_element(students.begin(), students.end());
        int maxPosition = max(seatMax, studentMax);
        vector<int> positions(maxPosition, 0);
        int size = seats.size();
        for(int i = 0 ; i < size ; ++i){
            positions[seats[i]-1]++;
        }
        for(int i = 0 ; i < size ; ++i){
            --positions[students[i]-1];
        }
        int moves = 0, unmatched = 0;
        for(int i = 0 ; i < maxPosition ; ++i){
            moves += abs(unmatched);
            unmatched += positions[i];
        }
        return moves;
    }
};