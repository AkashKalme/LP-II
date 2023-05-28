#include<iostream>

using namespace std;

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int mini = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[mini])
            {
                mini = j;
            }
        }
        if(mini != i)
        {
            swap(&arr[mini], &arr[i]);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the Number of Elements in Array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements (separated by Space): ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before Sorting: ";
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "After Sorting: ";
    printArray(arr, n);
    return 0;
}