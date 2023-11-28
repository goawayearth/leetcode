#include <iostream>
#define M 100
using namespace std;

int main(){
    int n,m;
    int first[M]={0};
    int second[M]={0};
    int ans1[M] = {0};
    int ans2[M] = {0};
    int flag = 0;
    cin>>n>>m;
    if(m == 0){
        return 0;
    }
    for(int i=0;i<m;i++){
        cin>>first[i];
    }
    for(int i=0;i<m;i++){
        cin>>second[i];
    }

    for(int i=0;i<m;i++){
        if(first[i] == 0){
            ans1[i] = 0;
            
        }
        else{
            ans1[i] = ans1[first[i]-1]+second[first[i]-1] ;
        }
        if(ans1[i]+second[i]>n){
            flag = 1;
        }
    }

    if(flag == 0){
        //求最大的开始日期
        for(int i = m-1;i>=0;i--){
            if(ans2[i] == 0){
                //说明每受到前面的印象
                ans2[i] = n - second[i] + 1;
            }

            if(first[i] != 0){
                //管着后面
                int tem = ans2[i]-second[first[i]-1];
                if(ans2[first[i]-1] == 0){
                    ans2[first[i]-1] = tem;
                }
                else{
                    if(tem<ans2[first[i]-1]){
                        ans2[first[i]-1] = tem;
                    }
                }
            }

            
        }

    }

    for(int i=0;i<m;i++){
        cout<<ans1[i]+1<<" ";
    }
    cout<<endl;

    if(flag == 0){
        for(int i=0;i<m;i++){
            cout<<ans2[i]<<" ";
        }
        cout<<endl;
    }



    return 0;
}