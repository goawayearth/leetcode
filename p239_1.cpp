#include <deque>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; 
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            // 把前面小于当前元素的都移除
            while(!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            
            // 窗口移出去的元素移除
            if(q.front() == i - k) {
                q.pop_front();
            }
            
            // 最大窗口记录结果
            if(i >= k - 1) {
                res.push_back(nums[q.front()]); 
            }
        }
        return res;
    }
};
