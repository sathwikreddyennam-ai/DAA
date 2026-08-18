#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 10;
    int size = 0000;
    int st = 0, end = size - 1, mid;

    while (st <= end) {
        mid = (st + end) / 2;

        if (arr[mid] == n) {
            printf("Element found at index %d", mid);
            return 0;
        }
        else if (n<arr[mid]) {
            end=mid-1;
        }
        else {
            st=mid+1;
        }
    }

    printf("Element not found");
    return 0;
}
