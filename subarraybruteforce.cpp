#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
using namespace std;
int Bruteforce(int arr[], int n);
int main() {
	cout << "Enter the size of the array \n";
	int n;
	cin >> n;
	srand(time(0));
	int *arr=new int[n];
	//Generating random values from -100 to 100
	for (int j = 0; j < n; j++) {
	    arr[j]= (rand() %
		(100 - (-100) + 1)) + (-100);
	     cout << arr[j]<<"\n";
	}
	//Measuring time
	clock_t start, end;
	start = clock();
	//The Function call
	int result= Bruteforce(arr, n);
	end = clock();
	//Time measurement finished
	double duration = double(end - start) / CLOCKS_PER_SEC;
	cout <<"The biggest sum of all subarrays = " <<result;
	cout << " The Brute-Force algorithm of size = " << n << " finished in Time = " << duration<<" Seconds";

	
	return 0;
}

int Bruteforce(int arr[], int n) {
	
	int highestsum = arr[0];
	int startindex = 0, endindex = 0;

	for (int i = 1; i < n; i++)
	{
		int tempSum = 0;
		int j = i;
		while (j >= 0)
		{
			tempSum += arr[j];
			if (tempSum > highestsum)
			{
				highestsum = tempSum;
				startindex = j;
				endindex = i;
			}
			j--;
		}
	}
		cout << "Subarray starts at index: " << startindex << "  and ends at index: " << endindex << endl;
	return highestsum;
}



