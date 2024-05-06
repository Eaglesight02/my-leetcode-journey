/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        // // Brute force method: put all values in an array and then:
        // // From right to left: mark negative if there is a bigger element to its right
        // // Then, take all positive elements into a linked list

        // vector<int> nodes;
        // ListNode* it = head;
        // while(it){
        //     nodes.emplace_back(it->val);
        //     ListNode* temp = it;
        //     it = it->next;
        //     delete(temp);
        // }
        // int size = nodes.size();
        // int maxInt = nodes[size-1];
        // for(int i = size-2 ; i >= 0 ; --i){
        //     if(nodes[i] < maxInt){
        //         nodes[i] *= -1;
        //     }
        //     else{
        //         maxInt = nodes[i];
        //     }
        // }
        // int i = 0;
        // while(nodes[i] < 0){
        //     ++i;
        // }
        // head = new ListNode(nodes[i]);
        // it = head;
        // ++i;
        // for(; i < size ; ++i){
        //     if(nodes[i] > 0){
        //         it->next = new ListNode(nodes[i]);
        //         it = it->next;
        //     }
        // }
        // return head;



        // Lee 215's solution: if current value is lesser than next value, then we return next value, else current.

        if(!head) return NULL;
        head->next = removeNodes(head->next);
        return head->next && head->val < head->next->val ? head->next : head;

    }
};