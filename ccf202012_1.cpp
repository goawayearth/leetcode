/*************************************************************************
        > File Name: ccf202012_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月01日 星期五 15时26分28秒
 ************************************************************************/

#include <iostream>

using namespace std;
long ans = 0;
int main(){

    int n = 0;

    cin>>n;

    for(int i=0;i<n;i++){
        int w,score;
        cin>>w>>score;
        int tem = w*score;
        ans+=tem;
    }
    ans = ans>0 ? ans:0;
    cout<<ans<<endl;




}
