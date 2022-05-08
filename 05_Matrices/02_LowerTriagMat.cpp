#include <iostream>
using namespace std;

class LTM
{
private:
    int *A;
    int n;

public:
    LTM(int a)
    {
        n = a;
        A = new int[(a * (a + 1)) / 2];
    }
    void Set(int i, int j, int y)
    {
        if (i>=j)
        {
            A[(((i-1)*i)/2)+j-1] = y;
        }
    }
    int get(int i, int j)
    {
        if (i >= j)
        {
            return A[(((i - 1) * i) / 2) + j - 1];
        }
        else
        {
            return 0;
        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= j)
                {
                    cout<<A[((i+1)*(i))/2+j]<< " ";
                }
                else
                {
                    cout<<"0 ";
                }
            }
            cout << endl;
        }
    }
    ~LTM()
    {
        delete[] A;
    }
};

int main()
{
    int n;
    cout << "Enter Dimensions : ";
    cin >> n;

    LTM l(n);

    int x;
    cout << "Enter All Elements : ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            l.Set(i, j, x);
        }
    }

    l.display();
    return 0;
}