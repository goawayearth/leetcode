#include <iostream>

using namespace std;


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }
    TreeNode* getChild(vector<int>& preorder, vector<int>& inorder,int s1, int e1, int s2, int e2){

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
