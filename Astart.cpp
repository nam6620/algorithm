#include<stdio.h>
#define MTK "Atart_graph.txt"
#define H "Atart_graph.h1.txt"
#define MAX 100


void swap(int *x, int *y);
void read_mtk();
void read_h();
void inmatran(int mt[][MAX],int size);
void inmang(int [],int size);
void Atart(int start, int goal);

int sodinh;
int mtk[MAX][MAX];
int h[MAX];
FILE *fp;


void inmatran(int mt[][MAX], int n){
	for(int i =0; i<n; i++)
	{
		for(int j=0; j<n;j++){
				printf("%4d ",mt[i][j]);
			}
			printf("\n");
	}
			
}

void inmang(int m[], int size) {
	
	for (int i=0;i<size;i++){
		printf("%4d ",m[i]);
	}
}
 
void read_mtk(){
	fp=fopen(MTK,"r");
	if(fp==NULL){
		printf("file not found");
	} else {
		fscanf(fp,"%d",&sodinh);
		printf("%d \n",sodinh);
		for (int j=0; j<sodinh; j++) {
			for (int i=0; i<sodinh; i++) {
				fscanf(fp,"%d",&mtk[j][i]);
			}
		}
		inmatran(mtk,sodinh);
		fclose(fp);
	}
}
void read_h(){
	fp=fopen(H,"r");
	if(fp==NULL){
		printf("file not found");
	} else {
		fscanf(fp,"%d",&sodinh);
		for (int j=0; j<sodinh; j++) {
			fscanf(fp,"%d",&h[j]);
		}
		printf("\n H: \n");
		inmang(h,sodinh);
		fclose(fp);
	}
}
void Atart(int start, int goal) {
	int n;
	int OPEN[MAX];
	int CLOSE[MAX];
	int VISITED[MAX];
	int g[MAX];
	int f[MAX];
	int PARENT[MAX];
	int dem = 0;
	
	//khoi toa cac gia tri
	for (int i=0; i<sodinh; i++) {
		CLOSE[i]=i;
		VISITED[i]=i;
		PARENT[i]=-1;
		g[i]=0;
		f[i]=0;
	}
	
	OPEN[dem++]=start;
	g[start]=0;
	f[start]=h[start];
	while (dem >=0 ){
		n=OPEN[--dem];
		printf("\n Dinh dang xet: %d",n);
		VISITED[n] = -1;
		CLOSE[n]=-1;
		if (n==goal) {
			printf("\n Found the way from %d to %d",start,goal);
			printf("\n PARENT []: "); inmang(PARENT,sodinh);
			int path[MAX];
			int len=0;
			for (int i=goal;i!=-1;i=PARENT[i]){
				path[len++]=i;
			}
			for (int i=len-1;i>0;i--){
				printf("%d - > ",path[i]);
			}
			printf("%d",path[0]);
			return;
		} else {
			for (int i=0; i<sodinh; i++) {
				if (mtk[n][i] != 0) {
					if (VISITED[i]==-1 && OPEN[i]==VISITED[i] ) {
						int g_new = g[n]+mtk[n][i];
						int f_new = g_new + h[i];
						printf("\n g_new[%d] = %d, f_new[%d] = %d",i,g_new,i,g_new);
						if (f_new < f[i]) {
							f[i] = f_new;
							g[i] = g_new;
						}
					}
					else {
						if(VISITED[i]==-1 && CLOSE[i]==-1 && VISITED[i]==CLOSE[i]) {
							int g_new = g[n]+mtk[n][i];
							int f_new = g_new + h[i];
							printf("\n g_new[%d] = %d, f_new[%d] = %d",i,g_new,i,g_new);
							if (f_new < f[i]) {
								f[i] = f_new;
								g[i] = g_new;
							}
						} else {
							g[i]=g[n]+mtk[n][i];
							f[i]=g[i]+h[i];
							VISITED[i]=-1;
							OPEN[dem++]=i;
							PARENT[i]=n;
						}
					}
				}
			}
			printf("\nOPEN[]: ");inmang(OPEN,dem);
			printf("\nCLOSE[]: ");inmang(CLOSE,sodinh);
			printf("\nVISITED[]: ");inmang(VISITED,sodinh);
			printf("\ng[]: ");inmang(g,sodinh);
			printf("\nf[]: ");inmang(f,sodinh);
			for (int i=0; i<dem-1;i++){
				for(int j=i+1;j<dem;j++) {
					if ( f[OPEN[i]] <f [OPEN[j]]) {
						int tam=OPEN[i];
						swap(&OPEN[i],&OPEN[j]);
					}
				}
			}
			printf("\nOPEN_sort: ");inmang(OPEN,dem);
		}
	}
}


void swap(int *x,int *y) {
	int tam=*x; *x=*y; *y=tam;
}
int main() {
	read_mtk();
	read_h();
	Atart(0,2);
	return 0;
}

