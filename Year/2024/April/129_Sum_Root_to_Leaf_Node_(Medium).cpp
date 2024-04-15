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

    int sumNumbers(TreeNode* root, int sum = 0) {
        sum *= 10;
        sum += root->val;
        if(!root->left && !root->right){                // Leaf node, return sum
            return sum;
        }
        int result = 0;
        if(root->left){
            result += sumNumbers(root->left, sum);      // Just like getting the digits from a given number, we multiply the sum by 10 and then add the value to it.
        }
        if(root->right){
            result += sumNumbers(root->right, sum);
        }
        return result;
    }
};