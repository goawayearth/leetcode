/*************************************************************************
        > File Name: p105.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月08日 星期三 10时15分09秒
 ************************************************************************/

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0),left(NULL), right(NULL){}
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
    int pos1=0;
    int pos2=0;
    TreeNode* buildTree(vector<int>& preorder,vector<int> inorder){
        TreeNode* root = new TreeNode();
        root->val = preorder[pos1];
        pos1++;
        vector<int> leftNode;
        while(inorder[pos2]!=root->val){
            leftNode.push_back(inorder[pos2]);
            pos2++;
        }
        vector<int> rightNode;
        pos2++;
        while(pos2<inorder.size()){
            rightNode.push_back(inorder[pos2]);
            pos2++;
        }
        inorder.clear();
        if(leftNode.size()>0){
            root->left = getChild(preorder,leftNode);
        }
        if(rightNode.size()>0){
            root->right = getChild(preorder,rightNode);
        }
        return root;
    }

    TreeNode* getChild(vector<int>& preorder,vector<int>& inorder){
        //这个inorder是重新作的，preorder是和之期纳的一样，pos指示preorder的位置
        TreeNode* root=new TreeNode();
        root->val = preorder[pos1];
        pos1++;
        int pos2=0;
        vector<int> leftNode;
        while(inorder[pos2]!=root->val){
            leftNode.push_back(inorder[pos2]);
            pos2++;
        }
        vector<int> rightNode;
        pos2++;
        while(pos2<inorder.size()){
            rightNode.push_back(inorder[pos2]);
            pos2++;
        }
        inorder.clear();
        if(leftNode.size()>0){
            root->left = getChild(preorder,leftNode);
        }
        if(rightNode.size()>0){
            root->right = getChild(preorder,rightNode);
        }
        return root;
    }    
};
int main(){
    
}























