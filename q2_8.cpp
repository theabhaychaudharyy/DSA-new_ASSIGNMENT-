#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> parenthesesStack;
    
    for (char ch : s) {
        if (ch == '(' || ch == '*') {
            parenthesesStack.push(ch);
        } else if (ch == ')') {
            if (!parenthesesStack.empty() && parenthesesStack.top() == '(') {
                parenthesesStack.pop();
            } else if (!parenthesesStack.empty() && parenthesesStack.top() == '*') {
                parenthesesStack.pop();
            } else {
                return false;
            }
        }
    }
    
    while (!parenthesesStack.empty() && parenthesesStack.top() == '*') {
        parenthesesStack.pop();
    }
    
    return parenthesesStack.empty();
}

int main() {
    string s = "()";
    bool isValidString = isValid(s);
    
    cout << boolalpha;  // Print "true" or "false" instead of "1" or "0"
    cout << "The string is valid: " << isValidString << endl;
    
    return 0;
}
