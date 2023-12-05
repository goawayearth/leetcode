/*************************************************************************
        > File Name: ccf201909_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月06日 星期三 01时51分54秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int nums[1000][3]={0};
    int n,m;
    cin>>n>>m;
    int sum=0;
    for(int i=0;i<n;i++){
        nums[i][0] = i;
        int sing= 0;
        for(int j=0;j<=m;j++){
            int tem;
            cin>>tem;
            if(j == 0){
                nums[i][1]=tem;
            }
            else{
                sing+=tem;
            }
            sum+=tem;
        }
         nums[i][2]=sing;
    }
    for(int i=0;i<n-1;i++){
        if(nums[i][2]<nums[i+1][2]||nums[i][2]==nums[i+1][2]&&nums[i][0]<nums[i+1][0]){
            //交换
            int a = nums[i][0];
            int b= nums[i][1];
            int c= nums[i][2];
            nums[i][0] = nums[i+1][0];
            nums[i][1] = nums[i+1][1];
            nums[i][2] = nums[i+1][2];
            nums[i+1][0] = a;
            nums[i+1][1] = b;
            nums[i+1][2] = c;
        }
    }
    cout<<sum<<" "<<nums[n-1][0]<<" "<<-nums[n-1][2];
}
    

