/*************************************************************************
        > File Name: p55.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月14日 星期二 19时59分19秒
 ************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution {
public:
    bool canJump(vector<int> &nums){
        int maxPos=0;
        for(int i=0;i<nums.size();i++){
            if(i > maxPos){
                return false;
            }
            maxPos = max(maxPos,i+nums[i]);
        }
        return true;
    }
};
int main(){

    return 0;
}

