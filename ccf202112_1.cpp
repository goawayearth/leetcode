/*************************************************************************
        > File Name: ccf202112_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月30日 星期四 12时25分44秒
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;
// unordered_map<long,int>hashMap;
int main(){

    int n,N;
    cin>>n>>N;
    long A[202]={0};

    for(int i=0;i<n;i++){
        cin>>A[i+1];
    }
    //接下来要求的是f0---fN-1
    int pos1 = 0;
    int pos2 = 1;
    int ans = 0;
    for(int i=0;i<N;i++){
        if(i>=A[pos2]){
            ans+=pos2;
            if(pos1<n)pos1++;
            if(pos2<n)pos2++;
        }
        else{
            ans+=pos1;
        }
    }

    cout<<ans<<endl;


    return 0;


}
