
#include<iostream>
#include<time.h>
using namespace std;
int cutrod(int price[],int size);
int main(){
  int size;
  cout<<"Please enter the size: ";
  cin>>size;
  int* price=new int[size];
  for(int i=0;i<=size;i++){
    price[i]=i;

    }
    //int size = sizeof(arr)/sizeof(arr[0]);
    clock_t start=clock();
  int result=cutrod(price,size);
  clock_t end=clock();
  cout<<"The result is :"<<result;
  cout<<"Time taken"<<(double)(end - start)/CLOCKS_PER_SEC;
  return 0;
}

int cutrod(int price[],int size){

if (size <= 0) 
     return 0; 
   int max_val = INT_MIN; 
  
 
   for (int i = 0; i<size; i++) 
         max_val = max(max_val, price[i] + cutrod(price, size-i-1)); 
  
   return max_val; 
}

int max(int a, int b) { return (a > b)? a : b;} 
