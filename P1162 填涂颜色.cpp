#include<iostream>

using namespace std;

int x[32][32],y[32][32];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n,i,j;

void dfs(int a,int b){
    //为什么上限是n+1呢？因为这样在外围增加一圈保证从（0，0）开始dfs的时候可以把外围都寻找到。
    if(a<0||a>n+1||b<0||b>n+1||x[a][b]!=0)return;
    x[a][b]=1;
    for(int i=0;i<4;i++)dfs(a+dx[i],b+dy[i]);
}

int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>y[i][j];
            if(y[i][j]==0)x[i][j]=0;
            else x[i][j]=2;
        }
    }
    dfs(0,0);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(x[i][j]==0)cout<<2<<" ";
            else cout<<y[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}