#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int n;
string s;
int dp[MAXN][MAXN];
int lps_left, lps_right;

void read()
{
    cin >> n >> s;
}

bool f(int left, int right)
{
    if(left > right)
       return true;

    if(dp[left][right] != -1)
        return dp[left][right];

    return dp[left][right] = (s[left] == s[right] && f(left + 1, right - 1));
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    for(int left = 0; left < n; left++)
    {
        for(int right = left; right < n; right++)
        {
            int len = right - left + 1;
            int lps_len = lps_right - lps_left + 1;

            if(len > lps_len && f(left, right))
            {
                lps_left = left;
                lps_right = right;
            }
        }
    }
}

void print()
{
    cout << "Longest Palindromic Substring : " << endl;

    for(int i = lps_left; i <= lps_right; i++)
    {
        cout << s[i];
    }
    cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    read();
    solve();
    print();

	return 0;
}
