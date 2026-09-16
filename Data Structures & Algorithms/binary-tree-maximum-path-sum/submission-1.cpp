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
    int dfs(TreeNode* root,int& sum){
        if(root==nullptr){
            return 0;
        }
        int ls=max(0,dfs(root->left,sum));
        int rs=max(0,dfs(root->right,sum));
        sum= max(sum,root->val+ls+rs);
        return max(ls,rs)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        dfs(root,sum);
        return sum;
    }   
};
