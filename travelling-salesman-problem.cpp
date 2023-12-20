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
         		cout<< "\n__________________________________________________\n";
				cout<< "\n__________________________________________________\n";


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
			cout << "|\t";
        for (int j = 0; j < n; j++) {
            cout <<matrix[i][j] << "\t|\t\t";
        }
		        cout<< "\n___________________________________________________________________________________________________________________\n";

        cout << endl;
    }
}

int main() {
    int n, e, u, v, w;
        cout<< "\t\t _______________________________________________________________________\n";
        cout<< "\t\t|\t\t\t\t\t\t\t\t\t|\n";
		cout << "\t\t|\t\t Welcome to Travelling Salesman Problem\t\t\t|\n";
		cout<< "\t\t|_______________________________________________________________________|\n\n";
		cout<< "__________________________________________________\n";
		cout << "Enter number of cities : ";
		cin >> n;
		cout<< "__________________________________________________\n";
        cout << "Enter number of paths : ";
        cin >> e;
		cout<< "__________________________________________________\n";


    for (int i = 1; i <= e; i++) {
        cout << "Enter city  " << i  << " : "  ;

        cin >> u;
        	cout<< "\n__________________________________________________\n";
         cout << "Enter city  " << i+1  << " : "  ;
        cin >> v;
                 		cout<< "\n__________________________________________________\n";

        G(u, v, w);
    }
    printMatrix(n);


    return 0;
}
