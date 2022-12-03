#include <iostream>
#include<chrono>
#include<bits/stdc++.h>

typedef long long ll;
#define push_back PB
const ll table_size = 100;

using namespace std;
using namespace std::chrono;

void compare();

class Hashinit 
{
   public:
      ll key;
      ll value;
      Hashinit(ll key, ll value) 
      {
         this->key= key;
         this->value = value;
      }
};

class Hash 
{
   private:
      Hashinit **table;
   public:
    
    // Initializing each index to NULL
      Hash() 
      {
        table = new Hashinit * [table_size];
        for (ll i=0;i<table_size;i++) 
        {
            table[i] = NULL;
        }
      }

      // Opertion that transforms the given key, here we use simple mod operation 
      ll hash_func(ll key) 
      {
         return key%table_size;
      }
      void insert(ll key, ll value) 
      {
        ll hash;
        hash = hash_func(key);
        // Linear probing for handling collisions
        while (table[hash]!=NULL && table[hash]->key!=key) 
        {
            hash = hash_func(hash + 1);
        }
        if (table[hash]!=NULL)
        {
            delete table[hash];
        }
         table[hash] = new Hashinit(key, value);
      }
      ll search(ll key) 
      {
        ll hash;
        hash = hash_func(key);
        // Linear probing again
        while (table[hash]!=NULL && table[hash]->key != key) 
        {
            hash = hash_func(hash + 1);
         }
        if (table[hash] == NULL)
        {
            return -1;
        }
        else
        {
           return table[hash]->value; 
        }
      }
      void del(ll key) 
      {
        ll hash;
        hash = hash_func(key);
        while (table[hash] != NULL) 
        {
            if (table[hash]->key == key)
            {
                break;
            }
            hash = hash_func(hash + 1);
        }
        if (table[hash] == NULL) 
        {
            cout<<"No Element found at key "<< key <<endl;
            return;
        }
        else 
        {
            delete table[hash];
        }
         cout<<"Element Deleted"<<endl;
      }
};

int main() {
   Hash hash;
   ll key, value;
   ll choice;
   while (1) 
   {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Compare with STL"<<endl;
      cout<<"5.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice) 
      {
         case 1:
            cout<<"Enter element to be inserted: ";
            cin>>value;
            cout<<"Enter key at which element to be inserted: ";
            cin>>key;
            hash.insert(key, value);
            break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
            if (hash.search(key) == -1) 
            {
               cout<<"No element found at key "<< key <<endl;
               continue;
            } 
            else 
            {
               cout<<"Element at key "<< key <<" : ";
               cout<<hash.search(key)<<endl;
            }
            break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>key;
            hash.del(key);
            break;
         case 4:
            compare();
            break;
         case 5:
            cout<<"Exiting..."<<endl;
            exit(1);
         default:
            cout<<"\nWrong Choice !!\n";
      }
   }
   return 0;
}

void compare()
{
   Hash h;
   unordered_map<int, int> stl_h;

   auto start = steady_clock::now();
   h.insert(1,10);
   auto end = steady_clock::now();
   double elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
   cout << endl;
   cout << "Time for Insert in my implementation: " << elapsed_time << " nanoseconds " << endl;

   start = steady_clock::now();
   stl_h.insert(make_pair(1,10));
   end = steady_clock::now();
   elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
   cout << "Time for Insert in STL's implementation: " << elapsed_time << " nanoseconds " << endl;
   cout << endl;

}