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
    class Solution {
public:
    vector<int> trans;
    bool isValidBST(TreeNode* root) {
        tra(root);
        bool flag = true;
        for(int i=0;i<trans.size()-1;i++){
            if(trans[i]>=trans[i+1]){
                flag = false;
                break;
            }
        }
        if(!flag){
            return false;
        }
        return true;
    }
    void tra(TreeNode* root){
        if(root->left!=NULL){
            tra(root->left);
        }
        trans.push_back(root->val);
        if(root->right!=NULL){
            tra(root->right);
        }
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
