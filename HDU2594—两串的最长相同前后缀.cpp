#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int nextval[100005];

void getnext(string str){
    int i=0,j=-1;
    nextval[0]=-1;
    while(i<str.length()){
        if(j==-1||str[i]==str[j]){
            i++;
            j++;
            nextval[i]=j;
        }
        else j=nextval[j];
    }
}

int main(){
    string s1,s2,s;
    int max=0;
    ifstream is("in.txt");
    getline(is,s1);
    getline(is,s2);
    s=s1+s2;
    getnext(s);
    max=nextval[s.length()];
    if(max==0){cout<<0<<endl;return 0;}
    for(int i=0;i<max;i++){
        cout<<s1[i];
    }
    cout<<" ";
    cout<<max<<endl;
    return 0;
}