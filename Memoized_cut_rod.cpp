#include<iostream>
#include<time.h>
using namespace std;

int memoizedcutrod(int price[],int size);
int auxiliary(int price[],int size,int revenue[]);
int main(){
  int size;
  cout<<"Please enter the size: ";
  cin>>size;
  int* price=new int[size];
  for(int i=0;i<=size;i++){
    price[i]=i+1;
    cout<<price[i];

    }
    //int size = sizeof(arr)/sizeof(arr[0]);
    clock_t start=clock();
  int result=memoizedcutrod(price,size);
  clock_t end=clock();
  cout<<"The result is :"<<result;
  cout<<"Time taken"<<(double)(end - start)/CLOCKS_PER_SEC;
  return 0;
}
int max(int a, int b) { return (a > b)? a : b;}
int memoizedcutrod(int price[],int size){

    int* revenue=new int [size+1];
    for(int i=0;i<size+1;i++){

        revenue[i]=INT_MIN;
    }
    return auxiliary(price,size,revenue);
}

int auxiliary(int price[],int size,int revenue[]){
    int q;
    if(revenue[size]>=0){
        cout<<"HUUUR";
        return revenue[size];
    }
    if(size=0){
        q=0;
    }else{
        q=INT_MIN;
    
    for(int i=1;i<size;i++){
        q=max(q,price[i]+auxiliary(price,size-i-1,revenue));
    }
    }
    revenue[size]=q;
    cout<<q;
    return q;
}