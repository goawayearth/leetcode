/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include<stdio.h>
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        int lenA=0;
        ListNode* pB = headB;
        int lenB=0;
        
        while(1){
        	if(pA != NULL){
        		lenA++;
        		pA = pA->next;
			}
			else{
				break;
			}
		}
		while(1){
			if(pB != NULL){
        		lenB++;
        		pB = pB->next;
			}
			else{
				break;
			}
		}
		pA = headA;
		pB = headB;
		
		int step = 0;
		if(lenA > lenB){
			step = lenA-lenB;
			while(step--){
				pA = pA->next;
			}
		}
		else {
			step = lenB - lenA;
			while(step--){
				pB = pB->next;
			}
		}
		
//        while(1){
//        	if(pA == NULL || pB == NULL){
//        		return NULL;
//			}
//        	else if(pA != pB){
//        		pB = pB->next;
//				pA = pA->next;
//			}
//			else{
//				return pA;
//			}
//		}
		while(pA != pB){
			pA = pA->next;
			pB = pB->next;
		}
        return pA;
    }
};

int main(){
	
}
