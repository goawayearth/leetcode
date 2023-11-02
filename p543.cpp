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
	
	int val[10000];
	int pos=0;
	
    int diameterOfBinaryTree(TreeNode* root) {
		len(root);
		int max=val[0];
		for(int i=1;i<pos;i++){
			if(val[i]>max)
				max = val[i];
		}
		return max;
    }
    
    int len(TreeNode* root){
    	if(root==NULL)return 0;
    	if(root->left==NULL && root->right==NULL){
    		val[pos] = 0;
    		pos++;
    		return 0;
		}
		else if(root->left==NULL && root->right!=NULL){
			int right = len(root->right);
			val[pos] = right + 1;
			pos++;
			return right + 1;
		}
		else if(root->right==NULL && root->left!=NULL){
			int left = len(root->left);
			val[pos] = left + 1;
			pos++;
			return left + 1;
			
		}
		else{
			int left = len(root->left);
			int right = len(root->right);
			val[pos] = left + right + 2;
    		pos++;
			if(left>right)return left+1;
    		return right+1;
		}
		return 0;
    	
	}
};
