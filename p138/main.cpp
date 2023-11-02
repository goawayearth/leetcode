#include <iostream>

using namespace std;

typedef struct Node {
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
}Node;


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* priPos = head;//指向原链表的指针
        Node* head1 = new Node(0);//新链表头节点
        Node* nowPos = head1;//新头节点指针
        if(head==NULL)return NULL;
        nowPos->val = priPos->val;
        priPos = priPos->next;
        while(priPos!=NULL){
            Node* node = new Node(priPos->val);
            nowPos->next = node;
            nowPos = node;
            priPos=priPos->next;
        }
        //已经将next复制完了
        priPos = head;
        nowPos = head1;
        Node* p1=head;//在原链表上游走
        Node* p2=head1;//在新链表上
        Node* rand1=head;
        while(priPos!=NULL){
            rand1 = priPos->random;
            while(p1 != rand1){
                p1 = p1->next;
                p2 = p2->next;
            }
            nowPos->random = p2;
            //下一轮
            priPos = priPos->next;
            nowPos = nowPos->next;
            p1=head;
            p2=head1;
        }



        return head1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
