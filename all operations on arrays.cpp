#include<stdio.h>
#include<conio.h>
#include <iostream>
using namespace std;

main()
{
    int array[15],no_el,i,choice;
    cout<<"Enter the no of element :";
    cin>>no_el;
    for(i=0;i<no_el;i++)
    {
        cout<<"Enter the element : ";
        cin>>array[i];
    }
    while(1)
    {
        cout<<endl<<"1. Insertion";
        cout<<endl<<"2. Deletion";
        cout<<endl<<"3. Searching";
        cout<<endl<<"4. Modification";
        cout<<endl<<"5. display";
        cout<<endl<<"6. exit";
        cout<<endl<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
          {
            case 1:
                cout<<"Enter the position at which you want to insert : ";
                int pos;
                cin>>pos;
                cout<<"Enter the new element : ";
                int new_el;
                cin>>new_el;
                pos--;
                for(i=no_el-1;i>=pos;i--)
                    array[i+1]=array[i];
                array[pos]=new_el;
                no_el++;
            break;
            case 2:
                cout<<"Enter the value you want to delete : ";
                int value;
                cin>>value;
                for(pos=0;pos<no_el;pos++)
                {
                    if(array[pos]==value)
                        break;
                }
                if(pos==no_el)
                {
                    cout<<"Search value not found";
                    break;
                }
                for(i=pos;i<no_el;i++)
                    array[i]=array[i+1];
                no_el--;
            break;
            case 3:
                cout<<"Enter the value to be search : ";
                cin>>value;
                for(pos=0;pos<no_el;pos++)
                {
                    if(array[pos]==value)
                        break;
                }
                if(pos==no_el)
                {
                    cout<<"Search value not found";
                    break;
                }
                cout<<"Search value found at : "<<pos+1;
            break;
            case 4:
                cout<<"Enter the position to be edit or modify : ";
                cin>>pos;
                cout<<"Enter the new value for old position : ";
                cin>>array[pos-1];
            break;
            case 5:
                cout<<endl;
                for(i=0;i<no_el;i++)
                    cout<<endl<<"The element is : "<<array[i];
                    cout<<endl;
            break;
            case 6:
                return(0);
            break;
        }
        getch();
    }
}
