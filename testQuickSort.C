
void swap(vector<int> &arr, int l, int r){
    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}

int partition(vector<int> &arr, int l, int r){
    int pivotKey = arr[l];
    int pivot = l;

    while(l<r){
        while(l<r && arr[r]>=pivotKey)
            r--;
        while(l<r && arr[l]<=pivotKey)
            l++;
        swap(arr,l,r);
    }
    swap(arr,pivotKey,l);
    return l;
}

void quickSort(vector<int> &arr, int l, int r){
    if(l>=r) return;

    int pivot = partition(arr, l, r);
    quickSort(arr,l,pivot-1);
    quickSort(arr,pivot+1,r);
}
