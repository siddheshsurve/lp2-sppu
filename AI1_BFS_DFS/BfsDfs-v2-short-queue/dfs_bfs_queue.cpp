// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define SIZE 1000
#define MAX 20

class queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;
public: 
    queue(int size = SIZE);
    ~queue();

    int pop();
    void push(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

queue::queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

queue::~queue(){
    delete[] arr;
}

int queue::pop() {
    if(isEmpty()) {
        cout<<"UnderFlow";
        exit(EXIT_FAILURE);
    }
    int x = arr[front];
    front = (front+1)%capacity;
    count--;
    return x;
}

void queue::push(int item) {
    if(isFull()) {
        cout<<"OverFlow";
        exit(EXIT_FAILURE);
    }
    rear = (rear+1)%capacity;
    arr[rear] = item;
    count++;
}

int queue::peek() {
    if(isEmpty()) {
        cout<<"UnderFlow";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

int queue::size() {
    return count;
}

bool queue::isEmpty() {
    return(size() == 0);
}

bool queue::isFull() {
    return(size() == capacity);
}

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
            for(int j=0; j<n; j++) {
                cout<<adj[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void DFS(int src, vector<bool>&visited) {
        visited[src] = true;
        cout<<src<<" ";
        for(int i=0; i<n; i++) {
            if((adj[src][i]) == 1 && (!visited[i])) {
                DFS(i, visited);
            }
        } 
    }

    void BFS(queue &q, vector<bool>&visited) {
        if(q.isEmpty()) {
            return;
        }
        int v = q.peek();
        q.pop();
        cout<<v<<" ";
        for(int i=0; i<n; i++) {
            if((adj[v][i]) == 1 && (!visited[i])) {
                visited[i] = true;
                q.push(i);
            }
        }
        BFS(q, visited);
    }
};

int main() {
    cout<<"= = = = DFS BFS of GRAPH = = = =\n";
    int a,b,c,d,e;
    cout<<"Enter no of vertex : ";
    cin>>a;
    vector<bool> visitedDFS(a, false);
    vector<bool> visited(a, false);
    Graph g(a);
    queue q;

    while(true) {
        cout<<"\n= = = MENU = = =\n1. Add Edge\n2. Adjacency Matrix\n3. DFS\n4. BFS\nEnter choice : ";
        cin>>b;
        switch(b) {
            case 1 :
                cout<<"Enter first vertex : ";
                cin>>c;
                cout<<"Enter second vertex : ";
                cin>>d;
                g.addEdge(c,d);
                break;
            case 2 :
                g.show();
                break;
            case 3 :
                for(int i=0;i<a; i++) {
                    visitedDFS[i] = false;
                }
                cout<<"Enter source node : ";
                cin>>e;
                cout<<"DFS : \n";
                g.DFS(e, visitedDFS);
                break;
            case 4 :
                for(int i=0; i<a; i++) {
                    visited[i] = false;
                }

                cout<<"Enter source node : ";
                cin>>e;
                visited[e] = true;
                q.push(e);
                g.BFS(q, visited);
                break;
        }
    }
    return 0;
}