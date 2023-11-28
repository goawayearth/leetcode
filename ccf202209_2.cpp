#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// int n,x;
// int ans = 0;
// vector<int> nums;

// void getNext(int pos,int sum){
//     if(pos>=nums.size()){
//         return ;
//     }
//     int tem1 = sum + nums[pos];
//     if(tem1>=x && (ans > tem1 || ans == 0)){
//         ans = tem1;
//     }
//     else if(tem1<x){
//         getNext(pos+1,tem1);
//     }
//     getNext(pos+1,sum);
// }

// int main(){
    
//     cin>>n>>x;
    
//     for(int i=0;i<n;i++){
//         int tem;
//         cin>>tem;
//         nums.push_back(tem);

//     }

//     getNext(0,0);

//     cout<<ans<<endl;

// }


int dp[31][300000];


int main(){
    int n,x;
    vector<int> nums;
    cin>>n>>x;
    
    for(int i=0;i<n;i++){
        int tem;
        cin>>tem;
        nums.push_back(tem);
    }
    for(int j=0;j<=n;j++)
        for(int i=0;i<x;i++){
            if(j == 0)
                dp[0][i] = 0;
            else{
                // 算这个
                // 超过数额规定，一个是目前的本身就超过
                // 自身超不过的话，就减去价值的值的基础上加上这个

                //不算这个的花
                //如果上一个本身就超过了，算上
                //这三个里面选最小的
                //算数
                int tem1;
                if(nums[i]>=i){
                    tem1 = nums[i];
                }
                else{
                    tem1 = dp[i-1][j-nums[i]]+nums[i];
                }
                int tem2;
                tem2 = dp[i-1][j];
                dp[i][j] = min(tem1,tem2);

            }

        }




}