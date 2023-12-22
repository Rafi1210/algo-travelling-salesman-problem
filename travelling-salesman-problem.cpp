#include <bits/stdc++.h>
using namespace std;

struct node {
    int vertex, weight;
};
  int n, e, u, v, w;
vector<vector<int>> matrix;  // Declare matrix as a global variable
vector<struct node> ad[100] = {};
int travel = 0;
void G() {
    struct node temp;
    cout << "\nEnter weight between " << u << " and " << v << " paths : ";

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

int tsp(int dp[101][101]){

	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < ad[i].size();j++){
			 if(dp[i][j] != 0){
				return dp[i][j];
			}
			int ans = 999999;
			if(dp[i][j] == 0){
					travel = tsp(dp);
				int newans = ad[i][j].weight + travel;
				ans  = min(newans, ans);
				return dp[i][j] = ans;
			}
		}
	}
}

void printPath(int i, int j, int dp[101][101]) {
    while (j != 0 && i != j) {
        cout << i << " ";
        i = dp[i][j];
    }
    cout << i;
}


int main() {
int dp[101][101];

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
		matrix.resize(n, vector<int>(n, 0));
		memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= e; i++) {
        cout << "Enter city  " << i  << " : "  ;
        cin >> u;
        cout<< "\n";
		cout << "Enter city  " << i+1  << " : "  ;
        cin >> v;
        G();
    }
    printMatrix(n);
     cout << "\nMinimum Cost is: ";
	int res = tsp(dp);
    cout << "\n" << res;
      cout << "\nShortest Path is: ";
       printPath(1, n,dp); // Print the path starting from city 1
    return 0;
}
