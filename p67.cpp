/*************************************************************************
        > File Name: p67.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月07日 星期二 23时33分30秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    string addBinary(string a, string b){
        string ans;
        int temp=0;
        int sum[10001]={0};
        int a1 = a.size();
        int b1 = b.size();
        int i=0;
        for(i=0;i<a1 && i<b1;i++){
            int n1 = a[a1-i-1]-'0';
            int n2 = b[b1-i-1]-'0';
            int sum1 = n1+n2+temp;
            sum[i]=sum1%2;
            temp=sum1/2;
        }
        while(i<a1){
            int n1=a[a1-i-1]-'0';
            int sum1 = n1+temp;
            sum[i]=sum1%2;
            temp=sum1/2;
            i++;
        }
        while(i<b1){
            int n1 = b[b1-i-1]-'0';
            int sum1 = n1+temp;
            sum[i]=sum1%2;
            temp=sum1/2;
            i++;
        }
        if(temp==1)
        {
            sum[i]=1;
            i++;
        }
        for(int j=i-1;j>=0;j--){
            ans = ans+(char)(sum[j]+'0');
        }
        return ans;
    }

};

int main(){
    Solution* so = new Solution();
    string a = "11";
    string b = "1";
    cout<<so->addBinary(a,b)<<endl;
}















