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

    string getSmallestString(string pre, TreeNode* root){
        if(!root){                                              // For a node with no value, we return the maximum possible string for that level.
            return char(26 + 'a') + pre;                        // We take the first character > 'z'.
        }
        string result = char(root->val + 'a') + pre;
        if(!root->left && !root->right){                        // For leaf node, we return the curstring.
            return result;
        }
        string left = getSmallestString(result, root->left);    // Else, we return the minimum of the left and right substrings.
        string right = getSmallestString(result, root->right);
        return min(left, right);                                
    }

    string smallestFromLeaf(TreeNode* root) {
        return getSmallestString("", root);
    }
};