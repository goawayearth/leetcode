/*************************************************************************
        > File Name: p64.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月16日 星期四 09时35分45秒
 ************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int matrix[201][201]={0};
        matrix[0][0] = grid[0][0];
        for(int i=1;i<m;i++){
            matrix[i][0] = grid[i][0]+matrix[i-1][0];
        }
        for(int i=1;i<n;i++){
            matrix[0][i] = grid[0][i]+matrix[0][i-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[i][j] = grid[i][j] + min(matrix[i-1][j],matrix[i][j-1]);
            }
        }
        return matrix[m-1][n-1];
    }
};
int main(){
    return 0;
}
