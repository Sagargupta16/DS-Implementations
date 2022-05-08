#include <iostream>
using namespace std;

class TM
{
private:
    int *A;
    int n;

public:
    TM(int a)
    {
        n = a;
        A = new int[2*a-1];
    }
    void Set(int i, int j, int y)
    {
        if (i==1)
        {
            A[j-1] = y;
        }
        else if(j==1){
            A[n+i-2] = y;
        }
    }
    int get(int i, int j)
    {
        if (j>=i)
        {
            return A[j-i];
        }
        else
        {
            return A[n+i-j-1];
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
                    cout << A[j - i] << " ";
                }
                else
                {
                    cout << A[n + i - j - 1] << " ";
                }
            }
            cout << endl;
        }
    }
    ~TM()
    {
        delete[] A;
    }
};

int main()
{
    int n;
    cout << "Enter Dimensions : ";
    cin >> n;

    TM t(n);

    int x;
    cout << "Enter All Elements : ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            t.Set(i, j, x);
        }
    }

    t.display();
    return 0;
}