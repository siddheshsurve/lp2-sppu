#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

void dfs(vector<vector<int>> &adjList, int src, vector<bool> &visited) {
    cout<<src<<" ";
    visited[src]=true;
    for(int i=0; i<adjList[src].size(); i++) {
        if(visited[adjList[src][i]]==false) {
            dfs(adjList, adjList[src][i], visited);
        }
    }
}

void bfs(vector<vector<int>> &adjList, int src) {
    int v=adjList.size();
    queue<int> next;
    vector<bool> visited(v, false);
    next.push(src);
    visited[src]=true;
    while(next.empty()==false) {
        int curr=next.front();
        next.pop();
        cout<<curr<<" ";
        for(int i=0; i<adjList[curr].size(); i++) {
            if(visited[adjList[curr][i]]==false) {
                next.push(adjList[curr][i]);
                visited[adjList[curr][i]]=true;
            }
        }
    }
}
int main()
{
    int v, e;
    // Create a graph and initialize it 
        cout<<"Enter the number of vertices in your graph: ";
        cin>>v;
        vector<vector<int>> adjList(v);
        cout<<"Enter the number of edges: ";
        cin>>e;
        cout<<"Enter end vertices of each edges one by one below: "<<endl;
        for(int i=0; i<e; i++) {
            int v1, v2;
            cout<<"edge "<<i<<": ";
            cin>>v1>>v2;
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        
    // get the source node for dfs and bfs traversal
        int src;
        cout<<"Enter the source node: ";
        cin>>src;
    // Display dfs traversal
    vector<bool> visited(v, false);
        cout<<"DFS traversal is: ";
        dfs(adjList, src, visited);
        cout<<endl;
    // Display bfs traversal
        cout<<"BFS traversal is: ";
        bfs(adjList, src);
        cout<<endl;
    return 0;
}


