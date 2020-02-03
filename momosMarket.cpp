#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    int *prices = new int[n];
    // vector<pair<int, int>> prices;
    int price;

    for(int i = 0; i < n; i++){
        cin >> prices[i];
        // prices.push_back( make_pair(price, i));
    }
    
    int q;
    cin >> q;
    
    int *savings = new int[q];
    for(int i = 0; i < q; i++){
        cin >> savings[i];
    }

    for(int i = 1; i < n; i++){
        prices[i] += prices[i-1];
    }

    for(int i = 0; i < q; i++){
        int momos = upper_bound(prices, prices + n, savings[i]) - prices;
        // cout << prices[momos].first << " " << prices[momos].second << endl;
        // cout << momos->second << " " << savings[i] - momos->first << endl;
        cout << momos << " " << savings[i] - prices[momos-1] <<  endl;
    }

    delete [] savings;
    delete [] prices;
    
	return 0;
}
