/*************************************************************************
        > File Name: p5.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月17日 星期五 10时12分16秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    string longestPalindrome(string s){
        int n = s.size();
        if(n<2)return s;
        int maxLen = 1;
        int begin = 0;
        vector<vector<bool>> dp(n,vector<bool>(n));

        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }

        for(int L = 2;L<=n;L++){
            for(int i=0;i<n;i++){
                int j = i+L-1;
                if(j>=n)break;
                if(s[i] != s[j]){
                    dp[i][j] = false;
                }
                else{
                    if(j - i < 3){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j] == true && j-i+1 > maxLen){
                    maxLen = j-i+1;
                    begin = i;
                }
            }
        }
        return s.substr(begin,maxLen);
    }
};
int main(){
    return 0;
}

