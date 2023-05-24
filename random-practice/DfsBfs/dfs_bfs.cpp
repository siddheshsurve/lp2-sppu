#include <bits/std++.h>
using namespace std;

#define size 1000

class queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;
public :
    queue(size = SIZE);
    ~queue()

    int pop();
    void push(int x);
    int front();
    int size();
    bool empty();
    bool full();
}

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
    if(empty()) {
        cout<<"UnderFlow\n";
    }
    int x = arr[front];
    front = (front+1)%capacity;
    count--;
    return x;
}

void queue :: push(int item) {
    if(full()) {
        cout<<"OverFlow\n";
    }
    rear = (rear+1)%capacity;
    arr[rear] = item;
    count++;
}

int queue :: front() {
    if(empty()) {
        cout<<"UnderFlow\n";
    } 
    return arr[front];
}

int queue :: size() {
    return count;
}

bool queue :: empty() {
    return(size() == 0)
}

bool queue :: full() {
    return(size() == capacity)
}

