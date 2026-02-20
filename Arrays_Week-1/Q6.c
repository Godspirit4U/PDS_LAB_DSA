#include <stdio.h>

int remove_duplicates(int arr[], int size) {

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; ) {
            if(arr[i] == arr[j]) {
                for(int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
            } else {
                j++;
            }
        }
    }
    return size;
}

int main() {

    int size;
    scanf("%d",&size);
    int arr[size + 10];

    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);

    size = remove_duplicates(arr, size);

    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}