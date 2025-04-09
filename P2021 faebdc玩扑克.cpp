#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n;
    cin>>n;
    deque<int> dq;
    for(int i=n;i>0;i--){
        dq.push_front(i);
        int x=dq.back();
        dq.pop_back();
        dq.push_front(x);
    }
    for(int a:dq){
        cout<<a<<" ";
    }
    return 0;
}