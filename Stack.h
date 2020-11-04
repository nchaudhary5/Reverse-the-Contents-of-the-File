
/*
            Stack
 -----------------------------------------
 - value : T
 - next : StackNode
 - top : StackNode
 -----------------------------------------
 + Stack() :
 + ~Stack() :
 + push(T) : void
 + pop(T) : void
 + isEmpty(T) : void
 */

#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

// Stack template
template <class T>
// Stack class declaration
class Stack
{
// private access specifier
private:
    
   // Structure for the stach nodes
   struct StackNode
   {
      T data;          // Value in the node
      StackNode *next;  // Pointer to next node
   };
   
   StackNode *top;     // Pointer to the stack top

public:
   //Constructor
   Stack()
   { top = nullptr; }
   
   // Destructor
   ~Stack();
   
   // Stack operations
   void push(T);
   void pop(T &);
   bool isEmpty();
};

//***************************************************
//  Destructor                                      *
//***************************************************
template <class T>
Stack<T>::~Stack()
{
   StackNode *nodePtr, *nextNode;

   // Position nodePtr at the top of the stack.
   nodePtr = top;

   // Traverse the list deleting each node.
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }
}

//*************************************************************
// Function name: push
// Purpose:Member function push pushes the argument onto              *
// the stack.
// List of parameter: item
// Returns: no returns
// Return type: void
//*************************************************************

template <class T>
void Stack<T>::push(T var)
{
   StackNode *n = nullptr; // Pointer to a new node

   // Allocate a new node and store num there.
   n = new StackNode;
   n->data = var;

   // If there are no nodes in the list
   // make newNode the first node.
   if (isEmpty())
   {
      top = n;
      n->next = nullptr;
   }
   else  // Otherwise, insert NewNode before top.
   {
      n->next = top;
      top = n;
   }
}
 
//*************************************************************
// Function name: pop
// Purpose:  Member function pop pops the value at the top
// of the stack off, and copies it into the variable
// passed as an argument.
// List of parameter: item
// Returns: no returns
// Return type: void
//*************************************************************

template <class T>
void Stack<T>::pop(T &var)
{
   StackNode *temp = nullptr; // Temporary pointer

   // First make sure the stack isn't empty.
   if (isEmpty())
   {
      cout << "The stack is empty.\n";
   }
   else  // pop value off top of stack
   {
      var = top->data;
      temp = top->next;
      delete top;
      top = temp;
   }
}

//*************************************************************
// Function name: isEmpty()
// Purpose:  Member function isEmpty returns true if the stack
// is empty, or false otherwise.
// List of Parameter: none
// Returns: it will return either true or false
// Return type: bool
//*************************************************************

template <class T>
bool Stack<T>::isEmpty()
{
   bool status;

   if (!top)
      status = true;
   else
      status = false;

   return status;
}
#endif
