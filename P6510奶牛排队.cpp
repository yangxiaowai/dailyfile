#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long res=0;
int s[100001],mn[100001],mx[100001];
int tmn,tmx;


int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s[i]=x;
    }
    for(int i=1;i<=n;i++){
        while(tmn&&s[mn[tmn]]>=s[i])tmn--;
        while(tmx&&s[mx[tmx]]<s[i])tmx--;
        int k=upper_bound(mn+1,mn+tmn+1,mx[tmx])-mn;
        if(k!=tmn+1&&res<i-mn[k]+1)res=i-mn[k]+1;
        mn[++tmn]=i;
        mx[++tmx]=i;
    }
    cout<<res<<endl;
    return 0;
}