#include<bits/stdc++.h>
#include<chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

struct node *create_node();
bool check_empty(struct node *p);
void empty();
void add_empty(int val,struct node **p);
void add_begin(int data, struct node **p);     
void add_end(int data,struct node **p);
void add_after(struct node **p, int data, int item);         
void delete_node(struct node** p, int key);
void print_node(struct node *last);

struct node
{
    int data;
    struct node *ptr;
};

int main()
{
    struct node *start = NULL;
    while (1)
    {
        int choice,pos = 0,data,item,key;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Circular linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert Node at end"<<endl;
        cout<<"3.Insert Node after item"<<endl;
        cout<<"4.Delete a Node"<<endl;
        cout<<"5.Display Linked List"<<endl;
        cout<<"6.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cin >> data;
            cout<<"Inserting Node at beginning:"<<endl;
            add_begin(data,&start);
            cout<<endl;
            break;
        case 2:
            cin >> data;
            cout<<"Inserting Node at end:"<<endl;
            add_end(data,&start);
            cout<<endl;
            break;
        case 3:
            cin >> item;
            cin >> data;
            cout<<"Inserting a particular node after a value: "<<endl;
            add_after(&start,data,item);
            break;
        case 4:
            cin >> key;
            cout<<"Display elements of link list"<<endl;
            delete_node(&start,key);
            cout<<endl;
            break;
        case 5:
            cout<<"Display elements of link list"<<endl;
            print_node(start);
            cout<<endl;
            break;
        case 6:
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


void add_empty(int val,struct node **p)         
{        
    struct node *temp =  create_node();      
    temp -> data = val;        
    *p = temp;        
    (*p) -> ptr = *p;                
}        
void add_begin(int data, struct node **p)       
{        
    if (*p == NULL)      
    {
        add_empty(data,p);
        return;
    }      
    struct node *temp =  create_node();        
    temp -> data = data;        
    temp -> ptr = (*p) -> ptr;        
    (*p) -> ptr = temp;                
}        
void add_end(int data,struct node **p)         
{        
    if (*p == NULL)       
    {
        add_empty(data,p);
        return;      
    }       
    struct node *temp = create_node();         
    temp -> data = data;        
    temp -> ptr = (*p) -> ptr;        
    (*p) -> ptr = temp;        
    *p = temp;                
}        
void add_after(struct node **p, int data, int item)         
{        
    if (*p == NULL) return ;       
    struct node *temp, *q;      
    q = (*p) -> ptr;       
    do      
    {       
        if (q ->data == item)       
        {       
            temp = create_node();      
            temp -> data = data;        
            temp -> ptr = q -> ptr;       
            q -> ptr = temp;       
            if (q == *p) 
            {     
                *p = temp;                
            }  
        }     
        q = q -> ptr;      
    } while(q != (*p) -> ptr);                 
}        

void delete_node(struct node** p, int key)
{
    if (*p == NULL) return;

    if ((*p)->data == key && (*p)->ptr == *p)
    {
        free(*p);
        *p = NULL;
        return;
    }

    struct node *temp = *p, *d;

    if ((*p)->data == key) 
    {
    while (temp->ptr != *p)
    {
        temp = temp->ptr;
    }

    temp->ptr = (*p)->ptr;
    free(*p);
    *p = temp->ptr;
    }

    while (temp->ptr != *p && temp->ptr->data != key) 
    {
        temp = temp->ptr;
    }

    if (temp->ptr->data == key) 
    {
        d = temp->ptr;
        temp->ptr = d->ptr;
        free(d);
    }
}

void print_node(struct node *last)         
{        
    struct node *p;         
    if (last == NULL)       
    {       
        cout << "List is empty." << endl;       
        return;         
    }       
    p = last -> ptr;       
    do      
    {       
    cout << p -> data << " ";       
    p = p -> ptr;      
    }       
    while(p != last->ptr);         
}     