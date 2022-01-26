// https://lightoj.com/problem/february-29
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'

int numLeaps(int year) {
    return (year / 4) - (year / 100) + (year / 400);
}
bool isleap (int year) {
    if ((year % 4 == 0) and (year % 100 != 0)) return true;
    if ((year % 400 == 0)) return true;
    return false;
}

void malena(){
    string str1;
    getline(cin, str1);
    stringstream ss(str1);
    string word;
    vector<string> vs, vs1;
    while (ss >> word) {
        vs.push_back(word);
    }

    string str2;
    getline(cin, str2);
    stringstream ss1(str2);
    string word1;
    while (ss1 >> word1) {
        vs1.push_back(word1);
    }
    int first = stoll(vs[2]), second = stoll(vs1[2]);
    // cout << first << " " << second << endl;
    first--;
    int til_first = numLeaps(first), til_second = numLeaps(second);
    // cout << til_first << " " << til_second << "\n";
    int total_leaps = til_second - til_first;
    if(isleap(first + 1)) {
        bool take = false;
        if(vs[0] == "January" or vs[0] == "February") {
            take = true;
        }
        if(!take) total_leaps--;
    }
    if(isleap(second)) {
        bool take1 = true;
        if(vs1[0] == "January") take1 = false;
        else if(vs1[0] == "February") {
            string num = "";
            for (auto ch: vs1[1]){
                if(ch != ',') num += ch;
            }
            int d = stoll(num);
            // cout << d << " ";
            if (d <= 28) take1 = false;
        }
        if(!take1) total_leaps--;
    }
    // cout << take << " " << take1 << endl;
    cout << total_leaps << "\n";

}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t, c = 0;
    t = 1;
    cin >> t;
    cin.ignore();
    while(t--) {
        cout << "Case " << ++c <<": ";
        malena();
    }
    return 0;
}
