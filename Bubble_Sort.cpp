/// Bubble Sort
/// Definition: Repeatedly compares adjacent elements and swaps them if they are in the wrong order.
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>&a){/// Sort the original vector , void returns nothing.
    int n = a.size();/// Gets the number of elements.
    for(int i=0;i<n-1;i++){/// Runs at most n-1 passes.
        bool swapped = false;/// Assumes no swap has happened yet in this pass.
        for(int j=0;j<n-1-i;j++){/// Compares adjacent elements; skips the sorted suffix.
            if(a[j]>a[j+1]){/// Checks whether the neighboring pair is in the wrong order.
                swap(a[j],a[j+1]);/// Exchanges the two values.
                swapped = true;/// Records that a swap occurred.
            }
        }
        if(!swapped){/// Stops if the array is already sorted.
            break;
        }
    }
}
int main(){
    vector<int> a = {5,3,2,4,1};
    bubbleSort(a);
    cout<<"Sorted array: ";
    for(int x:a){/// Visits each element to print it.
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
/// Why n-1-i? After each pass, the largest remaining element reaches the end.
/// There is no need to compare that sorted element again.
