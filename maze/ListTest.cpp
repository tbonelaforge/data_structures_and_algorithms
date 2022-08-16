#include <iostream>

#include "List.hpp"
#include "OrderedPair.h"

using namespace std;


int main() {
    /*
    cout << "Inside ListTest.main, about to construct a new list object...." << endl;
    List<OrderedPair> lop;
    cout << "The new list looks like:" << endl;
    lop.print(cout);
    cout << endl << "And that is all..." << endl;

    cout << "About to push a new ordered Pair on the stack..." << endl;
    OrderedPair op1(0, 1);
    lop.push(op1);
    cout << "Made it past the push command, now the list looks like:" << endl;
    lop.print(cout);
    cout << endl << " And that is all" << endl;
    cout << "About to push another ordered Pair on the stack..." << endl;
    OrderedPair op2(1, 1);
    lop.push(op2);
    cout << "Made it past the second push command, now lop looks like: " << endl;
    lop.print(cout);
    cout << endl << "And that is all..." << endl << "About to pop an element off the list..." << endl;
    OrderedPair popped = lop.pop();
    cout << "Just popped: " << endl;
    popped.print(cout);
    cout << endl << " and that is all..." << endl;
    cout << "AFter popping, the list looks like: " << endl;
    lop.print(cout);
    cout << endl << " And that is all" << endl;
    cout << "About to pop again..." << endl;
    popped = lop.pop();
    cout << "Just popped: " << endl;
    popped.print(cout);
    cout << endl << "And now the list looks like:" << endl;
    lop.print(cout);
    cout << endl;
    
    cout << "About to push a new ordered Pair on the stack..." << endl;
    lop.push(OrderedPair(0, 1));
    cout << "Made it past the push command, now the list looks like:" << endl;
    lop.print(cout);
    cout << endl << " And that is all" << endl;
    cout << "About to push another ordered Pair on the stack..." << endl;
    lop.push(OrderedPair(1, 2));
    cout << "Made it past the second push command, now lop looks like: " << endl;
    lop.print(cout);
    cout << endl << "And that is all..." << endl;
    cout << "About to dequeue an element from the front..." << endl;
    popped = lop.dequeue();
    cout << "dequeued the element: " << endl;
    popped.print(cout);
    cout << endl << "And now the list looks like: " << endl;
    lop.print(cout);
    cout << endl << "And that is all..." << endl;
    cout << "ABout to dequeue another element..." << endl;
    popped = lop.dequeue();
    cout << "The dequeued element: " << endl;
    popped.print(cout);
    cout << endl << "And now the list is: " << endl;
    lop.print(cout);
    cout << endl << "And that is all..." << endl;

    */
    cout << "About to create a new list of lists with 2 elements in it...\n" << endl;
    List< List<OrderedPair> > llop1;
    List<OrderedPair> lop1;
    cout << "About to push an ordered pair onto lop1...\n";
    lop1.push(OrderedPair(1, 1));
    cout << "About to push another ordered onto lop1...\n";
    lop1.push(OrderedPair(2, 2));
    cout << "Constructed the first lop1..." << endl;
    printf("%p\n", &lop1);
    lop1.print(cout);
    cout << endl;
    List<OrderedPair> lop2;
    lop2.push(OrderedPair(3, 3));
    lop2.push(OrderedPair(4, 4));
    cout << "Constructed the second lop2..." << endl;
    cout << "ABOUT TO PUSH THE FIRST LOP1 ONTO llop1...\n";
    llop1.push(lop1);
    cout << "FINISHED LLOP1.PUSH(LOP1)" << "\n";
    cout << "The first node inside llop1 is:" << endl;
    Node< List<OrderedPair> > * p = llop1.getTail();
    printf("%p", p);
    cout << endl << "the first LIST inside llop1 is:" << endl;
    printf("%p", &(p->info));
    cout << endl;
    cout << "About to push another lop2 onto llop1...\n" << endl;
    llop1.push(lop2);
    cout << "The list to be copied looks like:\n" << endl;
    llop1.print(cout);
    cout << endl;
    printf("The address of llop1 is: %p\n", &llop1);
    cout << "and that is all..." << endl;
    cout << "About to pop from llop1..." << endl;
    List<OrderedPair> poppedList;
    poppedList = llop1.pop();
    cout << "Just popped list:" << endl;
    poppedList.print(cout);
    cout << endl;
    cout << "After popping from the llop1, llop1 looks like:" << endl;
    llop1.print(cout);
    cout << endl;
    cout << "About to construct a new llop2..." << endl;
    List< List<OrderedPair> > llop2;
    llop2.push(lop1);
    cout << "Made it past the pushing of lop1 onto llop2..." << endl;
    cout << "Now llop2 looks like:" << endl;
    llop2.print(cout);
    cout << endl;
    cout << "About to create a copy of llop1, known as llop3:" << endl;
    llop1.push(lop2);
    cout << "Before copying, llop1 looks like:" << endl;
    llop1.print(cout);
    cout << endl;
    List< List<OrderedPair> > llop3(llop1);
    cout << "The copied list looks like:" << endl;
    llop3.print(cout);
    cout << endl << "And that is all..." << endl;
    cout << "About to pop from llop1 (the original)" << endl;
    llop1.pop();
    cout << "After popping, the original looks like: " << endl;
    llop1.print(cout);
    cout << endl << "And the copy still looks like:" << endl;
    llop3.print(cout);
    cout << endl << "And that is all..." << endl;
}
