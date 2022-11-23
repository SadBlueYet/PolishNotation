#include <iostream>
#include <stack>
#include <sstream>
#define _CRT_SECURE_NO_WARNINGS
void userInput();
void isExitString(char* bufptr);
int main() {
   
    userInput();
    return 0;
}
void userInput() {
    char* buffer = (char*)malloc(1024 * sizeof(char));
    std::cin >> buffer;
    isExitString(buffer);      
}

void isExitString(char* bufptr) {
    char* p = bufptr;
    std::stack <char> stackOperators;
    char* operand = (char*)malloc(1024 * sizeof(char));
    int counterOperand= 0;
    do {
        if (isdigit(*p)) {
            operand[counterOperand] = *p;
            p++;
            counterOperand++;
            if (isdigit(*p)) {
                do {
                    operand[counterOperand] = *p;
                    p++;
                    counterOperand++;
                } while (isdigit(*p));
            }
            operand[counterOperand] = ' ';
            counterOperand++;
        }

        else{
            if (stackOperators.size() == 0 || *p == '(') {
                stackOperators.push(*p);
                p++;
            }
            else {
                if ((stackOperators.top() == '+' || stackOperators.top() == '-' || stackOperators.top() == '*' ||
                    stackOperators.top() == '/') && (*p == '+' || *p == '-')) {
                    operand[counterOperand] = stackOperators.top();
                    operand[counterOperand + 1] = ' ';
                    counterOperand += 2;
                    stackOperators.pop();
                    if (stackOperators.size() != 0 && (stackOperators.top() == '+' || stackOperators.top() == '-' || stackOperators.top() == '*' ||
                        stackOperators.top() == '/')) {
                        do {
                            operand[counterOperand] = stackOperators.top();
                            operand[counterOperand + 1] = ' ';
                            stackOperators.pop();
                            counterOperand += 2;
                        } while (stackOperators.size() != 0);
                    }
                    stackOperators.push(*p);                                   
                    p++;                    
                }
                else if ((stackOperators.top() == '*' || stackOperators.top() == '/') && (*p == '*' || *p == '/')) {
                    operand[counterOperand] = stackOperators.top();
                    operand[counterOperand + 1] = ' ';
                    stackOperators.pop();
                    stackOperators.push(*p);
                    counterOperand += 2;
                    p++;
                }       
                
                else if (*p == ')') {
                    do {
                        operand[counterOperand] = stackOperators.top();
                        operand[counterOperand + 1] = ' ';
                        stackOperators.pop();
                        counterOperand +=2;
                    } while (stackOperators.top() != '(');
                    stackOperators.pop();
                    p++;
                }     
                else {
                    stackOperators.push(*p);
                    p++;
                }
            }
        }
        
    } while (*p != '\0');
    if(stackOperators.size() != 0) {
        do {
            operand[counterOperand] = stackOperators.top();
            operand[counterOperand + 1] = ' ';
            stackOperators.pop();
            counterOperand += 2;
        } while (stackOperators.size() != 0);
    }
    operand[counterOperand] = '\0';
    std::cout << operand;
}
