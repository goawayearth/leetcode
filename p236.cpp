/*************************************************************************
        > File Name: p236.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月10日 星期五 21时58分07秒
 ************************************************************************/
#include <vector>
#include <unordered_map>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
class Solution{
public:
    vector<int> left;
    vector<int> right;
    int ans;
    TreeNode* answer;
    unordered_map<int,int>map;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        leftToRight(root);
        rightToLeft(root);
        for(int i=0;i<left.size();i++){
            cout<<left[i]<<" ";
        }cout<<endl;
        for(int i=0;i<left.size();i++){
            cout<<right[i]<<" ";
        }cout<<endl;
        int v1 = p->val;
        int v2 = q->val;
        int n = left.size();
        int i=0;
        for(i=0;left[i]!=v1 && left[i]!=v2 ;i++){
            map[left[i]]=1;
        }
        map[left[i]]=1;
        int pos = 0;
        while(1){
            if(right[pos]==v1 || right[pos] == v2){
                cout<<right[pos]<<endl;
                break;

            }
            pos++;
        }
        while(1){
            int val = right[pos];
            auto it = map.find(val);
            if(it!=map.end()){
                //找到了
                ans = it->first;
                break;
            }
            pos--;
        }
        getNode(root,ans);
        return answer;
    
    }

    void getNode(TreeNode* root,int val){
        if(root == NULL)return;
        if(root->val == val){
            answer = root;
            return;
        }
        getNode(root->left,val);
        getNode(root->right,val);
    }



    void leftToRight(TreeNode* root){
        if(root == NULL)return;
        left.push_back(root->val);
        leftToRight(root->left);
        leftToRight(root->right);
    }
    void rightToLeft(TreeNode* root){
        if(root == NULL)return;
        right.push_back(root->val);
        rightToLeft(root->right);
        rightToLeft(root->left);
    }

};

int main(){
    return 0;
}
