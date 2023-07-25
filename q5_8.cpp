#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int read = 0;
    int write = 0;

    while (read < n) {
        char currentChar = chars[read];
        int count = 0;

        while (read < n && chars[read] == currentChar) {
            read++;
            count++;
        }

        chars[write] = currentChar;
        write++;

        if (count > 1) {
            string countStr = to_string(count);
            for (char ch : countStr) {
                chars[write] = ch;
                write++;
            }
        }
    }

    return write;
}

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = compress(chars);

    cout << "The new length of the array is: " << newLength << endl;
    cout << "The modified array is: [";
    for (int i = 0; i < newLength; i++) {
        cout << "'" << chars[i] << "'";
        if (i < newLength - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
