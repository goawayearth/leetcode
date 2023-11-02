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
	int leftVal[1000];
	int pos1=0;
	int rightVal[1000];
	int pos2=0;
    bool isSymmetric(TreeNode* root) {
		leftTran(root->left);
		rightTran(root->right);
		
		if(pos1!=pos2)return false;
		for(int i=0;i<pos1;i++){
			if(leftVal[i]!=rightVal[i])return false;
		}
		return true;
		
    }
    
    void leftTran(TreeNode* root){
    	if(root==NULL){
    		leftVal[pos1] = 101;
    		pos1++;
    		return;
		}
    	leftVal[pos1] = root->val;
    	pos1++;
    	leftTran(root->left);
    	leftTran(root->right);
	}
	
	void rightTran(TreeNode* root){
		if(root==NULL){
			rightVal[pos2] = 101;
			pos2++;
			return;
		}
		rightVal[pos2] = root->val;
		pos2++;
		rightTran(root->right);
		rightTran(root->left);
	}
    
    
};
