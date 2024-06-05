#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[], int p, int r) {
    int pivot = arr[r];
    int i =p-1;
    int j;
    for (j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i = i + 1;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}
void quicksort(int arr[],int p,int r){
	if(p<r){
		int q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}
int main(){
    int i,n;
    clock_t start, end;
    srand(time(NULL));

    do {
        printf("ENTER THE NUMBER OF INPUTS (0 to exit): ");
        scanf("%d", &n);
        if (n == 0)
            break;
        int arr[n];
        for (i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }

        start = clock();

        quicksort(arr, 0, n-1);

        end = clock();

        double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Time taken: %f seconds\n", time_taken);
    } while (1);
    
    return 0;
}