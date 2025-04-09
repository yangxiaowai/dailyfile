#include<iostream>
#include<unordered_map>
#include<queue>
#include<fstream>
using namespace std;
queue<int>* groups[1005]={nullptr};
unordered_map<int,int> unmap;
queue<queue<int>*> group;
int main(){
    ifstream is("in.txt");
    int n;
    is>>n;
    for(int i=1;i<=n;i++){
        int m;
        is>>m;
        for(int j=1;j<=m;j++){
            int x;
            is>>x;
            unmap[x]=i;
        }
    }
    string str;
    is>>str;
    while(str!="STOP"){
        if(str=="ENQUEUE"){
            int x;
            is>>x;
            if(groups[unmap[x]]==nullptr){
                groups[unmap[x]]=new queue<int>;
                groups[unmap[x]]->push(x);
                group.push(groups[unmap[x]]);
            }
            else{
                groups[unmap[x]]->push(x);
            }
        }
        else if(str=="DEQUEUE"){
            if(group.empty())return 0;
            cout<<group.front()->front()<<endl;
            int x=group.front()->front();
            group.front()->pop();
            if(group.front()->empty()){
                groups[unmap[x]]=nullptr;
                delete group.front();
                group.pop();
            }
        }
        is>>str;
    }
    is.close();
    return 0;
}