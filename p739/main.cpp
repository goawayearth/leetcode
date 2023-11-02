#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> myStack;

        int n = temperatures.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(myStack.empty()){
                myStack.push(i);
            }

            else{
                if(temperatures[myStack.top()]>=temperatures[i]){
                    myStack.push(i);
                }
                while((!myStack.empty()) && temperatures[myStack.top()]<temperatures[i]){
                    int cha = i-myStack.top();
                    ans[myStack.top()]=cha;
                    myStack.pop();

                }
                myStack.push(i);

            }
        }
        while(!myStack.empty()){
            ans[myStack.top()]=0;
            myStack.pop();
        }
        return ans;

    }
};

int main()
{
    Solution* solu = new Solution();
    vector<int>temer;
    temer.push_back(73);
    temer.push_back(74);
    temer.push_back(75);
    temer.push_back(71);
        temer.push_back(69);
    temer.push_back(72);
    temer.push_back(76);
    temer.push_back(73);


    vector<int> ans;

    ans = solu->dailyTemperatures(temer) ;
    cout<<"nihao"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
