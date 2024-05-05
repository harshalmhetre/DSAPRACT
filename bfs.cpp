#include <iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Graph {
    private:
    int nodes;
    Node** adjlist;

    public:
    Graph(int n){
        nodes=n;
        adjlist= new Node*[nodes] {nullptr};

    }

    ~Graph(){
        for(int i=0 ; i<nodes ;++i){
            Node* current=adjlist[i];
            while(current!=nullptr){
                Node* temp=current;
                current=current->next;
                delete temp;
            }
        }
        delete[] adjlist;
    }

    void addedge(int u, int v){
        Node* nn= new Node;
        nn->data=v;
        nn->next=adjlist[u];
        adjlist[u]=nn;

        nn=new Node;
        nn->data=u;
        nn->next=adjlist[v];
        adjlist[v]=nn;

    }

    void Display(){
        cout<<"Graph as Adjacency List ";
        for(int i=0 ; i<nodes ;++i){
            cout<<i<<"-->";
            Node* current=adjlist[i];
            while(current!=nullptr){
                cout<<current->data<<" ";
                current=current->next;
            }
            cout<<endl;
    }
    }

    void BFS(int start){
        bool visited[nodes] {false};
        queue <int> q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int current =q.front();
            q.pop();
            cout<<current<<" ";
            Node* child =adjlist[current];
            while(child!=nullptr){
                if(!visited[child->data]){
                    q.push(child->data);
                    visited[child->data]= true;
                }
                child=child->next;
            }
        }   
        delete[] visited;
    }
};

int main(){

    int nodes , start ,edges;

    cout<<"Enter the no. of the nodes and edges :";
    cin>>nodes>>edges;

    Graph g(nodes);

    for(int i=0; i<edges ;++i){
        int u,v;
        cout<<"Enter edges from u to v form";
        cin>>u>>v;
        g.addedge(u,v);
    }

    g.Display();
    cout<<"Enter the start node for BFS transversal of graph:";
    cin>>start;
    cout<<"BFS transversal of the graph ";
    g.BFS(start);

    return 0;
}