
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
bool checkEmpty(struct node *p);
void empty();
void addBegin(int val,struct node **p);
void addEnd(int val,struct node **p);
void addNode(int val,int pos,struct node **p);
void delBegin(struct node **p);
void delEnd(struct node **p);
void delNode(int pos, struct node **p);
void printNode(struct node *p);
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
    addBegin(5,&list1);
    addBegin(4,&list1);
    addBegin(4,&list2);
    addBegin(8,&list2);

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
            addBegin(data,&start);
            cout<<endl;
            break;
        case 2:
            cin >> data;
            cout<<"Inserting Node at Last: "<<endl;
            addEnd(data,&start);
            cout<<endl;
            break;
        case 3:
            cin >> pos;
            cin >> data;
            cout<<"Inserting Node at a given position:"<<endl;
            addNode(data,pos,&start);
            cout<<endl;
            break;
        case 4:
            cout<<"Deleting Node at beginning: "<<endl;
            delBegin(&start);
            break;
        case 5:
            cout<<"Deleting Node at end: "<<endl;
            delEnd(&start);
            break;
        case 6:
            cin >> pos;
            cout<<"Deleting a particular node: "<<endl;
            delNode(pos,&start);
            break;
        case 7:
            cout<<"Display elements of link list"<<endl;
            printNode(start);
            cout<<endl;
            break;
        case 8:
            compare();
            break;
        case 9:
            printNode(solve(list1,list2));
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
bool checkEmpty(struct node *p)
{
    return (p==NULL);
}
// Function to print a message if linked list is empty
void empty()
{
    cout << "Empty Linked List" << endl;
}

// Function to add node to the beginning of linked list
void addBegin(int val,struct node **p)
{
    if (checkEmpty(*p))
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
void addEnd(int val,struct node **p)
{
    struct node *temp = *p;
    
    // For Empty Linked List
    if (checkEmpty(*p))
    {
        addBegin(val,p);
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
void addNode(int val,int pos,struct node **p)
{
    try
    {
        if (checkEmpty(*p))
        {
            addBegin(val,p);
        }
        else
        {
            struct node *temp = *p;
            if (pos==1)
            {
                addBegin(val,p);
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
void delBegin(struct node **p)
{
    if (checkEmpty(*p))
    {
        empty();
    }
    else
    {
        *p = (*p)->ptr;
    } 
}

// Function to delete the last node
void delEnd(struct node **p)
{
    struct node *temp = *p;
    // Checking empty linked list
    if (checkEmpty(*p))
    {
        empty();
    }
    // For linked list of size 1
    else if (temp->ptr == NULL)
    {
        delBegin(p);
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
void delNode(int pos, struct node **p)
{
    try
    {
        if (checkEmpty(*p))
        {
            empty();
        }
        else
        {
            struct node *temp = *p;
            if (pos==1)
            {
                delBegin(p);
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

void printNode(struct node *p)
{
    struct node *temp = p;
    if (checkEmpty(p))
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
    addBegin(10,&st);

    auto start = steady_clock::now();
    addEnd(20,&st);
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
    delEnd(&st);
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
