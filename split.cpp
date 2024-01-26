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
#include <cstddef>
/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE


//When to terminate the recursive function
if (in == nullptr) {
  return;
}

//Making a new variable for the next value in linked list
Node* nextVal = in->next;

//To iterate through evens and odds when needed
Node* evensVal = evens;
Node* oddsVal = odds;

if (in->value % 2 == 0) { //in node is even 

  if (evens == nullptr){ //If the list is empty
    //Change the head to in and next to nullptr
    evens = in;
    evens->next = nullptr;

    //Set what was just looked at to null
    in = nullptr;
    //Recursive call with updated in pointer
    split(nextVal, odds, evens);
  } else if (evensVal == nullptr) { //If evensVal is the last item in evens
    //Change evensVal to in
    evensVal = in;
    //Set next to nullptr
    evensVal->next = nullptr;
    
    //Set what was just looked at to null
    in = nullptr;
    //Recursive call with updated in pointer
    split(nextVal, odds, evens);
    
  } else { //If evensVal is not at the end yet
    //Split call to iterate evensVal through evens
    split(in, odds, evensVal->next);
  }
  
} else if (in->value % 2 == 1) { //Odd
  
  //If odds is empty
  if (odds == nullptr){
    //Change the head to in and next to nullptr
    odds = in;
    odds->next = nullptr;
    //Set what was just looked at to null
    in = nullptr;
    //Recursive call with updated in pointer
    split(nextVal, odds, evens);
  } else if (oddsVal == nullptr) { 
    //Set oddsVal to in and next to nullptr
    oddsVal = in;
    oddsVal->next = nullptr;

    //Set what was just looked at to null
    in = nullptr;
    //Recursive call with updated in pointer
    split(nextVal, odds, evens);
  } else { //If oddsVal is not at end iterate through
    split(in, oddsVal->next, evens);
  }
  
  
}

}

/* If you needed a helper function, write it here */
