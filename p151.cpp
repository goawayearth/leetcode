/*************************************************************************
        > File Name: p151.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月12日 星期日 09时26分59秒
 ************************************************************************/
#include <vector>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class MinStack{
public:
    vector<int> nums;//存数值
    vector<int> min;//存索引
    
    MinStack(){
        
    }
    void push(int val){
        nums.push_back(val);
        int pos = nums.size()-1;
        if(min.size()==0){
            min.push_back(pos);
        }
        else if(nums[pos]<=nums[min[min.size()-1]]){
            min.push_back(pos);
        }
        else{
            for(int i=0;i<min.size();i++){
                if(nums[pos]>=nums[min[i]]){
                    min.insert(min.begin()+i,pos);
                    break;
                }
            }
        }

    }
    void pop(){
        nums.pop_back();
        for(int i=0;i<min.size();i++)
        {
            if(min[i]==nums.size()){
                min.erase(min.begin()+i);
                break;
            }
        }
    }
    int top(){
        return nums[nums.size()-1];
    }

    int getMin(){
        return nums[min[min.size()-1]];
    }

};

int main(){

    return 0;
}
