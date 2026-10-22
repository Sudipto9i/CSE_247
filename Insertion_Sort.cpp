///What is Insertion Sort?
///Definition: Insertion Sort sorts an array by taking one element at a time and inserting it into its correct position in the already-sorted portion.
#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=1;i<n;i++){/// Start from the second element
        int key = arr[i];/// Save the element we want to insert
        int j = i-1;/// Start checking the element immediately to its left
        while(j>=0&&arr[j]>key){/// arr[j]>key Check whether the left element id larger than the key.
            arr[j+1] = arr[j];/// Shift the larger element one position right
            j--;/// Move left to check the next element.
        }
        arr[j+1] = key;/// Insert the key in its correct position
    }
}
int main(){
    vector<int> arr = {5,3,4,1,2};
    insertionSort(arr);

    cout<<"Sorted array:";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
