#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& arr, int target){
    int low = 0;/// Starting index of the search range.
    int high = arr.size()-1;/// Last index of the search range.
    while(low<=high){/// Continue while at least one candidate remains.
        int mid = low+(high-low)/2;/// Calculates the middle index safely.
        if(arr[mid]==target){///If equal , the target is found.
            return mid;
        }else if(arr[mid]<target){/// Target must be to the right in an ascending array.
            low = mid + 1 ;/// Discard the middle and left portion.
        }else{
            high = mid -1;/// Discard the middle and right portion.
        }
    }
    return -1;/// No match exists in the array.
}
int main(){
    vector<int> arr = {10,20,30,40,50,60,70};
    int target = 60;
    int result = binarySearch(arr , target);
    if(result!=-1){
        cout<<"Element found at index: "<<result<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}
/// Memorize the logic
/// Middle is smaller: Go right.
/// Middle is larger: Go left.
