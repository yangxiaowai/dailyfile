#include <iostream>
#include<stack>

using namespace std;

stack<int> st;
int main(){
    int m=10000;
    int x,y;
    char z;
    cin>>x;
    st.push(x);
    while(cin>>z>>y){
        if(z=='*'){
            x=st.top();
            st.pop();
            st.push(x*y%m);
        }
        else{
            st.push(y);
        }
    }
    x=0;
    while(st.size()){
        x=x+st.top();
        x=x%m;
        st.pop();
    }
    cout<<x<<endl;
    return 0;
}
