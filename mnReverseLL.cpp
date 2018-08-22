#include <bits/stdc++.h>
using namespace std;
 
 struct ListNode {
      int data;
      ListNode *next;
     
};
 

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* prevNode=NULL;
    ListNode* prevCnt=NULL;
    ListNode* curNode=head;
    ListNode* curCnt=NULL;
    ListNode* temp=NULL;
    
    if(m==n)
      return head;

    if(m!=n)
    {
        int i=1;
        
        while(i!=m)
        {
            prevCnt=curNode;
            prevNode=curNode;
            curNode=curNode->next;
            //cout<<curNode->data<<" ";
            i++;
        }
        
        curCnt=curNode;
        //cout<<curCnt->data<<" ";
        
        while(i!=n+1)
        {
           
            temp=curNode->next;
            curNode->next=prevNode;
            prevNode=curNode;
            curNode=temp;
            i++;
        }
        
       
        if(m==1)
        {
            head=prevNode;
            return head;
        }

        prevCnt->next=prevNode;
        curCnt->next=curNode;
  
    } 
    
    
    
    return head;
}

ListNode* push(ListNode** refHead,int data)
{
    ListNode* head=*refHead;

    ListNode* newNode=(ListNode*)malloc(sizeof(ListNode));
    newNode->data=data;
    newNode->next=NULL;

    if(head==NULL)
    {
        head=newNode;

        *refHead=head;

        return *refHead;
    }
    
    ListNode* temp=head;
    
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;

    return *refHead;

}
void printList(ListNode* head)
{
    ListNode* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}


int main()
{
    ListNode* head=NULL;

    head=push(&head,1);
    head=push(&head,2);
    head=push(&head,3);
    head=push(&head,4);
    head=push(&head,5);
    head=push(&head,6);

    //head=reverse(&head);
    
    head=reverseBetween(head,1,6);

    printList(head);





}