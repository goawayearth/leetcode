/*************************************************************************
        > File Name: p763.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月15日 星期三 20时01分10秒
 ************************************************************************/
#include <unordered_map>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    vector<int> ans;
    unordered_map<char,int> hashMap; 
    vector<int> partitionLabels(string s){
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            char c = s[i];
            auto it = hashMap.find(c);
            if(it==hashMap.end()){
                hashMap[c] = i;
            }
        }
        getNext(s,0);
        return ans;
    }
    void getNext(string s,int pos){
        char c0 = s[pos];
        auto it = hashMap.find(c0);
        int end = it->second;
        for(int i=pos;i<=end;i++){
            int c1 = s[i];
            auto it1 = hashMap.find(c1);
            if(it1->second > end){
                end = it1->second;
            }
        }
        int ans1 = end-pos+1;
        ans.push_back(ans1);
        if(end<s.size()-1)
            getNext(s,end+1);
    }

};
int main(){
    return 0;
}

