#include <iostream>
#include <vector>
using namespace std;

typedef struct Node{
    int val;
    struct Node* next;
    Node(){
        val = 0;
        next = NULL;
    }
}Node;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        Node* head = new Node();
        head->val=nums[0];
        Node* p = head;

        for(int i=1;i<n;i++){
            Node* node = new Node();
            node->val = nums[i];
            p->next = node;
            p = node;
        }
        p->next = head;
        int num = n-(k%n);
        while(num--){
            head = head->next;
        }
        for(int i=0;i<n;i++){
            nums[i] = head->val;
            head = head->next;
        }

    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    Solution* s = new Solution();
    s->rotate(nums,1);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<endl;
    }

    return 0;
}
