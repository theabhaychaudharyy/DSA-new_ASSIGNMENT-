#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool buddyStrings(string s, string goal) {
    int n = s.length();
    int diffCount = 0;
    vector<int> diffIndices;

    for (int i = 0; i < n; i++) {
        if (s[i] != goal[i]) {
            diffCount++;
            diffIndices.push_back(i);
        }

        if (diffCount > 2) {
            return false;
        }
    }

    if (diffCount == 0) {
        // s and goal are already equal
        // Check if there are duplicate characters in s
        vector<int> charCount(26, 0);
        for (char ch : s) {
            charCount[ch - 'a']++;
            if (charCount[ch - 'a'] > 1) {
                return true;
            }
        }
        return false;
    }

    if (diffCount == 2) {
        int index1 = diffIndices[0];
        int index2 = diffIndices[1];
        return (s[index1] == goal[index2] && s[index2] == goal[index1]);
    }

    return false;
}

int main() {
    string s = "ab";
    string goal = "ba";
    bool result = buddyStrings(s, goal);

    cout << boolalpha;
    cout << "Can swap two letters in s to obtain goal: " << result << endl;

    return 0;
}
