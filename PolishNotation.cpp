#include <iostream>
#include <stack>
#include <sstream>
#include <math.h>
char* userInput();
char* exitString(char* bufptr);
void mathOperations(char* a);
int main() {
    mathOperations(userInput());
    
    return 0;
}
char* userInput() {
    char* buffer = (char*)malloc(1024 * sizeof(char));
    std::cin >> buffer;
    return exitString(buffer);      
}
char* exitString(char* bufptr) {
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
                    stackOperators.top() == '/' || stackOperators.top() == '^') && (*p == '+' || *p == '-')) {
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
                else if ((stackOperators.top() == '*' || stackOperators.top() == '/' || stackOperators.top() == '^') && (*p == '*' || *p == '/')) {
                    operand[counterOperand] = stackOperators.top();
                    operand[counterOperand + 1] = ' ';
                    stackOperators.pop();
                    stackOperators.push(*p);
                    counterOperand += 2;
                    p++;
                }
                else if (stackOperators.top() == '^' && *p == '^') {
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
    return operand;
}
void mathOperations(char*a) {
    std::istringstream str(a);
    std::stack<double> numbers;
    double value;
    char oper;
    double right, left;
    while (!str.eof())
    {
        while (str >> value) {
            numbers.push(value);
        }
        if (!str.eof()) {
            str.clear();
            str.unget();
            str >> oper;
            if (numbers.size() < 2) {
                std::cout << "corrupt oper. order" << std::endl;
                return;
            }
            right = numbers.top();
            numbers.pop();
            left = numbers.top();
            numbers.pop();
            if (oper == '+') numbers.push(left + right);
            if (oper == '-') numbers.push(left - right);
            if (oper == '*') numbers.push(left * right);
            if (oper == '/') numbers.push(left / right);
            if (oper == '^') numbers.push(pow(left, right));
        }
    }
    if (numbers.size() != 1){
        std::cout << "stack corrupted" << std::endl;
        return ;
    }
    std::cout << "result value is " << numbers.top() << std::endl;
    return ;
}
