#include <iostream>
#include <unordered_map>
#include <algorithm>//������sort����
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        //��ϣ��
        unordered_map<string, vector<string>> map;

        //������
        //sort(str.begin(), str.end());
        int n = strs.size();
        for(int i=0;i<n;i++){
            string str = strs[i];
            sort(str.begin(),str.end());
            map[str].push_back(strs[i]);
        }
        for(auto it=map.begin();it!=map.end();it++){
            ans.push_back(it->second);

        }

        return ans;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
