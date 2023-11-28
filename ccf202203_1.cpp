#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int,int> map;
int matrix[100000][2];
int ans = 0;

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>matrix[i][0]>>matrix[i][1];
        auto it = map.find(matrix[i][1]);
        if(it!=map.end() || matrix[i][1] == 0){
            map[matrix[i][0]] = 1;
        }
        else{
            map[matrix[i][0]] = 1;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}