
// Basic Imports
#include<bits/stdc++.h>
#include<chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

// Struct to define Node
struct node
{
    int data;
    struct node *ptr;
};

// Function Declarations
struct node *create_node();
bool check_empty(struct node *p);
void empty();
void add_begin(int val,struct node **p);
void add_end(int val,struct node **p);
void add_node(int val,int pos,struct node **p);
void del_begin(struct node **p);
void del_end(struct node **p);
void del_node(int pos, struct node **p);
void print_node(struct node *p);
void compare();
struct node * add(struct node * first, struct node * second);
struct node * reverse(struct node * p);
struct node * solve(struct node * list1, struct node * list2);

int main()
{
    // Initializing head
    struct node *start = NULL;
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    add_begin(5,&list1);
    add_begin(4,&list1);
    add_begin(4,&list2);
    add_begin(8,&list2);

    // Menu Driven Program
    while (1)
    {
        int choice,pos,data;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert Node at last"<<endl;
        cout<<"3.Insert Node at position"<<endl;
        cout<<"4.Delete Node at beginning"<<endl;
        cout<<"5.Delete Node at last"<<endl;
        cout<<"6.Delete Node at position"<<endl;
        cout<<"7.Display Linked List"<<endl;
        cout<<"8.Compare with STL "<<endl;
        cout<<"9.Sum of 2 linked lists "<<endl;
        cout<<"10.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cin >> data;
            cout<<"Inserting Node at Beginning: "<<endl;
            add_begin(data,&start);
            cout<<endl;
            break;
        case 2:
            cin >> data;
            cout<<"Inserting Node at Last: "<<endl;
            add_end(data,&start);
            cout<<endl;
            break;
        case 3:
            cin >> pos;
            cin >> data;
            cout<<"Inserting Node at a given position:"<<endl;
            add_node(data,pos,&start);
            cout<<endl;
            break;
        case 4:
            cout<<"Deleting Node at beginning: "<<endl;
            del_begin(&start);
            break;
        case 5:
            cout<<"Deleting Node at end: "<<endl;
            del_end(&start);
            break;
        case 6:
            cin >> pos;
            cout<<"Deleting a particular node: "<<endl;
            del_node(pos,&start);
            break;
        case 7:
            cout<<"Display elements of link list"<<endl;
            print_node(start);
            cout<<endl;
            break;
        case 8:
            compare();
            break;
        case 9:
            print_node(solve(list1,list2));
            break;
        case 10:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
   
    return 0;
}

// Function to create a node
struct node *create_node()
{
    return (struct node *)malloc(sizeof(struct node));
}

// Function to check if the linked list is empty
bool check_empty(struct node *p)
{
    return (p==NULL);
}
// Function to print a message if linked list is empty
void empty()
{
    cout << "Empty Linked List" << endl;
}

// Function to add node to the beginning of linked list
void add_begin(int val,struct node **p)
{
    if (check_empty(*p))
    {
        *p = create_node();
        (*p)->data = val;
        (*p)->ptr = NULL;
        return;
    }
    struct node *temp = *p;
    *p = create_node();
    (*p)->data = val;
    (*p)->ptr = temp;
}

// Adding Node to the end of the list
void add_end(int val,struct node **p)
{
    struct node *temp = *p;
    
    // For Empty Linked List
    if (check_empty(*p))
    {
        add_begin(val,p);
    }
    // For linked list of size 1
    else if (temp->ptr == NULL)
    {
        temp->ptr = create_node();
        temp->ptr->data = val;
        temp->ptr->ptr = NULL;
    }
    else
    {
        while (temp->ptr != NULL)
        {
            temp = temp->ptr;
        
        }
        temp->ptr = create_node();
        temp->ptr->data = val;
        temp->ptr->ptr = NULL;
    }

}

// Function to add node at a particular index/position
void add_node(int val,int pos,struct node **p)
{
    try
    {
        if (check_empty(*p))
        {
            add_begin(val,p);
        }
        else
        {
            struct node *temp = *p;
            if (pos==1)
            {
                add_begin(val,p);
            }
            else if (pos==2)
            {
                struct node *posNode;
                posNode = temp->ptr;
                temp->ptr = create_node();
                temp->ptr->data = val;
                temp->ptr->ptr = posNode;
            }
            else
            {
                for (int i=1;i<pos-1;i++)
                {
                    temp = temp->ptr;
                }
                struct node *posNode;
                posNode = temp->ptr;
                temp->ptr = create_node();
                temp->ptr->data = val;
                temp->ptr->ptr = posNode;
            }
        }
    }
    catch(...)
    {
        cout << "Invalid Position" << endl;
    }
}

// Function to delete the first node
void del_begin(struct node **p)
{
    if (check_empty(*p))
    {
        empty();
    }
    else
    {
        *p = (*p)->ptr;
    } 
}

// Function to delete the last node
void del_end(struct node **p)
{
    struct node *temp = *p;
    // Checking empty linked list
    if (check_empty(*p))
    {
        empty();
    }
    // For linked list of size 1
    else if (temp->ptr == NULL)
    {
        del_begin(p);
    }
    else
    {
        while (temp->ptr->ptr!=NULL)
        {
            temp = temp->ptr;
        }
        temp->ptr = NULL;
    } 
}

// Function to delete node at a particular index/position
void del_node(int pos, struct node **p)
{
    try
    {
        if (check_empty(*p))
        {
            empty();
        }
        else
        {
            struct node *temp = *p;
            if (pos==1)
            {
                del_begin(p);
            }
            else if (pos==2)
            {
                temp->ptr = temp->ptr->ptr;
            }
            else
            {
                for (int i=1;i<pos-1;i++)
                {
                    temp = temp->ptr;
                }
                temp->ptr = temp->ptr->ptr;
            }
        }
    }
    catch(...)
    {
        cout << "Invalid Position" << endl;
    }
}

void print_node(struct node *p)
{
    struct node *temp = p;
    if (check_empty(p))
    {
        empty();
    }
    else if (temp->ptr == NULL)
    {
        cout << temp->data << endl;
    }
    else
    {
        while(temp != NULL)
        {
            cout << temp->data;
            // cout << " ";
            temp = temp->ptr;
        }
    }
    
}

void compare()
{
    struct node *st = NULL;
    add_begin(10,&st);

    auto start = steady_clock::now();
    add_end(20,&st);
    auto end = steady_clock::now();
    double elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
    cout << "time for a push_back in our linked list: " << elapsed_time << " nanoseconds " << endl;

    list<int> list1;
    list1.push_back(10);

    auto start1 = steady_clock::now(); 
    list1.push_back(20);
    auto end1 = steady_clock::now();
    double elapsed_time1 = double (duration_cast <nanoseconds> (end1 - start1).count());
    cout << "time for a push_back in STL linked list: " << elapsed_time1 << " nanoseconds " << endl << endl;

    auto start3 = steady_clock::now();
    del_end(&st);
    auto end3 = steady_clock::now();
    double elapsed_time3 = double (duration_cast <nanoseconds> (end3 - start3).count());
    cout << "time for a pop_front in our linked list: " << elapsed_time3 << " nanoseconds " << endl;

    auto start2 = steady_clock::now();
    list1.pop_front();
    auto end2 = steady_clock::now();
    double elapsed_time2 = double (duration_cast <nanoseconds> (end2 - start2).count());
    cout << "time for a pop_front in STL linked list: " << elapsed_time2 << " nanoseconds " << endl;
}


struct node * add(struct node * first, struct node * second) {
  struct node * res = NULL;
  struct node * temp;
  struct node * prev = NULL;
  int carry = 0, sum = 0;
  while (first != NULL || second != NULL) 
  {
        sum = carry;
        sum += first != NULL ? first -> data : 0;
        sum += second != NULL ? second -> data : 0;
        carry = (sum >= 10) ? 1 : 0;
        sum %= 10;
        temp = create_node();
        temp->data = sum;
        temp -> ptr = NULL;
        if (res != NULL) 
        {
            prev -> ptr = temp;
        } 
        else
        {
            res = temp;
        }
        prev = temp;
        if (first)
        {
            first = first -> ptr;
        }
        if (second) 
        {
            second = second -> ptr;
        }
  }

  if (carry > 0)
  {
    temp -> ptr = create_node();
    temp -> ptr -> data = carry;
    temp -> ptr -> ptr = NULL;
  }
  return res;
}

struct node * reverse(struct node * p) 
{
  if (p == NULL || p -> ptr == NULL) 
  {
    return p;
  }
  struct node * rest = reverse(p -> ptr);
  p -> ptr -> ptr = p;
  p -> ptr = NULL;
  return rest;
}

struct node * solve(struct node * list1, struct node * list2)
{
  struct node * sum = reverse(add(reverse(list1), reverse(list2)));
  return sum;
}
