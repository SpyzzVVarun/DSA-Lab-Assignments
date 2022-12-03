// Basic Imports
#include<bits/stdc++.h>
#include<chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

struct node
{
    int data;
    struct node *ptr;
    struct node *back_ptr;
};

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

int main()
{
    struct node *start = NULL;
    while (1)
    {
        int choice,pos = 0,data = 0;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Doubly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert Node at last"<<endl;
        cout<<"3.Insert Node at position"<<endl;
        cout<<"4.Delete Node at beginning"<<endl;
        cout<<"5.Delete Node at last"<<endl;
        cout<<"6.Delete Node at position"<<endl;
        cout<<"7.Display Linked List"<<endl;
        cout<<"8.Compare with STL "<<endl;
        cout<<"9.Exit "<<endl;
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
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
   
    return 0;
}

struct node *create_node()
{
    return (struct node *)malloc(sizeof(struct node));
}

bool check_empty(struct node *p)
{
    return (p==NULL);
}

void empty()
{
    cout << "Empty Linked List" << endl;
}

void add_begin(int val,struct node **p)
{
    struct node *temp = *p;
    *p = create_node();
    (*p)->data = val;
    (*p)->ptr = temp;
    (*p)->back_ptr = NULL;
    temp->back_ptr = *p;
}

void add_end(int val,struct node **p)
{
    struct node *temp = *p;
    if (check_empty(*p))
    {
        add_begin(val,p);
    }
    else if (temp->ptr == NULL)
    {
        temp->ptr = create_node();
        temp->ptr->data = val;
        temp->ptr->ptr = NULL;
        temp->ptr->back_ptr = temp;
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
        temp->ptr->back_ptr = temp;
    }

}

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
                struct node *tempp;
                tempp = temp->ptr;
                temp->ptr = create_node();
                temp->ptr->data = val;
                temp->ptr->ptr = tempp;
                temp->ptr->back_ptr = temp;
                tempp->back_ptr = temp->ptr;
            }
            else
            {
                for (int i=1;i<pos-1;i++)
                {
                    temp = temp->ptr;
                }
                struct node *tempp;
                tempp = temp->ptr;
                temp->ptr = create_node();
                temp->ptr->data = val;
                temp->ptr->ptr = tempp;
                temp->ptr->back_ptr = temp;
                tempp->back_ptr = temp->ptr;
            }
        }
    }
    catch(...)
    {
        cout << "Invalid Position" << endl;
    }
}

void del_begin(struct node **p)
{
    if (check_empty(*p))
    {
        empty();
    }
    else
    {
        *p = (*p)->ptr;
        (*p)->back_ptr = NULL;
    } 
}

void del_end(struct node **p)
{
    struct node *temp = *p;
    if (check_empty(*p))
    {
        empty();
    }
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
                temp->ptr->back_ptr = temp;
            }
            else
            {
                for (int i=1;i<pos-1;i++)
                {
                    temp = temp->ptr;
                }
                temp->ptr = temp->ptr->ptr;
                temp->ptr->back_ptr = temp;
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
            cout << " ";
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
