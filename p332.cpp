/*************************************************************************
        > File Name: p332.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月10日 星期五 11时08分32秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
        int Max = amount + 1;
        vector<int> dp(amount+1,Max);
        dp[0]=0;
        for(int i=0;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j] <= i){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]>amount ? -1:dp[amount];
    }

};
