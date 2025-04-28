#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    int x;
    int y;
    Node *left;
    Node *right;
    Node(int _data, int _x, int _y) : data(_data), x(_x), y(_y)
    {
        left = NULL;
        right = NULL;
    }
};

bool compares(Node a, Node b)
{
    if (a.y == b.y)
    {
        return a.x < b.x; // 같은 y이면 x 오름차순
    }
    else
    {
        return a.y > b.y; // 자식노드의 y는 부모노드 보다 큼
    }
}

void setParent(Node *parent, Node *node)
{

    if (parent->x > node->x)
    { // 노드가 paretn의 왼쪽에 있음
        if (parent->left == NULL)
        {
            parent->left = node;
            return;
        }
        setParent(parent->left, node);
    }
    else
    {
        if (parent->right == NULL)
        {
            parent->right = node;
            return;
        }
        setParent(parent->right, node);
    }
}

void preOrder(Node *root, vector<int> &v)
{
    v.push_back(root->data);
    if (root->left != NULL)
    {
        preOrder(root->left, v);
    }
    if (root->right != NULL)
    {
        preOrder(root->right, v);
    }
}

void postOrder(Node *root, vector<int> &v)
{
    if (root->left != NULL)
    {
        postOrder(root->left, v);
    }
    if (root->right != NULL)
    {
        postOrder(root->right, v);
    }
    v.push_back(root->data);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    vector<Node> tree;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        tree.push_back({i + 1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    sort(tree.begin(), tree.end(), compares);

    Node *root = &tree[0];
    for (int i = 1; i < tree.size(); i++)
    {
        setParent(root, &tree[i]);
    }
    vector<int> answer1;
    preOrder(root, answer1);

    vector<int> answer2;
    postOrder(root, answer2);

    answer.push_back(answer1);
    answer.push_back(answer2);
    return answer;
}