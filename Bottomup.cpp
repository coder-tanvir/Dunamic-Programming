#include<iostream>
#include<time.h>
using namespace std;
int BOTTOM_UP_CUT_ROD(int price[],int size);
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
  int result=BOTTOM_UP_CUT_ROD(price,size);
  clock_t end=clock();
  cout<<"The result is :"<<result;
  cout<<"Time taken"<<(double)(end - start)/CLOCKS_PER_SEC;
  return 0;
}

int BOTTOM_UP_CUT_ROD(int price[],int size){
    int r[size+1];
    int q;
    r[0] = 0;
    for (int j = 1; j <= size; j++)
    {
        q = INT_MIN;
        for (int i = 0; i < j; i++)
        {
            q = max(q,price[i]+r[j-i-1]);
        }
        r[j] = q;
    }
    return r[size];
}

int max(int a, int b) { return (a > b)? a : b;} 
