#include<stdio.h>
#define INPUT "Leodoi.mtk1.txt"
#define H "Leodoi.h1.txt"
#define MAX 100




int sodinh;
int mtk[MAX][MAX];
int h[MAX];
FILE *fp;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}
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
 
void readFile(){
	fp=fopen(INPUT,"r");
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
		printMaxtrix(mtk,sodinh);
		fclose(fp);
	}
	fp=fopen(H,"r");
	if(fp==NULL){
		printf("file not found");
	} else {
		for (int j=0; j<sodinh; j++) {
			fscanf(fp,"%d",&h[j]);

		}
		inmang(h,sodinh);
		fclose(fp);
	}
}


void Leodoi(int start,int goal){
	int n;
	int OPEN[MAX];
	int OPENED[MAX];
	int CLOSE[MAX];
	int Tn[MAX];
	int CHA[MAX];
	
	for (int i=0;i<sodinh;i++) {
		OPENED[i]=i;
		CLOSE[i]=i;
		CHA[i]=-1;
	}
	
	int dem=0;
	OPEN[dem++]=start;
	printf("\nOPEN[]: ");inmang(OPEN,dem);
	while (dem>=0) {
		n=OPEN[--dem];
		printf("\n Dinh dang xet: %d",n);
		CLOSE[n]=-1;
		printf("\nCLOSE[]: ");inmang(CLOSE,sodinh);
		
		OPENED[n]=-1;
		printf("\nOPENED[]: ");inmang(OPENED,sodinh);
		if(n==goal) {
			printf("\n Found the way from %d to %d",start,goal);
			
			printf("\nCHA[]: ");inmang(CHA,sodinh);
			int duongdi[MAX];
			int len=0;
			for (int i=goal; i!=-1; i=CHA[i]){
				duongdi[len++]=i;
			}
			printf("\nDuong di tu %d -> %d la ",start,goal);
			for (int i=len-1;i>=0;i--){
				printf("%d -> ",duongdi[i]);
			}
			return;
		} else {
			int dem_Tn=0;
			for (int i=0;i<sodinh;i++) {
				if (mtk[n][i]==1 && CLOSE[i]!=-1 && OPENED[i]!=-1){
					Tn[dem_Tn++]=i;
					OPEN[i]=-1;
					OPENED[i]=-1;
					CHA[i]=n;
				}
			}
			printf("\nTn[] ");inmang(Tn,dem_Tn);
			for (int i=0;i<dem_Tn;i++) {
				OPEN[dem++] = Tn[i];
			}
			printf("\nOPEN[] chua sap xep: ");inmang(OPEN,dem);
			//chen cac gia tri cua Tn vao OPEN
			bubbleSort(OPEN,dem);
			printf("\nOPEN[] da sap xep: ");inmang(OPEN,dem);
		}
	}
}
int main() {
	readFile();
	Leodoi(0,8);
}
