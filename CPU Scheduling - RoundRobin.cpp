#include<iostream>
#include<queue>
using namespace std;

void Plot_Gantt_Chart(int burst[], int tat[], int n, queue<int> Q);

int main(){
	int n;
	cout << "Enter the number of processes : ";
	cin >> n;

	int burst[n], arrival_time[n], tat[n], waiting_time[n], remaining_time[n];
	queue<int> Q;

	for(int i=0; i<n; i++){
		cout << "Enter the arrival time and burst time of process " << i+1 << " : ";
		cin >> arrival_time[i] >> burst[i];
		remaining_time[i] = burst[i];
	}
	
	int remain=n, quantum, flag=0, time, i;
	cout << "Enter the quantum time : ";
	cin >> quantum;

	for(time=0, i=0; remain!=0;){
		if(remaining_time[i] <= quantum && remaining_time[i]>0){
			time += remaining_time[i];
			remaining_time[i]=0;
			flag=1;
		}
		else if(remaining_time[i] > 0){
			time += quantum;
			remaining_time[i] -= quantum;
		}
		Q.push(i);

		if(remaining_time[i]==0 && flag==1){
			remain--;
			tat[i] = time - arrival_time[i];
			waiting_time[i] = tat[i] - burst[i];
			flag=0;
		}
		
		if(i==n-1) 
	     	i=0; 
	    else if(arrival_time[i+1] <= time) 
	     	i++; 
	    else 
	     	i=0;
	}

	float avg_waiting_time=0.0, avg_turn_around_time=0.0;
	for(int i=0; i<n; i++){
		avg_waiting_time += waiting_time[i];
		avg_turn_around_time += tat[i];
	}
	avg_waiting_time = avg_waiting_time/n;
	avg_turn_around_time = avg_turn_around_time/n;

	cout << "Average Turn Around Time : " << avg_turn_around_time << " ms" << endl;
	cout << "Average Waiting Time : " << avg_waiting_time << " ms" << endl;


	for(int i=0; i<n; i++){
		cout << tat[i] << " :: " << waiting_time[i] << endl;
	}

	cout << endl << endl << "Gantt Chart : " << endl;
	Plot_Gantt_Chart(burst, tat, n, Q);

	return 0;
}




void Plot_Gantt_Chart(int burst[], int tat[], int n, queue<int> Q){
    int i, j;
    // print top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<burst[i]; j++) 
        	printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing process id in the middle
    for(i=0; i<n; i++) {
        for(j=0; j<burst[i] - 1; j++) 
        	printf(" ");

        printf("P%d", Q.front()+1);
        Q.pop();
        for(j=0; j<burst[i] - 1; j++) 
        	printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<burst[i]; j++) 
        	printf("--");
        printf(" ");
    }
    printf("\n");

    // printing the time line
    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<burst[i]; j++) 
        	printf("  ");
    	if(tat[i] > 9) 
    		printf("\b"); // backspace : remove 1 space
        printf("%d", tat[i]);
    }
    printf("\n");
} 