#include<iostream>
#include<queue>
#include<string>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;
//将比较器换成greater让这个优先队列以小根堆形式储存，小的数组在上面
//可以想象成greater就是大的往下沉，大跟堆小根堆都是树状的，所以top获取最上面的元素，当前最大/最小的，pop删除最上面的元素
string str;

int main(){
    int n,m;
    cin>>n>>m;
    pq.push(1);
    for(int i=0;i<n;i++){
        int x=pq.top();
        pq.pop();
        str+=to_string(x);
        pq.push(x*2+1);
        pq.push(x*4+5);
    }
    cout<<str<<endl;
    int i=0;
    while(1){
        for(int j=0;j<str.size()-1;j++){
            if(str[j]<str[j+1]){
                str.erase(j,1);i++;
                if(i>=m){cout<<str<<endl;return 0;}
                break;
            }
        }
    } 
    return 0;
}