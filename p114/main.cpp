#include <iostream>
#include <vector>
using namespace std;
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
    vector<int> tree;
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        tran(root);
        TreeNode* p;
        p = root;
        root->left=NULL;
        p->val=tree[0];
        for(int i=1;i<tree.size();i++){
            TreeNode* node = new TreeNode();
            node->left = NULL;
            node->val = tree[i];
            p->right = node;
            p = node;
        }
    }
    void tran(TreeNode* root){
        if(root==NULL)return;
        tree.push_back(root->val);
        tran(root->left);
        tran(root->right);
    }

};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
