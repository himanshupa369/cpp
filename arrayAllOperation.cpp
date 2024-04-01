#include <iostream>
#include <limits.h>
using namespace std;
void display(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}
void bubble(int *A, int n)
{
    int temp, issorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        issorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}
void insertion(int *A, int n)
{
    int key, j;
    for (int i = 0; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
void selection(int *A, int n)
{
    int index, temp;
    for (int i = 0; i < n - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[index])
            {
                index = j;
            }
            temp = A[i];
            A[i] = A[index];
            A[index] = temp;
        }
    }
}
int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quick(int *A, int low, int high)
{
    int index;
    if (low < high)
    {
        index = partition(A, low, high);
        quick(A, low, index - 1);
        quick(A, index + 1, high);
    }
}
void merge(int *A, int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void mergesort(int *A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}
int maximum(int *A, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
int minimum(int *A, int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (min > A[i])
        {
            min = A[i];
        }
    }
    return min;
}
void count(int A[], int n)
{
    int i, j;
    int max = maximum(A, n);
    int B[max + 1];
    for (i = 0; i < max + 1; i++)
    {
        B[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        B[A[i]] = B[A[i]] + 1;
    }
    i = j = 0;
    while (i <= max)
    {
        if (B[i] > 0)
        {
            A[j] = i;
            B[i] = B[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
void linear(int A[100], int n)
{
    int element, flag = 0;
    cout << "\nRunning Linear Search\nEnter the element you want to search in array : ";
    cin >> element;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == element)
        {
            cout << "\n"
                 << element << " found at " << i << " index";
            flag = 1;
            break;
        }
    }
    if (!flag)
        cout << "\n"
             << element << " not found";
}
void binary(int A[100], int n)
{
    int element, mid, low = 0, high = n - 1, flag = 0;
    cout << "\nFirstly Sorting Your array";
    count(A, n);
    cout << "\nDisplaying your array after sorting \n";
    display(A, n);
    cout << "\nNow running Binary Search\nEnter the element you want to search in your array : ";
    cin >> element;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == element)
        {
            cout << "\n"
                 << element << " found at " << mid << " index";
            flag = 1;
            break;
        }
        if (A[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (!flag)
        cout << "\n"
             << element << " not found in your array";
}
void deletion(int *A, int n)
{
    int element, flag = 0;
    cout << "\nEnter the element you want to delete from your array : ";
    cin >> element;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == element)
        {
            flag = 1;
            A[i] = A[i + 1];
        }
    }
    if (!flag)
    {
        cout << "\n"
             << element << " is not present in array";
    }
    else
    {
        cout << "\nDeletion Done\nDisplaying your array after deletion\n";
        display(A, n - 1);
    }
}
void insertioninarray(int *A, int n)
{
    int B[100], index, element, count = 0;
    char ch;
    cout << "\nEnter the lelement you want to insert in array : ";
    cin >> element;
    cout << "\nEnter the index no. : ";
    cin >> index;
    for (int i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
    for (int j = n - 1; j >= index; j--)
    {
        B[j + 1] = B[j];
    }
    B[index] = element;
    cout << "\nInsertion Done\nDispalying your array after insertion \n";
    display(B, n + 1);
    do
    {
        cout << "\nYou want to insert more in this array (y/n) : ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            count++;
            cout << "\nEnter the lelement you want to insert in array : ";
            cin >> element;
            cout << "\nEnter the index no. : ";
            cin >> index;
            for (int j = n - 1; j >= index; j--)
            {
                B[j + 1] = B[j];
            }
            B[index] = element;
            cout << "\nInsertion Done\nDispalying your array after insertion \n";
            display(B, n + 1 + count);
        }
        else
        {
            return;
        }
    } while (ch == 'y' || ch == 'Y');
}
int main()
{
    int A[100], n, c, choice, choice1, choice2;
    char ch;
    do
    {
        cout << "\nEnter the size of array : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "\nEnter element " << i + 1 << " : ";
            cin >> A[i];
        }
        cout << "\nDisplaying your array \n";
        display(A, n);
        cout << "\nEnter the operation you want to perform in array \n1)Sorting\n2)Searching\n3)Others operation\n--->";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter your choice \n1)Bubble Sort\n2)Insertion Sort\n3)Selection Sort\n4)Quick Sort\n5)Merge Sort\n6)Count Sort\n--->";
            cin >> c;
            switch (c)
            {
            case 1:
                bubble(A, n);
                cout << "\nDisplaying array after bubble sort \n";
                display(A, n);
                break;
            case 2:
                insertion(A, n);
                cout << "\nDisplaying array after insertion sort \n";
                display(A, n);
                break;
            case 3:
                selection(A, n);
                cout << "\nDisplaying array after selection sort \n";
                display(A, n);
                break;
            case 4:
                quick(A, 0, n - 1);
                cout << "\nDisplaying array after quick sort \n";
                display(A, n);
                break;
            case 5:
                mergesort(A, 0, n - 1);
                cout << "\nDisplaying array after merge sort \n";
                display(A, n);
                break;
            case 6:
                count(A, n);
                cout << "\nDisplaying array after count sort \n";
                display(A, n);
                break;
            default:
                cout << "\nWrong choice..!!";
                break;
            }
            break;

        case 2:
            cout << "\nEnter your choice in searching \n1)Linear Search\n2)Binary Search\n-->";
            cin >> choice1;
            switch (choice1)
            {
            case 1:

                linear(A, n);
                break;
            case 2:
                binary(A, n);
                break;
            default:
                cout << "\nWrong choice..!!";
                break;
            }
            break;
        case 3:
            cout << "\nEnter your choice to perform in Array\n1)Deletion\n2)Insertion\n3)Maximum and minimum element in array\n-->";
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                deletion(A, n);
                break;
            case 2:
                insertioninarray(A, n);
                break;
            case 3:
                cout << "\nMaximum no. in your array is " << maximum(A, n) << " and minimum no. in your array is " << minimum(A, n);
                break;
            default:
                cout << "\nWrong Choice..!!";
                break;
            }
            break;
        default:
            cout << "\nWrong choice..!!";
            break;
        }

        cout << "\nYou want to perform again another operation..!!(y/n) : ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}

