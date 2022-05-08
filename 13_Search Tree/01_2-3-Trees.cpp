//Also Called as Multi way Search Tree or M-Way 
#include<iostream>
using namespace std;

class TreeNode{
    public:
        int key1,key2;
        TreeNode* left;
        TreeNode* mid;
        TreeNode* right;
        TreeNode(int d){
            key1 = d;
            key2 =NULL;
            left =NULL;
            mid  =NULL;
            right=NULL;
        }
};

class Tree{
    private:
        TreeNode* root;
    public:
        Tree(){
            root=NULL;
        }
        void insert(int d){

        }

};



int main(){

    return 0;
}