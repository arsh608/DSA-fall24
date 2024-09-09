void comb_sort(int arr[], int n) {
    const float shrink = 1.3;
    int gap = n;
    bool swapped = true; 
    
    while (gap > 1 || swapped) {
        gap = (int)(gap / shrink);
        if (gap < 1) {
            gap = 1;
        }

        swapped = false;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}
