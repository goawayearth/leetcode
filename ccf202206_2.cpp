#include <iostream>
#include <unordered_map>

typedef long long ll;
using namespace std;
int n;
ll L;
int S;
int matrix[50][50];
unordered_map<string,int> has;
int ans = 0;//最后的答案

int pos[1006][2];

bool getStatus(int x,int y){
    string str = "i"+to_string(x)+"j"+to_string(y);
       auto it = has.find(str);
    if(it!=has.end()){
        return true;
    }
    return false;


}

int main(){
    cin>>n>>L>>S;

    for(int i=0;i<n;i++){
        cin>>pos[i][0]>>pos[i][1];
        string str = "";
        str+="i"+to_string(pos[i][0])+'j'+to_string(pos[i][1]);
        has[str] = 1;
     
    }

    for(int i=S;i>=0;i--){
        for(int j=0;j<S+1;j++){
            cin>>matrix[i][j];
        }
    }

    //起点可能的数量
    for(int k=0;k<n;k++){

        int flag = 0;
        int row = pos[k][0];
        int col = pos[k][1]; 
        //要保证小图上的树的位置在大图上也存在
        //但是小图上的没有树的位置大图上也不存在
        if(!(row+S<=L && col+S<=L)){
            flag = 1;
        }
        else{
        for(int i=0;i<=S;i++){
            for(int j=0;j<=S;j++){
                if(matrix[i][j]==0){
                    //小图这里没有树
                    if(getStatus(row+i,col+j)==true){
                        flag=1;
                        break;
                    }
                    
                }
                else{
                    //小图这里有树
                    if(getStatus(row+i,col+j)==false){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag == 1){
                break;
            }
        }}

        if(flag == 0){
            ans++;
        }

    }

    cout<<ans<<endl;
}