#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll>> graph(20009);
vector<ll> counting(20009);
vector<ll> visited(20009);
vector<ll> temp;

void dfs(ll vertex)
{
    temp.push_back(vertex);
    visited[vertex] = 1;
    for (auto child : graph[vertex])
    {
        if (visited[child] == 0)
        {
            if (counting[vertex] == 0)
            {
                counting[child] = 1;
            }

            dfs(child);
        }
    }
}

ll calculate()
{
    ll l = 0, v = 0;
    for (ll i = 0; i < temp.size(); i++)
    {
        if (counting[temp[i]] == 0)
        {
            l++;
        }
        else
        {
            v++;
        }
    }

    ll ans = max(l, v);
    temp.clear();
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    for (int k = 1; k <= num; k++)
    {
        ll n, sum = 0;
        set<ll> s;

        cin >> n;

        for (ll i = 0; i < n; i++)
        {
            ll a, b;

            cin >> a >> b;
            s.insert(a);
            s.insert(b);

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for (auto element : s)
        {
            if (visited[element] == 0)
            {
                dfs(element);
                sum += calculate();
            }
        }

        cout << "Case " << k << ": " << sum << endl;

        for (auto element : s)
        {
            graph[element].clear();
        }

       

        fill(visited.begin(), visited.end(), 0);
        fill(counting.begin(), counting.end(), 0);
    }
}