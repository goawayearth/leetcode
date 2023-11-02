
 Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
	vector<int> leef;
    vector<int> inorderTraversal(TreeNode* root) {
		store(root);
		return leef;		
    }
    
    void store(TreeNode* root){
    	if(root == NULL)return;
    	store(root->left);
		leef.push_back(root->val);
    	store(root->right);
	}
    
};
