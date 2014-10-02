    int removeElement(int A[], int n, int elem) {
        int count = 0, end = n;
        for(int i = n-1; i >= 0; i--){
            if(A[i]==elem){
                A[i] = A[n-1-count];
                count++;
            }
        }
        return n-count;
    }
