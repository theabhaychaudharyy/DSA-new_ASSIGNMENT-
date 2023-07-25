#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* constructTree(string s, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int i = s.find_first_not_of("0123456789", start);
    if (i == string::npos || i > end) {
        int value = stoi(s.substr(start, end - start + 1));
        return new TreeNode(value);
    }

    int value = stoi(s.substr(start, i - start));
    TreeNode* node = new TreeNode(value);
    node->left = constructTree(s, start + 2, i - 2);
    node->right = constructTree(s, i + 1, end - 1);

    return node;
}

TreeNode* constructTreeFromString(string s) {
    int n = s.length();
    if (n == 0) {
        return nullptr;
    }

    return constructTree(s, 0, n - 1);
}

void printInorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    string input = "4(2(3)(1))(6(5))";
    TreeNode* root = constructTreeFromString(input);

    cout << "Inorder traversal of the constructed binary tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
