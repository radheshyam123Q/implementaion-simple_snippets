#include <iostream>
using namespace std ;
int Binary_search(int arr[],int left,int right,int x)
{
 while (left<=right){
    int mid = left+ (right - left)/2 ;
    if(arr[mid]==x){
        return mid ;
    }
    else if(arr[mid]<x){
       left = mid +1 ; 
    }
    else{
        right = mid-1;
    }
  

 }
   return -1 ; 
 
}
int main(){
    int num , myarr[10], output ;
    cout<<"Enter 10 intiger in accending order"<<endl;
    for(int i = 0 ; i <10 ;i++){
      cin>>myarr[i];
    }
    cout<<"Enter one number that you want to search in the array :"<<endl;
    cin>>num ;
    output = Binary_search(myarr,0,9,num);
    if(output==-1){
        cout<<"no match found"<<endl;

    }
    else{
        cout<<"Match found at index position "<<output +1 <<endl;

    }
return 0 ;
}