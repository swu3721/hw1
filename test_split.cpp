/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
    
    Node* head = new Node(NULL, nullptr);
    //head->next = new Node(2, nullptr);
    //head->next->next = new Node(3, nullptr);
    //head->next->next->next = new Node(4, nullptr);
    //head->next->next->next->next = new Node(5, nullptr);

    Node* evens = nullptr;
    Node* odds = nullptr;

    split(head, odds, evens);

    Node* evenHead = evens;
    while (evenHead != nullptr) {
        std::cout << "Evens: " << evenHead->value << " " << std::endl;;
        evenHead = evenHead->next;
    }
    std::cout << "evens ran" << std::endl;

    Node* oddHead = odds;
    while (oddHead != nullptr) {
        std::cout << "Odds: " << oddHead->value << " " << std::endl;;
        oddHead = oddHead->next;
    }
    std::cout << "odds ran" << std::endl;

    
    while (evens != nullptr) {
        Node* tempe = evens;
        evens = evens->next;
        delete tempe;
    }
    while (odds != nullptr) {
        Node* tempo = odds;
        odds = odds->next;
        delete tempo;
    }

    return 0;

}
