/*************************************************************************
        > File Name: ccf202104_2.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月06日 星期三 10时28分30秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,L,r,t,ans;
    cin>>n>>L>>r>>t;
    ans = 0;
    vector<vector<int>>matrix(n,vector<int>(n));
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    //矩阵输入完毕
    

    for(int i=0;i<n;i++){
        int flag = 0;
        for(int j=0;j<n;j++){
            int starti = i-r >= 0?i-r:0;
            int startj = j-r >= 0?j-r:0;
            int endi = i+r <n?i+r:n;
            int endj = j+r <n?j+r:n;
            if(flag == 0){
                //说明是第一个，得算
                int sum = 0;
                for(int i=strati;i<endi;i++){
                    for(int j=startj;j<endj;j++){
                        






    return 0;
}


