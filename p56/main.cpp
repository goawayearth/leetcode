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
