/*************************************************************************
        > File Name: p17.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月11日 星期六 16时15分06秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    int letterNum;
    vector<string> ans;
    vector<string>letters={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    vector<string> letterCombinations(string digits){

        vector<string> inputLetter;
        int n = digits.size();
        if(n==0){
            return ans;
        }
        for(int i=0;i<n;i++){
            inputLetter.push_back(letters[digits[i]-'0']);
        }
        /*
        for(int i=0;i<inputLetter.size();i++){
            cout<<inputLetter[i]<<endl;
        }*/
        letterNum = inputLetter.size();
        int pos = 0;
        string a = "";
        getAns(inputLetter,0,a);
        return ans;
    }
    void getAns(vector<string> input,int pos,string Ans){
        string ans0 = Ans;
        for(int i=0;i<input[pos].size();i++){
            string ans1 = ans0+input[pos][i];
            if(ans1.size() == letterNum){
                ans.push_back(ans1);
            }
            else{
                getAns(input,pos+1,ans1);
            }
        }
    }
};
int main(){
    string digits="";
    Solution* so = new Solution();
    vector<string> ans = so->letterCombinations(digits);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

