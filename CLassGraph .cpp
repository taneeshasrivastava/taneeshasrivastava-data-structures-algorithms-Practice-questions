#include<iostream>
#include<map>
#include<cstring>
#include<vector>
#include<list>
#include<climits>
#include<set>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        V=v;
        l=new list<int>[V];
    }


    void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

//Dijkshtra's Algorithm
    void addEge(int u ,int v, int wt , bool undir=true){
        l[u].push_back(make_pair(wt,v));
        if(undir){
            l[v].push_back(make_pair(wt,u));
        }
    }
    int dijkastra(int src,int dist){
        //Data Structre 
        vector<int> dis(V,INT_MAX);
        set<pair<int,int> > s;

        //1. Init
        dist[src]=0;
        s.insert({0,src});

        while(!s.empty()){
            auto it= s.begin();
            int node= it->second;
            int distTillNow = it->first;
            s.erase(it);//pop

            for(auto nbrpair:l[node]){
            // Remove such a pair already exisiting 

                int nbr= nbrpair.second;
                int currEdge= nbrpair.first;

                if(distTillNow + currEdge <dist[nbr]){
                    
                    //Remove if nbr is present in the set  alrady 
                    auto f=s.find({dist[nbr],nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    //Insert the updated value with the new distance
                    dist[nbr]=distTillNow+currEdge;
                    s.insert(make_pair(dist[nbr],nbr));
                }
            }
        }
        //Singel source shortest distance to all other nodes
        for(int i=0;i<V;i++){
            cout<<"Node i "<<i <<"Dist  "<<dist[i]<<endl;
        }
        return dist[dist];
    }



//Directed Acyclic graph for tropological sort : Khan's algorithm 
void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
    }
//Tropological sort :
    void tropologicalSort(){
        vector<int> indegree(V,0);
        //iterate over all the edge to find the right indegree 
        for(int i = 0; i<V;i++){
            for(auto nbr: l[i]){
                indegree[nbr]++;
            }
        }
        //bfs
        queue<int> q;
        //init the q with nodes having 0 indegree 
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //start poping 
        while(!q.empty()){
            int node = q.front();
            cout<< node<<" ";
            q.pop();
        //Iterate ever the node of this node and reduces their indergree by 1 
            for(auto nbr: l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }



    BFS altertivve  :
    vector<int> bfs;
        vector<int> vis(V,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
         return bfs; 

    void bfs(int source){
        queue<int> q;
        bool *visited =new bool[V]{0};

        q.push(source);
        visited[source]=true;

        while(!q.empty()){
            int f= q.front();
            q.pop();
            cout<<f <<endl;

            for(auto nbr: l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]= true;
                }
            }
        }
    }


    //DFS altern
        vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> bfs;
        vector<int> vis(V,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return bfs; 
        
    }


    void dfshelper(int node,bool *visited){
        visited[node]=true;
        cout<<node<<",";
        for(int nbr: l[node]){
            if(!visited[nbr]){
                dfshelper(nbr,visited);
            }
        }
        return ;
    }
    void DFS(int source){
        bool *visited = new bool[V]{0};
        dfshelper(source,visited);
    }




    ////ADjeency list print
    // void printAdjList(){
    //         for(int i=0;i<V;i++){
    //             cout<<i<<"-->";
    //         for(auto node : l[i]){
    //             cout<<node<<" ,";
    //         } 
    //         cout<<endl;
    //     }
    
    // }
};

int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);


    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.tropologicalSort();


    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);

    cout<<g.dijkastra(0,4)<<endl;
    g.DFS(1);
    g.printAdjList();


    return 0;
}
