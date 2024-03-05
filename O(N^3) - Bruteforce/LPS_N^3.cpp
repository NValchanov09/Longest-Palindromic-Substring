#include<bits/stdc++.h>

using namespace std;

string s;
int n;
int lps_left, lps_right;

void read()
{
    cin >> n >> s;
}

bool check(int left, int right)
{
    while(left <= right && s[left] == s[right])
    {
        left++;
        right--;
    }
    return right < left;
}

void solve()
{
    for(int left = 0; left < n; left++)
    {
        for(int right = left; right < n; right++)
        {
            if(check(left, right))
            {
                int len = right - left + 1;
                int lps_len = lps_right - lps_left + 1;

                if(lps_len < len)
                {
                    lps_left = left;
                    lps_right = right;
                }
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
