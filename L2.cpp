
/// Linear Search and Binary Search ,Insertion Sort and it's complexity analysis.
/// Linary Search checks each element of an array one by one until the target is found or the array ends.
#include<bits/stdc++.h>
using namespace std;
int linearSearch(vector<int>&arr, int target){
    int n = arr.size();
    for(int i=0; i<n ;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int target = 5;
    int result = linearSearch(arr,target);
    if(result!=-1){
        cout<<"Element found at index : "<<result<<endl;
    }else{
        cout<<"Element not found in current array."<<endl;
    }
    return 0;
}

//Binary Search finds a target in a sorted array 
//by repeatedly dividing the search range into 
//two halves.
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&arr, int target){
    int low = 0;
    int high = arr.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    vector<int>arr = {1,2,3,4,5,6,7,8};
    int target = 3;
    int result = binarySearch(arr,target);
    if(result!=-1){
        cout<<"Result found at index: "<<result<<endl;
    }else{
        cout<<"Target not found."<<endl;
    }
}
*/
// Insertion Sort
// Insertion Sort sorts an array by taking one 
// element at a time and inserting it into its 
// correct position in the already-sorted portion.
#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=1 ;i<n;i++){// Start from the second element.
        int key = arr[i];// Save the element we want to insert.
        int j = i-1;// Start checking the element immediately to its left.
        while(j>=0&&arr[j]>key){//Check whether the left element is larger than the key.
            arr[j+1]=arr[j];// Shift the larger element one position right.
            j--;// Move left to check the next element.
        }
        arr[j+1]=key;// Insert the key in its correct position.
    }
}
int main(){
    vector<int> arr = {5,3,4,1,2};
    insertionSort(arr);
    cout<<"Sorted array: ";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
