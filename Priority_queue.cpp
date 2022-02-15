#include<iostream>
#include<queue>
using namespace std;

class Compare{
public:
    bool operator()(int a, int b ){
        return a>b;
    }
};
int main(){
    int arr[]={10,15,20,13,6,90};
    int n= sizeof(arr)/sizeof(int);
    
//Max heap :
    priority_queue<int> Max_heap;
    for(int x:arr){
        Max_heap.push(x);
    }
    while(!Max_heap.empty()){
        cout<< Max_heap.top() <<endl;
        Max_heap.pop();
    }

//Min heap :
//inbuild parameter: camparision 
    // priority_queue<int, vector<int>, greater<int> > Min_heap;
    priority_queue<int, vector<int>, Compare> Min_heap;
    for(int x:arr){
        Min_heap.push(x);
    }
    while(!Min_heap.empty()){
        cout<< Min_heap.top() <<endl;
        Min_heap.pop();
    }
    return 0;
}