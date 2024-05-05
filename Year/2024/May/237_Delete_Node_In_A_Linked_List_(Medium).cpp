/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // The disciption is very confusing:
    // tl;dr: LinkedList Head is not given, only the node to be deleted.
    // But, you cannot delete the node from memory: i.e: you have to change the node's value, not its memory.
    // It is also given that the node to be deleted is not the last one, since if it is, then we cannot assign value to the node.
    // So we assign values consecutively and for the edge case: node whose next->next node is NULL, we just take node->next value as current node's value and assign node->next = NULL
    void deleteNode(ListNode* node) {
        // while(node->next->next){
        //     node->val = node->next->val;
        //     node = node->next;
        // }
        // node->val = node->next->val;
        // node->next = node->next->next;


        // This is a very simple solution: Here, we copy the values from the next node to the current node(val, node->next) to the current node.
        // Then, the next node is deleted (not the current node), free up the memory.
        ListNode* temp = node->next;
        *node = *(node->next);
        delete(temp);
    }
};