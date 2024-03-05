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

int find_left(int len)
{
    for(int left = 0; left + len <= n; left++)
    {
        int right = left + len - 1;
        if(check(left, right))
            return left;
    }
    return -1;
}

void solve(int parity)
{
    int l = 0, r = n + 1, mid;
    if(l % 2 != parity) l++;
    if(r % 2 != parity) r--;

    while(r - l > 1)
    {
        mid = l + (r - l) / 2;
        if(mid % 2 != parity)
            mid++;

        if(mid > r)
            break;

        int left = find_left(mid);

        if(left != -1)
        {
            int lps_len = lps_right - lps_left + 1;
            if(mid > lps_len)
            {
                lps_left = left;
                lps_right = left + mid - 1;
            }
            l = mid + 2;
        }
        else
        {
            r = mid - 2;
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
    solve(0);
    solve(1);
    print();

	return 0;
}
