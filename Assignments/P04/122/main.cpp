#include <bits/stdc++.h>
using namespace std;
struct Node
{
    bool value=false;// Mark whether the node has been assigned
    int data;// Data field
    Node*left=nullptr,*right=nullptr;// Left and right child pointer
};

bool f = true;
// Mark whether a node is repeatedly assigned
 void insert(int data, string s, Node *root)
{
    // Insert node
    for (auto c : s) // Traverse the string of the location of the flag node
        if (c == 'L')
        {
            // If it is an L character, insert into the left subtree
            if (root->left == nullptr)
                root->left = new Node();
            root = root->left;
        }
        else
        {
            // If it is an R character, insert into the right subtree
            if (root->right == nullptr)
                root->right = new Node();
            root = root->right;
        }
    if (root->value) //The current node has been assigned
        f = false;   //The node is repeatedly assigned
    root->data = data;
    // Update the node data field 
    root->value = true; //The node has been assigned
}
bool levelOrder(Node *root, vector<int> &level)
{
    // Level traversal 
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        if (!root->value)
            // The node is not assigned, return false 
            return false;
            level.push_back(root->data);
        if (root->left != nullptr)
            q.push(root->left);
        if (root->right != nullptr)
            q.push(root->right);
    }
    return true;
}
int main()
{
    string input;
    Node *root = new Node();
    while (cin >> input)
    {
        if (input == "()")
        { // is an empty parenthesis, a tree has been entered
            vector<int> level;
            // Storage hierarchy traversal sequence
             if (f && levelOrder(root, level))
            {
                for (int i = 0; i < level.size(); ++i)
                    printf("%s%d", i > 0 ? " " : "", level[i]);
                puts("");
            }
            else puts("not complete");
            root = new Node();
            f = true;
        }
        else
        {
            int i = input.find(',');
            insert(stoi(input.substr(1, i - 1)), input.substr(i + 1, input.size() - 2 - i), root);
        }
    }
    return 0;
}
