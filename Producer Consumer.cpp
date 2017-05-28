#include<iostream>
using namespace std;

int mmutex=1, full=0, empty=3, x=0;

int wait(int s){
	return --s;
}

int signal(int s){
	return ++s;
}

void Producer(){
	mmutex = wait(mmutex);
	full = signal(full);
	empty = wait(empty);
	x++;
	cout << "Producer produces the item : " << x << endl;
	mmutex = signal(mmutex);
}

void Consumer(){
	mmutex = wait(mmutex);
	empty = signal(empty);
	full = wait(full);
	x--;
	cout << "Consumer consumes the item : " << x << endl;
	mmutex = signal(mmutex);
}

int main(){
	int n;
	cout << "1. Producer" << endl << "2. Consumer" << endl << "3. Exit!." << endl;
	while(1){
		cout << "Enter your choice : ";
		cin >> n;
		switch(n){
			case 1:
				if(mmutex==1 && empty!=0){
					Producer();
				}else{
					cout << "Buffer is full!" << endl;
				}
				break;

			case 2:
				if(mmutex==1 && full!=0){
					Consumer();
				}else{
					cout << "Buffer is empty!" << endl;
				}
				break;
			case 3:
				exit(0);
		}
	}
	return 0;
}