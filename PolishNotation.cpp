#include <iostream>
#include <stack>
#include <sstream>
#include <math.h>
#include <string.h>
#include <string>
#define PI 3.14159265
char* userInput();
char* exitString(char* bufptr);
void mathOperations(char* a);

class Stack {
public:
    std::stack <char> operators;
    int counter = 0;
    void stackPush(char oper) {
        operators.push(oper);
    }
    char* stackPopAndPush(char oper) {
        char* stringOfoperators = (char*)malloc(1024 * sizeof(char));
        counter = 0;
        do {
            if (operators.size() == 0) break;
            if ((oper == '+' || oper == '-') && operators.top() == '(') break;
            if ((oper == '*' || oper == '/') && (operators.top() == '+' || operators.top() == '-' || operators.top() == '(' || operators.size() == 0)) break;
            if (oper == '^' && operators.size() == 0) break;
            if (oper == ')' && operators.top() == '(') {
                operators.pop();
                break;
            }
            stringOfoperators[counter] = operators.top();
            stringOfoperators[counter + 1] = ' ';
            counter += 2;
            operators.pop();
            if (counter % 1024 == 0)
                stringOfoperators = (char*)realloc(stringOfoperators, 1024 * (counter / 1024 + 1) * sizeof(char));
        } while (true);
        if (oper != ')') operators.push(oper);
        stringOfoperators[counter] = '\0';
        return stringOfoperators;
    }
};

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
    Stack stack;
    double value;
    std::string num;
    char* p = bufptr;
    char* exitString = (char*)malloc(1024 * sizeof(char));
    char* operatr = (char*)malloc(1024 * sizeof(char));
    int counter = 0;
    do {
        if (isdigit(*p)) {
            exitString[counter] = *p;
            p++;
            counter++;
            if (isdigit(*p) || (*p == '.' || *p == ',')) {
                do {
                    if (*p == '.' || *p == ',') {
                        exitString[counter] = '.';
                        p++;
                        counter++;
                    }
                    exitString[counter] = *p;
                    p++;
                    counter++;

                } while (isdigit(*p) || (*p == '.' || *p == ','));

            }
            exitString[counter] = ' ';
            counter++;
        }

        else {
            if ((stack.operators.empty() || *p == '(') && *p != 's') {
                stack.stackPush(*p);
                p++;
            }
            else {
                int count = 0;
                if ((*p == '-' || *p == '+') && (stack.operators.top() == '(' || stack.operators.size() == 0)) {
                    stack.stackPush(*p);
                    p++;
                }
                else if ((*p == '*' || *p == '/') && (stack.operators.top() == '+' ||
                    stack.operators.top() == '-' || stack.operators.top() == '(' || stack.operators.size() == 0)) {
                    stack.stackPush(*p);
                    p++;
                }
                else if (*p == '^' && (stack.operators.size() == 0 || stack.operators.top() == '+' ||
                    stack.operators.top() == '-' || stack.operators.top() == '(' ||
                    stack.operators.top() == '*' || stack.operators.top() == '/')) {
                    stack.stackPush(*p);
                    p++;
                }
                else if (*p == ')') {
                    operatr = stack.stackPopAndPush(*p);
                    if (strlen(operatr) % 1024 == 0)
                        operatr = (char*)realloc(operatr, 1024 * (strlen(operatr) / 1024 + 1) * sizeof(char));
                    exitString[counter] = '\0';
                    exitString = strcat(exitString, operatr);
                    counter += stack.counter;
                    p++;
                }
                else if (*p == 's' || *p == 'S') {
                    
                    p++;
                    if (*p == 'q' || *p == 'Q') {
                        p++;
                        while (!isdigit(*p)) {
                            p++;
                        }
                        value = atoi(p);
                        value = sqrt(value);
                        num = std::to_string(value);
                        while (num[count] != '\0') {
                            exitString[counter] = num[count];
                            counter++; count++;
                        }
                        exitString[counter] = ' ';
                    }
                    if (*p == 'i' || *p == 'I') {
                        p++;
                        while (!isdigit(*p)) {
                            p++;
                        }
                        value = atoi(p);
                        value = sin(value * PI / 180);
                        num = std::to_string(value);
                        while (num[count] != '\0') {
                            exitString[counter] = num[count];
                            counter++; count++;
                        }
                        exitString[counter] = ' ';
                    }
                    
                }
                else if (*p == 'c' || *p == 'C') {
                    p++;
                    if (*p == 'o' || *p == 'O') {
                        while (!isdigit(*p)) {
                            p++;
                        }
                        value = atoi(p);
                        value = cos(value * PI / 180);
                        num = std::to_string(value);
                        while (num[count] != '\0') {
                            exitString[counter] = num[count];
                            counter++; count++;
                        }
                        exitString[counter] = ' ';
                    }
                    if (*p == 't' || *p == 'T') {
                        p++;
                        if (*p == 'o' || *p == 'O') {
                            while (!isdigit(*p)) {
                                p++;
                            }
                            value = atoi(p);
                            value = 1 / tan(value * PI / 180);
                            num = std::to_string(value);
                            while (num[count] != '\0') {
                                exitString[counter] = num[count];
                                counter++; count++;
                            }
                            exitString[counter] = ' ';
                        }
                    }
                }
                else if (*p == 't' || *p == 'T') {
                    p++;
                    if (*p == 'g' || *p == 'G') {
                        while (!isdigit(*p)) {
                            p++;
                        }
                        value = atoi(p);
                        value = tan(value * PI / 180);
                        num = std::to_string(value);
                        while (num[count] != '\0') {
                            exitString[counter] = num[count];
                            counter++; count++;
                        }
                        exitString[counter] = ' ';
                    }
                }

                else {
                    operatr = stack.stackPopAndPush(*p);
                    if (strlen(operatr) % 1024 == 0)
                        operatr = (char*)realloc(operatr, 1024 * (strlen(operatr) / 1024 + 1) * sizeof(char));
                    exitString[counter] = '\0';
                    exitString = strcat(exitString, operatr);
                    counter += stack.counter;
                    p++;
                }
            }
        }
        if (counter % 1024 == 0)
            exitString = (char*)realloc(exitString, 1024 * (counter / 1024 + 1) * sizeof(char));
    } while (*p != '\0');

    if (stack.operators.size() != 0) {
        do {
            exitString[counter] = stack.operators.top();
            exitString[counter + 1] = ' ';
            stack.operators.pop();
            counter += 2;
            if (counter % 1024 == 0)
                exitString = (char*)realloc(exitString, 1024 * (counter / 1024 + 1) * sizeof(char));
        } while (stack.operators.size() != 0);
    }
    exitString[counter] = '\0';
    return exitString;
}

void mathOperations(char* a) {
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
    if (numbers.size() != 1) {
        std::cout << "stack corrupted" << std::endl;
        return;
    }
    std::cout << "result value is " << numbers.top() << std::endl;
    return;
}