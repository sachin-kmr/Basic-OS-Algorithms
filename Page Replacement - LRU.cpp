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

int index(int arr[], int n, int el){
	for(int i=0; i<n; i++){
		if(arr[i] == el){
			return i;
		}
	}
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
		int blank = search(table, frames, 10000); //table is not fully used
		if(ans==0){ //page fault

			if(i<=frames || blank==1){ //first fill blank pages then think of replacement
				if(blank==1){
					int indix = index(table, frames, 10000);
					table[indix] = arr[i];
				}
				else{
					table[j] = arr[i];
				}
				j = (j+1)%frames;
			}
			else{ //select the victim
				int flag=frames, hashing[10]={0}, k;
				for(k=i; flag!=0;){
					k--; flag--; hashing[arr[k]]++;
					if(hashing[arr[k]]>1){
						flag++;
						hashing[arr[k]]--;
					}
				} //kth index is the victim

				int indix = index(table, frames, arr[k]);
				table[indix] = arr[i];
			}
			count++;
		}
		i++;
	}

	cout << endl << "Total number of page faults : " << count << endl;
}