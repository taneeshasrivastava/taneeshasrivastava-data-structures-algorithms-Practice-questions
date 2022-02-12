#include<iostream>
#include<vector>
using namespace std;


class Node{
    public:
    int key;
    Node *left;
    Node *right;

    Node(int key){
        this->key=key;
        left=right=NULL;
    }
};
Node* insert(Node* root, int key){
    if(root==NULL){
        return new Node(key);
    }
    if(key < root->key){
        root->left= insert(root->left,key);
    }
    else{
        root->right= insert(root->right,key);
    }
    return root;
}
//O(H)
bool search(Node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->key==key){
        return true ;
    }
    if(key<root->key){
        return search(root->left,key);
    }
    return search(root->right,key);
}
Node* findMin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
//BST deletion 
Node* remove(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    else if(key< root->key){
        root->left= remove(root->left,key);
    }
    else{
     //When the current node matched with the key 
    // no childern
    if(root->left==NULL and root->right==NULL){
        delete root;
        root=NULL;
    }
    //single childern :
    else if(root->left ==NULL){
        Node* temp= root;
        root=root->right;
        delete temp;
    }
    else if(root->right==NULL){
        Node* temp= root;
        root=root->left;
        delete temp;
    }
    //2 childern 
    else{
        Node* temp= findMin(root->right);
        root->key=temp->key;
        root->right=remove(root->right,temp->key);
    }
}
return root;
}
void printInoder(Node* root){
    if(root==NULL){
        return;
    }
    printInoder(root->left);
    cout<<root->key<<" ,";
    printInoder(root->right);
}

//Print in range 
void printRange(Node* root,int k1,int k2){
    if(root=NULL){
        return;
    }
    if(root->key>=k1 and root->key<=k2){
        //Call on both side
        printRange(root->left,k1,k2);
        cout<<root->key<<" ";
        printRange(root->right,k1,k2);
    }
    else if(root->key>k2){
        printRange(root->left,k1,k2);
    }
    else{
        printRange(root->right,k1,k2);
    }
}
//Print range alternative :
void solve(Node* root, int low, int high, vector<int> &ans)
    {
        if(root == NULL)
            return;
        solve(root->left,low,high,ans);
        if(root->key >= low && root->key <= high)
            ans.push_back(root->data);
        solve(root->right,low,high,ans);    
    }
vector<int> printNearNodes(Node *root, int low, int high) {
        //code here   
        vector<int> ans;
        solve(root,low,high,ans);
        return ans;
}

//Print root---leaf paths
void printRoot2Leafrpaths(Node* root,vector<int> &path){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL and root->right==NULL){
        for(int node:path){
            cout<<node<<"->";
        }
        cout<<endl;
        cout<<root->key<<" ";
        return;
    }
    path.push_back(root->key);
    printRoot2Leafrpaths(root->left,path);
    printRoot2Leafrpaths(root->right,path);
    path.pop_back();
    return;
}

//Alternative of path root---- leaf
 void solve(Node* root,vector<vector<int>>&v1,vector<int>&v)
{
   if(root==NULL)
   return;
   v.push_back(root->data);
   if(!root->left && !root->right)
   {

       v1.push_back(v);
        v.pop_back();

       return;
   }

 solve(root->left,v1,v);
 solve(root->right,v1,v);
 v.pop_back();

   return;
}
vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>>v1;
   if(root==NULL)
   return v1;
   vector<int>v;
   solve(root,v1,v);
   return v1;
}


//BST Mirro image 
void mirrorbst(Node* node)
{
    if (node == NULL)
        return;
    else
    {
        Node* newNode = new Node ;
        /* do the subtrees */
        mirrorbst(node->left);
        mirrorbst(node->right);

        /* swap the pointers in this node */
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}
void mirror(Node* node) {
        // code here 
    mirrorbst(node);
}


//Check Is BST :
bool isBSTUtil(Node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return true;
                
    /* false if this node violates
    the min/max constraint */
    if (node->key <= min || node->key>= max)
        return false;
        
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    return isBSTUtil(node->left, min, node->key) && isBSTUtil(node->right, node->key, max); 
}
bool isBST(Node* root) 
{
    // Your code here
        return isBSTUtil(root, INT_MIN,INT_MAX);
}

int main(){
    Node* root = NULL;
    int arr[]={8,3,10,1,6,14,4,7,13};
    for(int x:arr){
        root=insert(root,x);
    }
    printInoder(root);
    // int key;
    // cin>>key;
    // cout<<search(root,key)<<endl;

    // root= remove(root,key);
    // printInoder(root);

    // cout<<"Range is : "<<endl;
    // printRange(root,5,12);

// //path root to leaf 
//     vector<int> path;
//     printRoot2Leafrpaths(root,path);

// //Print mirror
//     mirror(root);
//     printInoder(root);

//Is BST?
    cout<<"This is BST : ";
    cout<<isBST(root);

    return 0;
}