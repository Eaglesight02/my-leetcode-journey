class Solution {
public:
    // Implement the given conditions using stack and queue. 
    // We cannot traverse more when we rotate the elements over the current queue size.
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // // With using stack
        // deque<int> dq;
        // stack<int> st;
        // int size = students.size();
        // for(int i = size - 1 ; i >= 0 ; --i){
        //     st.push(sandwiches[i]);
        //     dq.push_front(students[i]);
        // }
        // int curSize = 0;
        // while(!dq.empty() && curSize != size){
        //     if(dq.front() == st.top()){
        //         st.pop();
        //         dq.pop_front();
        //         curSize = 0;
        //         --size;
        //     }
        //     else{
        //         int temp = dq.front();
        //         dq.pop_front();
        //         dq.push_back(temp);
        //         ++curSize;
        //     }
        // }
        // return curSize;

        // Without using stack
        deque<int> dq;
        int size = students.size();
        for(int i = 0 ; i < size ; ++i){
            dq.push_front(students[i]);
        }
        int curSize = 0;
        int index = 0;
        while(!dq.empty() && curSize != size){
            if(dq.front() == sandwiches[index]){    // Front of queue and top of stack are matching, pop both of them.
                ++index;
                dq.pop_front();
                curSize = 0;
                --size;
            }
            else{                                   // Not matching, so send front to queue's back and reiterate.
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
                ++curSize;
            }
        }
        return curSize;
    }
};