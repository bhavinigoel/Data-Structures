#include <iostream>
//#include <string>
#include "MyStack.h"
using namespace std;

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int performOperation(char op, int operand1, int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                cerr << "Error: Division by zero" << endl;
                exit;
            }
        default:
            cerr << " Invalid operator" << endl;
            exit;
    }
}

int evaluatePostfix(const string& postfix) {
    stack<int> operands;

    for (char c : postfix) {
        if (c >= '0' && c <= '9') {
          
            operands.push(c - '0');
        } else if (isOperator(c)) {
            
            int operand2 = operands.peek();
            operands.pop();
            int operand1 = operands.peek();
            operands.pop();
            int result = performOperation(c, operand1, operand2);
            operands.push(result);
        }
    }

    if (operands.is_empty()!=-1) {
        return operands.peek();
    } else {
        cerr << " Empty expression" << endl;
        exit(1);
    }
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}