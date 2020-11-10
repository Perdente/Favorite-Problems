/*https://atcoder.jp/contests/abc171/tasks/abc171_c*/
/*
Note:Here we subtracting 1 from n each time cause it's 1's indexed
Say n=28
After subtracting n=27;

1st call-solve(27/26->1)n--;
2nd call-solve(0/26->)n=0 returns "";

go back to 2nd call-(char)'a'+0%26->'a'
go back to 1st call-(char)'a'+1%26->'b'

->ab

*/


#include <bits/stdc++.h>
using namespace std;

string solve(long long n) 
{
	  if (n == 0) return "";
    n--;
    return solve(n/26) + (char)('a' + n%26);
}

int main() {
    long long n;
    cin >> n;
    cout << solve(n) <<endl;
    return 0;
}
