/*************************************************************************
        > File Name: ccf201812_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月02日 星期六 10时57分48秒
 ************************************************************************/

#include <iostream>

using namespace std;

int main(){
    int r,y,g;
    cin>>r>>y>>g;
    int n;
    cin>>n;

    int ans = 0;

    for(int i=0;i<n;i++){
        int t1,t2;
        cin>>t1>>t2;
        switch(t1){
            case 0:ans+=t2;break;
            case 1:ans+=t2;break;
            case 2:ans+=(t2+r);break;
            }
    }
    cout<<ans<<endl;
}
