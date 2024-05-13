

void merge(double array[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    // Copia i dati negli array di supporto L ed R
    for (i = 0; i < n1; i++) {
        L[i] = array[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = array[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(double array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}


int partition(double array[], int l, int r) {
    double pivot = array[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++) {
        if (array[j] < pivot) {
            i++;
            double temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    double temp = array[i + 1];
    array[i + 1] = array[r];
    array[r] = temp;
    return i + 1;
}


void quickSort(double array[], int l, int r){
    if (l < r) {
        int pivotIndex = partition(array, l, r);
        quickSort(array, l, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, r);
    }
}


void bubbleSort(double array[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void insertionSort(double array[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        int value = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > value) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = value;
    }
}

void selectionSort(double array[], int n) {
    int i, j, posmin;
    for (i = 0; i < n - 1; i++) {
        posmin = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[posmin]) {
                posmin = j;
            }
        }
        if (posmin != i) {
            int temp = array[i];
            array[i] = array[posmin];
            array[posmin] = temp;
        }
    }
}
