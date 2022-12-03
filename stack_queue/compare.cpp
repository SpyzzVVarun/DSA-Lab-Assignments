#include<bits/stdc++.h>
#include<chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

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
    // Comparing Stack
    Stack my_stack;
    stack<int> stl_stack;

    // Comparing push
    auto start = steady_clock::now();
    my_stack.push(10);
    auto end = steady_clock::now();
    double elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
    cout << "Time for push in my implementation of Stack: " << elapsed_time << " nanoseconds " << endl;

    start = steady_clock::now();
    stl_stack.push(10);
    end = steady_clock::now();
    elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
    cout << "Time for push in STL's implementation of Stack: " << elapsed_time << " nanoseconds " << endl;

    // Comparing pop
    start = steady_clock::now();
    my_stack.pop();
    end = steady_clock::now();
    elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
    cout << "Time for pop in my implementation of Stack: " << elapsed_time << " nanoseconds " << endl;

    start = steady_clock::now();
    stl_stack.pop();
    end = steady_clock::now();
    elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
    cout << "Time for pop in STL's implementation of Stack: " << elapsed_time << " nanoseconds " << endl;

    cout << " " << endl;

    // Comparing queue
    Queue my_queue;
    queue<int> stl_queue;

    // Comparing push
    start = steady_clock::now();
    my_queue.enqueue(10);
    end = steady_clock::now();
    elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
    cout << "Time for enqueue in my implementation of Queue: " << elapsed_time << " nanoseconds " << endl;

    start = steady_clock::now();
    stl_queue.push(10);
    end = steady_clock::now();
    elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
    cout << "Time for enqueue in STL's implementation of Queue: " << elapsed_time << " nanoseconds " << endl;

    // Comparing pop
    start = steady_clock::now();
    my_queue.dequeue();
    end = steady_clock::now();
    elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
    cout << "Time for dequeue in my implementation of Queue: " << elapsed_time << " nanoseconds " << endl;

    start = steady_clock::now();
    stl_queue.pop();
    end = steady_clock::now();
    elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
    cout << "Time for dequeue in STL's implementation of Queue: " << elapsed_time << " nanoseconds " << endl;

    return 0;
}



