// 3. WAP to implement single link list with following features:
//     i)   Insertion of a node at beginning, at middle and at end of list.
//     ii)  Deletion of a node at beginning, at middle and at end of list.
//     iii) Display the link list.
//     iv)  Count the number of nodes in the link list.
//     v)   Search a node in the link list.
//     vi)  Sort the link list.
//     vii) Reverse the link list.


#include<iostream>

using namespace std;

struct node
{
  int data;
  struct node *next;
};

class list
{
   private:
    node *head, *tail;
   public:
    list()
    {
        head=0;
        tail=0;
    }

    void createnode(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=0;
        if(head==0)
        {
            head=temp;
            tail=temp;
            temp=0;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    void ins_begin(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=head;
        head=temp;
    }

    void ins_pos(int pos,int value)
    {
        int i;
        node *temp=new node;
        node *curr=new node;
        node *prev=new node;
        curr=head;
        for(i=1;i<pos;i++)
        {
          prev=curr;
          curr=curr->next;
        }
        temp->data=value;
        prev->next=temp;
        temp->next=curr;
    }

    void ins_end(int value)
    {
        node *temp=new node;
        temp->data =value;
        temp->next=0;
        if(head==0)
        {
            head=temp;
            tail=temp;
            temp=0;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
        cout<<endl;
    }

    void del_begin()
    {
        node *temp=new node;
        temp=head;
        head=head->next;
        delete temp;
    }

    void del_pos(int pos)
    {
        node *curr=new node;
        node *prev=new node;
        curr=head;
        for(int i=1;i<pos;i++)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        delete curr;
    }

    void del_end()
    {
        node *curr=new node;
        node *prev=new node;
        curr=head;
        while(curr->next!=0)
        {
            prev=curr;
            curr=curr->next;
        }
        tail=prev;
        prev->next=0;
        delete curr;
        cout<<endl;
    }

    void display()
    {
        node *temp=new node;
        temp=head;
        while(temp!=0)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }

    void count()
    {
        int n=0;
        node *temp=new node;
        temp=head;
        while(temp!=0)
        {
            n++;
            temp=temp->next;
        }
        cout<<"Number of nodes in given link list: "<<n;
        cout<<endl;
    }

    void search()
    {
        if(head==0)
        {
            cout<<"list is empty."<<endl;
        }
        else
        cout<<"enter the value to be searched: ";
        int value,pos=0;
        cin>>value;
        node *temp=new node;
        temp=head;
        while(temp!=0)
        {
            pos++;
            if(temp->data==value)
            {
                cout<<"Element "<<value<<" is found at position : "<<pos<<endl;
            }
            temp=temp->next;
        }
        cout<<endl;
    }

    void sort()
    {
        node *prev,*curr;
        int value;
        if(head==0)
        {
            cout<<"The list is empty."<<endl;
        }
        prev=head;
        while(prev!=0)
        {
            for(curr=prev->next;curr!=0;curr=curr->next)
            {
                if(prev->data>curr->data)
                {
                    value=prev->data;
                    prev->data=curr->data;
                    curr->data=value;
                }
            }
            prev=prev->next;
        }
        cout<<endl;
    }

    void reverse()
    {
        node *p, *q, *r;
        if(head==0)
        {
            cout<<"List is empty."<<endl;
        }
        p=head;
        q=0;
        while(p!=0)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        cout<<endl;
    }

};

int main()
{
    list l;
    l.createnode(3);
    l.createnode(8);
    l.createnode(6);
    l.createnode(5);
    cout<<" linked list is: "<<endl;
    l.display();
    l.ins_begin(1);
    l.ins_pos(2,3);
    l.ins_end(5);
    cout<<"Linked list after insertion : "<<endl;
    l.display();
    l.del_begin();
    l.del_pos(4);
    l.del_end();
    cout<<"Linked list after deletion : "<<endl;
    l.display();
    l.count();
    l.search();
    cout<<"Link list is: "<<endl;
    l.display();
    l.sort();
    cout<<"Sorted link list is: "<<endl;
    l.display();
    l.reverse();
    cout<<"Reversed link list is: "<<endl;
    l.display();
    return 0;

}
