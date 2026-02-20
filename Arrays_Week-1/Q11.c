#include <stdio.h>

int count_occurrence(int arr[], int size, int key) {

    int count = 0;

    for(int i = 0; i < size; i++) {
        if(arr[i] == key) count++;
    }

    return count;
}

int main() {

    int size;
    scanf("%d",&size);
    int arr[size];

    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);

    int key;
    scanf("%d",&key);

    int result = count_occurrence(arr, size, key);

    printf("%d",result);

    return 0;
}