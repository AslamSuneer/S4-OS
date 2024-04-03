#include <stdio.h>

void first_fit(int ps[100],int ts[100],int m,int n){
	int allocation[100];
	for (int i=0;i<m;i++){
		allocation[i]=-1;
	}
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (ts[j]>=ps[i]){
				allocation[i]=j;
				ts[j]-=ps[i];
				break;
			}
		}
	}
	printf("\nProcess No.\tProcess Size\tBlock No.\n");
	for (int i=0;i<m;i++){
		printf("%d\t\t%d\t\t",i+1,ps[i]);
		if (allocation[i]!=-1){
			printf("%d\n",allocation[i]+1);
		}
		else{
			printf("Not Allocated\n");
		}
	}
}

void best_fit(int ps[100],int ts[100],int m,int n){
	int allocation[100];
	for (int i=0;i<m;i++){
		allocation[i]=-1;
	}
	for (int i=0;i<m;i++){
		int best=-1;
		for (int j=0;j<n;j++){
			if (ts[j]>=ps[i]){
				if (best==-1){
					best=j;
				}
				else if (ts[j]<ts[best]){
					best=j;
				}
			}
		}
		if (best!=-1){
			allocation[i]=best;
			ts[best]-=ps[i];
		}
	}
	printf("\nProcess No.\tProcess Size\tBlock No.\n");
	for (int i=0;i<m;i++){
		printf("%d\t\t%d\t\t",i+1,ps[i]);
		if (allocation[i]!=-1){
			printf("%d\n",allocation[i]+1);
		}
		else{
			printf("Not Allocated\n");
		}
	}
}

void worst_fit(int ps[100],int ts[100],int m,int n){
	int allocation[100];
	for (int i=0;i<m;i++){
		allocation[i]=-1;
	}
	for (int i=0;i<m;i++){
		int worst=-1;
		for (int j=0;j<n;j++){
			if (ts[j]>=ps[i]){
				if (worst==-1){
					worst=j;
				}
				else if (ts[j]>ts[worst]){
					worst=j;
				}
			}
		}
		if (worst!=-1){
			allocation[i]=worst;
			ts[worst]-=ps[i];
		}
	}
	printf("\nProcess No.\tProcess Size\tBlock No.\n");
	for (int i=0;i<m;i++){
		printf("%d\t\t%d\t\t",i+1,ps[i]);
		if (allocation[i]!=-1){
			printf("%d\n",allocation[i]+1);
		}
		else{
			printf("Not Allocated\n");
		}
	}
}



void main(){
	int ch=0;	
	int ps[100];
	int bs[100];
	int m,n,i;
	int ts[100];
		printf("Enter number of blocks : ");
				scanf("%d",&n);
		printf("Enter Size of Block  : ",i+1);
			for (int i=0;i<n;i++)
		scanf("%d",&bs[i]);
		printf("Enter number of processes : ");
				scanf("%d",&m);
				printf("Enter Size of Process  : ", i+1);
		for (int i=0; i<m; i++)
		scanf("%d", &ps[i]);
	while (ch!=10){
		printf("\n1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Exit\n");
		printf("Enter Choice : ");
		scanf("%d",&ch);
		switch (ch){
			case 1: 
				for (int i = 0; i < n; i++) {
					ts[i] = bs[i];
				}
				first_fit(ps,ts,m,n);
				break;
			case 2:
				for (int i = 0; i < n; i++) {
					ts[i] = bs[i];
				}
				best_fit(ps,ts,m,n);
				break;
			case 3:
				for (int i = 0; i < n; i++) {
					ts[i] = bs[i];
				}
				worst_fit(ps,ts,m,n);
				break;
			case 4: 
				break;
			default: 
				printf("Invalid Choice\n");
				break;
		}
	}


}
