#include <iostream>
using namespace std;

class TreeNode
{
public:
    int key1,key2,key3;
    TreeNode *left;
    TreeNode *mid1;
    TreeNode *mid2;
    TreeNode *right;
    TreeNode(int d)
    {
        key1 = d;
        key2 = NULL;
        left = NULL;
        mid1 = NULL;
        mid2 = NULL;
        right = NULL;
    }
};

class Tree
{
private:
    TreeNode *root;

public:
    Tree()
    {
        root = NULL;
    }
    void insert(int d)
    {
    }
};

int main()
{

    return 0;
}