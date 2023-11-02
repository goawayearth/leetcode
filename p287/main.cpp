#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> numStore(100002);
        for(int i=0;i<n;i++){
            if(numStore[nums[i]] != 0){
                return nums[i];
            }
            else{
                numStore[nums[i]] = 1;
            }
        }
        return 0;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
