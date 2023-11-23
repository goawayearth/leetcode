/*************************************************************************
        > File Name: csp202309_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月18日 星期六 09时55分55秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

int main(){
    int n,m;
    //输入m,n
    cin>>n>>m;
    vector<vector<int>> point;
    vector<int> pos(2);
    for(int i=0;i<n;i++){
        int p1,p2;
        cin>>p1>>p2;
        pos[0]+=p1;
        pos[1]+=p2;
    }
    for(int i=0;i<m;i++){
        vector<int>one(2);
        cin>>one[0];
        cin>>one[1];
        point.push_back(one);
    }
    //操作和点输入完毕
    for(int i=0;i<m;i++){
            point[i][0]+=pos[0];
            point[i][1]+=pos[1];
        
    }
    for(int i=0;i<m;i++){
        cout<<point[i][0]<<" "<<point[i][1]<<endl;
    }
}


