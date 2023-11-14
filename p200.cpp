/*************************************************************************
        > File Name: p200.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月14日 星期二 09时20分30秒
 ************************************************************************/
#include <vector>
#include <iostream>
#include <unordered_map>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    unordered_map<string,vector<int>>pos;
    int ans = 0;
    int numIslands(vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                string str =  "";
                str+='i';
                str+=to_string(i);
                str+='j';
                str+=to_string(j);
                vector<int> single1={i,j};
                pos[str]=single1;
            }
        }
        while(pos.size()!=0){
            auto it = pos.begin();
            cout<<";;;"<<it->first<<endl;
            int x=it->second[0];
            int y = it->second[1];
            pos.erase(pos.begin());
            if(grid[x][y] == '1'){
                getNext(grid,x,y);
                ans++;
                for(auto it = pos.begin();it!=pos.end();it++){
                    cout<<";"<<it->first<<endl;
                }
            }
        }
        return ans;
    }

    void getNext(vector<vector<char>>grid,int x, int y){
        cout<<"输入的xy:"<<x<<" "<<y<<endl;
        int m = grid.size();
        int n = grid[0].size();
        if(x>=m || x <0 || y<0 || y>=n){
            return;
        }
        string str = "";
        str+='i';
        str+=to_string(x+1);
        str+='j';
        str+=to_string(y);
        auto it = pos.find(str);
        if(it!=pos.end()){
            pos.erase(it);
            if(grid[x+1][y] == '1'){
                getNext(grid,x+1,y);
            }
           
        }
        
        ///////////////
        string str1 = "";
        str1+='i';
        str1+=to_string(x-1);
        str1+='j';
        str1+=to_string(y);
        cout<<"查找的xy::"<<str1<<endl;
        cout<<"hash::"<<pos.begin()->first<<endl;
         it = pos.find(str1);
        if(it!=pos.end()){
            cout<<"这里每进来吗"<<endl;
            pos.erase(it);
            if(grid[x-1][y] == '1'){
                getNext(grid,x-1,y);
            }
           
        }
        ///////////////////////////
        string str2 = "";
        str2+='i';
        str2+=to_string(x);
        str2+='j';
        str2+=to_string(y+1);
         it = pos.find(str2);
        if(it!=pos.end()){
           
            pos.erase(it);
            if(grid[x][y+1] == '1'){
                getNext(grid,x,y+1);
            }
           
        }
        //////////////////////////
        string str3 = "";
        str3+='i';
        str3+=to_string(x);
        str3+='j';
        str3+=to_string(y-1);
         it = pos.find(str3);
        if(it!=pos.end()){

            pos.erase(it);
            if(grid[x][y-1] == '1'){
                getNext(grid,x,y-1);
            }
           
        }

    }


};

int main(){
    vector<vector<char>> grid={{'1'},{'1'}};
    Solution * so = new Solution();
    so->numIslands(grid);

    return 0;
}
