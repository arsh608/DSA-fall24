#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm> // For reverse function

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

//function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

//infix to prefix
string infix_to_prefix(string expression) {
    // Step 1: Reverse the infix expression
    reverse(expression.begin(), expression.end());

    // Step 2: Swap '(' with ')' and vice versa
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') expression[i] = ')';
        else if (expression[i] == ')') expression[i] = '(';
    }

    // Step 3: Perform infix to postfix on the modified expression
    string postfix = "";
    stack<char> s;

    for (int i = 0; i < expression.length(); i++) {
        // If character is '(', push it to the stack
        if (expression[i] == '(') {
            s.push(expression[i]);
        } 
        // If character is ')', pop and add to result until '(' is found
        else if (expression[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix.push_back(s.top());
                s.pop();
            }
            if (!s.empty()) s.pop(); // Remove '(' from stack
        } 
        else if (isalpha(expression[i]) || isdigit(expression[i])) {
            postfix.push_back(expression[i]);
        } 
        //character is an operator
        else if (isOperator(expression[i])) {
            while (!s.empty() && s.top() != '(' && precedence(expression[i]) < precedence(s.top())) { //here the same precedence will also be added to stack
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

    // Step 4: Reverse the postfix expression to get the prefix expression
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string expression;
    cout << "Enter an infix expression: ";
    cin >> expression;

    string prefix = infix_to_prefix(expression);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
