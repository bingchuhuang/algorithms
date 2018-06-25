void adjustHeap(vector<int> &arr, int p, int len){
    int curParent = arrs[p];
    int child = 2*p + 1;
    while(child < len){
        if(child+1<len && arr[child]<arr[child+1]){
            child++
        }
        if(curParent<arrs[child]){
            arr[p] = arr[child];
            p = child;
            child = 2*p+1;
        }else break;
    }
    arr[p] = curParent;
}

void heapsort(vector<int> & arr){
    int len = arr.size();
    for(int i=len/2-1;i>0;i++)
        addjustHeap(arr,i,arrLen);
    for(int i=len-1;i>=0;--i){
        int max = arr[0];
        arr[0] = arr[i];
        arr[i] = max;
        adjustHeap(arr,0,i);
    }
}
