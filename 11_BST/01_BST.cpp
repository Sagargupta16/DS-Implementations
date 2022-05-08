#include<iostream>
#include <stack>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

class Tree{
    public:
        int height(TreeNode* x){
            if(x==NULL){
                return 0;
            }
            int a=height(x->left);
            int b=height(x->right);
            return a>b ? a+1 : b+1;
        }//O(n);

        TreeNode* CreateTree(){
            int n,x;
            cout<<"Enter Number of Elements : ";
            cin>>n;
            cout<<"Enter "<<n<<" Elements : ";
            int A[n];
            TreeNode *a=NULL;
            for (int i = 0; i < n; i++){
                cin>>A[i];
            }
            return PreToBst(A,n);
        }//O(n)

        TreeNode* BstInsert(int d,TreeNode* r){
            if(r==NULL){
                TreeNode *a = new TreeNode(d);
                return a;
            }
            else if(r->data>d){
                if(r->left==NULL){
                    TreeNode *a = new TreeNode(d);
                    r->left = a;
                }
                else{
                    BstInsert(d,r->left);
                }
            }
            else if(r->data<d){
                if(r->right==NULL){
                    TreeNode *a = new TreeNode(d);
                    r->right = a;
                }
                else{
                    BstInsert(d,r->right);
                }
            }
            return r;
        }//O(Log(n))

        TreeNode* predecessor(TreeNode* r){
            while(r && r->right!=NULL){
                r=r->right;
            }
            return r;
        }//O(n)

        TreeNode* successor(TreeNode* r){
            while(r && r->left!=NULL){
                r=r->left;
            }
            return r;
        }//O(n)

        TreeNode* BstDelete(int key,TreeNode *r){    
            if(r==NULL){
                return NULL;
            }
            else if(r->left==NULL && r->left==NULL){
                delete r;
                r=NULL;
            }
            else if(key<r->data){
                r->left=BstDelete(key,r->left);
            }
            else if(key>r->data){
                r->right=BstDelete(key,r->right);
            }
            else{
                if(height(r->left)>height(r->right)){
                    TreeNode* q=predecessor(r->left);
                    r->data = q->data;
                    r->left = BstDelete(q->data,r->left);
                }
                else{
                    TreeNode* q=successor(r->right);
                    r->data = q->data;
                    r->right = BstDelete(q->data,r->right);
                }
            }
            return r;
        }//O(Log(n))

        TreeNode* RSearch(TreeNode *r,int key){
            if(r==NULL){
                return NULL;
            }
            else if(r->data==key){
                return r;
            }
            else if(r->data<key){
                return RSearch(r->right,key);
            }
            else{
                return RSearch(r->left,key);
            }
        }//O(Log(n))

        void InorderDisplay(TreeNode *r){
            if(r==NULL){
                return;
            }
            InorderDisplay(r->left);
            cout<<r->data<<" ";
            InorderDisplay(r->right);
        }//O(n)

        TreeNode *PreToBst(int A[],int n){
            stack<TreeNode*> s;
            int m=INT32_MAX;
            TreeNode * l=new TreeNode(m);
            s.push(l);
            TreeNode *t;
            int i=0;
            TreeNode *r = new TreeNode(A[i]);
            i++;
            TreeNode *p = r;
            while(i<n){
                if(A[i]<p->data){
                    t = new TreeNode(A[i]);
                    p->left = t;
                    s.push(p);
                    p=t;
                    i++;
                }
                else{
                    if(A[i]<(s.top())->data){
                        t = new TreeNode(A[i]);
                        p->right = t;
                        p = t;
                        i++;
                    }
                    else{
                        p=s.top();
                        s.pop();
                    }
                }
            }
            return r;
        }//O(n);
    
};

int main(){
    TreeNode *root=NULL;
    TreeNode *a=NULL;
    Tree T;

    int c,x;
    cout<<"----TREE MENU----"<<endl;
    cout<<"1. Create a BST "<<endl;
    cout<<"2. Insert in BST "<<endl;
    cout<<"3. Delete in BST "<<endl;
    cout<<"4. Search in BST "<<endl;
    cout<<"5. Display a BST "<<endl;
    cout<<"6. Quit "<<endl;
    do
    {
        cout<<"Enter your Choice : ";
        cin>>c;
        switch (c)
        {
        case 1:
            root=T.CreateTree();
            break;
        
        case 2:
            cout<<"Enter data You want to Insert : ";
            cin>>x;
            T.BstInsert(x,root);
            break;

        case 3:
            cout<<"Enter data You want to Delete : ";
            cin>>x;
            root=T.BstDelete(x,root);
            break;

        case 4:
            cout<<"Enter Data You want to Search : ";
            cin>>x;
            a = T.RSearch(root, x);
            if (a == NULL){
                cout << "Key Not Found!" << endl;
            }
            else{
                cout << "Key Found!" << endl;
            }
            break;

        case 5:
            T.InorderDisplay(root);
            cout<<endl;
            break;
        
        case 6:
            break;

        default:
            cout<<"Enter Valid Choice ! "<<endl;
            break;
        }

    }while(c!=6);
    
    return 0;
}