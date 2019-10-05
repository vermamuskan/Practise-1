#include <iostream>
using namespace std;
struct node
{
   int data;
   node *next;
};

class CLL
{
private:
    node *cll;
public:
    CLL()
    {
        cll=NULL;
    }

    void createnode(int value)
    {
       node *temp=new node;
       temp->data = value;
       if (cll == NULL)
         {
            cll = temp;
            temp->next = cll;
         }
       else
        {
           temp->next = cll->next;
           cll->next = temp;
           cll = temp;
        }
    }

    void ins_beg(int value)
    {
        node *temp=new node;
        temp->data = value;
        temp->next = cll->next;
        cll->next = temp;
    }

    void ins_pos(int value, int pos)
    {
        node *s;
        s = cll->next;
        for (int i = 1;i < pos;i++)
            {
               s = s->next;
            }

        node *temp = new node;
        temp->next = s->next;
        temp->data = value;
        s->next = temp;

    }

    void ins_end(int value)
    {
        node *temp = new node;
        node *s = new node;
        temp->data = value;
        s=cll;
        temp->next=s->next;
        s->next = temp;
        cll=temp;
    }

    void del(int value)
    {
       node *temp, *s;
       s = cll->next;
      /* If List has only one element*/
      if (cll->next == cll && cll->data == value)
      {
        temp = cll;
        cll = NULL;
        delete(temp);
        return;
      }
      if (s->data == value)  //First Element Deletion/
      {
        temp = s;
        cll->next = s->next;
        delete(temp);
        return;
      }
      while (s->next != cll)
      {

        if (s->next->data == value)
        {
            temp = s->next;
            s->next = temp->next;
            delete(temp);
            return;
        }
        s = s->next;
      }

      if (s->next->data == value)
      {
        temp = s->next;
        s->next = cll->next;
        delete(temp);
        cll = s;
        return;
      }
      cout<<"Element "<<value<<" not found in the list"<<endl;

    }

      void display()
    {
        cout<<endl;
        node *s;
        if (cll == NULL)
        {
           cout<<"List is empty, nothing to display"<<endl;
           return;
        }
        s = cll->next;
        while (s != cll)
         {
           cout<<s->data<<"->";
           s = s->next;
         }
        cout<<s->data<<endl;
        cout<<endl;
    }

};
 int main()
 {
     CLL l;
     l.createnode(1);
     l.createnode(2);
     l.createnode(3);
     cout<<"Created Circular link list is: "<<endl;
     l.display();
     l.ins_beg(0);
     l.ins_pos(4,3);
     l.ins_end(5);
     cout<<"Circular link list after insertion is: "<<endl;
     l.display();
     l.del(0);
     l.del(4);
     l.del(5);
     cout<<"Circular link list after deletion is: "<<endl;
     l.display();
     return 0;
 }

