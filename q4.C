double findMedianSortedArraysSmart(vector<int>& nums1, vector<int>& nums2) {

    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2) return findMedianSortedArrays(nums2, nums1);   // Make sure A2 is the shorter one.

    if (N2 == 0) return ((double)nums1[(N1-1)/2] + (double)nums1[N1/2])/2;  // If A2 is empty

    int lo = 0, hi = N2 * 2;
    while (lo <= hi) {
        int mid2 = (lo + hi) / 2;   // Try Cut 2 
        int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly

        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];  // Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];

        if (L1 > R2) lo = mid2 + 1;     // A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1) hi = mid2 - 1;    // A2's lower half too big; need to move C2 left.
        else return (max(L1,L2) + min(R1, R2)) / 2; // Otherwise, that's the right cut.
    }
    return -1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int s1 = nums1.size();
    int s2 = nums2.size();
    int sAll = s1+s2;

    int i=0;
    int isOdd = sAll%2;
    double out = 0;
    vector<int>::iterator it1 = nums1.begin();
    vector<int>::iterator it2 = nums2.begin();
    int ct = 0;
    while(i<sAll/2+1){
        int cur = 0;
        if(it1!=nums1.end()&&it2!=nums2.end()){
            if(*it1<*it2){ 
                cur = *it1;
                ++it1;
            }else{
                cur = *it2;
                ++it2;
            }
        }else if(it1==nums1.end()&&it2!=nums2.end()){
            cur = *it2;
            ++it2;
        }else if(it1!=nums1.end()&&it2==nums2.end()){
            cur = *it1;
            ++it1;
        }
            
        if(i==(sAll-1)/2||i==sAll/2){ 
            out += cur;
            ct++;
        }
        i++;
    }
    return out/ct;
}

void q4(){
    vector<int> a,b;
    a.push_back(1);
    a.push_back(2);
    b.push_back(2);
    cout<<findMedianSortedArrays(a,b)<<endl;

}
