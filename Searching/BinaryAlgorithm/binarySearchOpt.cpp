
#include <iostream>
#include <vector>
// from book: Data Structures and Algorithm Analysis by Clifford A. Shaffer, pg. 75
// Return the position of an element in sorted array "A" of
// size "n" with value "K". If "K" is not in "A", return
// the value "n".
int binary(int A[], int n, int K) {
int l = -1;
int r = n; // l and r are beyond array bounds
while (l+1 != r) { // Stop when l and r meet
int i = (l+r)/2; // Check middle of remaining subarray
if (K < A[i]) r = i; // In left half
if (K == A[i]) return i; // Found it
if (K > A[i]) l = i; // In right half
}
return n; // Search value not in A
}

int main() {
    int A[] = {1, 3, 5, 7, 9};
    //Dividing the total size of the array (sizeof(A)) by the size of a 
    //single element (sizeof(A[0])) gives the total number of elements in the array.
    //For A, there are 5 elements, and if each int is 4 bytes, the total size is 5 * 4 = 20 bytes.
    int n = sizeof(A) / sizeof(A[0]);
    int K = 7;

    int result = binary(A, n, K);

    if (result != n) {
        std::cout << "Element " << K << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << K << " not found in the array." << std::endl;
    }

    return 0;
}