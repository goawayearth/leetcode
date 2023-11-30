/*************************************************************************
  > File Name: ccf202112_2.cpp
  > Author: tml
  > Mail: 3200035928@qq.com
  > Created Time: 2023年11月30日 星期四 14时08分40秒
 ************************************************************************/

#include <iostream>

using namespace std;

long A[100001]={0};

int main(){

    int n;
    long N;
    cin>>n>>N;

    for(int i=0;i<n;i++){
        cin>>A[i+1];
    }
    //输入A完毕，共n+1个
    long r = N / (n+1);
    int pos1 = 0;
    int pos2 = 1;
    int ans = 0;
    int gx = 0;
    int fx = 0;
    for(int i=0;i<N;i++){
        //计算gi
        gx = i / r;
        fx = 0;
        //计算fx
        if(i>=A[pos2]){
            fx = pos2;
            if(pos1<n)pos1++;
            if(pos2<n)pos2++;
        }
        else{
            fx = pos1;
        }

        ans+= gx-fx > 0 ? gx-fx : fx-gx;
    }
    cout<<ans<<endl;
    
}
