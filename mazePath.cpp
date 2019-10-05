#include<iostream>
using namespace std;
int mazecount(int n,int m,int i,int j){
    if(i==n || j==m){
        return 1;
    }
    int count=0;
    count=count+mazecount(n,m,i+1,j)+mazecount(n,m,i,j+1);
    return count;

}
int count=0;
int maze(int n,int m,int i,int j,char b[],int outputindex)
{
    if(j==m || i==n){
        while(i<n){
            b[outputindex++]='H';
            i++;
        }
         while(j<m){
            b[outputindex++]='V';
            j++;
        }
        count++;
        for(int q=0;q<outputindex;q++){
            cout<<b[q];
        }
        cout<<" ";
        return count;
        }
    b[outputindex]='V';
    maze(n,m,i,j+1,b,outputindex+1);
    b[outputindex]='H';
    maze(n,m,i+1,j,b,outputindex+1);

}

int main(){
    char b[100];
    int m,n;
    cin>>m>>n;
    int x=maze(n-1,m-1,0,0,b,0);
    cout<<endl<<x;
}

