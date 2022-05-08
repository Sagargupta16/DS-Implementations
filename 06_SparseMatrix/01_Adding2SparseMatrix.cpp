#include<iostream>
#include<cstddef>
using namespace std;

class Sparse{
    private:
        int **A;
        int x;
    public:
        Sparse(int n,int m, int l){
            A = new int*[3];
            A[0] = new int[l];
            A[1] = new int[l];
            A[2] = new int[l];
            A[0][0] = n;
            A[1][0] = m; 
            A[2][0] = l;
            x=1;
        }
        void SetSparse(int a,int i,int j){
            if(a!=0){
                A[0][x]=i;
                A[1][x]=j;
                A[2][x]=a;
                x++;
            }
        }
        void Display(){
            int y=1;
            for(int i=0;i<A[0][0];i++){
                for(int j=0;j<A[1][0];j++){
                    if(i==A[0][y]&&j==A[1][y])
                    {
                        cout<<A[2][y]<<" ";
                        y++;
                    }
                    else{
                        cout<<"0 ";
                    }
                }
                cout<<endl;
            }
            cout<<endl;
        }
        friend Sparse AddSparse(Sparse *s1, Sparse *s2);
        ~Sparse(){
            delete []A[0];
            delete []A[1];
            delete []A[2];
            delete []A;
        }
};
Sparse AddSparse(Sparse *s1,Sparse *s2){
    if (s1->A[0][0] != s2->A[0][0] || s1->A[0][0] != s2->A[0][0]){
        cout << "Different Dimensions ! " << endl;
        Sparse s3(0,0,0);
        return s3;
    }
    else{
        Sparse s3(s1->A[0][0], s1->A[1][0], s1->A[2][0] + s2->A[2][0]);
        int x=1,y=1;
        for(int i=1;i<=9;i++){
            if(x>s1->A[2][0]){
                s3.SetSparse(s2->A[2][y], s2->A[0][y], s2->A[1][y]);
                y++;
            }
            else if (y > s2->A[2][0])
            {
                s3.SetSparse(s1->A[2][x], s1->A[0][x], s1->A[1][x]);
                x++;
            }
            else if (s1->A[0][x] == s2->A[0][y] && s1->A[1][x] == s2->A[1][y] )
            {
                s3.SetSparse(s1->A[2][x]+s2->A[2][y],s1->A[0][x],s1->A[1][x]);
                x++;
                y++;
            }
            else if (s1->A[0][x] == s2->A[0][y]){
                if (s1->A[1][x] <= s2->A[1][y]){
                    s3.SetSparse(s1->A[2][x],s1->A[0][x],s1->A[1][x]);
                    x++;
                }
                else{
                    s3.SetSparse(s2->A[2][y], s2->A[0][y], s2->A[1][y]);
                    y++;
                }
            }
            else{
                if (s1->A[0][x] <= s2->A[0][y])
                {
                    s3.SetSparse(s1->A[2][x], s1->A[0][x], s1->A[1][x]);
                    x++;
                }
                else
                {
                    s3.SetSparse(s2->A[2][y], s2->A[0][y], s2->A[1][y]);
                    y++;
                }
            }
        }
        return s3;
    }
}

int main(){
    int n=4,m=5;
    int A[n][m]={{0,0,7,0,0},{2,0,0,5,0},{9,0,0,0,0},{0,0,0,0,4}};
    int B[n][m]={{0,2,0,0,0},{0,1,0,3,0},{0,0,6,0,0},{1,0,0,0,2}};
    Sparse s1(n,m,5);
    Sparse s2(n,m,6);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            s1.SetSparse(A[i][j],i,j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            s2.SetSparse(B[i][j], i, j);
        }
    }
    s1.Display();
    s2.Display();

    Sparse s3 = AddSparse(&s1,&s2);
    s3.Display();

    return 0;
}