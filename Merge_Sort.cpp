// Merge Sort
// Merge Sort = Divide + Conquer + Combine 
// Divide: Break the array into smaller halves.
// Conquer: Sort those smaller halves recursively.
// Combine: Merge the sorted halves into one sorted array.
#include<bits/stdc++.h>
using namespace std;

// Merge two sorted parts 
// mergeArray --> Combines two sorted parts 
// low -> Starting Index 
// mid -> Middle Index 
// high -> Ending Index 

void mergeArray(vector<int>& a , int low , int mid , int high){
    // Create two temporary arrays 
    // Left Vector 
    // a.begin()+low -> identifies the starting position.
    // a.begin()+mid+1 -> identifies the position just after the ending element.
    vector<int> left(a.begin()+low, a.begin()+mid+1);
    // Right Vector 
    vector<int> right(a.begin()+mid+1,a.begin()+high+1);
    // i -> Tracks elements in the left array
    // j -> Tracks elements in the right array 
    // k -> tracks the position in the original array 
    int i=0, j=0, k=low;
    // Continue comparing while BOTH arrays have remaining elements.
    while(i<left.size()&&j<right.size()){
        // If the left element is smaller or equal, copy to the original array.
        if(left[i]<=right[j]){
            a[k++]=left[i++];
        }else{
            a[k++]=right[j++];
            // Otherwise, copy to the right element.
        }
    }
    // Copy remaining left elements.
    while(i<left.size()){
        a[k++]=left[i++];
    }
    // Copy remaining right elements.
    while(j<right.size()){
        a[k++]=right[j++];
    }
}

// Merge Sort Function
// mergeSort() ---> Divides the array recursively 
void mergeSort(vector<int>& a , int low, int high){
    if(low<high){// Base Condition 
        int mid = low + (high-low)/2;// Calculate middle index 
        mergeSort(a, low , mid );// Divide the left half 
        mergeSort(a , mid+1 , high);// Divide the right half 
        mergeArray(a, low , mid , high);// Merge both halves 
    }
}

int main(){
    vector<int> a = {5,2,8,1,6};
    mergeSort(a, 0,a.size()-1);
    // WE call the merge sort function.
    //  a = Original vector 
    //  0 = Starting index 
    // a.size()-1 = Last Index 
    cout<<"Merge Sort: ";
    for(int x : a ){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
