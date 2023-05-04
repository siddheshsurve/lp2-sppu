#include <iostream>
#include <vector>
// #include <queue>
using namespace std;

// Define the default capacity of a queue
#define SIZE 1000
 
// A class to store a queue
class queue
{
    int *arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue
 
public:
    queue(int size = SIZE);     // constructor
    ~queue();                   // destructor
 
    int pop();
    void push(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};
 
// Constructor to initialize a queue
queue::queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
 
// Destructor to free memory allocated to the queue
queue::~queue() {
    delete[] arr;
}
 
// Utility function to pop the front element
int queue::pop()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    int x = arr[front];
    // cout << "Removing " << x << endl;
    // cout<<x<<endl;
 
    front = (front + 1) % capacity;
    count--;
 
    return x;
}
 
// Utility function to add an item to the queue
void queue::push(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    // cout << "Inserting " << item << endl;
    // cout<<item<<endl;
 
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
 
// Utility function to return the front element of the queue
int queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
 
// Utility function to return the size of the queue
int queue::size() {
    return count;
}
 
// Utility function to check if the queue is empty or not
bool queue::isEmpty() {
    return (size() == 0);
}
 
// Utility function to check if the queue is full or not
bool queue::isFull() {
    return (size() == capacity);
}

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
    queue next;
    vector<bool> visited(v, false);
    next.push(src);
    visited[src]=true;
    while(next.isEmpty()==false) {
        int curr=next.peek();
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