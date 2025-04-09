#include<iostream>
#include<string>

using namespace std;

int findstr(string s){
    int i=0,j=-1,max=1;
    int next[s.length()+1];
    next[i]=j;
    while(i<s.length()){
        if(j==-1||s[i]==s[j]){
            i++;j++;
            next[i]=j;
        }
        else j=next[j];
    }
    return (s.length()-next[s.length()]);
}

int main(){
    int n;
    cin>>n;cin.ignore();
    string s;
    getline(cin,s);
    cout<<findstr(s)<<endl;
    return 0;
}