#include<stdio.h>
#define INPUT "postman.txt"
#define MAX 20

int n;
int a[MAX][MAX];
FILE *fp;
char ch[MAX];

void printfArr(int a[][MAX], int n) {
	printf("\n ");
	for (int j=0; j<n; j++) {
		printf("\n ");
		for (int i=0; i<n ; i++) {
			printf("%d ", a[j][i]);
		}
	}
	
}

void printfA(int a[], int n) {
	printf("\n ");
	for (int i=0; i<n ;i++) {
		printf("%d ",a[i]);
	}
}


void readFile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
	} else {
		fscanf(fp,"%d",&n);
		//printf("%d ",n);
		for (int j=0; j<n; j++) {
			for(int i =0; i< n; i++)
			{
				fscanf(fp,"%d",&a[j][i]);
			}
		}
		fscanf(fp,"%s",&ch);

		//for(int i =0; i< n; i++) {
			//printf("%c ",ch[i]);
		//}
		
		fclose(fp);
		//printfArr(a,n);
	}
}

void init(int m[],int size, int value){
	for(int i=0; i<size; i++){
		m[i]=value;
	}
}

void postman(int start) {
	int l=0;
	int k = start;
	int VET[MAX];
	int Parent[MAX];
	bool check = false;
	
	init(VET,n,0);
	init(Parent,n,-1);
	//printfA(Parent,n);
	while (check == false) {
		int m=0;
		int min;
		VET[k]=-1;
		check = true;
		//printf("%d ", k);
		while (VET[m] == -1 && m < n){
			m++;
			if (VET[m] == 0) {
				 min = a[k][m];
				 l=m;
			}
		}
		//printfA(VET,n);
		for (int j=0; j<n; j++) {
			if (min > a[k][j] && VET[j] != -1 && a[k][j] != 0 ) {
				min = a[k][j];
				l=j;
				//printf("%d ", min);
			}
		}
		
		for (int i=0; i<n; i++) {
			if(VET[i] == 0) check = false; 
		}
		if (check == true ) {
			printf("\n");
			int path[n]; int len=0;
			for(int i=k; i!=-1; i=Parent[i]){
				path[len++]=i;
			}
			path[len++]=start;
			for(int i=len-2; i>=0; i--){
				printf("%c ->",ch[path[i]]);
				
			} 
			printf("%c",ch[path[len-1]]);
			return; 
		}
		Parent[l]=k;
		//printfA(Parent,n);
		k=l;
	}
}

int main(){
	readFile();
	postman(0);
}
