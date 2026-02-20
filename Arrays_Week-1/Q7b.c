#include <stdio.h>

void reverse_inplace(int arr[], int size) {

    int start = 0, end = size - 1;

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

    reverse_inplace(arr, size);

    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}