#include<iostream>
using namespace std;

typedef struct LNode
{
    int data;
    LNode* next;
}LNode,*LinkNode;


LinkNode CreateLinkNode(LinkNode head,int n)
{
    LinkNode s = nullptr;
    for(int i = 1 ;i <= n ; i++)
    {
        
        s = (LinkNode)malloc(sizeof(LNode));
        int x;
        cout<<"请输入第"<<i<<"个元素:";
        cin>>x;
        s->data = x;
        s->next = head->next;
        head->next = s;
    }

    return head;

}

void OutPut(LinkNode head)
{
    LinkNode s = head->next;
    cout<<"该链表为：";
    while (s != NULL)
    {
        cout<<s->data<<" ";
        s = s->next;
    }
    
}


int main()
{
    LinkNode head;
    int num =5;
    CreateLinkNode(head,num);
    OutPut(head);
}