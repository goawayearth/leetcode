/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* p1=l1;
    	ListNode* p2=l2;
    	ListNode* sum = new ListNode();
    	ListNode* q=sum;
    	int n1;
    	int n2;
    	int temp;
    	int jin=0;
    	while(l1 && l2){
    		n1=l1->val;
    		n2=l2->val;
    		temp=n1+n2+jin;
    		ListNode* Node=new ListNode();
    		Node->val=temp%10;
    		jin=temp/10;
    		q->next=Node;
    		q=Node;
    		l1=l1->next;
    		l2=l2->next;
    		
		}
		while(l1){
			temp=l1->val+jin;
			ListNode* Node=new ListNode();
    		Node->val=temp%10;
    		jin=temp/10;
    		q->next=Node;
    		q=Node;
    		l1=l1->next;
		}
		while(l2){
			temp=l2->val+jin;
			ListNode* Node=new ListNode();
    		Node->val=temp%10;
    		jin=temp/10;
    		q->next=Node;
    		q=Node;
    		l2=l2->next;
		}
		if(jin!=0){
			ListNode* Node=new ListNode();
			Node->val=1;
    		q->next=Node;
    		q=Node;
		}
		
		return sum->next;
    }
};
