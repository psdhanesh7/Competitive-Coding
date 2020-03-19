#include <bits/stdc++.h>
using namespace std;

int getMinLife(int **mg, int si, int sj, int r, int c)
{
	if( (si == r-1 && sj == c-2) || (si == r-2 && sj == c-1) )
	{
		return 1;
	}

	int option1 = getMinLife(mg, si+1, sj, r, c);
	int option2 = getMinLife(mg, si, sj+1, r, c);

	int ans = min(option1, option2);

	return ans;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int r, c;
        cin >> r >> c;
        
        int **mg = new int*[r];
        
        for(int i = 0; i < r; i++)
        {   
            mg[i] = new int[c];
            for(int j = 0 ; j < c; j++)
            {
                cin >> mg[i][j];
            }
        }

        int minLife = getMinLife(mg, 0, 0, r, c);

        for(int i = 0; i < r; i++)
        {
        	delete [] mg[i];
        }

        delete [] mg;
    }
    return 0;
}
