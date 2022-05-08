#include<iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        int col=0;//0 black,1 red
        TreeNode* left;
        TreeNode* right;
        TreeNode(int d){
            data=d;
            col =1;
            left=NULL;
            right=NULL;
        }
};


int main(){
    
    return 0;
}