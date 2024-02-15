/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author:
 * Date:
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using std::cout;
using std::endl;
using std::cin;


int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();

    
    while (t.tt != eof) {
        if (t.tt == integer){
            numstack.push(t.val);
        }
            else if (t.tt == lptok){
                opstack.push(t.val);
            }
            else if(t.tt == rptok){
                while(opstack.peek() != lptok){
                    opstack.pop();
                    numstack.pop();
                    numstack.pop(); 
                }
            }
        }
    }


    /*
    
    1. Initialize two stacks: one for numbers (numStack) and one for operators (opStack).
2. Scan the input expression from left to right.
3. For each token in the expression:
   3.1 If the token is a number:
       3.1.1 Push it onto the numStack.
   3.2 If the token is a left parenthesis '(':
       3.2.1 Push it onto the opStack.
3.3 If the token is a right parenthesis ')':
       3.3.1 While the top of the opStack is not '(':
              - Pop the top operator from the opStack.
              - Pop the top two numbers from the numStack.

              
              - Apply the operator to the numbers and push the result back onto the numStack.
       3.3.2 Pop the '(' from the opStack.
   3.4 If the token is an operator (+, -, *, /):
       3.4.1 While the opStack is not empty and the precedence of the current token is less than or equal to the precedence of the top operator on the opStack:
              - Pop the top operator from the opStack.
              - Pop the top two numbers from the numStack.
              - Apply the operator to the numbers and push the result back onto the numStack.
       3.4.2 Push the current token onto the opStack.
4. After scanning all tokens, there may be remaining operators on the opStack:
   4.1 While the opStack is not empty:
          - Pop the top operator from the opStack.
          - Pop the top two numbers from the numStack.
          - Apply the operator to the numbers and push the result back onto the numStack.
5. The final result will be the only element left on the numStack.
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    */
}

