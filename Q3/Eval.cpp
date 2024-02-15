#include <iostream>
#include "Scanner.h"
#include "Stack.h"

using std::cout;
using std::endl;
using std::cin;

/* Pseudocode:
     * while T is not EOF or the operator stack is non empty
     *   if T is a number:
     *       push T to the number stack
     *       get the next token
     *   else if T is a left parenthesis:
     *       push T to the operator stack
     *       get the next token
     *   else if T is a right parenthesis:
     *       if the top of the operator stack is a left parenthesis:
     *           pop it from the operator stack
     *       else:
     *           pop the top two numbers and the top operator
     *           perform the operation
     *           push the result to the number stack
     *       get the next token
     *          else if T is +, - or EOF:
     *       if the operator stack is nonempty and the top is one of +, -, *, /:
     *           pop the top two numbers and the top operator
     *           perform the operation
     *           push the result to the number stack
     *       else:
     *           push T to the operator stack
     *       get the next token
     * 
     * 
     *   else if T is * or /:
     *       if the operator stack is nonempty and the top is one of *, /:
     *           pop the top two numbers and the top operator
     *           perform the operation
     *           push the result to the number stack
     *       else:
     *           push T to the operator stack
     *       get the next token
     */

int main() {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack; // 2x Stacks of type Token

    t = S.getnext();

    while (t.tt != eof || !opstack.isEmpty()) {
        if (t.tt == integer) {
            numstack.push(t); // Push the token onto the numstack
            t = S.getnext(); // Get the next token
        } 
        else if(t.tt == lptok){
            opstack.push(t); 
            t = S.getnext(); 
        }
        else if (t.tt == rptok){
            if(opstack.peek().tt == lptok){
                opstack.pop();
            }
            else{
                int num1 = numstack.pop().val; 
                int num2 = numstack.pop().val; 
                Token op = opstack.pop();

                int result; 
                if(op.tt == pltok){
                    result = num1 + num2; 
                }
                else if(op.tt == mitok){
                    result = num1 - num2; 
                }
                else if(op.tt == asttok){
                    result = num1 * num2; 
                }
                else if(op.tt == slashtok){
                    result = num1 / num2;
                }
                Token resultToken;
                resultToken.tt = integer;
                resultToken.val = result;
                numstack.push(resultToken); 
            }
            t = S.getnext(); 
        }
        else if(t.tt == pltok || t.tt == mitok || t.tt == eof){
              if (!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok)){
                int num1 = numstack.pop().val; 
                int num2 = numstack.pop().val;
                Token op = opstack.pop(); 

                int result; 
                if(op.tt == pltok){
                    result = num1 + num2; 
                }
                else if(op.tt == mitok){
                    result = num1 - num2; 
                }
                else if(op.tt == asttok){
                    result = num1 * num2; 
                }
                else if(op.tt == slashtok){
                    result = num1 / num2;
                }
                Token resultToken;
                resultToken.tt = integer;
                resultToken.val = result;
                numstack.push(resultToken); 
              }
              else{
                opstack.push(t);
              }
              t = S.getnext(); 
        }
        else if(t.tt == asttok || t.tt == slashtok){
            if(!opstack.isEmpty() && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok)){
                int num1 = numstack.pop().val;
                int num2 = numstack.pop().val; 
                Token op = opstack.pop();

                int result; 
                if(op.tt == pltok){
                    result = num1 + num2; 
                }
                else if(op.tt == mitok){
                    result = num1 - num2; 
                }
                else if(op.tt == asttok){
                    result = num1 * num2; 
                }
                else if(op.tt == slashtok){
                    result = num1 / num2;
                }
                Token resultToken;
                resultToken.tt = integer;
                resultToken.val = result;
                numstack.push(resultToken); 
            }
            else{
                opstack.push(t);
            }
            t = S.getnext(); 
        }
        }
    }
