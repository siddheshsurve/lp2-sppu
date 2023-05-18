#include <iostream>
#include <vector>
using namespace std;
#define SIZE 1000

class queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public : 
    queue(int size = SIZE);
    ~queue();
    int pop();
    void push(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

queue :: queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

queue :: ~queue() {
    delete[] arr;
}

int queue :: pop() {
    if(isEmpty()) {
        cout<<"Underflow\n";
        exit(EXIT_FAILURE);
    }
    int x = arr[front];
    front = (front+1)%capacity;
    count--;
    return x;
}

 void queue :: push(int item) {
    if(isFull()) {
        cout<<"Overflow\n";
        exit(EXIT_FAILURE);
    }
    rear = (rear+1)%capacity;
    arr[rear] = item;
    count++;
}

int queue :: peek() {
    if(isEmpty()) {
        cout<<"Underflow\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

int queue :: size() {
    return count;
}

bool queue :: isEmpty() {
    return (size() == 0);
}

bool queue :: isFull() {
    return (size() == capacity);
}

void dfs(vector<vector<int>> &adjList, int src, vector<bool> &visited) {
    cout<<src<<" ";
    visited[src]=true;
    for(int i=0; i<adjList[src].size(); i++) {
        if(visited[adjList[src][i]] == false) {
            dfs(adjList, adjList[src][i], visited);
        }
    }
}

void bfs(vector<vector<int>> &adjList, int src) {
    queue next;
    next.push(src);
    int v = adjList.size();
    vector<bool> visited(v, false);
    visited[src] = true;
    while(next.isEmpty() == false) {
        int curr = next.peek();
        next.pop();
        cout<<curr<<" ";
        for(int i=0; i<adjList[src].size(); i++) {
            if(visited[adjList[src][i]] == false) {
                next.push(adjList[src][i]);
                visited[adjList[src][i]] = true;
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
    //Display bfs traversal
        cout<<"BFS traversal is: ";
        bfs(adjList, src);
        cout<<endl;
    return 0;
}