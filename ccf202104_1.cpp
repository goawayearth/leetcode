/*************************************************************************
        > File Name: ccf202104_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月01日 星期五 15时11分17秒
 ************************************************************************/

#include <iostream>
#include <unordered_map>

using namespace std;

int matrix[501][501]={0};
unordered_map<int ,int> hashMap;
int main(){
    int n,m,L;
    cin>>n>>m>>L;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tem;
            cin>>tem;
            hashMap[tem]++;

        }
    }

    for(int i=0;i<L;i++){
        cout<<hashMap[i]<<" ";
    }
    cout<<endl;

    return 0;

}
