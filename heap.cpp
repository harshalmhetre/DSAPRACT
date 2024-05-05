#include <iostream>
using namespace std;


// maxheap
void maxinsert(int arr[],int i){
    int parent =(i-2)/2;
    int cur= i;
    while(parent >=0 && arr[parent] < arr[cur]){
        swap(arr[parent],arr[cur]);
        cur =parent;
        parent =(cur-1)/2;
    }
    }

void mininsert(int arr[],int i){
    int parent =(i-2)/2;
    int cur= i;
    while(parent >=0 && arr[parent] > arr[cur]){
        swap(arr[parent],arr[cur]);
        cur =parent;
        parent =(cur-1)/2;
    }
    }
int main (){
    int n;
    cout<<"Total no. of students in class";
    cin>>n;
    int arr[n] ;
    cout<<"Enter the marks of the students";
    for(int i=0 ;i<n ; i++){
        cin>>arr[i];
    }

    for (int i=1 ;i<n ;i++){
        maxinsert(arr,i);
    }
    // cout<<"After the insetion :";
    // for(int i=0 ;i<)
    
    cout <<"\nMaximum Marks:"<<arr[0];

    for (int i=1 ;i<n ;i++){
        mininsert(arr,i);
    }
    
    cout <<"\nMinimum Marks:"<<arr[0];
}

