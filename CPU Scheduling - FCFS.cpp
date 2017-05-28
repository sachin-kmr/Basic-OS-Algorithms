#include<iostream>
#include<cstdio>
using namespace std;

void Plot_Gantt_Chart(int burst[], int tat[], int n);

int main(){
	int n;
	cout << "Enter number of processes : ";
	cin >> n;

	int burst[n], completion_time[n], tat[n], waiting_time[n];
	cout << "Enter burst time (ms) for processes : ";
	for(int i=0; i<n; i++){
		cin >> burst[i];
	}

	completion_time[0] = burst[0];

	for(int i=1; i<n; i++){
		completion_time[i]=burst[i]+completion_time[i-1];
	}

	for(int i=0; i<n; i++){
		tat[i] = completion_time[i];
	}

	for(int i=0; i<n; i++){
		waiting_time[i] = tat[i] - burst[i];
	}

	float av_waiting_time=0.0, av_turn_around_time=0.0;

	for(int i=0; i<n; i++){
		av_waiting_time += waiting_time[i];
		av_turn_around_time += tat[i];
	}
	av_waiting_time = av_waiting_time/n;
	av_turn_around_time = av_turn_around_time/n;

	cout << "Average waiting time : " << av_waiting_time << " ms" << endl;
	cout << "Average turn-around time : " << av_turn_around_time  << " ms" << endl;

	cout << endl << endl << "Gant Chart : " << endl << endl;

	Plot_Gantt_Chart(burst, tat, n);

	return 0;
}

void Plot_Gantt_Chart(int burst[], int tat[], int n){
    int i, j, x=1;
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

        printf("P%d", x++);
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