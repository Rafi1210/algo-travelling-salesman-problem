#include <bits/stdc++.h>
#define MAX_N 15
const int INF = 987654321;
using namespace std;

int ShortestTSP(vector<vector<int> > graph) {
    int ans = INF;
    int n = graph.size();       //size of graph
    int dp[1<<MAX_N][MAX_N];    //dp[i][j]=min distance of path ending at city-j using only cities in bitmask of int
                                //bitmask of 7 represent set of cities {1,2,8} since binary(7)=1011
    memset(dp, INF, sizeof(dp));
    int mask, dist;
    //base case
    for (int i=0; i<n;i++) dp[1<<i][i]=0;

    //dp
    for (int i=0; i<mask; i++) {
        for (int last = 0; last < n; last++) {      //we see all paths ending at city-last
            if (mask & (1<<last) == 0) continue;    //present mask, doesn't has city-last
            for (int cur = 0; cur < n; cur++) {
                if (mask & (1<<cur) == 0) continue;
                int prev_mask = mask ^ (1<<cur);
                dp[mask][cur] = min(dp[mask][cur] , dp[prev_mask][last] + dist[last][cur]);
            }
        }
    }

    for (int i = 0; i < n; i++) ans = min(ans , dp[(1<<n)-1][i]);

    return ans;
}

int main() {
    // Example usage:
    vector<vector<int>> graph = {
        {0, 2, 0, 12,5},
        {2, 0, 4, 8,0},
        {0, 4, 0, 3,3},
        {12, 8, 3,10, 0},
        {5,0,3,10,0}
    };

    int result = ShortestTSP(graph);
    cout << "Shortest TSP distance: " << result << endl;

    return 0;
}
