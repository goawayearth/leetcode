/*************************************************************************
        > File Name: ccf202009_1.cpp
        > Author: tml
        > Mail: 3200035928@qq.com
        > Created Time: 2023年12月02日 星期六 01时04分00秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct Node{
    int remote;
    int X;
}Node;
vector<Node> nums;

int main(){
    int n,X,Y;
    cin>>n>>X>>Y;

    for(int i=0;i<n;i++){
        int tx,ty;
        cin>>tx>>ty;
        Node node;
        node.remote = pow(tx-X,2)+pow(ty-Y,2);
        node.X = i+1;
        nums.push_back(node);
    }
    vector<Node> nums1 = nums;
    for(int i=0;i<3;i++){
        for(int j=0;j<n-1;j++){
        if(nums[j].remote<=nums[j+1].remote){
                Node node;
                node.remote = nums[j].remote;
                node.X = nums[j].X;
                nums[j].remote = nums[j+1].remote;
                nums[j].X = nums[j+1].X;
                
                nums[j+1].remote = node.remote;
                nums[j+1].X = node.X;
            
            }
        }
    }
    int num = 0;
    int pos = n-1;
    for(int j=0;j<3;j++){
    for(int i=0;i<nums1.size();i++){
        if(nums1[i].remote == nums[pos-j].remote){
             cout<<nums1[i].X<<endl;
             nums1.erase(nums1.begin()+i);
             break;
        }
    }
    }
}
