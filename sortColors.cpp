/*
*Sort Colors
*Given an array with n objects colored red, white or blue, sort them so that objects of the same color 
*are adjacent, with the colors in the order red, white and blue.
*Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/

void sortColors(int A[], int n) {
    int red_ct = 0;
    int white_ct = 0;
    int blue_ct = 0;
    for(int i = 0; i < n; i++){
        if(A[i] == 0 )
            red_ct++;
        if(A[i] == 1)
            white_ct++;
        if(A[i] == 2)
            blue_ct++;
    }
    
    for(int i = 0; i < n; i++){
        if(i<red_ct)
            A[i] = 0;
        else if(i<red_ct+white_ct)
            A[i] = 1;
        else
            A[i] = 2;
    }
}
