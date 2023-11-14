/*************************************************************************
        > File Name: p45.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月14日 星期二 20时31分12秒
 ************************************************************************/
#include <vector>
#include <iostream>
#include <unordered_map>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    int jump(vector<int>& nums){
        unordered_map<int,int>hashMap;
        int maxPos=0;
        hashMap[0] = 0;
        int n = nums.size();
        if(n==1)return 0;
        for(int i=0;i<n;i++){
            if(i+nums[i]>=n-1){
                return hashMap[i]+1;
            }
            if(i+nums[i]>maxPos){
                for(int j=maxPos+1;j<=i+nums[i];j++){
                    hashMap[j] = hashMap[i]+1;
                }
                maxPos = i+nums[i];

            }
        }

        return 0;
    }
};
int main(){
    return 0;
}
