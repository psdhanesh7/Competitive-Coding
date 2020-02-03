#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int t;
    cin >> t;
    while(t--){
        
        int n, k;
        cin >> n >> k;
        
        int *candies = new int[n];
        for(int i = 0; i < n; i++){
            cin >> candies[i];
        }
        
        sort(candies, candies+n);

        int minCandies = 1;
        int maxCandies = candies[0];
        int ans = 1;

        while(minCandies <= maxCandies){

            int mid = (minCandies + maxCandies)/2;
            int remStudents = k;
            int i = 0;

            while(remStudents > 0 && i < n){
                remStudents -= candies[i]/mid;
                i++;
            }

            if(remStudents > 0){
                maxCandies = mid - 1;
            }
            else{
                minCandies = mid + 1;
                ans = mid;
            }

            cout << minCandies << " " << maxCandies << " " << mid << endl;
        }

        // cout << ans << endl;

        delete [] candies;
        
    }
    
    return 0;
}