#include <iostream>

using namespace std;
int matrix[100000][2];
int mm[100000];

int main(){
    int n,m,k;
    int ans = 0;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>matrix[i][0]>>matrix[i][1];
    }
    for(int i=0;i<m;i++){
        cin>>mm[i];
    }
    for(int i=0;i<m;i++){
        ans = 0;
        int start = mm[i]+k;
        int flag = 0;
        // end = start + long -1;
        for(int j=0;j<n;j++){
            int end = start+matrix[j][1]-1;
            if(matrix[j][0]<=end && matrix[j][0]>=start){
                flag=1;
                ans++;
            }
        }
        cout<<ans<<endl;
    }

}