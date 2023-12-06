/*************************************************************************
        > File Name: ccf201912_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月06日 星期三 09时42分24秒
 ************************************************************************/

#include <iostream>

using namespace std;

bool has7(int num){
    string str = to_string(num);
    for(int i=0;i<str.size();i++){
        if(str[i]=='7'){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    int ans[4]={0};
    cin>>n;
    int num = n;
    int start = 1;
    while(num>0){
        num--;
        if(start % 7 == 0 || has7(start)){
            //存在需要跳的数
            int pos = start % 4;
            ans[pos]++;
            num++;
        }
        start++;
    }
    for(int i=1;i<4;i++){
        cout<<ans[i]<<endl;
    }
    cout<<ans[0]<<endl;
}
