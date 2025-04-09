#include<iostream>
#include<stack>
#include<cmath>


using namespace std;
stack<char> op,dat;
stack<int> num,dat2;

int check(char z){
    switch(z){
        case '+':return 1;
        case '-':return 1;
        case '*':return 2;
        case '/':return 2;
        case '^':return 3;
        case '(':return 0;
        case ')':return 0;
        default:return -1;
    }
}

int js(int x,int y,char z){
    switch(z){
        case '+':return x+y;
        case '-':return x-y;
        case '*':return x*y;
        case '/':return x/y;
        case '^':return pow(x,y);
        default:return -0x3f3f3f3f;
    }
}

//将中缀表达式转换成后缀表达式
void transfer(string str){
    int len=str.length();
    for(int i=0;i<len;i++){
        if(isdigit(str[i]))dat.push(str[i]);
        else if(str[i]=='(')op.push(str[i]);
        else if(str[i]==')'){
            char ch=op.top();
            while(ch!='('){
                op.pop();
                dat.push(ch);
                ch=op.top();
            }
            op.pop();
        }
        else if(check(str[i])>=1&&check(str[i])<=3){
            if(!op.empty()){
                char ch=op.top();
                while(check(ch)>=check(str[i])&&!op.empty()){
                    if(check(str[i])==check(ch)&&str[i]=='^')break;
                    op.pop();
                    dat.push(ch);
                    if(!op.empty())ch=op.top();
                }
            }
            op.push(str[i]);
        }
    }
    while(!op.empty())
	{
		char t=op.top();
		op.pop();
		dat.push(t);
	}
	while(!dat.empty())
	{
		char t=dat.top();
		dat.pop();
		op.push(t);
	}
	while(!op.empty())
	{
		char t=op.top();
		cout<<t<<' ';
		op.pop();
		dat.push(t);
	}
	cout<<endl;
}

void calculate(){
    while(!dat.empty())
	{
		char t=dat.top();
		dat.pop();
		op.push(t);
	}
    while(!op.empty()){
        char ch=op.top();
        op.pop();
        if(isdigit(ch))num.push(ch-'0');
        else{
            int y=num.top();
            num.pop();
            int x=num.top();
            num.pop();
            num.push(js(x,y,ch));
            while(!num.empty()){
                int ch=num.top();
                num.pop();
                dat2.push(ch);
            }
            while(!dat2.empty()){
                int ch=dat2.top();
                cout<<ch<<" ";
                dat2.pop();
                num.push(ch);
            }
            while(!op.empty()){
                char ch=op.top();
                cout<<ch<<" ";
                op.pop();
                dat.push(ch);
            }
            while(!dat.empty()){
                char ch=dat.top();
                dat.pop();
                op.push(ch);
            }
            cout<<endl;
        }
    }
}

int main(){
    string str;
    cin>>str;
    transfer(str);
    calculate();
    return 0;
}