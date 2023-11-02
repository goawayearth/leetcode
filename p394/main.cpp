#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<char> myStack;
        int n = s.size();
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c == ']'){
                //遇到了该处理的地方
                string str="";
                while(myStack.top()!='['){
                    str+=myStack.top();
                    myStack.pop();
                }
                //现在栈顶是[
                myStack.pop();
                //计算要重复多少次
                string numStr="";
                int num = 0;
                while((!myStack.empty()) && myStack.top()>='0' && myStack.top()<='9'){
                    numStr+=myStack.top();
                    myStack.pop();
                }
                for(int k=numStr.size()-1;k>=0;k--){
                    num = num*10+numStr[k]-'0';
                }
                //int num = myStack.top()-'0';//这是多少次
                string str1=str;
                str="";
                for(int k=0;k<num;k++){
                    str+=str1;
                }

                int len = str.size();
                for(int j=len-1;j>=0;j--){
                    myStack.push(str[j]);
                }

            }
            else{
                myStack.push(c);
            }

        }
        while(!myStack.empty()){
            ans = myStack.top()+ans;
            myStack.pop();
        }

        return ans;
    }
};

int main()
{
    string str="100[leetcode]";
    Solution* solu = new Solution();
    string ans = solu->decodeString(str);
    cout<<ans<<endl;
    return 0;
}
