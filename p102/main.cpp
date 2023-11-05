#include <iostream>
#include <vector>

using namespace std;

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
        if(root == NULL)return ans;
        vector<TreeNode*>node;
        node.push_back(root);
        return traves(node);
    }

    vector<vector<int>> traves(vector<TreeNode*>node){
        vector<TreeNode*> nextNode;
        vector<vector<int>> ans1;
        vector<int> ans;
        int n = node.size();
        if(n==0)return ans1;
        for(int i=0;i<n;i++){
            int a = node[i]->val;
            ans.push_back(a);
            if(node[i]->left != NULL){
                nextNode.push_back(node[i]->left);
            }
            if(node[i]->right!=NULL){
                nextNode.push_back(node[i]->right);
            }
        }
        ans1.push_back(ans);
        vector<vector<int>> tem = traves(nextNode);
        for(int i=0;i<tem.size();i++){
            ans1.push_back(tem[i]);
        }
        return ans1;
    }





};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
