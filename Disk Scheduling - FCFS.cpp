#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n, head, count=0;
	cout << "Enter the size of queue : ";
	cin >> n;

	int arr[n+1];
	cout << "Enter the queue : ";
	for(int i=1; i<n+1; i++){
		cin >> arr[i];
	}

	cout << "Enter head position : ";
	cin >> head;

	arr[0] = head;

	for(int i=1; i<=n; i++){
		count += abs(arr[i]-arr[i-1]);
		cout << "Move from " << arr[i-1] << " to " << arr[i] << " with head movement ";
		cout << abs(arr[i]-arr[i-1]) << endl;
	}

	cout << endl << "Total head movements : " << count << " cylinders." << endl;
	return 0;
}