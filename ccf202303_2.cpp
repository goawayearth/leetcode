#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n,k;//块数，资源和最少天数
    long long m;
    unordered_map<long long,long long> map;
    
    cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        long long one,second;
        cin>>one>>second;
        map[one] += second;
    }
    vector<int> first;
    vector<int> second;
    for(auto it = map.begin();it!=map.end();it++){
        int key = it->first;
        first.push_back(key);
    }
    sort(first.begin(),first.end());
    for(int i=0;i<first.size();i++){
        int source = map[first[i]];
        second.push_back(source);
    }

    int flag = 1;
    while(flag){
        flag=0;
        int pos = first.size()-1;
        if(first[pos]>k){
            if(m>=second[pos]){
                flag = 1;
                if(pos>0 && first[pos-1]+1 == first[pos]){
                    second[pos-1]+=second[pos];
                    m-=second[pos];
                    first.pop_back();
                    second.pop_back();
                }
                else{
                    m-=second[pos];
                    first[pos]-=1;
                }
                
            }
        }
    }

    cout<<first[second.size()-1]<<endl;
    return 0;
}

