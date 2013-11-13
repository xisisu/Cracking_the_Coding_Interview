#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node(int d) { data = d; next = NULL; };
    void SetData(int aData) { data = aData; };
    void SetNext(Node *aNext) { next = aNext; };
    Node *Next() { return next; };
    int Data() { return data; };
};

// List class
class List {
    Node *head;
    
public:
    List() { head = NULL; };
    
    Node *Head() { return head; };
    void SetHead(Node *aHead) { head = aHead; };
    void Init(int size, int range);
    void Append(int d);
    void AppendHead(int d);
    void Delete(int d);
    void toString();
};

void List::Init(int size, int range)
{
    if (head != NULL) { 
    	cout << "List already exist!\n"; 
    	return; 
    }
   
    srand(time(NULL));
    
    head = new Node(rand()%range+1);
    Node *tmp = head;

    for (int i = 1; i < size; i++) {
        Node *newNode = new Node(rand()%range+1);
        tmp->SetNext(newNode); 
        tmp = newNode;
    }
}

void List::Append(int d)
{
    Node *newNode = new Node(d);
    
    if (head == NULL) {
    	head = newNode;
    } else {
    	Node *tmp = head;
    	while (tmp->Next() != NULL) { tmp = tmp->Next(); }
        tmp->SetNext(newNode);
    }
}

void List::AppendHead(int d)
{
    Node *newNode = new Node(d);

    newNode->SetNext(head);
    head = newNode;
}

void List::Delete(int d)
{
    if (head == NULL) { cout << "List empty!\n"; return; }
        
    Node *tmp = head;
    
    if (tmp->Data() == d) { head = tmp->Next(); return; }
    
    while(tmp->Next() != NULL) {
        if (tmp->Next()->Data() == d) { 
            tmp->SetNext(tmp->Next()->Next());
            return; 
        }
        tmp = tmp->Next();
    }
    
    return;
}

void List::toString() 
{
    Node *tmp = head;
    int count = 0;

    while(tmp != NULL) {
        cout << tmp->Data() << " -> ";
        tmp = tmp->Next();
        count++;
    }
    cout << "NULL (" << count << ")" << endl;
}