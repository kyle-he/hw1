/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <stddef.h>
#include <iostream>
using namespace std;

void print_ll(Node* list) {
    Node* curr = list;
    while (curr != NULL) {
        cout << curr->value;
        if (curr->next != NULL) {
            cout << ", ";
        }
        curr = curr->next;
    }
    cout << endl;
}

void deallocate(Node* list) {
	Node * currElement = list;
	while(currElement != nullptr)
	{
		Node * nextElement = currElement->next;
		delete currElement;
		currElement = nextElement;
	}
}

int main(int argc, char* argv[])
{
    Node* input = new Node(7, NULL);
    Node* curr_input_node = input;
    for (int i = 8; i <= 8; i++) {
        curr_input_node->next = new Node(i, NULL);
        curr_input_node = curr_input_node->next;
    }

    cout << "Before Split" << endl;
    print_ll(input);

    Node* odd = NULL;
    Node* even = NULL;
    split(input, odd, even);

    cout << endl << "After Split" << endl;

    cout << "Input list: ";
    print_ll(input);

    cout << "Even list: ";
    print_ll(odd);

    cout << "Odd list: ";
    print_ll(even);

    deallocate(input);
    deallocate(odd);
    deallocate(even);
}
