#include <iostream>
#include <stack>
#include <sstream>
#include <math.h>

#include <string>
#define PI 3.14159265
void userInput();
void exitString(std::string bufptr);
void mathOperations(std::string a);
void trigonometry(double value, int& count, int& counter, std::string& exitString);
void createValue(std::string& value, char ch);
class Stack {
public:
    std::string stringOfoperators;
    std::stack <char> operators;
    int counter = 0;
    void stackPush(char oper) {
        operators.push(oper);
    }
    void stackPopAndPush(char oper) {
        stringOfoperators = "";
        counter = 0;
        do {
            if (operators.size() == 0) break;
            if ((oper == '+' || oper == '-') && operators.top() == '(') break;
            if ((oper == '*' || oper == '/') && (operators.top() == '+' || operators.top() == '-' || operators.top() == '(' || operators.size() == 0)) break;
            if (oper == '^' && operators.size() == 0) break;
            if (oper == ')' && operators.top() == '(') {
                operators.pop();
                if (operators.size() == 0) break;
            }
            stringOfoperators += operators.top();
            stringOfoperators += ' ';
            counter += 2;
            operators.pop();
        } while (true);
        if (oper != ')') operators.push(oper);
    }
};

int main() {
    userInput();
    return 0;
}

void userInput() {
    std::string buffer;
    std::cin >> buffer;
    exitString(buffer);
}

void exitString(std::string bufptr) {
    Stack stack;
    std::string num = "", exiString = "", operatr = "", value;
    double val;
    int counter = 0, i = 0;
    do {
        if (isdigit(bufptr[i])) {
            exiString += bufptr[i];
            i++;
            counter++;
            if (isdigit(bufptr[i]) || (bufptr[i] == '.' || bufptr[i] == ',')) {
                do {
                    if (bufptr[i] == '.' || bufptr[i] == ',') {
                        exiString += '.';
                        i++;
                        counter++;
                    }
                    exiString += bufptr[i];
                    i++;
                    counter++;

                } while (isdigit(bufptr[i]) || (bufptr[i] == '.' || bufptr[i] == ','));

            }
            exiString += ' ';
            counter++;
        }

        else {
            if ((stack.operators.empty() || bufptr[i] == '(' || bufptr[i] == '^') && bufptr[i] != 's') {
                stack.stackPush(bufptr[i]);
                i++;
            }
            else {
                value = "";
                int count = 0;
                if (bufptr[i] == ')') {
                    stack.stackPopAndPush(bufptr[i]);
                    operatr = stack.stringOfoperators;
                    exiString += operatr;
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
                        if (isdigit(bufptr[i])) {
                            while (isdigit(bufptr[i])) {
                                createValue(value, (char)bufptr[i]);
                                i++;
                            }
                        }
                        val = sqrt(stod(value));
                        trigonometry(val, count, counter, exiString);
                        continue;
                    }
                    if (bufptr[i] == 'i' || bufptr[i] == 'I') {
                        while (!isdigit(bufptr[i])) {
                            i++;
                        }
                        if (isdigit(bufptr[i])) {
                            while (isdigit(bufptr[i])) {
                                createValue(value, (char)bufptr[i]);
                                i++;
                            }
                        }
                        val = sin(stod(value) * PI / 180);
                        trigonometry(val, count, counter, exiString);
                        continue;
                    }
                }
                else if (bufptr[i] == 'c' || bufptr[i] == 'C') {
                    i++;
                    if (bufptr[i] == 'o' || bufptr[i] == 'O') {
                        while (!isdigit(bufptr[i])) {
                            i++;
                        }
                        if (isdigit(bufptr[i])) {
                            while (isdigit(bufptr[i])) {
                                createValue(value, (char)bufptr[i]);
                                i++;
                            }
                        }
                        val = cos(stod(value) * PI / 180);
                        trigonometry(val, count, counter, exiString);
                        continue;
                    }
                    if (bufptr[i] == 't' || bufptr[i] == 'T') {
                        i++;
                        if (bufptr[i] == 'g' || bufptr[i] == 'G') {
                            while (!isdigit(bufptr[i])) {
                                i++;
                            }
                            if (isdigit(bufptr[i])) {
                                while (isdigit(bufptr[i])) {
                                    createValue(value, (char)bufptr[i]);
                                    i++;
                                }
                            }
                            val = 1 / tan(stod(value) * PI / 180);
                            trigonometry(val, count, counter, exiString);
                            continue;
                        }
                    }
                }
                else if (bufptr[i] == 't' || bufptr[i] == 'T') {
                    while (!isdigit(bufptr[i])) {
                        i++;
                    }
                    if (isdigit(bufptr[i])) {
                        while (isdigit(bufptr[i])) {
                            createValue(value, (char)bufptr[i]);
                            i++;
                        }
                    }
                    val = tan(stod(value) * PI / 180);
                    trigonometry(val, count, counter, exiString);
                    continue;
                }
                else {
                    stack.stackPopAndPush(bufptr[i]);
                    operatr = stack.stringOfoperators;
                    exiString += operatr;
                    counter += stack.counter;
                    i++;
                    continue;
                }
                stack.stackPush(bufptr[i]);
                i++;
            }
        }
    }while (i < bufptr.length());

    if (stack.operators.size() != 0) {
        do {
            exiString += stack.operators.top();
            exiString += ' ';
            stack.operators.pop();
            counter += 2;
        } while (stack.operators.size() != 0);
    }
    mathOperations(exiString);
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
void trigonometry(double val, int& count, int& counter, std::string& exitString) {
    std::string num;
    num = std::to_string(val);
    while (num[count] != '\0') {
        exitString += num[count];
        counter++; count++;
    }
    exitString += ' ';
}
void createValue(std::string& value, char ch) {
    value += ch;
}