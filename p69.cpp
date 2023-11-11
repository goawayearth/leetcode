/*************************************************************************
        > File Name: p69.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月08日 星期三 01时04分48秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
    public:
        int mySqrt(int x){
            long left=0;
            long right = x;
            while(left<right){
            long mid = (left+right+1)/2;
            long square = mid*mid;
            if(square>x){
                    right = mid-1;
                
            }
            else{
                    left = mid;
                }

        }
            return (int)left;
        }
};
int main(){
    Solution* so = new Solution();
    cout<<so->mySqrt(1)<<endl;
}
