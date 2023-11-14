/*************************************************************************
        > File Name: p200_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月14日 星期二 13时35分04秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    char record[300][300]={0};
    int ans = 0;
    int numIslands(vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && record[i][j] == 0){
                    record[i][j] = 1;
                    getNext(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void getNext(vector<vector<char>> &grid,int x, int y){
        int m = grid.size();
        int n = grid[0].size();
        if(x+1<m && record[x+1][y] == 0 && grid[x+1][y] == '1'){
            record[x+1][y] = 1;
            getNext(grid,x+1,y);
        }
        if(x-1>=0 && record[x-1][y] == 0 && grid[x-1][y] == '1'){
            record[x-1][y] = 1;
            getNext(grid,x-1,y);
        }
        if(y+1<n && record[x][y+1] == 0 && grid[x][y+1] == '1'){
            record[x][y+1] = 1;
            getNext(grid,x,y+1);
        }
        if(y-1>=0 && record[x][y-1] == 0 && grid[x][y-1] == '1'){
            record[x][y-1] = 1;
            getNext(grid,x,y-1);
        }

    }


};

