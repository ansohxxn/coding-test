#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node 
{
public:
    int data;
    int x;
    int y;
    Node* leftChild = NULL;
    Node* rightChild = NULL;

    Node(int _data, int _x, int _y, Node* _leftChild, Node* _rightChild)
        :data(_data), x(_x), y(_y), leftChild(_leftChild), rightChild(_rightChild)
    { }
};

void BST_InsertNode(Node* tree, Node* node)
{
    if (node->x < tree->x) {
        if (tree->leftChild == NULL) {
            tree->leftChild = node;
            return;
        }
        else
            BST_InsertNode(tree->leftChild, node);
    }
    else if (node->x > tree->x) {
        if (tree->rightChild == NULL) {
            tree->rightChild = node;
            return;
        }
        else
            BST_InsertNode(tree->rightChild, node);
    }
}

void BST_PreOrder(Node* tree, vector<int>& pre)
{
    if (tree == NULL)
        return;
    pre.push_back(tree->data);
    BST_PreOrder(tree->leftChild, pre);
    BST_PreOrder(tree->rightChild, pre);
}

void BST_PostOrder(Node* tree, vector<int>& pos)
{
    if (tree == NULL)
        return;
    BST_PostOrder(tree->leftChild, pos);
    BST_PostOrder(tree->rightChild, pos);
    pos.push_back(tree->data);
}

bool cmp(Node& a, Node& b)
{
    if (a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    vector<vector<int>> answer;
    
    vector<Node> nodes;
    for (int i = 0; i < nodeinfo.size(); ++i)
        nodes.push_back(Node(i + 1, nodeinfo[i][0], nodeinfo[i][1], NULL, NULL));
    sort(nodes.begin(), nodes.end(), cmp);

    for (int i = 1; i < nodes.size(); ++i)
        BST_InsertNode(&nodes[0], &nodes[i]);

    vector<int> pre;
    BST_PreOrder(&nodes[0], pre);

    vector<int> pos;
    BST_PostOrder(&nodes[0], pos);

    answer.push_back(pre);
    answer.push_back(pos);

    return answer;
}