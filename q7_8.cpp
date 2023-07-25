#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string s) {
    stack<char> stk;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] != ']') {
            stk.push(s[i]);
        } else {
            string currString = "";
            while (!stk.empty() && stk.top() != '[') {
                currString = stk.top() + currString;
                stk.pop();
            }
            stk.pop();  // Pop the '['

            string repeatString = "";
            while (!stk.empty() && isdigit(stk.top())) {
                repeatString = stk.top() + repeatString;
                stk.pop();
            }
            int repeat = stoi(repeatString);

            string repeatedSubstring = "";
            for (int j = 0; j < repeat; j++) {
                repeatedSubstring += currString;
            }

            for (char ch : repeatedSubstring) {
                stk.push(ch);
            }
        }
    }

    string decodedString = "";
    while (!stk.empty()) {
        decodedString = stk.top() + decodedString;
        stk.pop();
    }

    return decodedString;
}

int main() {
    string s = "3[a]2[bc]";
    string decodedString = decodeString(s);

    cout << "Decoded string: " << decodedString << endl;

    return 0;
}
