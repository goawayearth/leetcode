#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int>list;
    int last;
    int numSquares(int n) {
        for(int i=1;i<=100;i++){
            if(i*i > n){
                break;
            }
            list.push_back(i*i);
        }
        last = list.size();//最后的位置，不算
        int ans = sub(0,n);
        return ans;
    }

    int sub(int start,int sum){
        if(start == last-1){
            if(list[start]==sum){
                return 1;
            }
            else if(list[start]<sum){
                int add = sub(start,sum-list[start]);
                if(add == -1){
                    return -1;
                }
                return 1+add;
            }
            else{
                return -1;//没有匹配成功
            }
        }
        if(list[start]>sum){
            return -1;
        }
        else if(list[start]==sum){
            return 1;
        }
        else if(list[start]<sum){
            int sum1=sum-list[start];
            int first = sub(start,sum1);
            int second = sub(start+1,sum);
            if(first==-1&&second!=-1){
                return second;
            }
            else if(first==-1&&second==-1){
                return -1;
            }
            else if(first!=-1 && second==-1){
                return first+1;
            }
            else{
                return first+1 < second ? first+1:second;
            }
        }
        return 0;
    }
};

int main()
{
    Solution* so = new Solution();
    cout<<so->numSquares(251);
    return 0;
}
