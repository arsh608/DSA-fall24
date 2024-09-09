void shell_sort(int arr[], int n) {
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        cout << "Gap: " << gap << endl;
        // Perform a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
                // Print the array state after shifting elements
                printArray(arr, n);
            }
            arr[j] = temp;
        }
        // Print the array state after each gap iteration
        printArray(arr, n);
    }
}
