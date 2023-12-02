/*************************************************************************
        > File Name: ccf201809_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月02日 星期六 10时43分09秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
vector<int> nums;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tem;
        cin>>tem;
        nums.push_back(tem);
    }
    vector<int> ans(n);
    ans[0] = (nums[0]+nums[1]) / 2;
    for(int i=1;i<n-1;i++){
        ans[i] = (nums[i-1]+nums[i]+nums[i+1]) / 3;
    }
    ans[n-1] = (nums[n-2]+nums[n-1]) / 2;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}



