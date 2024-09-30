#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infix_to_postfix(string expression) {
    string postfix = "";
    stack<char> s;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            s.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix.push_back(s.top());
                s.pop();
            }
            if (!s.empty()) s.pop();
        } else if (isalpha(expression[i]) || isdigit(expression[i])) {
            postfix.push_back(expression[i]);
        } else if (expression[i] == '+' || expression[i] == '-' ||
                   expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
            while (!s.empty() && s.top() != '(' && precedence(expression[i]) <= precedence(s.top())) {
                postfix.push_back(s.top());
                s.pop();
            }
            s.push(expression[i]);
        }
    }

    while (!s.empty()) {
        postfix.push_back(s.top());
        s.pop();
    }

    return postfix;
}

int main() {
    string expression;
    cout << "Enter an infix expression: ";
    cin >> expression;
    string postfix = infix_to_postfix(expression);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
