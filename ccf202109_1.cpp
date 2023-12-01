/*************************************************************************
        > File Name: ccf202109_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月01日 星期五 14时45分46秒
 ************************************************************************/

#include <iostream>

using namespace std;

int B[100000]={0};
int A[100000]={0};

long ans1=0;
long ans2=0;


int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    
    int lastMax=-1;
    //B是单调递增的
    for(int i=0;i<n;i++){
        if(B[i]>lastMax){
            //说明现在是才是最大值
            ans1+=B[i];
            ans2+=B[i];
            lastMax = B[i];
        }
        else{
            ans2+=lastMax;
            ans1+=0;
        }
    }
    cout<<ans2<<endl;
    cout<<ans1<<endl;
}


