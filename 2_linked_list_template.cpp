#include <iostream>
#include <string>
#include <set>
using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node(int d) { 
    	data = d; 
    	next = NULL; 
    };

    void appendToTail(int d) {
		Node end = new Node(d);
		Node n = this;
		while (n->next != NULL)
			n = n->next;
		n->next = end;
    }

	Node deleteNode(Node head, int d) {
		Node n = head;

		if (n.data == d) {
			return head->next;
		}

		while (n->next != NULL) {
			if (n->next.data == d) {
				n->next = n->next->next;
				return head;
			}
			n = n->next;
		}

		return head;
	}

	void printList(Node head) {
		Node n = head;

		while (n != NULL) {
			cout << n.data << " --> ";
			n = n->next;
		}
		cout << "NULL" << endl;
	}

};


class Node {
public:
	void Node(int d) {
		data = d;
		next = NULL;
	}

	void appendToTail(int d) {
		Node end = new Node(d);
		Node n = this;
		while (n->next != NULL)
			n = n->next;
		n->next = end;
	}

	Node deleteNode(Node head, int d) {
		Node n = head;

		if (n.data == d) {
			return head->next;
		}

		while (n->next != NULL) {
			if (n->next.data == d) {
				n->next = n->next->next;
				return head;
			}
			n = n->next;
		}

		return head;
	}

	void printList(Node head) {
		Node n = head;

		while (n != NULL) {
			cout << n.data << " --> ";
			n = n->next;
		}
		cout << "NULL" << endl;
	}

private:
	int data;
	Node *next;
};

int main()
{
	Node head = new Node(0);

	head.appendToTail(1);
	head.appendToTail(2);
	head.appendToTail(3);
	head.appendToTail(4);
	head.appendToTail(5);
	head.appendToTail(6);
	head = deleteNode(head, 5);
	head = deleteNode(head, 7);

	printList(head);
	return 0;
}
