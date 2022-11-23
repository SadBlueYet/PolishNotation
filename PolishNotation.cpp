#include <iostream>
#include <stack>
#include <sstream>
#define _CRT_SECURE_NO_WARNINGS
//65+65-59*98/65
/*char polishNotation(char* bufptr);
int main() {
    char* buffer = (char*)malloc(1024 * sizeof(char));
    std::cin >> buffer;
    polishNotation(buffer);
	return 0;
}

char polishNotation(char* bufptr) {
    char* p = bufptr;
    int counter = 0;
    char oper;
    int couterOutputStr = 0;
    std::stack <char> stackOper;
    char* outputString = (char*)malloc(1024 * sizeof(char));

    do{ 
        
        if (isdigit(*p)) {
            outputString[couterOutputStr] = *p;
            p++;
            couterOutputStr++;
            counter++;
            if(isdigit(*p)) {
                do {
                    outputString[couterOutputStr] = *p;
                    p++;
                    counter++;
                    couterOutputStr++;
                } while (isdigit(*p));
            }
            outputString[couterOutputStr] = ' ';
            couterOutputStr++;
            counter++;
            
            if (counter % 1024 == 0){
                outputString = (char*)realloc(outputString, 1024 * (counter / 1024 + 1) * sizeof(char));
                *p = (char)realloc(bufptr, 1024 * (counter / 1024 + 1) * sizeof(char));
            }

        }
        if(!isdigit(*p)) {
            if (stackOper.size() == 0){
                stackOper.push(*p);
                p++;
            }
            if (*p == '\0' && stackOper.size() != 0) {
                do { 
                    outputString[couterOutputStr] = stackOper.top();
                    stackOper.pop();
                    outputString[couterOutputStr + 1] = ' ';
                    couterOutputStr += 2;
                } while (stackOper.size() != 0);
                break;
            }
            if(stackOper.size() != 0 && !isdigit(*p)) {

                if(*p == '-' || *p == '+' && stackOper.top() == '+' || stackOper.top() == '-') {      
                    outputString[couterOutputStr] = stackOper.top();
                    stackOper.pop();
                    stackOper.push(*p);
                    outputString[couterOutputStr + 1] = ' ';
                    couterOutputStr += 2;
                    counter += 2;
                    p++;
                    if (counter % 1024 == 0) {
                        outputString = (char*)realloc(outputString, 1024 * (counter / 1024 + 1) * sizeof(char));
                        *p = (char)realloc(bufptr, 1024 * (counter / 1024 + 1) * sizeof(char));
                    }
                }
                if (*p == '*' || *p == '/' && stackOper.top() == '*' || stackOper.top() == '/') {
                    outputString[couterOutputStr] = stackOper.top();
                    stackOper.pop();
                    stackOper.push(*p);
                    outputString[couterOutputStr + 1] = ' ';
                    couterOutputStr += 2;
                    counter += 2;
                    p++;
                    if (counter % 1024 == 0) {
                        outputString = (char*)realloc(outputString, 1024 * (counter / 1024 + 1) * sizeof(char));
                        *p = (char)realloc(bufptr, 1024 * (counter / 1024 + 1) * sizeof(char));
                    }
                }
                if(!isdigit(*p)) {
                    stackOper.push(*p);
                    p++;
                }
            }
  
        }
    } while (*p != '\0');
    outputString[couterOutputStr] = '\0';
    std::cout << outputString;
    return *outputString;
}*/
/*#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
int main() {
    istringstream s("8 9 + 1 7 - *");
    stack<int> opz;
    int value;
    char sign;
    while (!s.eof())
    {
        while (s >> value) {
            opz.push(value);
        }
        if (!s.eof())
        {
            s.clear();
            s.unget();
            s >> sign;
            if (opz.size() < 2)
            {
                cout << "corrupt oper. order" << endl;
                return 0;
            }
            int right = opz.top();
            opz.pop();
            int left = opz.top();
            opz.pop();
            switch (sign) {
            case '+':   opz.push(right + left); break;
            case '-':   opz.push(right - left); break;
            case '*':   opz.push(right * left); break;
            case '/':   opz.push(right / left); break;
            default:
                cout << "undefined operatop " << sign << endl;
                return 0;
            }
        }
    }
    if (opz.size() != 1)
    {
        cout << "stack corrupted" << endl;
        return 0;
    }
    cout << "result value is " << opz.top() << endl;
    return 0;
}*/
void str();
void exitString(char* bufptr);
int main() {
   
    str();
    return 0;
}
void str() {
    char* buffer = (char*)malloc(1024 * sizeof(char));
    std::cin >> buffer;
    exitString(buffer);      
}

void exitString(char* bufptr) {
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