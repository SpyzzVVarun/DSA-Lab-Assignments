#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Stack
{
    public:
        queue<int> q1,q2;

        void push(int ele)
        {
            q1.push(ele);
        }

        void pop()
        {
            if (q1.empty())
            {
                return;
            }

            while (q1.size()!=1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();

            queue<int> q = q1;
            q1 = q2;
            q2 = q;
        }
        void print_elements()
        {
            cout << "Stack using queue" << endl;
            queue<int> copy = q1;
            while (!copy.empty())
            {
                cout << copy.front() << endl;
                copy.pop();
            }

        }
};

int main(void)
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.print_elements();
    return 0;
}