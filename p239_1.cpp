#include <deque>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; 
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            // ��ǰ��С�ڵ�ǰԪ�صĶ��Ƴ�
            while(!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            
            // �����Ƴ�ȥ��Ԫ���Ƴ�
            if(q.front() == i - k) {
                q.pop_front();
            }
            
            // ��󴰿ڼ�¼���
            if(i >= k - 1) {
                res.push_back(nums[q.front()]); 
            }
        }
        return res;
    }
};
