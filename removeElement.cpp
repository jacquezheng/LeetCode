/* https://oj.leetcode.com/problems/remove-element/
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */


int removeElement(int A[], int n, int elem) {
    int count = 0;
    for(int i = n-1; i >= 0; i--){
        if(A[i]==elem){
            A[i] = A[n-1-count];
            count++;
        }
    }
    return n-count;
}
