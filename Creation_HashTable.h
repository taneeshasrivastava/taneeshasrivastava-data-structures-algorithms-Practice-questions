#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
public:
    string key;
    T value;
    Node* next;

    Node(string key, T value){
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};
template<typename T>
class Hashtable{
    Node<T> ** table;
    int cs;//Total entries that have been inserted
    int ts;// size of table

    int hashfn(string key){
        int idx=0;
        int power=1;
        for(auto ch:key){
            // % to avoid overflow 
            // abc  1 + 29 + 29^2 = idx in ht
            idx= (idx+ch*power)%ts;
            power=(power*29)%ts;
        }
        return idx;
    }
    void rehash(){
        //Save the ptr to the oldTable and we do insertion in new table 
        Node<T> **oldtable= table;
        int oldts=ts;
        //Increse the table size 
        cs=0;
        ts=2*ts+1;
        table =new Node<T>*[ts];//shold make it prime 
        
        for(int i=0;i<ts;i++){
            table[i]=NULL;
        }

        //copy element from old table to new table:
        for(int i=0;i<oldts;i++){
            Node<T> *temp=oldtable[i];

            while(temp!=NULL){
                string key = temp->key;
                T value =temp->value;
                //Happend in new table :
                insert(key,value);
                temp=temp->next;
            }
            //destory the ith linkedlist 
            if(oldtable[i]!=NULL){
                delete oldtable[i];
            }
        }
        delete [] oldtable;

        
    }


public:
    Hashtable(int default_size = 7){
    int  cs=0;
    int ts=default_size;

        table= new Node<T>*[ts];
        for(int i=0;i<ts;i++){
            table[i]=NULL;
        }
    }
    void insert(string key,T val){
        int idx= hashfn(key);
        Node<T>* n=new Node<T>(key,val);
        n->next=table[idx];
        table[idx]=n;

        cs++;
        float load_factor = cs/ float(ts);
        if(load_factor>0.7){
            rehash();
        }
    }
    T* search(string key){
        int idx=hashfn(key);

        Node<T> *temp =table[idx];

        while(temp!=NULL){
            if(temp->key==key){
                return &temp->value;
            }
            temp=temp->next; 
            
        }
        return NULL;
    }
    T& operator[](string key){
        T* valuefound= search(key);
        if(valuefound==NULL){
            T object;
            insert(key,object);
            valuefound =search(key);
        }
        return *valuefound;
    }
    void print(){
        for(int i=0;i<ts;i++){
            cout<<"BUCKET : "<<i<<"->";
            Node<T> *temp=table[i];
            while(temp!=NULL){
                cout<< temp->key <<"->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};