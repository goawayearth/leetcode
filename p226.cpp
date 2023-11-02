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
    TreeNode* invertTree(TreeNode* root) {
    	if(root==NULL)return NULL;
    	TreeNode* treeroot = new TreeNode();
    	treeroot->val = root->val;
		treeroot->left = invertTree(root->right);
		treeroot->right = invertTree(root->left);
    	return treeroot;
    }
    
};
