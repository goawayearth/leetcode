/*************************************************************************
        > File Name: ccf201803_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月02日 星期六 10时26分02秒
 ************************************************************************/

#include <iostream>

using namespace std;

int main(){
    int ans = 0;
    int flag = 1;
    int last = -1;
    int addSco = 2;
    while(flag){
        int tem = 0;
        cin>>tem;
        switch(tem){
            case 0:flag = 0;break;
            case 1:ans+=1;last = 1;addSco = 2;break;
            case 2:{
                       if(last == -1 || last == 1){
                           ans+=2;
                           addSco = 2;
                           last = 2;
                       }
                       else{
                           ans+=(addSco+2);
                           addSco+=2;
                           last = 2;
                       }
                   }
        }
    }
    cout<<ans<<endl;




}
