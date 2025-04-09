#include<iostream>

using namespace std;

int main(){
    int st=20000101;
    int cnt=0;
    while(st<=20240413){
        int res=0;
        while(st!=0){
            switch(st%10){
                case 0:res+=13;st=st/10;break;
                case 1:res+=1;st=st/10;break;
                case 2:res+=2;st=st/10;break;
                case 3:res+=3;st=st/10;break;
                case 4:res+=5;st=st/10;break;
                case 5:res+=4;st=st/10;break;
                case 6:res+=4;st=st/10;break;
                case 7:res+=2;st=st/10;break;
                case 8:res+=2;st=st/10;break;
                case 9:res+=2;st=st/10;break; 
            }
        }
        if(res>50)cnt++;
        st++;
        int year=st/10000;int month=(st%10000)/100;int day=st%100;
        if(day>31){day=day%31;month++;}
        if(month>12){month=month%31;year++;}
        st=year*10000+month*100+day;
    }
    cout<<cnt<<endl;
    return 0;
}