#include<iostream>
#include<queue>
using namespace std;

struct Box{
    int i;
    int j;
    int di;
    Box(){}
    Box(int i,int j,int di):i(i),j(j),di(di){}
};

int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};
int mg[401][401];

void mgpath(int n,int m,int i,int j){
    int time=0;
    Box b;
    queue<Box> qu;
    b=Box(i,j,-1);
    qu.push(b);
    mg[i][j]=-1;
    while(qu.size()>0){
        time++;
        int z=qu.size();
        for(int x=0;x<z;x++){
            b=qu.front();
            qu.pop();
            for(int y=0;y<8;y++){
                if(b.i+dx[y]>0&&b.i+dx[y]<=n&&b.j+dy[y]>0&&b.j+dy[y]<=m){
                    if(mg[b.i+dx[y]][b.j+dy[y]]==0){
                        qu.push(Box(b.i+dx[y],b.j+dy[y],-1));
                        mg[b.i+dx[y]][b.j+dy[y]]=time;
                    }
                }
            }
        }
    }
}

void disppath(int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mg[i][j]==0){
                cout<<-1<<" ";
                continue;
            }
            if(mg[i][j]==-1){
                cout<<0<<" ";
                continue;
            }
            cout<<mg[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n,m,i,j;
    cin>>n>>m>>i>>j;
    mgpath(n,m,i,j);
    disppath(n,m);
    return 0;
}