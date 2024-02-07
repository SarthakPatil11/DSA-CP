// PROGRAM FOR IMPLEMENTATION OF "FIRST COME FIRST SEARVE (FCFS)" SCHEDULING ALGORITHM.
#include<stdio.h>

//STUCTURE FOR INDIVIDUAL PROCECESS.
struct process{
	int pid, bt, wt, tt;
};

int main(){
	static int i, nump;
	static float towt, tott;
	printf("Enter the number of the processes : ");
	scanf("%d", &nump);
	struct process p[nump];
	
	//TO TAKE INPUT AS A BURST TIME & CALCULATE THE OTHER PROCESS DETAILS. 
	for(i = 0; i < nump; i++){
		p[i].pid = i;
		printf("Enter the burst time of process number %d : ", i);
		scanf("%d", &p[i].bt);
		if(i == 0) p[i].wt = 0;
		else p[i].wt = p[i - 1].tt;
		p[i].tt = p[i].wt + p[i].bt;
		towt += p[i].wt;
		tott += p[i].tt;
	}
	
	//TO PRINT ALL PROCESS DETAILS.
	printf("\nProcess ID\tWT\tBT\tTT");
	for(i = 0; i < nump; i++) printf("\n\t%d\t%d\t%d\t%d", p[i].pid, p[i].wt, p[i].bt, p[i].tt);
	printf("\n\nAverage Wating Time : %.2f", towt / nump);
	printf("\nAverage Total Time : %.2f", tott / nump);
	
	return 0;
}
