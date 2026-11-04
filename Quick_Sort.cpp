// Quick Sort
// Quick Sort is a divide-and-conquer sorting algorithm that 
// selects a pivot, partitions elements around it, 
// and recursively sorts the two parts.
// Pivot -> Partition -> Recursively Sort 
// Pivot: Choose one element.
// Partition: Put smaller elements on the left and larger elements on the right (depending on the partition scheme)
// Recursively sort: Sort the left and right parts.
#include<bits/stdc++.h>
using namespace std;

// Partition the array around the last element 
int partitionArray(vector<int>& a, int low, int high){
    int pivot = a[high]; // Choose the last element as pivot.
    int i = low - 1 ;// Track the boundary of smaller elements.
    for(int j=low ;j<high;j++){
        if(a[j]<=pivot){// If the element belongs on the smaller side, move it there.
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);// Place the pivot in its final position.
    return i+1;
}

// Quick Sort Function
void quickSort(vector<int>& a , int low , int high){
    if(low<high){// Stop when the part has at most one element.
        int pivotIndex = partitionArray(a , low , high);
        quickSort(a, low , pivotIndex - 1 );// Sort the left partition.
        quickSort(a,pivotIndex + 1 , high);// Sort the right partition.
    }
}

int main(){
    vector<int> a = {5,2,8,1,6};
    quickSort(a,0,a.size() - 1 );

    cout<<"Sorted array: ";

    for(int x : a ){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
