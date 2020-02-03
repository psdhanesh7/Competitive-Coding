#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int t;
    cin >> t;
    
    while(t--){
        int n, c;
        cin >> n >> c;
        int *pos = new int[n];
        
        for(int i = 0; i < n; i++){
            cin >> pos[i];
        }

        sort(pos, pos + n);
        
        int minDist = 0, maxDist = pos[n-1] - pos[0];
        int distance = 0;
        int ans = -1;
        
        while(minDist <= maxDist){
            distance = (minDist + maxDist)/2;
            int remCows = c-1;
            int i = 1;
            int j = 0;

            while(remCows > 0 && i < n){
                if((pos[i] - pos[j]) >= distance){
                    remCows--;
                    j = i;
                }

                i++;
            }

            

            if(remCows > 0){
                maxDist = distance - 1;
            }
            else{
                minDist = distance + 1;
                ans = distance;
            }
            // cout << ans << endl;
            
        }
        cout << ans << endl;

        delete [] pos;
    }
}