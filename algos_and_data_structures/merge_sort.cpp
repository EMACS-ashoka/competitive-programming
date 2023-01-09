void merge(vector<int> &a, int p, int q, int r) {
    /*
    a[p:q-1] and a[q:r] are sorted

    merge function merges a[p:r] into sorted array
    */

    int n_left = q-p;
    int n_right = r-q+1;

    // copy a[p:q-1] and a[q:r] into left and right array
    vector<int> left(n_left);
    vector<int> right(n_right);

    for (int i = 0; i < n_left; i++) {
        left[i] = a[i+p];
    }

    for (int i = 0; i < n_right; i++) {
        right[i] = a[i+q];
    }

    // while there are elements still left in both the arrays, add the smallest one to a[p:r]

    int i = 0;
    int j = 0;
    while (i < n_left && j < n_right) {
        if (left[i] <= right[j]) {
            a[p+i+j] = left[i];
            i++;
        }
        else {
            a[p+i+j] = right[j];

            // store inversion count in global var or turn function return to int
            // inv_count += n_left - i;

            j++;

        }
    }

    // add the remaining elements to a[p:r]

    while (i < n_left) {
        a[p+i+j] = left[i];
        i++;
    }

    while (j < n_right) {
        a[p+i+j] = right[j];
        j++;
    }
}

void mergesort(vector<int> &a, int l, int r) {
    // BASE CASE
    if (l >= r) {
        return;
    }

    // RECURSION (DIVIDE and CONQUER)
    int mid = (l + r)/2;
    mergesort(a, l, mid);
    mergesort(a, mid+1, r);

    // COMBINE
    merge(a, l, mid+1, r);
}