#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

private:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};

// Helper function to build a binary tree from a level-order traversal
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i + 1 < vec.size()) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    // Example 1
    vector<string> nodes1 = {"1", "null", "2", "3"};
    TreeNode* root1 = buildTree(nodes1);
    cout << "Input: root = [1,null,2,3]" << endl;
    vector<int> result1 = solution.inorderTraversal(root1);
    cout << "Output: ";
    printVector(result1);

    // Example 2
    vector<string> nodes2 = {"1", "2", "3", "4", "5", "null", "8", "null", "null", "6", "7", "9"};
    TreeNode* root2 = buildTree(nodes2);
    cout << "Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]" << endl;
    vector<int> result2 = solution.inorderTraversal(root2);
    cout << "Output: ";
    printVector(result2);

    // Example 3
    vector<string> nodes3 = {};
    TreeNode* root3 = buildTree(nodes3);
    cout << "Input: root = []" << endl;
    vector<int> result3 = solution.inorderTraversal(root3);
    cout << "Output: ";
    printVector(result3);

    // Example 4
    vector<string> nodes4 = {"1"};
    TreeNode* root4 = buildTree(nodes4);
    cout << "Input: root = [1]" << endl;
    vector<int> result4 = solution.inorderTraversal(root4);
    cout << "Output: ";
    printVector(result4);

    return 0;
}
