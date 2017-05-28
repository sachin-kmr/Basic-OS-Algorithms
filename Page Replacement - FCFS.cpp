#include<iostream>
using namespace std;

int search(int arr[], int n, int el){
	for(int i=0; i<n; i++){
		if(arr[i] == el){
			return 1;
		}
	}
	return 0;
}

int main(){
	int n, frames, count=0;
	cout << "Enter number of pages : ";
	cin >> n;

	int arr[n];
	cout << "Enter pages : ";
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	cout << "Enter number of frames : ";
	cin >> frames;

	int table[frames];
	for(int i=0; i<frames; i++){
		table[i]=10000;
	}

	int i=0, j=0;
	while(1){
		if(i==n){
			break;
		}
		int ans = search(table, frames, arr[i]);
		if(ans == 0){
			table[j] = arr[i];
			j=((j+1)%frames);
			count++;
		}
		i++;
	}

	cout << endl << "Total number of page faults : " << count << endl;
}