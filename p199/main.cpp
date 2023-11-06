#include <iostream>
#include <vector>
using namespace std;

  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(NULL), right(NULL) {}
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {

        if(root==NULL){
            return ans;
        }
        vector<TreeNode*> node;
        node.push_back(root);
        traves(node);
        return ans;


    }

    void traves(vector<TreeNode*>node){
        int n = node.size();
        if(n==0)return;
        int an = node[node.size()-1]->val;
        ans.push_back(an);
        vector<TreeNode*> nextNode;

        for(int i=0;i<n;i++){
            if(node[i]->left != NULL){
                nextNode.push_back(node[i]->left);
            }
            if(node[i]->right!=NULL){
                nextNode.push_back(node[i]->right);
            }
        }
        traves(nextNode);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
