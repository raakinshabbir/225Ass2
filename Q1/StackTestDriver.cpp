/* 
 * StackTestDriver.cpp
 *
 * Description: Test Driver for Stack class.
 *
 * Author:
 * Date:
 */

/* 
   Feel free to modify this test driver to match your design of the Stack class.
   For example, I designed my push(...) and pop() methods such that they each return
   a bool value. I will then change this test driver to capture this bool value. 
*/ 

#include <iostream> 
#include "Stack.h"

using std::cout;
using std::endl;


int main () {
    Stack * stk = new Stack( );

    stk->push(1);
    stk->push(2);
    stk->push(3);
    stk->traverse(); 

    //pop top two
    cout << "pop top 2 elements on the stack:" << endl; 
    int x = stk->peek();
    stk->pop();
    int y = stk->peek();
    stk->pop();
    cout << "first popped " << x << ", and next popped: " << y << endl;

    cout << "this is the new stack: " << endl; 
    stk->traverse(); 

    // push 6, 7, 8, 9, 10
    cout << "push more elements onto the stack: " << endl; 
    for (int i = 6; i <= 10; i++) {
        stk->push(i);
    }

    stk->traverse(); 

    cout << "pop all elements from the stack: " << endl; 
    while (!stk->isEmpty()) {
        int x = stk->peek();
        stk->pop();
        stk->traverse(); 
    }

    delete stk;
    stk = nullptr;
    return 0;
}
