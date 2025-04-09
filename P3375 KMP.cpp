#include<iostream>
#include<string>
using namespace std;

void getnextval(string s1,int* nextval){
    int x=0,y=-1;
    nextval[x]=y;
    int l=s1.length();
    while(x<l-1){
        if(y==-1||s1[x]==s1[y]){
            x++;y++;
            nextval[x]=y;
        }
        else y=nextval[y];
    }
}
void getnext(string s2){
    int next[s2.length()+1];
    int i=0,j=-1;
    next[i]=j;
    int l=s2.length();
    while(i<l){
        if(j==-1||s2[i]==s2[j]){
            i++;j++;
            next[i]=j;
        }
        else j=next[j];
    }
    cout<<0<<" ";
    for(int i=1;i<l;i++){
        cout<<next[i+1]<<" ";
    }
}
void KMP(string s1,string s2){
    int* nextval2=new int[s2.length()+1];
    getnextval(s2,nextval2);
    int l1=s1.length();
    int l2=s2.length();
    int i=0,j=0;
    while(i<l1&&j<=l2){
        if(j==-1||s1[i]==s2[j]){
            i++;j++;
            if(j==l2){int res=i-j+1;cout<<res<<endl;i=i-j+1;j=nextval2[j-1];}
        }
        else {j=nextval2[j];}
    }
}

int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    KMP(s1,s2);
    getnext(s2);
    return 0;
}