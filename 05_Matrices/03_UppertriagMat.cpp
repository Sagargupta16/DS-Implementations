#include <iostream>
using namespace std;

class UTM
{
private:
    int *A;
    int n;

public:
    UTM(int a)
    {
        n = a;
        A = new int[(a * (a + 1)) / 2];
    }
    void Set(int i, int j, int y)
    {
        if (j >= i)
        {
            A[(((j - 1) * j) / 2) + i - 1] = y;
        }
    }
    int get(int i, int j)
    {
        if (j >= i)
        {
            return A[(((j - 1) * j) / 2) + i - 1];
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
                if (j >= i)
                {
                    cout << A[(((j + 1) * j) / 2) + i] << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    ~UTM()
    {
        delete[] A;
    }
};

int main()
{
    int n;
    cout << "Enter Dimensions : ";
    cin >> n;

    UTM u(n);

    int x;
    cout << "Enter All Elements : ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            u.Set(i, j, x);
        }
    }

    u.display();
    return 0;
}