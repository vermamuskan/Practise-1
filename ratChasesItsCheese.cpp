#include<iostream>
using namespace std;
bool check(char a[][1000],int n,int m,int i,int j,int b[][1000],int visited[][1000])
{
    if(i==n-1 && j==m-1)
    {
        b[i][j]=1;
        return 1;
    }
    if(i<0 || j<0)//ye cond. daali hi nai
    {
        return 0;
    }
    if(a[i][j]=='X')//ye pehle check hogi
    {
        return 0;
    }
    if(visited[i][j])//ye bhi pehle check hogi
    {
        return 0;
    }
    visited[i][j]=1;//ye pehle hoga
    /*if(i==n-1)
    {
        b[i][j]=1;//yaha 1 ni dala tha
        if(check(a,n,m,i,j+1,b,visited))
        {
            return true;
        }
        b[i][j]=0;
        return false;
    }
    if(j==m-1)
    {
        b[i][j]=1;//yaha bhi
        if(check(a,n,m,i+1,j,b,visited))
        {
            return true;
        }
        b[i][j]=0;
        return false;
    }*/
    if(i>=n || j>=m){
        return false;
    }

    b[i][j]=1;
    bool done1=check(a,n,m,i,j+1,b,visited);
    if(done1)
    {
        return 1;
    }
    bool done2=check(a,n,m,i+1,j,b,visited);
    if(done2)
    {
        return 1;
    }
    bool done3=check(a,n,m,i,j-1,b,visited);
    if(done3)
    {
        return 1;
    }
    bool done4=check(a,n,m,i-1,j,b,visited);
    if(done4)
    {
        return 1;
    }
    b[i][j]=0;
    return 0;
}
int main()
{
    int n,m;
    char a[1000][1000];
    int visited[1000][1000]={0};
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int b[1000][1000]={0};
    int x=check(a,n,m,0,0,b,visited);
    if(x==1)
    {
      for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else if(x==0)
    {
        cout<<"NO PATH FOUND";
    }
    return 0;
}

