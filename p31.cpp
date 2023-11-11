/*************************************************************************
        > File Name: p31.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月10日 星期五 09时58分09秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution{
public:
    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int flag=0;
        int i =0 ;
        int j = 0;
        int value = -1;
        int posj=-1;
        int posi=-1;
        for(i=n-2;i>=0;i--){
            for(j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    flag=1;
                    if(value == -1){
                        value = nums[j];
                        posj = j;
                        posi = i;
                    }
                    else{
                        if(nums[j]<value){
                            value = nums[j];
                            posj = j;
                            posi = i;
                        }
                    }
                }
            }
            if(flag==1){
                break;
            }
        }
        
        if(flag==0){
            //已经是最大的排列
            for(int i=0;i<n;i++){
                int flag2 = 0;
                for(int j=0;j<n-1;j++){
                    if(nums[j]>nums[j+1]){
                        flag2=1;
                        int temp = nums[j];
                        nums[j] = nums[j+1];
                        nums[j+1] = temp;
                    }
                }
                if(flag2==0){
                    break;
                }
            }
        }
        else{
            j = posj;
            i = posi;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            int start = i+1;
            int end = nums.size();
            for(int k = start;k<end-1;k++){
                int flag1=0;
                for(int g = start;g<end-1;g++){
                    if(nums[g]>nums[g+1]){
                        int temp = nums[g];
                        nums[g] = nums[g+1];
                        nums[g+1] = temp;
                        flag1=1;
                    }
                }
                if(flag1==0){
                    break;
                }
            }

        }
    }
};

int main(){
    return 0;
}

