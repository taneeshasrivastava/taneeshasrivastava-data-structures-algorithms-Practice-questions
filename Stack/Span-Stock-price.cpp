#include<iostream>
#include<stack>
using namespace std;
void stockSpan(int price[],int n,int span[]){
    stack<int> s;
    s.push(0);
    span[0]=1;

    for(int i=1;i<n-1;i++){
        int currPrice=price[i];
        while(!s.empty() and price[s.top()]<=currPrice){
            s.pop();
        }
        if(!s.empty()){
            int preHigh=s.top();
            span[i]=i-preHigh;
        }
        else{
            span[i]=i+1;
        }
        s.push(i);
    }
}
int main(){
   
    int price[]={100,80,60,70,60,75,85};
    int n= sizeof(price)/sizeof(int);
    int span[10000]={0};
    stockSpan(price,n,span);
    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }

    return 0;
}
