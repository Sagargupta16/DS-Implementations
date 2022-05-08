#include<iostream>
#include<stack>
using namespace std;

class TreeNode{
    public:
    int data;
    int height;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d,int h){
        data = d;
        height = h;
        left = NULL;
        right = NULL;
    }
};

class Avl{
    public:
        int height(TreeNode* x){
            if(x==NULL){
                return 0;
            }
            int a=height(x->left);
            int b=height(x->right);
            return a>b ? a+1 : b+1;
        }//O(n);

        int BalanceFactor(TreeNode* r){
            if(r==NULL){
                return 0;
            }
            return height(r->left)-height(r->right);
        }

        TreeNode* LLRotation(TreeNode* r){
            TreeNode* x = r->left;
            x->right = r;
            r->left=NULL;
            return x;
        }
        TreeNode* LRRotation(TreeNode* r){
            TreeNode* x = r->left->right;
            x->left = r->left;
            x->right = r;
            r->left=NULL;
            x->left->right=NULL;
            return x;
        }
        TreeNode* RRRotation(TreeNode* r){
            TreeNode* x = r->right;
            x->left = r;
            r->right=NULL;
            return x;
        }
        TreeNode* RLRotation(TreeNode* r){
            TreeNode* x = r->right->left;
            x->right = r->right;
            x->left = r;
            r->right=NULL;
            x->right->left=NULL;
            return x;
        }
        TreeNode* L0Rotation(TreeNode* r){
            TreeNode *x = r->left;
            TreeNode *y = x->right;
            x->right = NULL;
            r->left = NULL;
            y->left = x;
            y->right = r;
            return y;
        }
        TreeNode* R0Rotation(TreeNode* r){
            TreeNode *x = r->right;
            TreeNode *y = x->left;
            x->left = NULL;
            r->right = NULL;
            y->right = x;
            y->left = r;
            return y;
        }

        TreeNode* AvlInsert(TreeNode* r,int d){
            if (r == NULL){
                TreeNode *a = new TreeNode(d,1);
                return a;
            }
            if(d<r->data){
                r->left = AvlInsert(r->left,d);
            }
            else{
                r->right = AvlInsert(r->right,d);
            }
            r->height = height(r);

            int b = BalanceFactor(r);
            int bl = BalanceFactor(r->left);
            int br = BalanceFactor(r->right);
            if(b==2){
                if(bl==1){
                    return LLRotation(r);
                }
                else if(bl==-1){
                    return LRRotation(r);
                }
            }
            else if(b==-2){
                if(br==-1){
                    return RRRotation(r);
                }
                else if(br==1){
                    return RLRotation(r);
                }
            }

            return r;
        }
        void InorderDisplay(TreeNode *r){
            if(r==NULL){
                return;
            }
            InorderDisplay(r->left);
            cout<<r->data<<" ";
            InorderDisplay(r->right);
        }//O(n)
        void PreorderDisplay(TreeNode *r){
            if(r==NULL){
                return;
            }
            cout << r->data << " ";
            PreorderDisplay(r->left);
            PreorderDisplay(r->right);
        }//O(n)
        void PostorderDisplay(TreeNode *r){
            if(r==NULL){
                return;
            }
            PostorderDisplay(r->left);
            PostorderDisplay(r->right);
            cout << r->data << " ";
        }//O(n)

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

        TreeNode* AvlDelete(int key,TreeNode *r){    
            if(r==NULL){
                return NULL;
            }
            else if(r->left==NULL && r->left==NULL){
                delete r;
                r=NULL;
                return r;
            }
            else if(key<r->data){
                r->left=AvlDelete(key,r->left);
            }
            else if(key>r->data){
                r->right=AvlDelete(key,r->right);
            }
            else{
                if(height(r->left)>height(r->right)){
                    TreeNode* q=predecessor(r->left);
                    r->data = q->data;
                    r->left = AvlDelete(q->data,r->left);
                }
                else{
                    TreeNode* q=successor(r->right);
                    r->data = q->data;
                    r->right = AvlDelete(q->data,r->right);
                }
            }
            int b = BalanceFactor(r);
            int bl = BalanceFactor(r->left);
            int br = BalanceFactor(r->right);
            if(b==2){
                if(bl==1){
                    return LLRotation(r);
                }
                else if(bl==-1){
                    return LRRotation(r);
                }
                else{
                    return L0Rotation(r);
                }
            }
            else if(b==-2){
                if(br==-1){
                    return RRRotation(r);
                }
                else if(br==1){
                    return RLRotation(r);
                }
                else{
                    return R0Rotation(r);
                }
            }
            return r;
        }//O(Log(n))
};


int main(){
    TreeNode *root=NULL;
    TreeNode *a=NULL;
    Avl T;

    int c,x;
    cout<<"----TREE MENU----"<<endl;
    cout<<"1. Insert in AVL "<<endl;
    cout<<"2. Delete in AVL "<<endl;
    cout<<"3. Display a AVL "<<endl;
    cout<<"4. Quit "<<endl;
    do
    {
        cout<<"Enter your Choice : ";
        cin>>c;
        switch (c)
        {
        case 1:
            cout<<"Enter data You want to Insert : ";
            cin>>x;
            root=T.AvlInsert(root,x);
            break;
        case 2:
            cout << "Enter data You want to Delete : ";
            cin >> x;
            root = T.AvlDelete(x,root);
            break;

        case 3:
            cout<<"Inorder   : ";
            T.InorderDisplay(root);
            cout<<endl;
            cout << "Preorder  : ";
            T.PreorderDisplay(root);
            cout << endl;
            cout << "Postorder : ";
            T.PostorderDisplay(root);
            cout << endl;
            break;
        
        case 4:
            break;

        default:
            cout<<"Enter Valid Choice ! "<<endl;
            break;
        }

    }while(c!=4);
    
    return 0;
}