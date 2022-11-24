#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

using namespace std;

//Part 2
class Node 
{
    public:
    Node *left;
    Node *right;
    int num;

    Node(int n) : num(n){}
};

//using breadth first search approach
string serialize(Node *root)
{
    string temp;
    if (root == nullptr)
    {
        return "";
    }
    else
    {
        deque<Node*> ser;
        ser.push_front(root);
        Node *cur;
        while(ser.empty()==false)
        {
            cur = ser.front();
            ser.pop_front();
            if(cur!=nullptr)
            {
                temp+=to_string(cur->num);
                temp+="|"; // in case value is more than 1 digit
                ser.push_back(cur->left);
                ser.push_back(cur->right);
            }
            else
            {
                temp+="X";
            }
        }
    }
    return temp;
}
Node * deserialize(string str)
{
    if (str.length()==0)
    {
        return nullptr;
    }
    istringstream runner(str);
    string temp;
    const char comma = ',';
    getline(runner, temp, comma);
    deque<Node*> dq;
    int t = stoi(temp); // to change to any type, modify this line
    Node* node;
    node->num = t;
    Node *root = node;
    dq.push_front(node);
    while(!dq.empty())
    {
        node = dq.front();
        dq.pop_front();
        getline(runner, temp, comma);
        if(temp == "X")
        {
            node->left==nullptr;
        }
        else
        {
            Node * n = new Node(stoi(temp));
            node->left = n;
            dq.push_back(n);
        }
        getline(runner, temp, comma);
        if(temp == "X")
        {
            node->right==nullptr;
        }
        else
        {
            Node * n = new Node(stoi(temp));
            node->right= n;
            dq.push_back(n);
        }
    }
    return root;
}

// Part 3
