#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
using namespace std;

//Function prototypes
int Maxmiddle(int arr[], int low, int mid, int high);
int SubArraySum(int arr[], int low, int high);
int max(int a, int b);

int main()
{
	int n;
	double totaltime;
	cout << "Enter the size of the array: ";
	cin >> n;

	int* a = new int[n];
	for (int j = 0; j < n; j++) {
		a[j] = (rand() %
			(100 - (-100) + 1)) + (-100);
		cout << a[j] << "\n";
	}
	clock_t begin, end;
	begin = clock();
	cout << "\nThe Highest sum of all subarraym is : " << SubArraySum(a, 0, n - 1);
	end = clock();
	totaltime = double(end - begin) / CLOCKS_PER_SEC;
	cout << "\n Divide and conquer algorithm took- " << totaltime << " Seconds to complete. ";
	return 0;
}


int Maxmiddle(int arr[], int low, int mid, int high)
{
	int totalsum = 0;
	int leftsum = 0;
	int leftvalue = -1;
	int rightsum = 0;
	int rightvalue = -1;
	for (int i = mid; i >= low; i--)
	{
		leftsum = leftsum + arr[i];
		if (leftsum > leftvalue)
			leftvalue = leftsum;
	}		
	for (int i = mid + 1; i <= high; i++)
	{
		rightsum = rightsum + arr[i];
		if (rightsum > rightvalue)
			rightvalue = rightsum;
	}
	totalsum= leftvalue + rightvalue;
	return totalsum;
}

int SubArraySum(int arr[], int low, int high)
{
	int mid= (low + high) / 2;
	
	if (low == high) {
		
		return arr[low];
	}
	// Maximum sum sub-array can be either in the left part, right part or covering elements from both parts.
	return max(max(SubArraySum(arr, low, mid), SubArraySum(arr, mid + 1, high)), Maxmiddle(arr, low, mid, high));
}

int max(int a, int b)
{
	if (a > b) {
		return a;
	}
	return b;

}

