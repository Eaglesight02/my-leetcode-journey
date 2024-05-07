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

    int getDoubleNumber(ListNode* head){
        if(head){
            int carry = getDoubleNumber(head->next);
            head->val *= 2;
            head->val += carry;
            carry = head->val / 10;
            head->val %= 10;
            return carry;
        }
        return 0;
    }

    ListNode* doubleIt(ListNode* head) {
        // // My solution: uses a vector for extra space
        // vector<int> digits;
        // ListNode* temp = head;
        // ListNode* prev = new ListNode;
        // prev->next = head;
        // int size = 0;
        // while(temp){
        //     digits.emplace_back(temp->val);
        //     temp = temp->next;
        //     ++size;
        // }
        // short int carry = 0;
        // for(int i = size-1 ; i >= 0 ; --i){
        //     digits[i] *= 2;
        //     digits[i] += carry;
        //     if(digits[i] > 9){
        //         carry = 1;
        //         digits[i] %= 10;
        //     }
        //     else{
        //         carry = 0;
        //     }
        // }
        // if(carry == 1){
        //     digits.insert(digits.begin(),1);
        //     ++size;
        // }
        // temp = head;
        // int i = 0;
        // while(temp && i < size){
        //     temp->val = digits[i];
        //     prev = prev->next;
        //     temp = temp->next;
        //     ++i;
        // }
        // if(i < size){
        //     prev->next = new ListNode(digits[i]);
        // }
        // digits.clear();
        // return head;





    //     // Lee 215's solution: single pass, no extra memory.
    //     // Uses the intuition that if current or next value is greater than 4, then doubling it will give us a two digit number.
    //     if(head->val > 4){
    //         ListNode* temp = new ListNode(0);
    //         temp->next = head;
    //         head = temp;
    //     }
    //     for(ListNode* temp = head ; temp != NULL ; temp = temp->next){
    //         temp->val *= 2;
    //         if(temp->next && temp->next->val > 4){
    //             ++temp->val;
    //         }
    //         temp->val %= 10;
    //     }
    //     return head;





    // Can also be done using a stack - recursively
    int carry = getDoubleNumber(head);
    if(carry == 1){
        ListNode* temp = new ListNode(carry);
        temp->next = head;
        head = temp;
    }
    return head;
}
};