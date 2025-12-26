int maxElement(int arr[], int n) {
    int max=INT_MIN;
    for(int i=0; i<n; i++) {
        if(arr[i]>max) max=arr[i];
    }
    return max;
}

void radixSort(int arr[], int n) {
    int max=maxElement(arr, n);
    for(int exp=1; (max/exp)>0; exp*=10) {
        int *temp=(int*)calloc(sizeof(int), n);
        int bucket[10]={0};
        for(int i=0; i<n; i++) {
            bucket[(arr[i]/exp)%10]++;
        }
        for(int i=1; i<10; i++) {
            bucket[i]+=bucket[i-1];
        }
        for(int i=n-1; i>=0; i--) {
            int digit=(arr[i]/exp)%10;
            temp[bucket[digit]-1]=arr[i];
            bucket[digit]--;
        }
        for(int i=0; i<n; i++) {
            arr[i]=temp[i];
        }
        free(temp);
    }
}

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[]={170, 45, 75, 90, 802, 24, 2, 66};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, n);
    print(arr, n);
}
