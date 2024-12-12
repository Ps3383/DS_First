#pragma once
#include<iostream>
using namespace std;

template < class T >
class myQueue {
private:
    int front, rear, capacity;
    T** queue;
public:
    myQueue(int capa );
    ~myQueue();
    bool isEmpty();
    T& Front();            
    T& Rear();            
    void Push(T& item);    
    void Pop();           
    void Display();
};

template<class T>
myQueue<T>::myQueue(int capa ) {
    capacity = capa;
    queue = new T *[capacity];
    front = rear = 0;
}

template<class T>
myQueue<T>::~myQueue() {
    for (int i = 0; i < capacity; ++i) {
        delete queue[i]; 
    }
    delete[] queue; 
}

template<class T>
bool myQueue<T>::isEmpty() {
    return front == rear;
}

template<class T>
T& myQueue<T>::Front() {
    if (!isEmpty())
        return *queue[(front + 1) % capacity];
    else
        throw "queue is empty";
}

template<class T>
T& myQueue<T>::Rear() {
    if (!isEmpty())
        return *queue[rear];
    else
        throw "queue is empty";
}

template<class T>
void myQueue<T>::Push(T& item) {
    if ((rear + 1) % capacity == front) {
        T** newqueue = new T *[2 * capacity];
        int start = (front + 1) % capacity;

        if (start < 2) {
            copy(queue + start, queue + start + capacity - 1, newqueue);
        }
        else {
            copy(queue + start, queue + capacity, newqueue);
            copy(queue, queue + rear + 1, newqueue + capacity - start);
        }

        front = capacity * 2 - 1;
        rear = capacity - 2;
        capacity = capacity * 2;
        delete[] queue;
        queue = newqueue;
    }
    rear = (rear + 1) % capacity;
    queue[rear] = new T(item);
}

template<class T>
void myQueue<T>::Pop() {
    if (!isEmpty()) {
        int frontIndex = (front + 1) % capacity;
        delete queue[frontIndex]; 
        queue[frontIndex] = nullptr;
        front = frontIndex;
    }
    else
        throw "queue is empty";
}

template<class T>
void myQueue<T>::Display() {
    if (isEmpty()) {
        cout << "Queue is empty\n\n";
        return;
    }
    cout << "Queue elements: ";
    int i = (front + 1) % capacity;
    while (i != (rear + 1) % capacity) { 
        cout << *queue[i] << " ";  
        i = (i + 1) % capacity;
    }
    cout << endl;
}

