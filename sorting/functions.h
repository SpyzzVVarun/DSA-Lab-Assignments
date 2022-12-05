#include "global.h"

void insertion_sort(ll arr[],ll n);
void bubble_sort(ll arr[],ll n);
void selection_sort(ll arr[],ll n);
ll partition(ll arr[], ll first, ll last);
void quick_sort(ll arr[],ll first, ll last);
void merge(ll arr[], ll left, ll middle, ll right);
void merge_sort(ll arr[], ll left, ll right);
void count_sort(ll arr[], ll n, ll e);
void radix_sort(ll arr[],ll n);
void bucket_sort(float arr[],ll n);
void print_array(ll arr[], ll n);
void compare(ll arr[],ll n);

// Function to print the sorted array
void print_array(ll arr[], ll n)
{
    cout << endl;

    cout << "Sorted array: ";
    for (ll i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}



// Function to compare our Quick Sort with STL Sort
void compare(ll arr[],ll n)
{
    ll arr_tempi[n];
    copy(arr,arr+n,arr_tempi);
    auto start = steady_clock::now();
    quick_sort(arr,0,n-1);
    auto end = steady_clock::now();
    double elapsed_time = double (duration_cast <nanoseconds> (end - start).count());
    cout << "Time taken for Sorting using our Quick Sort: " << elapsed_time << " nanoseconds " << endl;

    auto start1 = steady_clock::now(); 
    sort(arr_tempi,arr_tempi+n);
    auto end1 = steady_clock::now();
    double elapsed_time1 = double (duration_cast <nanoseconds> (end1 - start1).count());
    cout << "Time taken for Sorting using STL Sort: " << elapsed_time1 << " nanoseconds " << endl << endl;
}

// Insertion Sort
void insertion_sort(ll arr[],ll n)
{
    ll i,j;
    for (i=1;i<n;i++)
    {
        for (j=i;j>0;j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr[j-1],arr[j]);
            }
            else
            {
                break;
            }
        }
    }
}

// Bubble Sort
void bubble_sort(ll arr[],ll n)
{
    ll i,j,flag = 0;
    for(i=0;i<n;i++)
    {
        flag = 0;
        for(j=0;j<n-1;j++)
        {
            if (arr[j+1]<arr[j])
            {
                swap(arr[j+1],arr[j]);
                flag = 1;
            }
        }
        if (flag==0)
        {
            break;
        }
    }
}

// Selection Sort
void selection_sort(ll arr[],ll n)
{
    ll i,j,min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min])
        {
            min = j;
        }
        if(min!=i)
        {
            swap(arr[min], arr[i]);
        }
    }
}

// Quick Sort
ll partition(ll arr[], ll first, ll last)
{
    ll pivot,i,j;

    pivot = arr[last]; 
    i = (first- 1); 
    for (j=first;j<=last-1;j++)
    {
        if (arr[j]<pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return (i + 1);
}
  
void quick_sort(ll arr[], ll first, ll last)
{
    ll p;
    if (first < last)
    {
        p = partition(arr, first, last);
        quick_sort(arr,first, p - 1);
        quick_sort(arr, p + 1,last);
    }
}

// Merge Sort
void merge(ll arr[], ll left, ll middle, ll right) 
{
    ll i,j,k;
    ll left_arr[middle-left+1], right_arr[right-middle];

    for(i = 0; i<(middle-left+1); i++)
    {
       left_arr[i] = arr[left+i]; 
    }
    for(i = 0; i < (right-middle); i++)
    {
        right_arr[i] = arr[middle+1+i];
    }

    i=0;
    j=0;
    k=left;
    while((i < (middle-left+1))&&(j < (right-middle)))
    {
        if(left_arr[i] <= right_arr[j]) 
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while(i < (middle-left+1)) 
    {       
        arr[k] = left_arr[i];
        i++; 
        k++;
    }
    while(j <(right-middle)) 
    {     
        arr[k] = right_arr[j];
        j++; 
        k++;
    }
}

void merge_sort(ll arr[], ll left, ll right) 
{
    ll middle;
    if(left < right) 
    {
        middle = left + (right-left)/2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle+1, right);
        merge(arr, left, middle, right);
    }
}

// Radix Sort
void count_sort(ll arr[], ll n, ll e)
{
    ll i;
    ll output[n]; 
    ll count[10];

    for (i=0;i<10;i++)
    {
        count[i]=0 ;
    }
    for (i=0;i<n;i++)
    {
        count[(arr[i]/e)%10] ++ ;
    }
    for (i=1;i<10;i++)
    {
        count[i] += count[i-1];
    }
    for (i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/e)%10]-1] = arr[i];
        count[(arr[i]/e)%10]--;
    }
    for (i=0;i<n;i++)
    {
        arr[i] = output[i];
    }
}

void radix_sort(ll arr[], ll n)
{
    ll max,i,e;
    max = arr[0];
    for (i=1;i<n;i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (e=1;max/e>0;e*=10)
    {    
        count_sort(arr,n,e);
    }
}

void bucket_sort(float arr[], ll n)
{
    ll i,j,k=0;
    vector<float> v[n];

    for (i=0;i<n;i++) 
    {
        j = n*arr[i];
        v[j].PB(arr[i]);
    }
  
    for (i=0;i<n;i++)
    {
        sort(v[i].begin(), v[i].end());
    }
    
    for (i=0;i<n;i++)
    {
        while(!v[i].empty())
        {
            arr[k++] = *(v[i].begin());
            v[i].erase(v[i].begin());
        }
    }
}
