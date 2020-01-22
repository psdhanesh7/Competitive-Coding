#include <iostream>
using namespace std;


int main() {
    /* Read input as specified in the question.
     * Print output as specified in the question.
     */
    int n;
    cin >> n;
    
    int *ar = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
        cout << ar[i] << " " ;
    }
    
    int p = 1;
    for(int i = 0; i < n; i++)
    {
        // cout << ar[i] << " " ;
        p = p * ar[i];
    }
    
    cout << p << endl;
    
    return 0;
}