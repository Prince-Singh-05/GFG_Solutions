//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
  
    // void rotate(int a[], int n) {
    //     int temp = a[0];
        
    //     for(int i = 0; i<n-1; i++) {
    //         a[i] = a[i+1];
    //     }
        
    //     a[n-1] = temp;
    // }
    
    long long max_sum(int a[], int n) {
        
        // long long maxSum = 0;
        
        // int count = 0;
        
        // while(count < n) {
            
        //     rotate(a, n);
        //     count++;
            
        //     long long sum = 0;
            
        //     for(int i = 0; i < n; i++) {
        //         sum += i*a[i];
        //     }
            
        //     maxSum = max(maxSum, sum);
            
            
        // }
        
        // return maxSum;
        
        
        // long long sum=0;
        // long long res=0;
        // long long maxi=0;
        // for(int i=0;i<n;i++){
        //     sum+=a[i];
        //     res+=(long long)a[i]*i;
        // }
        // maxi=max(res,maxi);
        // for(int i=0;i<n;i++){
        //     res=res+a[i]*n-sum;
        //     maxi=max(res,maxi);
        // }
        // return maxi;
        
        long long totalSum = 0;
        long long weightedSum = 0;
    
        // Calculate the total sum of array elements and initial weighted sum
        for (long long i = 0; i < n; i++) {
            totalSum += a[i];
            weightedSum += i * a[i];
        }
    
        long long maxSum = weightedSum;
        long long size = n;
    
        // Iterate through each rotation and update the weighted sum
        while (n > 0) {
            weightedSum = weightedSum + totalSum - size * a[n - 1];
            maxSum = max(maxSum, weightedSum);
            --n;
        }
    
        return maxSum;
        
    }

};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends