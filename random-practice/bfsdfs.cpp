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
    queue(int size=SIZE);
    ~queue();
    int pop();
    void push(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

queue :: queue {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    capacity = 0;
}

int main () {

}