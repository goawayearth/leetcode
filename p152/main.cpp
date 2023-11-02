#include <iostream>
#include <vector>

using namespace std;

typedef struct Node{
    int max;
    int min;
}Node;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        vector<Node> list;

        for(int i=0;i<n;i++){
            if(i==0){
                    Node node;
                    node.max=nums[i];
                    node.min=nums[i];
                    list.push_back(node);
                    ans = node.max;
            }
            else{

                int first = list[i-1].max*nums[i];
                int second=list[i-1].min*nums[i];
                if(second>first){
                    int tem = first;
                    first=second;
                    second=tem;

                }
                //这个时候可以保证first比较大
                if(nums[i]>first){
                    Node node;
                    node.max = nums[i];
                    node.min = second;
                    list.push_back(node);
                }
                else if(nums[i]<second){
                    Node node;
                    node.max=first;
                    node.min=nums[i];
                    list.push_back(node);
                }
                else{
                    Node node;
                    node.max = first;
                    node.min=second;
                    list.push_back(node);
                }

            }


            if(list[i].max>ans){
                ans = list[i].max;
            }

        }

        return ans;
    }
};

int main()
{
    vector<int>nums;
    nums.push_back(-2);
    nums.push_back(3);
    nums.push_back(-4);
    Solution* so = new Solution();
    cout<<so->maxProduct(nums)<<endl;

    return 0;
}
