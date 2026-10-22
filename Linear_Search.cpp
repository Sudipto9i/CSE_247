/// What is Linear Search?
/// Definition: Linear Search checks each element of an array one by one until the target is found or the array ends.
/// Imagine you are searching for student ID 30 in a list. You check the first ID, then the second, then the third,
/// and continue until you found 30.
#include<bits/stdc++.h>

using namespace std;///Let us write cout and vector without std::.

int linearSearch(vector<int>&arr, int target){/// Defines a function that returns an integer index.
    ///vector<int>& arr --> Receives the vector by reference, without copying it.
    ///int target --> The value we want to find.
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==target){///Check whether the current element matches.
            return i;/// Returns the matching index immediately.
        }
    }
    return -1;///Signals that the target was not found.
}
int main(){
    vector<int> arr={10,25,27,30,45,50};
    int target = 55;
    int result = linearSearch(arr, target);
    if(result!=-1){
        cout<<"Element found at index: "<<result<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
}
/// Remember: C++ arrays and vectors use zero-based indexing.
/// Therefore, 30 is at index 2 , which is the third position.

