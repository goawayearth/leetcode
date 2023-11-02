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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	int n = nums.size()-1;
		return treeSort(nums,0,n);
    }
    
    TreeNode* treeSort(vector<int>& nums,int start,int end){
    	int mid = (start+end)/2;
		TreeNode* node = new TreeNode();
    	node->val = nums[mid];
    	
		if(start == end){
    		node->left = NULL;
    		node->right = NULL;
		}
    	else if(mid==start){
    		//前面没有数字了 
    		node->left=NULL;
			node->right = treeSort(nums,mid+1,end);
		}
		else{
			node->left = treeSort(nums,start,mid-1);
    		node->right = treeSort(nums,mid+1,end);
		}
		
    	return node;
	}
    
};
