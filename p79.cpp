/*************************************************************************
        > File Name: p79.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月13日 星期一 17时04分55秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    int m,n;
    int flag = 0;//右，下，左，上
    int matrix[10][10]={0};
    bool ans = false;
    bool exist(vector<vector<char>>& board, string word){
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(word.size() ==1)
                        return true;
                    matrix[i][j]=1;
                    getNext(board,word,1,i,j);
                    matrix[i][j] = 0;
                }
            }
        }
	return ans;
    }
    void getNext(vector<vector<char>>& board, string word, int pos,int x,int y){
        if(x+1<m && board[x+1][y] == word[pos] && matrix[x+1][y] == 0){
            if(pos+1 == word.size()){
                ans = true;
            }
            matrix[x+1][y] = 1;
            getNext(board,word,pos+1,x+1,y);
            matrix[x+1][y] = 0;
        }
        if(y+1<n && board[x][y+1] == word[pos] && matrix[x][y+1] == 0){
            if(pos+1 == word.size()){
                ans = true;
            }
            matrix[x][y+1] = 1;
            getNext(board,word,pos+1,x,y+1);
            matrix[x][y+1] = 0;
        }
        if(x-1 >=0 && board[x-1][y] == word[pos] && matrix[x-1][y] == 0){
            if(pos+1 == word.size()){
                ans = true;
            }
            matrix[x-1][y] = 1;
            getNext(board,word,pos+1,x-1,y);
            matrix[x-1][y] = 0;
        }
        if(y-1 >= 0 && board[x][y-1] == word[pos] && matrix[x][y-1] == 0){
            if(pos+1 == word.size()){
                ans = true;
            }
            matrix[x][y-1] = 1;
            getNext(board,word,pos+1,x,y-1);
            matrix[x][y-1] = 0;
        }
    }

};
int main(){
    return 0;
}
