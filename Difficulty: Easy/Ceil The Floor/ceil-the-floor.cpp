//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


int floorOfX(int arr[], int n, int x) {
    
    int low = 0;
    int high = n-1;
    int k = -1;
    
    while(low <= high) {
        
        int mid = low + (high-low)/2;
        
        if(arr[mid] <= x) {
            k = arr[mid];
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    
    return k;
    
}

int ceilOfX(int arr[], int n, int x) {
    
    int low = 0;
    int high = n-1;
    int k = -1;
    
    while(low <= high) {
        
        int mid = low + (high-low)/2;
        
        if(arr[mid] >= x) {
            k = arr[mid];
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    
    return k;
    
}


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    sort(arr, arr+n);
    
    int floor = floorOfX(arr, n, x);
    int ceil = ceilOfX(arr, n ,x);
    
    pair<int, int> ans;
    
    ans.first = floor;
    ans.second = ceil;
    
    return ans;
    
}