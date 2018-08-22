#include <bits/stdc++.h>

using namespace std;

void sortList(Node *head)
{
   Node* ptr=(Node*)malloc(sizeof(Node));
   ptr=head;
   
   int zero=0,one=0,two=0;
   
   while(ptr!=NULL)
   {
       if(ptr->data==0)
       zero++;
       
       if(ptr->data==1)
       one++;
       
       if(ptr->data==2)
       two++;
       
       ptr=ptr->next;
   }
   
   ptr=head;
   
   while(ptr!=NULL)
   {
       if(zero==0)
       break;
       
       ptr->data=0;
       ptr=ptr->next;
       zero--;
   }
   
   while(ptr!=NULL)
   {
       if(one==0)
       break;
       
       ptr->data=1;
       ptr=ptr->next;
       one--;
   }
   
   while(ptr!=NULL)
   {
       if(two==0)
       break;
       
       ptr->data=2;
       ptr=ptr->next;
       two--;
   }
}
