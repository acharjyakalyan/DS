#include<iostream>
#include<cstdlib>
#include "linkedlist.hpp"
using namespace std;

linkedlist::linkedlist() {
    Head = NULL;
    Tail = NULL;
    size = 0;
}

linkedlist::linkedlist(int data) {
    Head = (Node*)malloc(sizeof(Node));
    Tail = Head;
    Head->data = data;
    Head->next = NULL;
    size = 1;
}

linkedlist::~linkedlist() {
    Node* current = Head;
    while (current) {
        Head = current->next;
        delete current;
        current = Head;
    }
    Head = NULL;
    Tail = NULL;
    size = 0;
}

int linkedlist::insert_beg(int data) {
    Node* current = (Node*)malloc(sizeof(Node));
    if (current == NULL) return 1;

    current->data = data;
    current->next = Head;
    Head = current;
    return 0;
}

int linkedlist::insert_end(int data) {
    Node* current = (Node*)malloc(sizeof(Node));
    if (current == NULL) return 1;

    Tail->next = current;
    Tail = current;
    current->next = NULL;
    current->data = data;

    return 0;
}

int linkedlist::del_beg() {
    Node* current = Head;
    if (Head == Tail) Tail = NULL;
    Head = current->next;
    delete current;
    return 0;
}

int linkedlist::show() {
    Node* current = Head;
    cout << "Head";
    while (current) {
        cout << "->" << current->data;
        current = current->next;
    }
    cout << "->NULL" << endl;
    return 0;
}

int linkedlist::is_empty() {
    return Head == NULL;
}
