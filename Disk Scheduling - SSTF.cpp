#include<iostream>
#include<cmath>
using namespace std;

void remove(int arr[], int start, int n){
	for(int i=start; i<n-1; i++){
		arr[i] = arr[i+1];
	}
	return;
}

int main(){
	int n, head, count=0;
	cout << "Enter size of queue : ";
	cin >> n;

	int arr[n+1];
	cout << "Enter the queue : ";
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}

	cout << "Enter the head position : ";
	cin >> head;

	arr[0] = head;

	sort(arr, arr+(n+1));

	n++; //start pos added

	int j,i;
	for(j=0; j<n; j++){
		if(arr[j] == head){
			break;
		}
	}

	for(i=j; i!=n && i!=0 ; i++){
		int temp1 = arr[i+1] - arr[i];
		int temp2 = arr[i] - arr[i-1];

		int ans = min(temp1, temp2);
		remove(arr, i, n);
		
		if(ans == temp1){
			i--;
		}
		else{
			i = i-2;
		}
		n--;
		count += ans;
	}

	if(n==i){
		for(int i=n; i>0; i--){
			count += arr[i]-arr[i-1];
		}
	}

	if(i==0){
		for(int i=0; i<n; i++){
			count += arr[i+1] - arr[i];
		}
	}

	cout << "Total head movements : " << count << " cyclinders." << endl;
}