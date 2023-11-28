#include <iostream>

using namespace std;
int num[22]={0};
int ansb[22]={0};

int getMul(int pos){
    if(pos == 0)return 1;
    int ans=1;
    for(int i=1;i<=pos;i++){
        ans*=num[i];
    }
    return ans;
}//这个返回的是ci

int main(){
    int n,m;
    cin>>n>>m;
    

    for(int i=1;i<=n;i++){
        cin>>num[i];
    }


    for(int i=1;i<=n;i++){
        // m % ci
        int ci = getMul(i);
        int tem = m % ci;
        // c0*b1 + ... + (ci-2)*b(i-1)
        int tem2 = 0;
        for(int j=1;i>1 && j<=i-1;j++){
            tem2+=(getMul(j-1) * ansb[j]);
        }
        ansb[i]=(tem-tem2)/getMul(i-1);
    }

    for(int i=1;i<n+1;i++){
        cout<<ansb[i]<<" ";
    }
    cout<<endl;
    return 0;


}