/*************************************************************************
        > File Name: p46.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月09日 星期四 13时17分10秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    int num=0;
    vector<vector<int>> ans;
    vector<int> oneans;

    vector<vector<int>> permute(vector<int>& nums){
       vector<int> flag(nums.size());
       num = nums.size();
       takeElement(nums,flag);
       return ans;

    }
    void takeElement(vector<int>& nums,vector<int>& flag){
        for(int i=0;i<num;i++){
            if(flag[i]==0){
                 oneans.push_back(nums[i]);
                 flag[i]=1;
                 if(oneans.size()==num){
                     vector<int> one;
                     for(int j=0;j<num;j++){
                         one.push_back(oneans[j]);
                     }
                     ans.push_back(one);
                 }
                 else {
                     takeElement(nums,flag);
                 }
                 flag[i]=0;
                 oneans.pop_back();
            }
        }
    }
};
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    Solution* so = new Solution();
    vector<vector<int>>ans = so->permute(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
