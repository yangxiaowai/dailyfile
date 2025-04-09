#include<iostream>
#include<algorithm>
using namespace std;

int l[200010],r[200010],count0,count1,res,n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x==0)count0++;
        else if(x==1)count1++;
        int t = count0-count1+n;
        if(!l[t]&&t!=n)l[t]=i;else r[t]=i;
    }
    for(int i=0;i<=2*n;i++){
        res=max(res,r[i]-l[i]);
    }
    cout<<res<<endl;
    return 0;
}