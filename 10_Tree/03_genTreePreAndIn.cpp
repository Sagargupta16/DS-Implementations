#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(int d)
    {
        data = d;
        lchild = NULL;
        rchild = NULL;
    }
};

class BT
{
public:
    Node *root;
    BT()
    {
        root = NULL;
    }
    
};

int main(){
    int pro[]={4,7,9,6,3,2,5,8,1};
    int ino[]={7,6,9,3,4,5,8,2,1};
    int n = sizeof(pro)/sizeof(pro[0]);


    return 0;
}