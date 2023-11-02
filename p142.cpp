#include<iostream>
#include<unordered_map>

using namespace std;

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> map;
        ListNode* p = head;
        while(p){
        	auto it = map.find(p);
        	if(it == map.end()){
        		//˵��û�ҵ�
				map[p] = 1;
			}
			else{
				//�ҵ���
				return p; 
			} 
			p = p->next;
		}
		return NULL;
    }
};

int main(){
	return 0;
}
