#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of Processes : ";
    cin >> n;

    int burst[10], waiting_time[n], remain_time[n], tat[n], arr_time[n];

    cout << "Enter arrival time and burst time for processes : ";
    for(int i=0; i<n; i++){
        cin >> arr_time[i];
        cin >> burst[i];
    }

    for(int i=0; i<n; i++){
        remain_time[i] = burst[i];
    }

    burst[9]=9999;
    int time, remain=0, smallest, end;

    for(time=0;remain!=n;time++){
        smallest=9;
        for(int i=0;i<n;i++){
            if(arr_time[i] <= time && burst[i] < burst[smallest] && burst[i]>0)
                smallest = i;
        }
        burst[smallest]--;
        if(burst[smallest]==0){
            remain++;
            end=time+1;

            tat[smallest] = end - arr_time[smallest];
            waiting_time[smallest] = tat[smallest] - remain_time[smallest];
        }
    }

    float av_waiting_time=0.0, av_turn_around_time=0.0;

    for(int i=0; i<n; i++){
        // cout << "Waiting time : " << waiting_time[i] << endl;
        // cout << "Turn around time : " << tat[i] << endl;
        av_waiting_time += waiting_time[i];
        av_turn_around_time += tat[i];
    }

    av_waiting_time = av_waiting_time/n;
    av_turn_around_time = av_turn_around_time/n;

    cout << "Average Turn Around Time : " << av_turn_around_time << endl;
    cout << "Average Waiting Time : " << av_waiting_time << endl;

    return 0;
}
