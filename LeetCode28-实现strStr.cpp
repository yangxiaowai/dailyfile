#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int strStr(string s,string t){
    int nextval[10000];
    int i=0,j=-1;
    nextval[0]=-1;
    while(i<t.length()-1){
        if(j==-1||t[i]==t[j]){
            i++;j++;
            if(t[i]==t[nextval[i]])nextval[i]=nextval[nextval[i]];
            else nextval[i]=j;
        }
        else j=nextval[j];
    }
    int x=0,y=0;
    while(x<s.length()){
        if(y==-1||s[x]==t[y]){
            x++;y++;
            if(y>=t.length())return x-y;
        }
        else y=nextval[y];
    }
    return -1;
}

int main(){
    string s1,s2;
    ifstream is("in.txt");
    getline(is,s1);
    getline(is,s2);
    cout<<strStr(s1,s2)<<'\n';
    return 0;
}