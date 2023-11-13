/*************************************************************************
        > File Name: p22.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月13日 星期一 14时28分17秒
 ************************************************************************/
#include <stack>
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    vector<char> myStack;
    int num=0;
    int target;
    vector<string> ans;
    vector<string> generateParenthesis(int n){
        //n对括号的可能
        target = n;
        vector<char> stack1;
        string str = "";
        get(0,stack1,str);
        return ans;

    }
    void get(int num1,vector<char>myStack,string str){
        int n1 = num1;
        string str1 = str;
        vector<char> s1 = myStack;
        if(s1.empty()){
            s1.push_back('(');
            string str0 = str1+'(';
            int num0 = n1+1;
            get(num0,s1,str0);

        }
        else{
            if(n1<target){
                //放右括号
                string st = str1+')';
                s1.pop_back();
                get(n1,s1,st);
                //左括号
                vector<char> s2 = myStack;
                string st1 = str1+'(';
                s2.push_back('(');
                int nn = n1+1;
                get(nn,s2,st1);
            }
            else if(n1 == target){
                string str2=str1+')';
                s1.pop_back();
                while(s1.size()!=0){
                    str2+=')';
                    s1.pop_back();
                }
                ans.push_back(str2);
            }
        }
    }
};
int main(){


    return 0;
}
