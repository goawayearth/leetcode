#include<iostream>

using namespace std;

 typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  }ListNode;

class Solution {
public:
    //归并排序

  ListNode* sortList(ListNode* head) {
  if (!head || !head->next) return head;

  // 用快慢指针找到中间节点
  ListNode *slow = head, *fast = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // 对两段链表分别排序
  ListNode* right = sortList(slow->next);
  slow->next = nullptr;
  ListNode* left = sortList(head);

  // 合并排序后的两段链表
  return merge(left, right);
}

ListNode* merge(ListNode* l1, ListNode* l2) {
  ListNode dummy(0);
  ListNode* cur = &dummy;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      cur->next = l1;
      l1 = l1->next;
    } else {
      cur->next = l2;
      l2 = l2->next;
    }
    cur = cur->next;
  }
  cur->next = l1 ? l1 : l2;
  return dummy.next;
}
};

int main(){

	return 0;
}
