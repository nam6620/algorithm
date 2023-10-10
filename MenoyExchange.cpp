#include<stdio.h>
#define INPUT "MoneyExchange.txt"
#define MAX 20

int money;
int n;
FILE *fp;
int type[MAX];
int count[MAX];

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

void printfMoney(int a[MAX], int n) {
	printf("\n ");
	for (int i=0; i<n ; i++) {
		printf("%d ", a[i]);
	}
}
void readFile(){
	fp=fopen(INPUT,"r");
	if(fp==NULL){
		//printf("File not found");
	} else {
		//printf("\nFile is opened ");
		fscanf(fp,"%d",&money);
		//printf("\nMoney: %d ",money);
		fscanf(fp,"%d",&n);
		//printf("\nN: %d \n",n);
		for(int i =0; i< n; i++)
		{
			fscanf(fp,"%d",&type[i]);
		}
		
		fclose(fp);
		
	}
}


void exchange() {
	int l = 0;
	int VET[MAX];
	quicksort(type,0,n-1);
	//printfMoney(type,n);
	while (money > 0) {
		if(money < type[n-1]) break;
		for (int i = 0 ; i< n; i++) {
			if (money >= type[i]) {
				//printf("%d ", money);
				money = money - type[i];
				VET[l] = type[i];
				l++;
				for (int j=i; j<n-1; j++){
					type[j]=type[j+1];
				}
				n--;
				break;
			} 
		}
	}
	if (money > 0) {
		printf("\n -1");
	} else {
		printf("\n %d ",l);
		printfMoney(VET,l);
	}

}

int main() {
	readFile();
	exchange();
	return 0;
}

