#include <stdio.h>

int search_insert_next(int arr[], int size, int key, int value) {

    int index = -1;

    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            index = i;
            break;
        }
    }

    if(index == -1) return size;

    for(int i = size; i > index + 1; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index + 1] = value;

    return size + 1;
}

int main() {

    int size;
    scanf("%d",&size);
    int arr[size + 10];

    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);

    int key, value;
    scanf("%d %d",&key,&value);

    size = search_insert_next(arr, size, key, value);

    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}