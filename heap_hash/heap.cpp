#include <iostream>
#include <bits/stdc++.h>
#include<chrono>

typedef long long ll;
#define PB push_back

using namespace std;
using namespace std::chrono;

void compare();

// Min Heap
class Heap
{
    private:
        vector<ll> heap;

        // Get left child of a node if it exists
        ll left(ll parent)
        {
            ll left;
            left = 2*parent+1;
            if (left < heap.size())
            {
                return left;
            }
            else
            {
                return -1;
            }
        }

        // Get right child of a node if it exists
        ll right(ll parent)
        {
            ll right;
            right = 2*parent+2;
            if (right < heap.size())
            {
                return right;
            }
            else
            {
                return -1;
            }
        }

        //  Get parent node of a node if it exists
        ll parent(ll child)
        {
            ll parent;
            parent = (child-1)/2;
            if (child == 0)
            {
                return -1;
            }
            else
            {
                return parent;
            }
        }

        // Maintain heap structure in bottom to top manner
        void heapifyup(ll index) 
        {
            if (index >= 0 && parent(index) >= 0 && heap[parent(index)] > heap[index])
            {
                ll temp;
                temp = heap[index];
                heap[index] = heap[parent(index)];
                heap[parent(index)] = temp;
                heapifyup(parent(index));
            }
        }

        // Maintain heap structure in top to bottom manner
        void heapifydown(ll index)
        {
            ll c1,c2,t;
            c1= left(index);
            c2 = right(index);
            if (c1 >= 0 && c2 >= 0 && heap[c1] > heap[c2]) 
            {
                c1 = c2;
            }
            if (c1 > 0 && heap[index] > heap[c1])
            {
                t = heap[index];
                heap[index] = heap[c1];
                heap[c1] = t;
                heapifydown(c1);
            }
        }

    public:
    
        // Get number of elements in the heap
        ll size()
        {
            return heap.size();
        }

        // Insert an element in the heap while maintaining the heap properties   
        void insert(ll val) 
        {
            heap.PB(val);
            heapifyup(heap.size()-1);
        }

        // Delete the minimum element, i.e. the root node, of the min heap
        void delete_min()
        {
            if (heap.size() == 0)
            {
                cout<<"Heap is Empty"<<endl;
                return;
            }
            heap[0] = heap.at(heap.size() - 1);
            heap.pop_back();
            heapifydown(0);
            cout<<"Element Deleted"<<endl;
        }

        // Extract the minimum element, i.e. the root node, of the min heap
        ll get_min() 
        {
            if (heap.size() == 0)
            {
                return -1;
            }
            else
            {
                return heap.front();
            }
            return heap.front();
        }

        // Print the elements of the heap
        void print_heap()
        {
            cout<<"Heap"<< "\n";
            for (auto i = heap.begin();i != heap.end();i++)
            {
                cout << *i << " ";
            }
            cout<< "\n";
        }
};

int main()
{
    Heap h;
    // Menu driven program
    while (1) 
    {
        ll choice,element;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Minimum Element"<<endl;
        cout<<"3.Get Minimum Element"<<endl;
        cout<<"4.Print Heap"<<endl;
        cout<<"5.Compare with STL"<<endl;
        cout<<"6.Exit"<<endl;
        
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>element;
                h.insert(element);
                break;
            case 2:
                h.delete_min();
                break;
            case 3:
                if (h.get_min() == -1)
                {
                    cout<<"Heap is Empty"<<endl;
                }
                else
                {
                    cout<<"Minimum Element: "<<h.get_min()<<endl;
                }
                break;
            case 4:
                cout<<"Displaying elements of Hwap: ";
                h.print_heap();
                break;
            case 5:
                compare();
                break;
            case 6:
                cout<<"Exiting..."<<endl;
                exit(1);
                break;  
            default:
                cout<<"Incorrect Choice!!!"<<endl;
        }
    }
   return 0;
}

void compare()
{
   Heap heap;
   vector<long long> stl_h;

   for(int i = 0; i < 50; i++)
    {
        ll random = rand()/50;
        heap.insert(random);
        stl_h.push_back(random);
    }

   ll k = rand()/50; 
   auto start = steady_clock::now();
   heap.insert(k);
   auto end = steady_clock::now();
   double elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
   cout << endl;
   cout << "Time for Insert in my implementation: " << elapsed_time << " nanoseconds " << endl;

   start = steady_clock::now();
   stl_h.push_back(k);
   end = steady_clock::now();
   elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
   cout << "Time for Insert in STL's implementation: " << elapsed_time << " nanoseconds " << endl;
   cout << endl;
}