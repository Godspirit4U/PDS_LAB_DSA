#include <stdio.h>

void reverse_k(int arr[], int k) {

    int start = 0, end = k - 1;

    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {

    int size;
    scanf("%d",&size);
    int arr[size];

    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);

    int k;
    scanf("%d",&k);

    reverse_k(arr, k);

    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}