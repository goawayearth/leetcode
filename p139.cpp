/*************************************************************************
        > File Name: p139.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月14日 星期二 08时34分04秒
 ************************************************************************/
#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
/*class Solution{
public:
    
    bool ans = false;
    bool wordBreak(string s,vector<string>& wordDict){
    int len = s.size();
    vector<int> record;
    int n = wordDict.size();
    for(int i=0;i<len;i++){
        string sub = s.substr(0,i-0+1);
        for(int j=0;j<n;j++){
            if(wordDict[j] == sub){
                if(i == len-1)return true;
                getNext(s,wordDict,i+1);
                break;
            }
        }
    }
    return ans;
    }
    void getNext(string s,vector<string>& wordDict,int start){
        int len = s.size();
        for(int i=start;i<len;i++){
            string sub = s.substr(start,i-start+1);
            for(int j=0;j<wordDict.size();j++){
                if(wordDict[j] == sub){
                    if(i == len-1){
                        ans = true;
                    }
                    else{
                        getNext(s,wordDict,i+1);
                        break;
                    }
                }
            }
        }
    }*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(){

    return 0;
}
