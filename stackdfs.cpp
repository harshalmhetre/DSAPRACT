#include <iostream>
#include <stack>
using namespace std;

class Graph {
private:
    int nodes;
    int graph[10][10];

public:
    // Constructor
    Graph(int n) : nodes(n) {
        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                graph[i][j] = 0;
            }
        }
    }

    // Function to get graph data from user
    void getData() {
        cout << "Enter the connections between nodes (1 for connected, 0 for not connected):\n";
        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                cout << "Is there a connection from node " << i << " to node " << j << "? ";
                cin >> graph[i][j];
            }
        }
    }

    // Function to display the graph in matrix form
    void displayGraph() {
        cout << "Graph represented as an adjacency matrix:\n";
        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Recursive DFS function
    void recursiveDFS(int start, bool visited[]) {
        visited[start] = true;
        cout << start << " ";

        for (int neighbor = 0; neighbor < nodes; ++neighbor) {
            if (graph[start][neighbor] == 1 && !visited[neighbor]) {
                recursiveDFS(neighbor, visited);
            }
        }
    }

    // Non-Recursive DFS function
    void nonRecursiveDFS(int start) {
        bool visited[nodes] = {false};
        stack<int> stack;

        stack.push(start);
        visited[start] = true;

        while (!stack.empty()) {
            int vertex = stack.top();
            stack.pop();
            cout << vertex << " ";

            for (int neighbor = 0; neighbor < nodes; ++neighbor) {
                if (graph[vertex][neighbor] == 1 && !visited[neighbor]) {
                    stack.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main() {
    int nodes;

    // Taking input for the number of nodes
    cout << "Enter the number of nodes in the graph: ";
    cin >> nodes;

    Graph g(nodes);

    // Getting graph data from user
    g.getData();

    // Displaying the graph
    g.displayGraph();

    cout << "Enter the starting node for DFS traversal: ";
    int start;
    cin >> start;

    cout << "Recursive DFS traversal: ";
    bool visited[nodes] = {false};
    g.recursiveDFS(start, visited);
    cout << endl;

    cout << "Non-Recursive DFS traversal: ";
    g.nonRecursiveDFS(start);
    cout << endl;

    return 0;
}
