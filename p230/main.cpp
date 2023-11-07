#include <iostream>

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
    int k_flag;
    int num = 0;
    int value=0;
    int kthSmallest(TreeNode* root, int k) {
        k_flag=k;
        tran(root);
        return value;
    }
    void tran(TreeNode* root){
        if(root==NULL){
            return;
        }
        tran(root->left);
        num++;
        if(num == k_flag){
            value = root->val;
            return;
        }
        tran(root->right);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
