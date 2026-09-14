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
    bool isBST(TreeNode* root,int left_max,int right_max){
        if(root==nullptr){
            return true;
        }
        if(root->val<=left_max||root->val>=right_max){
            return false;
        }
        return isBST(root->left,left_max,root->val)&&isBST(root->right,root->val,right_max);

    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,INT_MIN,INT_MAX);
    }
};
