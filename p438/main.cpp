#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int stdList[26] = {0};//´æ·ÅpµÄ×Ö·û
        int every[26]={0};
        int np = p.size();
        for(int i=0;i<np;i++){
            stdList[p[i]-'a']++;
        }//p is recoreded

        if(s.size()<p.size()){
            return ans;
        }
        else if(s.size()==p.size() && s==p){
            ans.push_back(0);
            return ans;
        }
        else{
            int start = 0;
            int end = start+np-1;
            for(int i=start;i<=end;i++){
                every[s[i]-'a']++;
            }
            int i;
            for(i=0;i<26;i++){
                if(stdList[i]!=every[i]){
                    break;
                }
            }
            if(i==26){
                ans.push_back(start);
            }
            start++;
            end++;
            int times = s.size()-p.size();
            while(times--){
                every[s[start-1]-'a']--;
                every[s[end]-'a']++;
                int i;
                for(i=0;i<26;i++){
                    if(stdList[i]!=every[i]){
                        break;
                    }
                }
                if(i==26){
                    ans.push_back(start);
                }
                start++;
                end++;
            }
        }

        return ans;
    }
};

int main()
{
    string s = "ababababab";
    string p = "aab";
    Solution* so = new Solution();
    vector<int> ans = so->findAnagrams(s,p);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
