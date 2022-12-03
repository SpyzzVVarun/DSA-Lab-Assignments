#include "functions.h"

int main()
{
    // Taking Array size and elements as input
    ll n,i,temp;
    cout<<"Enter size of array : ";
    cin >> n;
    ll arr[n],arr_temp[n];
    float arr_bs[n],temp_bs;
    cout<<"Enter array elements : ";
    for (i=0;i<n;i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    copy(arr,arr+n,arr_temp);

    // Menu Driven Program code
    while (1)
    {
        ll choice;
        copy(arr_temp,arr_temp+n,arr);
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Sorting"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insertion Sort"<<endl;
        cout<<"2.Bubble Sort"<<endl;
        cout<<"3.Selection Sort"<<endl;
        cout<<"4.Quick Sort"<<endl;
        cout<<"5.Merge Sort"<<endl;
        cout<<"6.Radix Sort"<<endl;
        cout<<"7.Bucket Sort (enter different input: floats from 0 to 1)"<<endl;
        cout<<"8.Compare with STL "<<endl;
        cout<<"9.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            insertion_sort(arr,n);
            print_array(arr,n);
            break;
        case 2:
            bubble_sort(arr,n);
            print_array(arr,n);
            break;
        case 3:
            selection_sort(arr,n);
            print_array(arr,n);
            break;
        case 4:
            quick_sort(arr,0,n-1);
            print_array(arr,n);
            break;
        case 5:
            merge_sort(arr,0,n-1);
            print_array(arr,n);
            break;
        case 6:
            radix_sort(arr,n);
            print_array(arr,n);
            break;
        case 7:
            cout<<"Enter size of array : ";
            cin >> n;
            cout<<"Enter array elements : ";
            for (i=0;i<n;i++)
            {
                cin >> temp_bs;
                arr_bs[i] = temp_bs;
            }
            bucket_sort(arr_bs,n);
            cout << endl;
            cout << "Sorted array: ";
            for (ll i=0;i<n;i++)
            {
                cout << arr_bs[i] << " ";
            }
            cout << endl;
            break;
        case 8:
            compare(arr,n);
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