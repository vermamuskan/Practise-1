#include<iostream>
using namespace std;
int nthFibo(int n)
{
    if(n==0)
    {
        return NULL;
    }
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    int a=0,b=1,c=1;
    for(int i=3;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        int n;
        cin>>n;
        cout<<"#"<<i+1<<" : "<<nthFibo(n+3)<<endl;
    }
}
