#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
#include<iostream>
using namespace std;

class ListEmpty : public runtime_error{
public:
    ListEmpty(const string & err) : runtime_error(err) {}
};


template< typename T >
class Node {
public:
    T data;
    Node* next;
    Node* pre;
    Node(T val) {
        data = val;
        next = nullptr;
        pre = nullptr;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    bool empty() const;
    const T& front() const;
    const T& back() const;
    const T& index(int h)const;
    void push_front(const T& e);
    void push_back(const T& e);
    void pop_front();
    void pop_back();
    void erase_index(int h) const;
    void display();
    int  size_of_list() const;
};

template <typename T>
bool LinkedList<T>::empty()const {
    if (head == nullptr) {
        return true;
    }
    return false;
}

template <typename T>
const T& LinkedList<T>::front() const {
    if (empty()) {
        throw ListEmpty("empty list!");
    }
    return head->data;
}

template <typename T>
const T& LinkedList<T>::back() const {
    if (empty()) {
        throw ListEmpty("empty list!");
    }
    return tail->data;
}

template <typename T>
const T& LinkedList<T>::index(int h) const {
    if (empty()) {
        throw ListEmpty("empty list!");
    } 
        Node<T>* temp = head;
        for (int k = 0; k < h; ++k) {
            temp = temp->next;
        }
        return temp->data; 
}

template <typename T>
void LinkedList<T>::erase_index(int key) const {

    Node <T>* curr = head;
    int g = key - 1;
    while (g > 0) {
        curr = curr->next;
        --g;
    }

    if (curr == nullptr || curr->next == nullptr)
        return;

    Node <T>* nodeDelete = curr->next;
    curr->next = nodeDelete->next;

    if (nodeDelete->next != nullptr) {
        nodeDelete->next->pre = curr;
    }
    delete nodeDelete;
}

template <typename T>
int LinkedList<T>::size_of_list() const {
    Node<T>* temp = head;
    int count = 0;
    if (head == nullptr)
        return 0;
    while (temp != nullptr) {
        ++count;
        temp = temp->next;
    }
    return count;
}

template <typename T>
void LinkedList<T>::push_front(const T& e) {
    Node<T>* newnode = new Node<T>(e);
    if (empty()) {
        head = newnode;
        tail = newnode;
        newnode->next = nullptr;
        newnode->pre = nullptr;
    }
    else {
        newnode->next = head;
        head->pre = newnode;
        newnode->pre = nullptr;
        head = newnode;
    }
}

template <typename T>
void LinkedList<T>::push_back(const T& e) {
    Node<T>* newnode = new Node<T>(e);
    if (empty()) {
        head = newnode;
        tail = newnode;
        newnode->next = nullptr;
        newnode->pre = nullptr;
    }
    else {
        tail->next = newnode;
        newnode->pre = tail;
        tail = newnode;
    }
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (empty()) {
        throw ListEmpty("empty list!");
    }
    else {
        Node<T>* temp = head;
        head = head->next;
        if (head) {
            head->pre = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (empty()) {
        throw ListEmpty("empty list!");
    }
    else {
        Node<T>* temp = tail;
        tail = tail->pre;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::display() {
    if (empty()) {
        throw ListEmpty("empty list!");
    }
    else {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next) {
                cout << " ";
            }
            temp = temp->next;
        }
    }
    cout << endl;
}
#endif