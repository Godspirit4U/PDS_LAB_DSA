#include <stdio.h>

void reverse_temp(int arr[], int size) {

    int temp[size];

    for(int i = 0; i < size; i++) {
        temp[i] = arr[size - i - 1];
    }

    for(int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

int main() {

    int size;
    scanf("%d",&size);
    int arr[size];

    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);

    reverse_temp(arr, size);

    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}