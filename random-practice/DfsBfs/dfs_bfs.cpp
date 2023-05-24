#include <bits/stdc++.h>

using namespace std;
#define MAX 20

class Graph {
    int adj[MAX][MAX];
    int n;

public :
    Graph(int x) {
        n = x;
        for(int i=0; i<x; i++) {
            for(int j=0; j<x; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int a, int b) {
        adj[a][b] = 1;
        adj[b][a] = 1;
        cout<<"Edge added successfully !\n";
    }

    void show() {
        for(int i=0; i<n; i++) {
            for(int j=0; i<n; j++) {
                cout<<adj[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
     
    void dfs(int src, vector<bool>&visited) {
        visited[src] = true;
        cout<<src<<" ";
        for(int i=0; i<n; i++) {
            if((adj[src][i] == 1) && (!visited[i])) {
                dfs(i, visited);
            }
        }
    }

    void bfs(queue<int>&q, vector<bool>&visited) {
        if(q.empty()) {
            return;
        }
        int v = q.front();
        q.pop();
        cout<<v<<" ";
        for(int i=0; i<n; i++) {
            if((adj[v][i] == 1) && (!visited[i])) {
                visited[i] = true;
                q.push(i);
            }
        }
        bfs(q, visited);
    }
};

int main() {
    int a=0,b=0,c=0,d=0,e=0;
    cout<<"--------- DFS bfs code-------\n";
    cout<<"Enter the number of vertice in graph : \n";
    cin>>a;
    vector<bool> visitedDFS(a, false);
    vector<bool> visited(a, false);
    Graph g(a);


    while(true) {
        cout<<"\n=====Menu=====\n1. Add Edge\n2. Adjacency Matrix\n3. DFS\n4. BFS\nEnter choice : ";
        cin>>b;
        switch(b) {
            case 1 :
                cout<<"Enter first vertex of (0-"<<a-1<<") : ";
                cin>>c;
                cout<<"Enter second vertex of (0"<<a-1<<") : ";
                cin>>d;
                g.addEdge(c,d);
                break;
            case 2:
                g.show();
                break;
            case 3:
                for(int i=0; i<a; i++) {
                    visitedDFS[i] = false;
                } 
                cout<<"Enter source node : ";
                cin>>e;
                cout<<"DFS : \n";
                g.dfs(e, visitedDFS);
                break;
            case 4:
                for(int i=0; i<a; i++) {
                    visited[i] = false;
                }
                
                queue<int> q;
                cout<<"Enter source node : ";
                cin>>e;
                visited[e] = true;
                cout<<"BFS : \n";
                q.push(e);
                g.bfs(q, visited);
                break;
        }
    }
    return 0;
}
