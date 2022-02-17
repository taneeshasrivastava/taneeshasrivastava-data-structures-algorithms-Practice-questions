#include"Creation_HashTable.h"
#include<bits/stdc++.h>
using namespace std;


int main(){
    Hashtable<int> h;
    h.insert("Mango",100);
    h.insert("Apple",120);
    h.insert("Banana",140);
    h.insert("orange",200);
    h.print();

    string fruit;
    cin>>fruit;

    int *price=h.search(fruit);
    if(price!=NULL){
        cout<<"Price is : "<<*price<<endl;
    }
    else{
        cout<<"NOT present";
    }

    h["newfruit"]= 200;
    cout<<"new fruit cost "<<h["newfruit"]<<endl;
    h["newfruit"] +=20;
    cout<<"new updated fruit cost "<<h["newfruit"]<<endl;
    return 0;
}
