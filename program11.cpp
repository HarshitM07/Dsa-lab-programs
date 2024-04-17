#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>&arr,int n){
    for(int i = 1;i<n;i++){
        int temp = arr[i];
        int j = i-1;
        for(;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=temp;
    }
}

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        
        swap(arr[minIndex], arr[i]);

       
    }
}

int partition(vector<int>&arr, int s, int e){
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    int pivotIndex = s+count;
    swap(arr[pivotIndex],arr[s]);

    int i = s, j = e;

    while(i<pivotIndex && j>pivotIndex){
    while(arr[i]<pivot){
        i++;
    }
    while(arr[j]>pivot){
        j--;
    }

    if(i<pivotIndex && j>pivotIndex){
        swap(arr[i++],arr[j--]);
    }
    }

    return pivotIndex;
    
    
    }

void quickSort(vector<int>&arr, int s, int e){
    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

void merge(vector<int>&arr, int s, int e){
    int mid = s + (e-s)/2;
    int len1 = mid - s +1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    int mainArrayIndex = s;
    for(int i = 0; i< len1; i++){
        first[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }
    mainArrayIndex = mid + 1;
    for(int i = 0; i< len2; i++){
        second[i] = arr[mainArrayIndex];
        mainArrayIndex++;
    }

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1<len1){
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2<len2){
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(vector<int>&arr, int s, int e){
    if(s>=e){
        return;
    }

    int mid = s + (e-s)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);
}
int main() {
    cout << "Enter the size of the array you want to sort: ";
    int n;
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nChoose sorting algorithm:" << endl;
    cout << "1. Quicksort" << endl;
    cout << "2. Mergesort" << endl;
    cout<< "3. Selectionsort"<<endl;
    cout<< "4. Insertionsort"<<endl;
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            quickSort(arr, 0, n - 1);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            break;
        case 3:
            selectionSort(arr, n);
        case 4:
            insertionSort(arr, n);
        default:
            cout << "Invalid choice. Sorting with Quicksort by default." << endl;
            quickSort(arr, 0, n - 1);
            break;
    }
    cout<<endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}