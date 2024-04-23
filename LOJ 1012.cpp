#include <bits/stdc++.h>
using namespace std;
#define ll long long int

char a[22][22];
int ans;

void dfs(int x, int y, int w, int h)
{
    ans += 1;
    a[x][y] = 'p';
    

    if (a[x + 1][y] == '.' && x + 1 < w && y < h && x + 1 >= 0 && y >= 0)
    {

        dfs(x + 1, y, w, h);
    }

    if (a[x - 1][y] == '.' && x - 1 >= 0 && y < h && x - 1 < w && y >= 0)
    {

        dfs(x - 1, y, w, h);
    }

    if (a[x][y + 1] == '.' && x < w && y + 1 < h && x >= 0 && y + 1 >= 0)
    {

        dfs(x, y + 1, w, h);
    }

    if (a[x][y - 1] == '.' && x < w && y - 1 >= 0 && x >= 0 && y - 1 < h)
    {

        dfs(x, y - 1, w, h);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++)
    {
        int w, h, count = 0, x, y;
        cin >> h >> w;

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '@')
                {
                    
                    x = i;
                    y = j;
                }
            }
        }

        dfs(x, y, w, h);

        cout << "Case"
             << " " << i << ": " << ans << endl;

        ans = 0;
    }
}