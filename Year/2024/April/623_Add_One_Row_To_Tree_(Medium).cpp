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

    void createRowNodes(TreeNode* root, int val, int curdepth, int& depth){
        if(!root){
            return;
        }
        if(curdepth == depth - 1){                              // Creating left and right children for the node at depth = depth-1
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            leftNode->left = root->left;
            rightNode->right = root->right;
            root->left = leftNode;
            root->right = rightNode;
            return;
        }
        createRowNodes(root->left, val, curdepth + 1, depth);
        createRowNodes(root->right, val, curdepth + 1, depth);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){                                     // If node is added at the first level, we do it here.
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        int curdepth = 1;
        createRowNodes(root, val, curdepth, depth);         // Depth-First-Search
        return root;
    }
};