#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n, head, count=0, tot;
	cout << "Enter size of queue : ";
	cin >> n;

	int arr[n+3];
	cout << "Enter the queue : ";
	for(int i=1; i<=n; i++){
		cin >> arr[i];
	}

	cout << "Enter the head position : ";
	cin >> head;

	cout << "Enter total number of cyclinders : ";
	cin >> tot;

	arr[n+1] = 0;
	arr[n+2] = tot-1;

	arr[0] = head;

	sort(arr, arr+(n+3));

	int j;
	for(j=0; j<n+3; j++){
		if(arr[j] == head){
			break;
		}
	}

	char s;
	cout << "Head moving towards right? (y/n) : ";
	cin >> s;

	if(s == 'y'){
		/*for(int i=j; i<n+3; i++){
			count += abs(arr[i+1] - arr[i]);
		}
		for(int i=j; i>0; i--){
			count += abs(arr[i]-arr[i-1]);
		}*/ //Implement same as the else part
	}
	else{
		for(int i=j; i>0; i--){
			int temp = abs(arr[i]-arr[i-1]);
			count += temp;
			//count += abs(arr[i]-arr[i-1]);
		}
		count += abs(arr[j+1]-arr[0]);

		for(int i=j+2; i<n+3; i++){
			int temp = abs(arr[i]-arr[i-1]);
			count += temp;
			//count += abs(arr[i]-arr[i-1]);
		}

		count -= arr[n+2] - arr[n+1]; //since last not considered
	}

	cout << endl << "Total head movements : " << count << " cylinders.";
}