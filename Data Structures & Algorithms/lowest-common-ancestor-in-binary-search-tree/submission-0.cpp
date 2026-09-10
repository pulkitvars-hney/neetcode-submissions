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
    TreeNode* search(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==nullptr||root==p||root==q){
            return root;
        }
        TreeNode* right=search(root->right,p,q);
        TreeNode* left=search(root->left,p,q);

        if(left==nullptr){
            return right;
        }
        else if(right==nullptr){
            return left;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return search(root,p,q);
    }
};
