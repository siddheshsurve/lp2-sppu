#include <iostream>
#include <vector>
using namespace std;

int min_key(int key[], bool visited[], int V) {
    int min = 999, min_idx;
    for(int i=0; i<V; i++) {
        if(visited[i] == false && key[i]<min) {
            min = key[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void printMst(int parent[], vector<vector<int>> cost, int V) {
    int minCost = 0;
    cout<<"Edge\tWeight\n";
    for(int i=1; i<V; i++) {
        cout<<parent[i]<<" - "<<i<<"\t"<<cost[i][parent[i]]<<"\n";
        minCost+=cost[i][parent[i]];
    }
    cout<<"Minimum cost is "<<minCost;
}

void findMST(vector<vector<int>> cost, int V) {
    int parent[V], key[V];
    bool visited[V];

    for(int i=0; i<V; i++) {
        key[i] = 999;
        parent[i] = -1;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int x=0; x<V-1; x++) {
        int u = min_key(key, visited, V);
        visited[u] = true;
        for(int v=0; v<V; v++) {
            if(cost[u][v] != 0 && visited[v] == false && cost[u][v]<key[v]) {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }
    printMst(parent, cost, V);
}

int main() {
    cout<<"= = = = = PRIMS MST = = = = =\n";
    cout<<"Enter no of vertices in your graph : ";
    int V;
    cin>>V;

    vector<vector<int>> cost(V, vector<int>(V, 0));

    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            int a;
            cin>>a;
            cost[i][j] = a;
        }
    }

    findMST(cost, V);
}