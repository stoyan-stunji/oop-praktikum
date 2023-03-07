void swap(int& num1, int& num2)
{
    int temp = 0;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) 
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = start + count;

    swap(arr[pivotIndex], arr[start]);

    while (start < pivotIndex && end > pivotIndex)
    {

        while (arr[start] <= pivot)
        {
            start++;
        }

        while (arr[end] > pivot) 
        {
            end--;
        }

        if (start < pivotIndex && end > pivotIndex)
        {
            swap(arr[start++], arr[end--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}
