/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <stddef.h>

void split(Node *&in, Node *&odds, Node *&evens)
{
  if (in == NULL) {
    return;
  } 

  Node* in_head = in;
  in = in->next;

  if (in_head->value % 2 == 1) {
    if (odds == NULL){
      odds = in_head;
    } else {
      odds->next = in_head;
    }
    in_head->next = NULL;
    split(in, in_head, evens);
  } else if (in_head->value % 2 == 0) {
    if (evens == NULL){
      evens = in_head;
    } else {
      evens->next = in_head;
    }
    in_head->next = NULL;
    split(in, odds, in_head);
  }
}
