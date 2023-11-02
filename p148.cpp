#include<iostream>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
		if(head == NULL){
			return head;
		}
		else if(head->next == NULL){
			return head;
		}
		//两个元素以及以上的元素排序
		ListNode* start = head;
		ListNode* tail = start;
		
		while(tail->next){
			tail = tail->next;
		}
		Sort(start, tail->next);
		return head;
    }
    
    void Sort(ListNode* start,ListNode* tail){
    	if(start->next == tail){ 
    		return;
		}
    	ListNode* mid = quikSort(start,tail);
    	Sort(start,mid);
    	Sort(mid,tail);
	}
    
    
    ListNode* quikSort(ListNode* start,ListNode* tail){
    	int value = start->val;
    	ListNode* cur = start;
    	while(cur != tail){
    		if(cur->val < value){
    			int temp = cur->val;
    			cur->val = start->val;
    			start->val = temp;
    			cur = cur->next;
    			start = start->next;
			}
			else{
				cur = cur->next; 
			}
		}
		return start;
	}
        
};

int main(){
	
	return 0;
}
