#include <bits/stdc++.h>
using namespace std;

int main(){
    // NON DIRECTED GRAPHS
    #if 0
    // graph stored in a matrix
    int n, m;
    cin >> n >> m;
    int adj[n+1][m+1];
    for(int i = 0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    time complexity = 0(n*n)
    #endif

    int n, m;
    cin >> n >> m;
    vector <int> adj[n+1];
    for(int i = 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // THIS LINE U WOULD COMMENT FOR DIRECTED GRAPH and TC would be 0(E)
    }
    // time complexity = 0(2E) where E stands for Edges
    return 0;
}