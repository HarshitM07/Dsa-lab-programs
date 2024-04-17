#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

template <typename T>
class graph {
public:
    unordered_map<T, list<T>> adjList;

    // Function to add an edge to the graph
    void addEdge(T u, T v, bool direction) {
        adjList[u].push_back(v);
        if (!direction) {  // If undirected
            adjList[v].push_back(u);
        }
    }

    // Function to print the graph
    void print() {
        for (auto i : adjList) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    // Function to transpose the graph using adjacency list
    graph<T> transposeList() {
        graph<T> transposedGraph;
        for (auto i : adjList) {
            for (auto j : i.second) {
                transposedGraph.addEdge(j, i.first, 1);
            }
        }
        return transposedGraph;
    }

    // Function to transpose the graph using adjacency matrix
    vector<vector<bool>> transposeMatrix() {
        vector<vector<bool>> adjMatrix(adjList.size(), vector<bool>(adjList.size(), false));

        // Populate the adjacency matrix
        int index = 0;
        unordered_map<T, int> vertexToIndex;
        for (auto i : adjList) {
            vertexToIndex[i.first] = index++;
        }
        for (auto i : adjList) {
            int uIndex = vertexToIndex[i.first];
            for (auto j : i.second) {
                int vIndex = vertexToIndex[j];
                adjMatrix[vIndex][uIndex] = true;
            }
        }

        return adjMatrix;
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    graph<int> g;
    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1); // Assuming all edges are directed
    }

    // Print original graph
    cout << "Original Graph:" << endl;
    g.print();

    // Transpose using adjacency list
    cout << "Transpose Graph (Adjacency List):" << endl;
    graph<int> transposedList = g.transposeList();
    transposedList.print();

    // Transpose using adjacency matrix
    cout << "Transpose Graph (Adjacency Matrix):" << endl;
    vector<vector<bool>> transposedMatrix = g.transposeMatrix();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
