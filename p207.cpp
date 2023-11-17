/*************************************************************************
        > File Name: p207.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年11月17日 星期五 10时32分04秒
 ************************************************************************/
#include <vector>
#include <iostream>
#include <unordered_map>
using std::cin;
using std::cout;
using std::endl;
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indeg(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop();
            for (int v: edges[u]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }
};
int main(){
    return 0;
}
