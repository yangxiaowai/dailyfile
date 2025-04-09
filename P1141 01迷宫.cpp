#include<iostream>
#include<cstring>
using namespace std;

int n,m,res[100002],a,b,f[1003][1003];
char s[1004][1004];

//x,y表示要查找的节点横纵坐标
//z表示节点的值0或1
//l表示查找的次数，f数组便于回溯记忆化不用重复搜索
void dfs(int x,int y,int z,int l){
    if(x<0||x>=n||y<0||y>=n||f[x][y]!=-1||s[x][y]-'0'!=z)return;
    f[x][y]=l;res[l]++;
    dfs(x-1,y,!z,l);dfs(x,y+1,!z,l);dfs(x+1,y,!z,l);dfs(x,y-1,!z,l);
}

int main(){
    cin>>n>>m;cin.ignore();
    memset(f,-1,sizeof(f));
    for(int i=0;i<n;i++){
          cin>>s[i];
    }
    for(int i=0;i<m;i++){
        int p,q;
        cin>>p>>q;p--;q--;
        if(f[p][q]==-1)dfs(p,q,s[p][q]-'0',i);else res[i]=res[f[p][q]];
    }
    for(int j=0;j<m;j++){
        cout<<res[j]<<endl;
    }
    return 0;
}