/*************************************************************************
        > File Name: ccf202305_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月26日 星期日 20时57分44秒
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



int main(){
    int num = 0;
    cin>>num;//总共的棋盘数量
    vector<string> nums;
    for(int i=0;i<num;i++){
        string single="";
        for(int j=0;j<8;j++){
            string one;
            cin>>one;
            single+=one;
        }
        nums.push_back(single);
    }
    /*
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<endl;
    }*/
    vector<int> ans;
    unordered_map<string,int>hashMap;
    for(int i=0;i<nums.size();i++)
    {
        hashMap[nums[i]]++;
        ans.push_back(hashMap[nums[i]]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

}

