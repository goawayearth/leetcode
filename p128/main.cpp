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
                //˵���������������
                //��Ҫ�����ܲ��ܺ�����������������
                auto it1 = map.find(number-1);
                if(it1!=map.end()){
                    //����ҵ�����֯
                    map[number]=map[number-1]+1;
                    int leftNum=map[number-1];
                    int pos=number-1;
                    while(leftNum--){
                        map[pos]=map[number];
                        pos--;
                    }

                }
                else if(it1==map.end()){
                    //���û�ҵ���֯
                    map[number]=1;

                }
                it1 = map.find(number+1);
                if(it1==map.end()){
                    //�Ҳ�û�ҵ�
                    if(map[number]>maxVale){
                        maxVale=map[number];
                    }
                }
                else{
                    //�Ҳ��ҵ���
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
                //�ҵ�����ߵ�ֵ
                continue;
            }
            else{
                //û����ߵ�ֵ
                int sum=1;
                int start = nums[i]+1;
                while(1){
                    auto it=map.find(start);
                    if(it!=map.end()){
                        //�ҵ���
                        sum++;
                        start++;
                    }
                    else{
                        //û�ҵ�
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
