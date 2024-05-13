void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void merge(int array[], int l, int m, int r){

  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  // Copia i dati negli array di supporto L ed R
  for(i = 0; i < n1; i++){

    L[i] = array[l + i];
  }

  for(j = 0; j < n2; j++){

    R[j] = array[m + 1 + j];
  }

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2){

    if (L[i] <= R[j]){

      array[k] = L[i];
      i++;

    } else {
      array[k] = R[j];
      j++;

    }

    k++;
  }

  while (i < n1){

    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2){

    array[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int array[], int l, int r){

  if (l < r){
    
    int m = l + (r - l) / 2;

    mergeSort(array, l, m);
    mergeSort(array, m + 1, r);

    merge(array, l, m, r);
  }
}



void quickSort(int array[], int l, int r){

    if(l < r){

        int pivotIndex = partition(array, l, r);

        quickSort(array, l, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, r);
    }
}


int partition(int array[], int l, int r){

    int pivot = array[r];
    int i = l - 1;

    for(int j = l; j <= r; j++){

        if(array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(array[i + 1], array[r]);

    return i + 1;
}


void bubbleSort(int arr[], int n){

    int i, j, temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if( arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            } 
        }
    }
}

void  inserimentoSort( int  arr[],  int  n) {  
    int  i, value, j;  
    for  (i = 1; i < n; i++) {  
        value = arr[i];  
        j = i - 1;  
  
        while  (j >= 0 && arr[j] > value) {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = value;  
    }  
}  


void selectionSort(int arr[], int n) {
    int i, j, posmin;

    
    for (i = 0; i < n-1; i++) {
        
        posmin = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[posmin]){
                posmin = j;
            }
        }
        
        if (posmin != i){
            swap(&arr[posmin], &arr[i]);
        }
    }
}