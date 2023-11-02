#include<iostream>

using namespace std;
 
//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      /*ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}*/
  };
 
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		int num = 0;
		ListNode* p = head;
		while(p)
		{
			if(p != NULL){
				num++;//数量加一
				p = p->next; 
			}
		}
		//一共有num个结点，删除倒数第n个，就是删除第 num-n+1 个结点 
		//就是向后移动num - n 次
		int time = num - n - 1;
		p = head;
		if(time > 0){
			while(time-- ){
			p = p->next;
			}
		}
		else if(time == -1){
			return p->next; 
		}
		
		if(n>=2){
			ListNode* q = p->next;
			p->next = p->next->next;
			delete q;
		}
		else{
			p->next = NULL;
		}
		return head;		
    }
};

int main(){
	return 0;
}
