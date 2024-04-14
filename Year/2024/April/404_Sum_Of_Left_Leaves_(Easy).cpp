/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root){                                          // root doesn't exist.
            return 0;
        }
        if(!root->left && !root->right){                    // No children of root exist.
            return 0;
        }
        int sum = 0;
        if(root->left){                                     // If root->left exists, but it has no children, then we would take the value
            if(!root->left->left && !root->left->right){
                sum += root->left->val;
            }
            else sum += sumOfLeftLeaves(root->left);        // Else, we would call the recursive function for the left child
        }
        if(root->right){                                    // If right child exists for the current node, then we would the recursive function on it.
            sum += sumOfLeftLeaves(root->right);    
        }
        return sum;
    }
};