
// (arr + i), (i - 1), (arr + j), (ptr2 + 1), (j - 1), (j + 1), (arr + pos), (i + 1)

void sort(int* arr, int len) {
    entry:  
        int i = 0;

    BB1:
        if (i < len) goto BB2; else goto exit; 
    
    BB2: 
        int* ptr1 = arr + i;
        int key = *ptr1;
        int j = i - 1;
        goto BB3;
    
    BB3: 
        if (j >= 0) goto BB4; else goto BB5;
    
    BB4:
        int* ptr2 = arr + j;
        int el = *ptr2;
        if (el < key) goto BB5;
        int* ptr3 = ptr2 + 1;
        *ptr3 = *ptr2;
        j = j - 1;
        goto BB3;
    
    BB5: 
        unsigned pos = j + 1;
        int* ptr4 = arr + pos;
        *ptr4 = key;
        i = i + 1;
        goto BB1;
    
    exit:
        return;
} 

