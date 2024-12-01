//#include "LinkList.h"
//
//template <typename T>
//bool LinkedList<T>::empty()const {
//    if (head == nullptr) {
//        return true;
//    }
//    return false;
//}
//
//template <typename T>
//const T& LinkedList<T>::front() const {
//    if (empty()) {
//        throw ListEmpty("empty list!");
//    }
//    return head->data;
//}
//
//template <typename T>
//const T& LinkedList<T>::back() const {
//    if (empty()) {
//        throw ListEmpty("empty list!");
//    }
//    return tail->data;
//}
//
//template <typename T>
//int LinkedList<T>::size_of_list() const {
//    Node<T>* temp = head;
//    int count = 0;
//    if (head == nullptr)
//        return 0;
//    while (temp != nullptr) {
//        ++count;
//        temp = temp->next;
//    }
//    return count;
//}
//
//template <typename T>
//void LinkedList<T>::push_front(const T& e) {
//    Node<T>* newnode = new Node<T>(e);
//    if (empty()) {
//        head = newnode;
//        tail = newnode;
//        newnode->next = nullptr;
//        newnode->pre = nullptr;
//    }
//    else {
//        newnode->next = head;
//        head->pre = newnode;
//        newnode->pre = nullptr;
//        head = newnode;
//    }
//}
//
//template <typename T>
//void LinkedList<T>::push_back(const T& e) {
//    Node<T>* newnode = new Node<T>(e);
//    if (empty()) {
//        head = newnode;
//        tail = newnode;
//        newnode->next = nullptr;
//        newnode->pre = nullptr;
//    }
//    else {
//        tail->next = newnode;
//        newnode->pre = tail;
//        tail = newnode;
//    }
//}
//
//template <typename T>
//void LinkedList<T>::pop_front() {
//    if (empty()) {
//        throw ListEmpty("empty list!");
//    }
//    else {
//        Node<T>* temp = head;
//        head = head->next;
//        if (head) {
//            head->pre = nullptr;
//        }
//        else {
//            tail = nullptr;
//        }
//        delete temp;
//    }
//}
//
//template <typename T>
//void LinkedList<T>::pop_back() {
//    if (empty()) {
//        throw ListEmpty("empty list!");
//    }
//    else {
//        Node<T>* temp = tail;
//        tail = tail->pre;
//        if (tail) {
//            tail->next = nullptr;
//        }
//        else {
//            head = nullptr;
//        }
//        delete temp;
//    }
//}
//
//template <typename T>
//void LinkedList<T>::display() {
//    if (empty()) {
//        throw ListEmpty("empty list!");
//    }
//    else {
//        Node<T>* temp = head;
//        while (temp != nullptr) {
//            cout << temp->data;
//            if (temp->next) {
//                cout << " ";
//            }
//            temp = temp->next;
//        }
//    }
//    cout << endl;
//}