/*************************************************************************
        > File Name: p146.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月13日 星期一 00时07分01秒
 ************************************************************************/
#include <unordered_map>
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;

class LRUCache{
public:
    unordered_map<int ,vector<int>> hashMap;
    vector<vector<int>> nums;
    int largestSize;
    int deleteNum=0;
    int curPos=0;
    LRUCache(int capacity){
        largestSize = capacity;
    }

    int get(int key){
        auto it = hashMap.find(key);
        if(it == hashMap.end()){
            return -1;
        }
        else {
            int pos = (it->second)[0]-deleteNum;
            return nums[pos][1];
        }
    }

    void put(int key, int value){
        vector<int> newone = {key,value};
        auto it = hashMap.find(key);
        if(it != hashMap.end()){
            nums.push_back(newone);
            hashMap[key][0] = nums.size()-1+deleteNum;
            hashMap[key][1]++;

        }
        else{//not in
            if(curPos < largestSize){
                nums.push_back(newone);
                curPos++;
                vector<int> op = {nums.size()-1+deleteNum , 0};
                hashMap[key] = op;
            }
            else{

                int flag = 1;
                while(flag){
                    int time = hashMap[nums[0][0]][1];
                    if(time == 0){
                        nums.erase(nums.begin());
                        flag = 0;
                        deleteNum++;
                    }
                    else{
                        hashMap[nums[0][0]][1]--;
                        nums.erase(nums.begin());
                        deleteNum++;
                    }
                                
                }
                nums.push_back(newone);
                curPos++;
                vector<int> op = {nums.size()-1+deleteNum,0};
                hashMap[key] = op;
            }
        }
    }

};

int main(){
    return 0;
}
