#include<stdio.h>
#define INPUT "bag.txt"
#define MAX 20

int bagWeight;
int n;
FILE *fp;
int P[MAX];
int W[MAX];
int location[MAX];


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(float arr[] , int arr1[] ,int arr2[], int location[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap(&arr1[j],&arr1[j+1]);
                swap(&arr2[j],&arr2[j+1]);
                swap(&location[j],&location[j+1]);
            }
        }
    }
}
void printfArray(int a[MAX], int n) {
	printf("\n ");
	for (int i=0; i<n ; i++) {
		printf("%d ", a[i]);
	}
}

void readFile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		printf("File not found");
	} else {
		//printf("\nFile is opened ");
		fscanf(fp,"%d",&bagWeight);
		//printf("\nwieghtBag: %d ",bagWeight);
		fscanf(fp,"%d",&n);
		//printf("\nN: %d \n",n);
		for(int i =0; i< n; i++)
		{
			fscanf(fp,"%d",&P[i]);
			location[i] = i+1;
		}
		for(int i =0; i< n; i++)
		{
			fscanf(fp,"%d",&W[i]);
		}
		//printfArray(P,n);
		//printfArray(W,n);
		fclose(fp);
	}
}

void putIn() {
	float ar[MAX];
	int VET[MAX];
	int l=0, i = 0;
	int money=0,weight=0;;
	for (int i=0; i<n;i++) {
		ar[i] = float(W[i])/P[i];
	}
	bubbleSort(ar,W,P,location,n);
	//printfArray(P,n);
	//printfArray(W,n);
	while (i<n  && bagWeight > 0 ) {
		if (P[i] <= bagWeight) {
			VET[l] = location[i];
			l++;
			bagWeight -= P[i]; 
			money += W[i];
			weight += P[i];
		}
		i++;
	}
	printfArray(VET,l);
	printf("\n value %d ",money);
	printf("\n weight %d ",weight);
}

int main() {
	readFile();
	putIn();
}
