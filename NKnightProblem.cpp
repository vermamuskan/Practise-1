 #include<iostream>
using namespace std;
bool isSafe2(int arr[100][100],int n,int x,int y){
    int dir[8][2] = {{2,1},{1,2},{-2,1},{-1,2},{-1,-2},{-2,-1},{1,-2},{2,-1}};
    //(i+2, j+1), (i+1, j+2), (i-2,j+1), (i-1, j+2), (i-1, j-2), (i-2, j-1), (i+1, j-2) and (i+2, j-1)
    for(int k=0;k<8;k++){
        //for(int i=x,j=y; i>=0 && i<n && j>=0 && j<n; i+=dir[k][0],j+=dir[k][1]){
        int i=x+dir[k][0];
        int j=y+dir[k][1];
            if(arr[i][j]){
                return false;
            }
        //}
    }
    return true;
}
int nknight(int arr[100][100],int n,int x,int y,int c,int out[100][100]){
    if(c==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(out[i][j]==1)
                {
                  cout<<"{"<<i<<"-"<<j<<"}"<<" ";
                }
            }
        }
        cout<<" ";
        return 1;
    }
    if(x==n)
    {
        return 0;
    }
    int sum = 0;
    for( ;y<n;y++){
            if(isSafe2(arr,n,x,y)){
            out[x][y] = 1;
            sum+=nknight(arr,n,x,y+1,c-1,out);
            out[x][y] = 0;
        }
    }
    sum+=nknight(arr,n,x+1,0,c,out);
    return sum;
}
int main(){
    int arr[100][100],out[100][100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }
    int x=nknight(arr,n,0,0,n,out);
    cout<<endl<<x;
}

