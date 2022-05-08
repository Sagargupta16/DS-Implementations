#include <iostream>
using namespace std;

class SYM
{
private:
    int *A;
    int n;

public:
    SYM(int a)
    {
        n = a;
        A = new int[(a * (a + 1)) / 2];
    }
    void Set(int i, int j, int y)
    {
        if (i >= j)
        {
            A[(((i - 1) * i) / 2) + j - 1] = y;
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
            return A[(((j - 1) * j) / 2) + i - 1];
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
                    cout << A[((i + 1) * (i)) / 2 + j] << " ";
                }
                else
                {
                    cout << A[((j + 1) * (j)) / 2 + i] << " ";
                }
            }
            cout << endl;
        }
    }
    ~SYM()
    {
        delete[] A;
    }
};

int main()
{
    int n;
    cout << "Enter Dimensions : ";
    cin >> n;

    SYM l(n);

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