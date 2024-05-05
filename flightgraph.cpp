#include<iostream>
using namespace std;

class flight{
    int n;
    string city[10];
    int a[10][10];
public:
    void DFS(int v, bool visited[]) {
        visited[v] = true;
        for (int i = 0; i < n; ++i) {
            if (a[v][i]!=0 && !visited[i]) {
                DFS(i, visited);
            }
        }
    }
    
    void getdata() {
        cout<<"Enter the number of cities:";
        cin>>n;
        cout<<"Enter the names of cities:"<<endl;
        for(int i = 1; i <= n; i++) {
            cout<<"City "<<i <<": ";
            cin>>city[i];
        }
        cout<<"Adjacency matrix representing flight paths (1 for flight exists, 0 for no flight):"<<endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout<<"Flight between "<<city[i]<<"&"<<city[j]<<"is present:";
                cin>>a[i][j];
                if(a[i][j] == 1) {
                    cout<<"Enter the time required for flight to travel the path in min: ";
                    cin>>a[i][j];
                }
            }
        }
    }
    
    void display() {
        cout<<"\nAdjacency matrix: "<<endl;
        cout<<"  ";
        for(int i = 0; i < n; ++i) {
            cout<<city[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i < n; ++i) {
            cout<<city[i]<<" ";
            for(int j = 0; j < n; ++j) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    bool isconnect() {
        bool visited[n] = {false};
        
        DFS(0, visited); 
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                return false; 
            }
        }
        return true;
    }
};

int main() {
    flight g;
    g.getdata();
    g.display();
    if(g.isconnect()) {
        cout<<"The flight path is connected";
    }
    else {
        cout<<"The flight path is not connected";
    }
    return 0;
}
