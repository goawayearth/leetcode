- 找特定数字：哈希表

- 链表反转：头插法新建链表
- unordered_map需要引用的是
  - #include <tr1/unordered_map>
  - using namespace std::tr1;
- #include<algorithm>
  - sort(str.begin(),str.end());
  - 有很多函数

- codeblock使用哈希表，设置->编译器->勾选c++11即可

- 需要将各个排序复习一遍

- ```c++
  #include <vector>
  #include <algorithm>
  
  class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if (intervals.empty()) return {};
      
      // Sort intervals by start time
      sort(intervals.begin(), intervals.end(), 
           [](const vector<int>& a, const vector<int>& b) {
             return a[0] < b[0]; 
           });
  
      vector<vector<int>> merged;
      int start = intervals[0][0];
      int end = intervals[0][1];
      
      for (auto interval : intervals) {
        if (interval[0] <= end) {
          end = max(end, interval[1]);
        } else {
          merged.push_back({start, end});
          start = interval[0];
          end = interval[1];
        }
      }
      
      merged.push_back({start, end});
      return merged;
    }
  };
  ```

- 