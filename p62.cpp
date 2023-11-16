/*************************************************************************
        > File Name: p62.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月16日 星期四 08时40分50秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
/*class Solution{
public:
    int ans=0;
    int uniquePaths(int m,int n){
        getNext(m,n,0,0);
        return ans;
    }
    void getNext(int& m,int& n,int x,int y){
        if(x == m-1 && y == n-1){
            ans++;
        }
        else{
            if(x < m-1){
                getNext(m,n,x+1,y);
            }
            if(y < n-1){
                getNext(m,n,x,y+1);
            }
        }
    }
};时间超限*/
/*中间数据太大
class Solution{
public:
    int uniquePaths(int m,int n){
        int sum = m+n-2;// 8 
        int sing = n-1;// 6
        int tem = 1;
        int tem1 = 1;
        for(int i=1;i<sing+1;i++){
            tem*=i;
            tem1*=(sum+1-i);
        }
        return tem1 / tem;
    }
};
*/

class Solution{
public:
    int matrix[101][101]={0};
    int uniquePaths(int m,int n){
        for(int i=0;i<m;i++){
            matrix[i][0]=1;
        }
        for(int i=0;i<n;i++){
            matrix[0][i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[i][j] = matrix[i-1][j]+matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    }
};
int main(){
    Solution* so = new Solution();
    cout<<so->uniquePaths(3,7)<<endl;
}
