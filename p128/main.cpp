#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/*
class Solution {
public:
    unordered_map<int,int> map;
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxVale=0;
        for(int i=0;i<n;i++){
            int number = nums[i];
            auto it = map.find(number);
            if(it==map.end()){
                //说明这个数还不存在
                //需要看看能不能和其他得序列连起来
                auto it1 = map.find(number-1);
                if(it1!=map.end()){
                    //左侧找到了组织
                    map[number]=map[number-1]+1;
                    int leftNum=map[number-1];
                    int pos=number-1;
                    while(leftNum--){
                        map[pos]=map[number];
                        pos--;
                    }

                }
                else if(it1==map.end()){
                    //左边没找到组织
                    map[number]=1;

                }
                it1 = map.find(number+1);
                if(it1==map.end()){
                    //右侧没找到
                    if(map[number]>maxVale){
                        maxVale=map[number];
                    }
                }
                else{
                    //右侧找到了
                    map[number]+=map[number+1];
                    int allNum = map[number];
                    int pos = number+map[number+1];
                    while(allNum--){
                        map[pos]=map[number];
                        pos--;
                    }
                    if(map[number]>maxVale){
                        maxVale=map[number];
                    }
                }
            }

        }
        return maxVale;
    }
};*/

class Solution {
public:
    unordered_map<int,int>map;
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxValue=0;
        for(int i=0;i<n;i++){
            map[nums[i]]=1;
        }
        for(int i=0;i<n;i++){
            auto it = map.find(nums[i]-1);
            if(it != map.end()){
                //找到了左边得值
                continue;
            }
            else{
                //没有左边得值
                int sum=1;
                int start = nums[i]+1;
                while(1){
                    auto it=map.find(start);
                    if(it!=map.end()){
                        //找到了
                        sum++;
                        start++;
                    }
                    else{
                        //没找到
                        break;
                    }

                }
                if(sum>maxValue){
                    maxValue=sum;
                }
            }
        }

    return maxValue;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
