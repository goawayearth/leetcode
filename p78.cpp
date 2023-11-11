/*************************************************************************
        > File Name: p78.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月11日 星期六 13时52分32秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums){
        vector<int> temp;
        vector<int> temp1;
        ans.push_back(temp);
        if(nums.size()>1)
            getNext(nums,1,temp);
        temp1.push_back(nums[0]);
        ans.push_back(temp1);
        if(nums.size()>1)
            getNext(nums,1,temp1);
        return ans;
    }
    void getNext(vector<int>nums,int pos,vector<int>temp){
        vector<int> tem = temp;
        if(pos<nums.size()-1){
            getNext(nums,pos+1,tem);
        }
        vector<int> tem1 = temp;
        tem1.push_back(nums[pos]);
        ans.push_back(tem1);
        if(pos<nums.size()-1){
            getNext(nums,pos+1,tem1);
        }
    }
};
int main(){
    vector<int> nums = {1,2};
    Solution* so = new Solution();
    vector<vector<int>>ans = so->subsets(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

        
