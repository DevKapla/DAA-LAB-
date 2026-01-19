#include <bits/stdc++.h>
using namespace std;

// Binary Search Iterative
void binarySearchIterative() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = 5, key = 8;
    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) {
            ans = mid;
            break;
        }
        if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
}

// Binary Search Recursive
int bsRec(int arr[], int l, int r, int key) {
    if (l > r) return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return bsRec(arr, l, mid - 1, key);
    return bsRec(arr, mid + 1, r, key);
}

void binarySearchRecursive() {
    int arr[] = {2, 4, 6, 8, 10};
    cout << bsRec(arr, 0, 4, 8) << endl;
}

// Merge Sort Recursive
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortRec(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortRec(arr, l, m);
        mergeSortRec(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeSortRecursive() {
    int arr[] = {5, 2, 9, 1, 6};
    mergeSortRec(arr, 0, 4);
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// Merge Sort Iterative
void mergeSortIterative() {
    int arr[] = {5, 2, 9, 1, 6};
    int n = 5;

    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }

    for (int x : arr) cout << x << " ";
    cout << endl;
}

// Quick Sort Recursive
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortRec(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSortRec(arr, low, p - 1);
        quickSortRec(arr, p + 1, high);
    }
}

void quickSortRecursive() {
    int arr[] = {10, 7, 8, 9, 1};
    quickSortRec(arr, 0, 4);
    for (int x : arr) cout << x << " ";
    cout << endl;
}

// Quick Sort Iterative
void quickSortIterative() {
    int arr[] = {10, 7, 8, 9, 1};
    int n = 5;

    stack<int> st;
    st.push(0);
    st.push(n - 1);

    while (!st.empty()) {
        int h = st.top(); st.pop();
        int l = st.top(); st.pop();
        int p = partition(arr, l, h);

        if (p - 1 > l) { st.push(l); st.push(p - 1); }
        if (p + 1 < h) { st.push(p + 1); st.push(h); }
    }

    for (int x : arr) cout << x << " ";
    cout << endl;
}

// Maximum Subarray Sum
int maxCross(int arr[], int l, int m, int h) {
    int sum = 0, left = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        left = max(left, sum);
    }
    sum = 0;
    int right = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum += arr[i];
        right = max(right, sum);
    }
    return left + right;
}

int maxSub(int arr[], int l, int h) {
    if (l == h) return arr[l];
    int m = (l + h) / 2;
    return max(
        max(maxSub(arr, l, m), maxSub(arr, m + 1, h)),
        maxCross(arr, l, m, h)
    );
}

void maximumSubarraySum() {
    int arr[] = {2, -4, 3, -1, 2, -4, 3};
    cout << maxSub(arr, 0, 6) << endl;
}

int main() {
    binarySearchIterative();
    binarySearchRecursive();
    mergeSortRecursive();
    mergeSortIterative();
    quickSortRecursive();
    quickSortIterative();
    maximumSubarraySum();
    return 0;
}
