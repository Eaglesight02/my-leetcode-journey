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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // we first take the left and right paths:
        // We return the nodes (left and right):
        // If node is a leaf node and its value is equal to target, we return NULL
        if(!root){
            return NULL;
        }
        TreeNode* left = removeLeafNodes(root->left, target);
        TreeNode* right = removeLeafNodes(root->right, target);
        root->left = left;
        root->right = right;
        if(root->val == target && !root->left && !root->right){
            return NULL;
        }
        return root;
    }
};