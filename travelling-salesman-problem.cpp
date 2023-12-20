#include <iostream>
#include <vector>
using namespace std;

struct node {
    int vertex, weight;
};

vector<struct node> ad[100] = {};

void G(int u, int v, int w) {
    struct node temp;
    cout << "Enter weight between " << u << " and " << v << " paths : ";
    cin >> w;

        temp.vertex = v;
        temp.weight = w;
        ad[u].push_back(temp);

        temp.vertex = u;  // Reverse the direction for an undirected graph
        ad[v].push_back(temp);
}

void printMatrix(int n){
    vector<vector<int>> matrix(n, vector<int>(n, 0)); //Initialize matrix with zero
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < ad[i].size(); j++) {
            int v = ad[i][j].vertex;
            int weight = ad[i][j].weight;
            matrix[i - 1][v - 1] = weight;
            matrix[v - 1][i - 1] = weight;  //An undirected graph so same weight in both index
        }
    }
    // Print the matrix
    cout << "\nAdjacency Matrix Path Weight Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t\t";
        }
        cout << endl;
    }
}

int main() {
    int n, e, u, v, w;

    cout << "Enter number cities and paths : ";
    cin >> n >> e;

    for (int i = 1; i <= e; i++) {
        cout << "Enter cities between path : "  ;
        cin >> u >> v;
        G(u, v, w);
    }
    printMatrix(n);


    return 0;
}
