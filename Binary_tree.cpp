#include<iostream>
#include<queue>
using namespace std;

// // input:  1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1
// // preorder: 1 2 4 5 7 3 6 
// // inoder: 4 2 7 5 1 3 6
// //postorder: 4  7 5 2 6 3 1 
//// level ord: 
// 1
// 2 4
// 5 7
// 3
// 6
class node{

public:
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=right=NULL;
    }
};
node* buildtree(){
    int d;
    cin>>d;
    if(d==1){
        return NULL;
    }
    node* n =new node(d);
    n->left=buildtree();
    n->right=buildtree();
    return n;
}
void printpreorder(node* root){
    if(root==NULL){
        return;
    }
    cout<< root->data <<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
void printInoder(node* root){
    if(root==NULL){
        return;
    }
    printInoder(root->left);
    cout<<root->data<<" ";
    printInoder(root->right);

}

//Print level order :
// 1
// 2 3
// 4 5 6
// 7
void levelOrderPrint(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp=q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            //insert a new null for the next level:
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<< temp->data <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}
node* levelOrderBuild(){
    int d;
    cin>>d;
    node* root= new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* current= q.front();
        q.pop();
        int c1,c2;
        cin>> c1 >> c2;
        if(c1!=-1){
            current->left= new node(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right=new node(c2);
            q.push(current->right);
        }
    }
    return root;
}
//O(N)
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    return 1 + max(h1,h2);
}
// vector<int> printKthLevel(node* root, int k){
//     queue<node*> q;
//     q.push(root); 
//     vector<int> s;

//     int level=0;
//     int flag=0;

//     while(!q.empty()){
//         int size=q.size();

//         while(size--){
//             node* p=q.front();
//             q.pop();

//             if(level==k){
//                 flag =1 ;
//                 s.push_back(p->data);
//             }
//             else{
//                 if(root->left){
//                     q.push(root->left);
//                 }
//                 if(root->right){
//                     q.push(root->right);
//                 }
//             }
//         }
//         level++;
//         if (flag == 1){
//             break;
//         }
//     }
//     return s;
// }

vector<int> printKthLevel(node* root, int k){
queue <node *> q;
vector <int> ans;
int count = -1;
q.push(root);
q.push(NULL);
while(k!=count){
    node * temp;
    temp =  q.front();
//need to check if it is not NULL
if(count + 1 == k && temp!=NULL){
        ans.push_back(temp -> data);
    }
    if(temp == NULL){
        count++;
        q.pop();
        q.push(NULL);
    }
    else{//check before pushing if child exist or not
        if(temp -> left!=NULL){
            q.push(temp -> left);
        }
        if(temp -> right!=NULL){
            q.push(temp -> right);
        }
        q.pop();
    }
}
return ans;
}

//Tc: O(N^2)
int diameterBt(node*root){
    if(root==NULL){
        return 0;
    }
    int d1= height(root->left) + height(root->right);
    int d2= diameterBt(root->left);
    int d3=diameterBt(root->right);

    return max(d1,max(d2,d3));
}
//efficent :
//TC: O(N)
class HDpair{
    public:
        int height;
        int diameter;
};
HDpair optDiameter(node* root){
    HDpair p;
    if(root=NULL){
        p.height=p.diameter=0;
        return p;
    }
    HDpair left=optDiameter(root->left);
    HDpair right=optDiameter(root->right);

    p.height= max(left.height,right.height) +1;
    int D1=left.height + right.height;
    int D2=left.diameter ;
    int D3=right.diameter;

    p.diameter=max(D1,max(D2,D3));
    return p;

}
// diameter : function use 
//O(N)
    int diameter_nopair(Node* root) {
        // Your code here
        int maxD = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* t = q.front();
            q.pop();
            
            if(t->left)q.push(t->left);
            if(t->right)q.push(t->right);
            maxD = max(height(t->left)+height(t->right)+1,maxD);
        }
        return maxD;
    }
int main(){
    // node* root=buildtree();
    // printpreorder(root);
    // cout<<endl;

    // printInoder(root);
    // cout<<endl;
    node* root = levelOrderBuild();
    levelOrderPrint(root);
    cout<<endl;
    cout<<"The height of tree : "<<  height(root);

    int k = 2;
    vector<int> output = printKthLevel(root, k);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }

    cout<<"the diameter is :"<< diameterBt(root);
    cout<<"Optimised diameter is"<< optDiameter(root).diameter <<endl;
    return 0;
}

