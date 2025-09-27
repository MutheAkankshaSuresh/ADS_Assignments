#include <iostream>
#include <vector>
using namespace std;

// Merge two halves and count inversions
int mergeAndCount(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    int count = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += (mid - i + 1);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= end) temp.push_back(arr[j++]);

    // Copy sorted elements back
    for (int k = 0; k < temp.size(); ++k)
        arr[start + k] = temp[k];

    return count;
}

// Merge sort + count inversions
int countInversions(vector<int>& arr, int start, int end) {
    if (start >= end) return 0;

    int mid = (start + end) / 2;
    int count = 0;

    count += countInversions(arr, start, mid);
    count += countInversions(arr, mid + 1, end);
    count += mergeAndCount(arr, start, mid, end);

    return count;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int total = countInversions(arr, 0, arr.size() - 1);
    cout << "Total Inversions: " << total << endl;
    return 0;
}
