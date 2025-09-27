// #include <bits/stdc++.h>
// using namespace std;

// void maxact(int s[], int e[], int n) {
    
//     vector<pair<pair<int,int>, int>> activities;
//     for (int i = 0; i < n; i++) {
//         activities.push_back({{e[i], s[i]}, i + 1}); 
//     }

    
//     sort(activities.begin(), activities.end());

//     vector<int> selected;
//     int last_end = -1;

//     for (int i = 0; i < n; i++) {
//         int start = activities[i].first.second;
//         int end = activities[i].first.first;
//         int idx = activities[i].second;

//         if (start >= last_end) {
//             selected.push_back(idx);
//             last_end = end;
//         }
//     }

   
//     cout << selected.size() << "\n";
//     for (int x : selected) cout << x << " ";
//     cout << "\n";
// }

// int main() {
//     int n;
//     cin >> n;
//     int s[n], e[n];
    
//     for (int i = 0; i < n; i++) {
//         cin >> s[i] >> e[i]; 
//     }

//     maxact(s, e, n);

//     return 0;
// }








//problem of train platforms 
#include <bits/stdc++.h>
using namespace std;

int minPlatforms(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);

    int plat_needed = 0, result = 1;
    int i = 1, j = 0;
    while (i < n && j < n) {
        // If next train arrives before previous one departs -> need new platform
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
        // Else train departs, free one platform
        else {
            plat_needed--;
            j++;
        }
        result = max(result, plat_needed); // keep track of max
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    int arr[n], dep[n];

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> dep[i];

    cout << minPlatforms(arr, dep, n) << endl;
    return 0;
}
