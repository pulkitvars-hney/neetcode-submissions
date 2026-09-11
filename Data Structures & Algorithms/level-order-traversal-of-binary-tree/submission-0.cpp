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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
           if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for (int i = 0; i < size; i++) {
                TreeNode* n = q.front();
                q.pop();
                temp.push_back(n->val);
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};