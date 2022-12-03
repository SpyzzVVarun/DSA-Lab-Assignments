#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Stack
{
    public:
        list<int> l;
        int top = 0;

        bool empty()
        {
            return (top==0);
        }

        void push(int ele)
        {
            top ++;
            l.push_front(ele);
        }

        void pop()
        {
            if (empty())
            {
                cout << "Stack is Empty" << endl;
            }
            else
            {
                top--;
                l.pop_front();
            }
        }

        void print_elements()
        {
            for (auto ele: l)
            {
                cout << ele << endl;
            }
        }        
};

class Queue
{
    public:
        list<int> l;
        int head = 0,tail=  0;

        bool empty()
        {
            return (head==tail);
        }

        void enqueue(int ele)
        {
            tail++;
            l.push_back(ele);
        }

        void dequeue()
        {
            head++;
            l.pop_front();
        }

        void print_elements()
        {
            for (auto ele: l)
            {
                cout << ele << " ";
            }
        }     
};

int main(void)
{
    cout << "Stack" << endl;
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.print_elements();
    cout << " " << endl;  
    Queue q;
    cout << "Queue" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.print_elements();
    return 0;
}