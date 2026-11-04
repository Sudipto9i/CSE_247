// Merge Sort
#include<bits/stdc++.h>
using namespace std;

// Merge two sorted parts 
void mergeArray(vector<int>& a , int low , int mid , int high){
    vector<int> left(a.begin()+low, a.begin()+mid+1);
    vector<int> right(a.begin()+mid+1,a.begin()+high+1);
    int i=0, j=0, k=low;
    while(i<left.size()&&j<right.size()){
        if(left[i]<=right[j]){
            a[k++]=left[i++];
        }else{
            a[k++]=right[j++];
        }
    }
    while(i<left.size()){
        a[k++]=left[i++];
    }
    while(j<right.size()){
        a[k++]=right[j++];
    }
}

// Merge Sort Function
void mergeSort(vector<int>& a , int low, int high){
    if(low<high){
        int mid = low + (high-low)/2;
        mergeSort(a, low , mid );
        mergeSort(a , mid+1 , high);
        mergeArray(a, low , mid , high);
    }
}

int main(){
    vector<int> a = {5,2,8,1,6};
    mergeSort(a, 0,a.size()-1);
    cout<<"Merge Sort: ";
    for(int x : a ){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
