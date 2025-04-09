// #include<iostream>

// using namespace std;
// const int MaxSize=1000000;
// int a;
// class qu{
//     int* data;
//     int front,rear;
//     public:
//     qu():front(0),rear(0),data(new int[1000001]){}
//     ~qu(){delete []data;}
//     void push(int n){
//         if((rear+1)%a==front)return;
//         rear=(rear+1)%a;
//         data[rear]=n;
//     }
//     void pop(){
//         if(rear==front)return;
//         front=(front+1)%a;
//     }
//     int gethead(){
//         return data[(front+1)%a];
//     }
//     bool isonly(){
//         return rear==(front+1)%a;
//     }
// };

// int main(){
//     int n,k;
//     cin>>n>>k;
//     a=n+1;
//     qu q;
//     for(int i=1;i<=a;i++)q.push(i);
//     while(!q.isonly()){
//         int cnt=1;
//         while(cnt<k){
//             int x=q.gethead();
//             q.pop();
//             q.push(x);
//             cnt++;
//         }
//         q.pop();
//     }
//     cout<<q.gethead()<<'\n';
//     return 0;
// }

// #include<iostream>

// using namespace std;

// int main(){
//     int n,k,m=0;//最后一个元素下标为0
//     cin>>n>>k;
//     for(int i=2;i<=n;i++){
//         m=(m+k)%i;
//     }
//     cout<<m+1<<'\n';//初始时第一个元素下标为1
//     return 0;
// }

#include<iostream>

using namespace std;
const int MaxSize=11;
class qu{
    int* data;
    int front,rear;
    public:
        qu(){data=new int[MaxSize];front=rear=0;}
        ~qu(){delete []data;}
        void push(int x){
            if((rear+1)%MaxSize)return;
            rear=(rear+1)%MaxSize;
            data[rear]=x;
        }
        void pop(){
            if(rear==front)return;
            front=(front+1)%MaxSize;
        }
        int gethead(){
            return data[front+1];
        }
        bool isonly(){
            return (front+1)==rear;
        }
        bool empty(){
            return rear==front;
        }
};

int main(){
    int n,k;
    cin>>n>>k;
    qu q;
    for(int i=1;i<=n;i++)q.push(i);
    while(!q.isonly()){
        int cnt=1;
        while(cnt<k){
            int x=q.gethead();
            q.pop();
            q.push(x);
        }
        q.pop();
    }
    cout<<q.gethead()<<'\n';
    return 0;
}