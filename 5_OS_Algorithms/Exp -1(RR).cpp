#include<stdio.h>
#include<conio.h>

//STUCTURE FOR INDIVIDUAL PROCECESS.
struct process{
	int pid, bt, wt, tt;
};

struct temp{
	int pid, bt;
};
int main(){
	static int i, j, nump, ts;
	static float tobt, towt, tott, avgwt, avgtt;
	printf("Enter the number of the processes : ");
	scanf("%d", &nump);
	struct process main[nump];
	struct  temp tmp[nump];
	
	//TO TAKE INPUT AS A BURST TIME. 
	for(i = 0; i < nump; i++){
		tmp[i].pid = i;
		printf("Enter the burst time of process number %d : ", i);
		scanf("%d", &tmp[i].bt);
		tobt += tmp[i].bt;
	}
	
	printf("Enter the time slice: ");
	scanf("%d", &ts);
	
	printf("\nProcess ID\tWT\tBT\tTT");
	for(i = j = 0; j < nump; i++, j++){
		if(tmp[j].bt != 0 && tmp[j].bt >= ts){
			tobt -= ts;
			main[i].pid = tmp[j].pid;
			main[i].bt = tmp[j].bt;
			tmp[j].bt -= ts;
			if(i == 0) main[i].wt = 0;
			else main[i].wt = main[i - 1].tt;
			main[i].tt = main[i].wt + main[i].bt;
			printf("\n\t%d\t%d\t%d\t%d\t%d\t%d", main[i].pid, main[i].wt, main[i].bt, main[i].tt, tmp[j].bt, tmp[j].pid);
		}
		else continue;
		if(j == nump-1 && tobt != 0) j = -1;
	}
	return 0;
}
