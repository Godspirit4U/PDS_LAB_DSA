#include <stdio.h>

int insert_marks(int arr[], int size, int mark) {
    arr[size] = mark;
    return size + 1;
}

int delete_failed(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        if(arr[i] < 40) {
            for(int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;
        }
    }
    return size;
}

void reverse_marks(int arr[], int size) {
    int start = 0, end = size - 1;
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

float average_marks(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) sum += arr[i];
    return (float)sum/size;
}

int main() {

    int size;
    scanf("%d",&size);
    int arr[size + 10];

    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);

    int mark;
    scanf("%d",&mark);
    size = insert_marks(arr, size, mark);

    size = delete_failed(arr, size);

    reverse_marks(arr, size);

    float avg = average_marks(arr, size);

    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    printf("\n%.2f",avg);

    return 0;
}