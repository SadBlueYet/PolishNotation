#include <iostream>
#include <stack>
#include <sstream>
#include <math.h>
#include <string.h>
#include <string>
#define PI 3.14159265
std::string userInput();
std::string exitString(std::string bufptr);
void mathOperations(std::string a);
std::string trigonometry(double value, int& count, int& counter, std::string exitString);
class Stack {
public:
    std::stack <char> operators;
    int counter = 0;
    void stackPush(char oper) {
        operators.push(oper);
    }
    std::string stackPopAndPush(char oper) {
        std::string stringOfoperators;
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

std::string userInput() {
    std::string buffer;
    std::cin >> buffer;
    return exitString(buffer);
}

std::string exitString(std::string bufptr) {
    Stack stack;
    double value;
    std::string num, exitString, operatr;
    int counter = 0;
    for(int i = 0; i < bufptr.length(); i++) {
        if (isdigit(bufptr[i])) {
            exitString[counter] = bufptr[i];
            i++;
            counter++;
            if (isdigit(bufptr[i]) || (bufptr[i] == '.' || bufptr[i] == ',')) {
                do {
                    if (bufptr[i] == '.' || bufptr[i] == ',') {
                        exitString[counter] = '.';
                        i++;
                        counter++;
                    }
                    exitString[counter] = bufptr[i];
                    i++;
                    counter++;

                } while (isdigit(bufptr[i]) || (bufptr[i] == '.' || bufptr[i] == ','));

            }
            exitString[counter] = ' ';
            counter++;
        }

        else {
            if ((stack.operators.empty() || bufptr[i] == '(') && bufptr[i] != 's') {
                stack.stackPush(bufptr[i]);
                i++;
            }
            else {
                int count = 0;
                if (bufptr[i] == ')') {
                    operatr = stack.stackPopAndPush(bufptr[i]);
                    exitString[counter] = '\0';
                    exitString += operatr;
                    counter += stack.counter;
                    i++;
                    continue;
                }
                else if (bufptr[i] == 's' || bufptr[i] == 'S') {
                    i++;
                    if (bufptr[i] == 'q' || bufptr[i] == 'Q') {
                        while (!isdigit(bufptr[i])) {
                            i++;
                        }
                        value = (int)bufptr[i];
                        value = sqrt(value);
                        exitString = trigonometry(value, count, counter, exitString);
                        continue;
                    }
                    if (bufptr[i] == 'i' || bufptr[i] == 'I') {
                        while (!isdigit(bufptr[i])) {
                            i++;
                        }
                        value = (int)bufptr[i];
                        value = sin(value * PI / 180);
                        exitString = trigonometry(value, count, counter, exitString);
                        continue;
                    }
                }
                else if (bufptr[i] == 'c' || bufptr[i] == 'C') {
                    i++;
                    if (bufptr[i] == 'o' || bufptr[i] == 'O') {
                        while (!isdigit(bufptr[i])) {
                            i++;
                        }
                        value = (int)bufptr[i];
                        value = cos(value * PI / 180);
                        exitString = trigonometry(value, count, counter, exitString);
                        continue;
                    }
                    if (bufptr[i] == 't' || bufptr[i] == 'T') {
                        i++;
                        if (bufptr[i] == 'o' || bufptr[i] == 'O') {
                            while (!isdigit(bufptr[i])) {
                                i++;
                            }
                            value = (int)bufptr[i];
                            value = 1 / tan(value * PI / 180);
                            num = std::to_string(value);
                            exitString = trigonometry(value, count, counter, exitString);
                            continue;
                        }
                    }
                }
                else if (bufptr[i] == 't' || bufptr[i] == 'T') {
                    while (!isdigit(bufptr[i])) {
                        i++;
                    }
                    value = (int)bufptr[i];
                    value = tan(value * PI / 180);
                    exitString = trigonometry(value, count, counter, exitString);
                    continue;
                }
                else {
                    operatr = stack.stackPopAndPush(bufptr[i]);
                   
                    exitString[counter] = '\0';
                    exitString += operatr;
                    counter += stack.counter;
                    i++;
                    continue;
                }
                stack.stackPush(bufptr[i]);
                i++;
            }
        }
    }

    if (stack.operators.size() != 0) {
        do {
            exitString[counter] = stack.operators.top();
            exitString[counter + 1] = ' ';
            stack.operators.pop();
            counter += 2;
        } while (stack.operators.size() != 0);
    }
    exitString[counter] = '\0';
    return exitString;
}

void mathOperations(std::string a) {
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
std::string trigonometry(double value, int& count, int& counter, std::string exitString) {
    std::string num;
    num = std::to_string(value);
    while (num[count] != '\0') {
        exitString[counter] = num[count];
        counter++; count++;
    }
    exitString[counter] = ' ';
    return exitString;
}