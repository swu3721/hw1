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

Node* evensVal = evens;
Node* oddsVal = odds;

if (in->value % 2 == 0) { //in node is even 

  if (evens == nullptr){ //If the list is empty
    evens = in;
    evens->next = nullptr;

    //Set what was just looked at to null
    in = nullptr;
    //Recursive call with updated in pointer
    split(nextVal, odds, evens);
  } else if (evensVal == nullptr) { //If evensVal is not the last item in the list
    evensVal = in;
    evensVal->next = nullptr;
    
    in = nullptr;
    split(nextVal, odds, evens);
    
    //Navigating to proper spot in evens
    //while (evensVal->next != nullptr){
      //evensVal = evensVal->next;
    //}
    //split(in, odds, evens->next);

    //Add in node to even list
    //evensVal->next = in;
    //Necessary?
    //evensVal->next->next = nullptr;
  } else {
    split(in, odds, evensVal->next);
  }
  
} else if (in->value % 2 == 1) { //Assume it can only be even or odd
  
  //If odds is empty
  if (odds == nullptr){
    odds = in;
    odds->next = nullptr;
    //Set what was just looked at to null
    in = nullptr;
    //Recursive call with updated in pointer
    split(nextVal, odds, evens);
  } else if (oddsVal == nullptr) { 
    oddsVal = in;
    oddsVal->next = nullptr;
    
    //Navigating to proper place in odds
    //while (oddsVal->next != nullptr){
      //oddsVal = oddsVal->next;
    //}
    //split(in, odds->next, evens);
    //Odd
    //oddsVal->next = in;
    //oddsVal->next->next = nullptr;
    in = nullptr;
    split(nextVal, odds, evens);
  } else {
    split(in, oddsVal->next, evens);
  }
  
  
  
}

//Set what was just looked at to null
//in = nullptr;
//Recursive call with updated in pointer
//split(nextVal, odds, evens);
}

/* If you needed a helper function, write it here */
