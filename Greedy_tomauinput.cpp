#include<stdio.h>
#define INPUT "Greedy_tomauinput.txt"
#define MAX 20

int n;
int a[MAX][MAX];
FILE *fp;


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
		printf("%d ",n);
		for (int j=0; j<n; j++) {
			for(int i =0; i< n; i++)
			{
				fscanf(fp,"%5d",&a[j][i]);
			}
		}
		fclose(fp);
		printfArr(a,n);
	}
}
void init(int m[],int size, int value){
	for(int i=0; i<size; i++){
		m[i]=value;
	}
}

int max(int m[], int size) {
	int max =0;
	int posmax =0;
	for (int i=0; i<size; i++){
		if (max <m[i]){
			max=m[i];
			posmax=i;
		}
	}
	return posmax;
}

void toMau() {
	int V[MAX];
	int COLOR[MAX];
	init(COLOR,n,0);
	for (int j=0; j<n; j++) {
		int dem =0;
			for(int i =0; i< n; i++)
			{
				if (a[j][i]==1 && i!=j) dem++;
			}
		V[j]= dem;
	}
	//printf("\n");
	//printfA(V,n);
	//printf("\n");
	int color =1;
	while (color <=3) {
		int m=max(V,n);
		COLOR[m]=color;
		for (int i=0; i<n;){
			if (a[m][i]==0 && COLOR[i]==0){
				COLOR[i]=color;
				for (int j=i+1;j<n;j++) {
					if(a[i][j]==1) {
						i=j+1;
						break;
					}
				}
			}
			i++;
		}
		V[m]=-1;
		printf("\n COLOR[]");
		printfA(COLOR,n);
		color++;
	}
}


int main() {
	readFile();
	toMau();
}

