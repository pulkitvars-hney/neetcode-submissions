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
    unordered_map<int, int> mp;

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int preStart, int preEnd,
                    int inStart, int inEnd) {

        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // Root comes first in preorder
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder
        int inRoot = mp[rootVal];

        // Number of nodes in left subtree
        int leftSize = inRoot - inStart;

        root->left = solve(preorder, inorder,
                           preStart + 1,
                           preStart + leftSize,
                           inStart,
                           inRoot - 1);

        root->right = solve(preorder, inorder,
                            preStart + leftSize + 1,
                            preEnd,
                            inRoot + 1,
                            inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder,
                     0, preorder.size() - 1,
                     0, inorder.size() - 1);
    }
};
