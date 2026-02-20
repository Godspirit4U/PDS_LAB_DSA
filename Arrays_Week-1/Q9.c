#include <stdio.h>

int search_delete(int arr[], int size, int key) {

    int index = -1;

    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            index = i;
            break;
        }
    }

    if(index == -1) return size;

    for(int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

int main() {

    int size;
    scanf("%d",&size);
    int arr[size + 10];

    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);

    int key;
    scanf("%d",&key);

    size = search_delete(arr, size, key);

    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}