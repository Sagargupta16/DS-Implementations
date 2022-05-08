#include <iostream>
using namespace std;

class Stack
{
public:
    int Top = -1;
    char ar[1000];
    bool isEmpty()
    {
        if (Top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    char pop()
    {
        if (!isEmpty())
        {
            Top--;
            return ar[Top + 1];
        }
        return -1;
    }
    void push(char x)
    {
        if (Top == 999)
        {
            cout << "Stack is Full " << endl;
        }
        else
        {
            Top++;
            ar[Top] = x;
        }
    }
    void display()
    {
        char a;
        if (isEmpty())
        {
            return;
        }
        else
        {
            a = pop();
            display();
            cout << a << " ";
            push(a);
        }
    }
};
int precedence(char a)
{
    if (a == '*')
    {
        return 3;
    }
    else if (a == '/')
    {
        return 2;
    }
    else if (a == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    Stack s;
    string x, y = "", z;
    int i, w = 1;
    cout << "Enter Inline Expression without space : ";
    cin >> x;

    for (i = 0; i < x.length(); i++)
    {
        z = "";
        if (x[i] == '*' || x[i] == '/' || x[i] == '+' || x[i] == '-')
        {
            if (s.ar[s.Top] == '(' || s.Top == -1)
            {
                s.push(x[i]);
            }
            else
            {
                if (precedence(x[i]) <= precedence(s.ar[s.Top]))
                {
                    while (s.ar[s.Top] != '(' && s.Top != -1)
                    {
                        y = y + s.pop() + ' ';
                    }
                    if (s.ar[s.Top] == '(')
                    {
                        s.pop();
                    }
                    s.push(x[i]);
                }
                else
                {
                    s.push(x[i]);
                }
            }
        }
        else if (x[i] == '(')
        {
            s.push(x[i]);
        }
        else if (x[i] == ')')
        {
            while (s.ar[s.Top] != '(')
            {
                y = y + s.pop() + ' ';
            }
            s.pop();
        }
        else if (x[i] >= '0' && x[i] <= '9')
        {
            while (x[i] >= '0' && x[i] <= '9')
            {
                z = z + x[i];
                i++;
            }
            i--;
            y = y + z + ' ';
        }
        else
        {
            y = y + x[i] + ' ';
        }
        cout << w << ".String :" << y << endl;
        cout << w << ".Stack  :";
        s.display();
        cout << endl
             << endl;
        w++;
    }
    while (!s.isEmpty())
    {
        y = y + s.pop() + ' ';
        cout << w << ".String :" << y << endl;
        cout << w << ".Stack  :";
        s.display();
        cout << endl
             << endl;
        w++;
    }

    cout << "PostFix is : " << y << endl;
}