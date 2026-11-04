// Selection Sort
// Definition: Repeatedly finds the smallest element in the unsorted part and places it at the beginning.
// Memory trick: Find minimum -> Swap once -> Grow sorted part.
// Example: 5 3 2 1 
// Pass 1 : 1 3 2 5 
// Pass 2 : 1 2 3 5 
// Pass 3 : 1 2 3 5 
// Important: Selection Sort does not swap every time it finds a smaller element.
// It remembers the minimum index and swaps once after completing the inner loop.
#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&a){
    int n = a.size();
    for(int i=0 ; i<n-1 ; i++){
        int minIndex = i;// Assume the current position contains the minimum.
        for(int j = i+1;j<n;j++){// j = i+1 Searches the remaining unsorted elements.
            if(a[j]<a[minIndex]){// Checks whether a smaller value exists.
                minIndex = j;// Remember the index of the new minimum.
            }
        }
        swap(a[i],a[minIndex]);// Places the minimum at the current position.
    }
}
int main(){
    vector<int> a = {5,3,2,1};
    selectionSort(a);
    cout<<"Selection sort: ";
    for(int x : a){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
