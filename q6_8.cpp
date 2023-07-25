#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> pFreq(26, 0);
    vector<int> sFreq(26, 0);
    vector<int> result;

    int pLen = p.length();
    int sLen = s.length();

    for (char ch : p) {
        pFreq[ch - 'a']++;
    }

    int left = 0;
    int right = 0;

    while (right < sLen) {
        sFreq[s[right] - 'a']++;

        if (right - left + 1 > pLen) {
            sFreq[s[left] - 'a']--;
            left++;
        }

        if (pFreq == sFreq) {
            result.push_back(left);
        }

        right++;
    }

    return result;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> indices = findAnagrams(s, p);

    cout << "Start indices of p's anagrams in s: [";
    for (int i = 0; i < indices.size(); i++) {
        cout << indices[i];
        if (i < indices.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
