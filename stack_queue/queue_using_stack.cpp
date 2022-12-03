#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Queue
{
    public:
        stack<int> s1,s2;

        void enqueue(int ele)
        {
            s1.push(ele);
        }

        void dequeue()
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }

        void print_elements()
        {
            cout << "Queue using stack" << endl;
            stack<int> copy = s1;
            while (!copy.empty())
            {
                cout << copy.top() << " ";
                copy.pop();
            }
        }

};

int main(void)
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.print_elements();
    return 0;
}