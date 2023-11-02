#include<iostream>

using namespace std;

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
	
    ListNode* swapPairs(ListNode* head) {
    	if(head == NULL) return NULL;
    	
    	if(head->next == NULL)return head;
    	
    	ListNode* p1 = head;
    	ListNode* p2 = head->next;
    	
    	head = p2;
    	while(p1 && p2){
    		p1->next = p2->next;
    		p2->next = p1;
    		if(p1->next == NULL){
    			break;
			}
			if(p1->next->next == NULL){
				break;
			}
			p2 = p1->next;
			p1->next = p2->next;
			p1 = p2;
			p2 = p2->next;
		}
		return head;
    }
};

int main(){
	
	return 0;
}



