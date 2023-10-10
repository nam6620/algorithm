#include<stdio.h>
#define INPUT "DFS1.txt"
#define MAX 20
int a[MAX][MAX];
FILE *fp;
int sodinh;

void printMaxtrix(int mt[][MAX], int n){
	for(int i =0; i<n; i++)
	{
		for(int j=0; j<n;j++){
				printf("%d ",mt[i][j]);
			}
			printf("\n");
	}
			
}
void inmang(int m[], int size) {
	for (int i=0;i<size;i++){
		printf("%d ",m[i]);
	}

}


void readfile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
	} else {
		printf("\nFile is opened ");
		fscanf(fp,"%d",&sodinh);
		printf("\nso dinh: %d \n",sodinh);
		for(int i =0; i<sodinh; i++)
			for(int j=0; j<sodinh;j++){
				fscanf(fp,"%d",&a[i][j]);
			}
			
		printMaxtrix(a,sodinh);
		fclose(fp);
		
	}
}
void init(int m[],int size, int value){
	for(int i=0; i<size; i++){
		m[i]=value;
	}
}


void DepthFirstSearch(int start, int goal){
	int OPEN[MAX];
	int CLOSE[MAX];
	int Parent[MAX];
	int Tn[MAX];
	int n;
	int dem=0;
	int d;
	OPEN[dem]=start;
	init(CLOSE,sodinh,0);
	init(Parent,sodinh,-1);
	init(Tn,sodinh,0);
	Tn[start]=-1;
	Parent[start]=-1;
	while(dem>=0){
		n=OPEN[0];
		printf("\nDinh dang xet: %d",n);
		for (int j=0; j<dem;j++){
			OPEN[j]=OPEN[j+1];
		}
		CLOSE[n]=-1;
		if (n==goal) {
			printf("\nTim thay duong di tu %d toi %d ",start,goal);
			int path[sodinh]; int len=0;
			for(int i=goal; i!=-1; i=Parent[i]){
				path[len++]=i;
			}
			//in ds theo cua path
			for(int i=len-1; i>=0; i--){
				printf("%d ",path[i]);
			} 
			return; 
		}else {
			d = 0;
			int C[sodinh];
			for(int i=0; i<sodinh; i++){
				if(a[n][i]==1 && CLOSE[i]!=-1 && Tn[i]==0){
					C[d]=i;
					d++;
					Parent[i]=n;
					Tn[i]=-1;
				}
			}
			printf("\nOPEN ");
			inmang(OPEN,dem);
			if(d>0) {
				dem=dem+d;
				for (int j=0; j<dem-d;j++) {
					OPEN[j+d]=OPEN[j];
				}

				for (int i=0;i<d;i++) {
					OPEN[i]=C[i];
				}
			}
			printf("\nOPEN ");
			inmang(OPEN,dem);
			printf("\nCLOSE ");
			inmang(CLOSE,sodinh);
			printf("\nParent ");
			inmang(Parent,sodinh);
			printf("\n");
			dem--;
			
		}
		if(dem<0) {
			printf("\n khong tim thay duong di");
		} 
	}
}


int main(){
	readfile();
	DepthFirstSearch(0,7);
	return 0;
}
