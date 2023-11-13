/*************************************************************************
        > File Name: p131.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月13日 星期一 18时13分06秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s){
        int n = s.size();
        for(int i=0;i<n;i++){
            if(isPal(s,0,i)){
                vector<string> single;
                string ss="";
                for(int k=0;k<=i;k++){
                    ss+=s[k];
                }
                single.push_back(ss);
                if(i == n-1){
                    ans.push_back(single);
                }
                else{
                    getNext(s,i+1,single);
                }
            }
        }
        return ans;
    }

    void getNext(string s, int start, vector<string>single){
        int n = s.size();
        for(int i=start;i<n;i++){
            if(isPal(s,start,i)){
                vector<string> s1 = single;
                string ss = "";
                for(int k=start;k<=i;k++){
                    ss+=s[k];
                }
                s1.push_back(ss);
                if(i==n-1){
                    ans.push_back(s1);
                }
                else{
                    getNext(s,i+1,s1);
                }
            }
        }
        
    }

    bool isPal(string s,int start,int end){
        int p1 = start;
        int p2 = end;
        while(p2>p1){
            if(s[p1] != s[p2]){
                return false;
            }
            p2--;
            p1++;
        }
        return true;
    }


};

int main(){
    return 0;
}


