// PROGRAM FOR IMPLEMENTATION OF "SHORTSES PATH FIRST (SJF)" SCHEDULING ALGORITHM.
#include<stdio.h>

//STUCTURE FOR INDIVIDUAL PROCECESS.
struct process{
	int id, bt, wt, tt;
}temp;
int main(){
	static int nop, i, j;
	static float towt, tott;
	printf("Enter how many number of process you want to enter: ");
	scanf("%d", &nop);
	struct process p[nop];
	
	//TO TAKE INPUT AS A BURST TIME.
	for(i = 0; i < nop; i++){
		p[i].id = i+1;
		printf("Enter the burst time of process number %d: ", i+1);
		scanf("%d", &p[i].bt);
	}
	
	//TO SORT PROCESSES AS PER BURST TIME.
	for(i = 0; i < nop; i++){
		for(j = i + 1; j < nop; j++){
			if(p[i].bt > p[j].bt){
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}
	
	//CALCULATE THE OTHER PROCESS DETAILS.
	for(i = 0; i < nop; i++){
		if(i == 0) p[i].wt = 0;
		else p[i].wt = p[i - 1].tt;
		p[i].tt = p[i].bt + p[i].wt;
		towt += p[i].wt;
		tott += p[i].tt;
	}
	
	//TO PRINT ALL PROCESS DETAILS.
	printf("\nProcess ID\tWT\tBT\tTT");
	for(i = 0; i < nop; i++) printf("\n\t%d\t%d\t%d\t%d", p[i].id, p[i].wt, p[i].bt, p[i].tt);
	printf("\n\nAverage Wating Time : %.2f", towt / nop);
	printf("\nAverage Total Time : %.2f", tott / nop);
	return 0;
}
