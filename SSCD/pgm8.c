/*Program 8
Design, develop and implement a C/C++/Java program to implement Banker’s algorithm. Assume suitable input required to demonstrate the results
Code*/
#include<stdio.h>
void main() {
	int k=0, output[10], d=0, t=0, ins[5], i, available[5], allocated[10][5], need[10][5],MAX[10][5];
	int pno,P[10], j, n, count=0 ;
	printf("\n Enter the number of resources : ");
	scanf("%d", &n);
	printf("\n Enter the max instances of each resources\n");
	for (i=0;i<n;i++) 
	{
		available[i]=0;
		scanf("%d",&ins[i]);
	}
	printf("\n Enter the number of processes : ");
	scanf("%d", &pno);
	printf("\n Enter the allocation matrix \n");
	for (i=0;i<n;i++)	
	printf("\n");
	for (i=0;i <pno;i++) 
	{
		P[i]=i;
		printf("P[%d]  ",P[i]+1);
		for (j=0;j<n;j++) 
		{
			scanf("%d",&allocated[i][j]);
			available[j]+=allocated[i][j];
		}
	}
	printf("\nEnter the MAX matrix \n     ");
	for (i=0;i<n;i++) {
	
		available[i]=ins[i]-available[i];
	}
	printf("\n");
	for (i=0;i <pno;i++) {
		printf("P[%d]  ",i+1);
		for (j=0;j<n;j++)
		 scanf("%d", &MAX[i][j]);
	}
	printf("\n");
	A: d=-1;
	for (i=0;i <pno;i++) {
		count=0;
		t=P[i];
		for (j=0;j<n;j++) {
			need[t][j] = MAX[t][j]-allocated[t][j];
			if(need[t][j]<=available[j])
			 count++;
		}
		if(count==n) {
			output[k++]=P[i];
			for (j=0;j<n;j++)
			available[j]+=allocated[t][j];
		} else
		 P[++d]=P[i];
	}
	if(d!=-1) {
		pno=d+1;
		goto A;
	}
	printf("The safe sequence is:\n");
	for (i=0;i<k;i++)
	printf(" P[%d] ",output[i]+1);
}


