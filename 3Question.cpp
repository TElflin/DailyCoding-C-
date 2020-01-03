#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;

class Node
{
public:

    Node (string name, Node *leftnod = nullptr, Node *rightnod = nullptr) : val(name), left(leftnod), right(rightnod) {}
//    string getVal();
//    Node getLeft();
//    Node getRight();
    ~Node (){}
//private:
    string val;
    Node *left;
    Node *right;

};

string serialize (Node &node)
{
    string null = "null";

    string leftStr;
    if
        (node.left == nullptr) leftStr = null;
    else
        leftStr = serialize(*node.left);

    string rightStr;
    if
        (node.right == nullptr) rightStr = null;
    else
        rightStr = serialize(*node.right);

    string strTree = node.val + "," + leftStr + "," + rightStr;
    return strTree ;
}

Node* deserializeVec(vector<string> &vecStr)
{
    string val = vecStr.front();
    vecStr.erase(vecStr.begin());
    if (val == "null") return nullptr;

    Node *node = new Node(val);
    node->left = deserializeVec(vecStr);
    node->right = deserializeVec(vecStr);

    return node;

}
Node deserialize (string strTree)
{
    vector<string> vecStr;
    stringstream iss(strTree);
    string token;

    while (getline(iss, token, ','))
    {
        vecStr.push_back(token);
    }

    return *deserializeVec(vecStr);
}
int main()
{

    Node node("root", new Node("left", new Node("left.left")), new Node("right"));

    string result = "";
    result = serialize(node);

    assert( deserialize(result).left->left->val == "left.left");


}
