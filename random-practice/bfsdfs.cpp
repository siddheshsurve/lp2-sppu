#include <iostream>
#include <vector>
using namespace std;
#define SIZE 1000

using namespace std;

class queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;
public :
    queue(int size=SIZE);
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
    if(isEmpty()){
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

int queue::peek() {
    if(isEmpty()){
        cout<<"Underflow\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

int queue::size(){
    return count;
}

bool queue::isEmpty() {
    return (size() == 0);
}

bool queue::isFull() {
    return (size() == capacity);
}

