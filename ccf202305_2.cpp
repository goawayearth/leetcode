#include <iostream>

using namespace std;

#define N 10000
#define D 20

int n,d;
int Q[N][D];
int K[N][D];
int V[N][D];
int W[N];
long long ans1[N][N]={0};
long long ans2[N][D]={0};

int main(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>Q[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>K[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>V[i][j];
        }
    }

    for(int i=0;i<n;i++){
        cin>>W[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<d;k++){
                ans1[i][j]+=Q[i][k] * K[j][k];
            }
            
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans1[i][j] *= W[i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<n;k++){
                ans2[i][j]+=ans1[i][k] * V[k][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cout<<ans2[i][j]<<" ";
        }
        cout<<endl;
    }








}