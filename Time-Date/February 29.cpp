// https://lightoj.com/problem/february-29
// https://www.geeksforgeeks.org/count-of-leap-years-in-a-given-year-range/
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
    // First we count the total number of leap years in range. But....
    // How to know if the date didn't exceed the Feb 29, huh ????
    if(isleap(first + 1)) {
        bool take = false;
        // If initial month is in January then there is high chance we meet Feb 29, right ?? Yeapp😁
        // But wait why full month of February🤔, cause last day of February, 29th so every day from February gets the pass, right?
        // Ok, so what about? March, April and so on? They just leave February behind🥺
        if(vs[0] == "January" or vs[0] == "February") { 
            take = true;
        }
        if(!take) total_leaps--;
    }
    if(isleap(second)) {
        bool take1 = true;
        // Similar Fashion date until February 28 has no probablity of 29th Feb, right?
        // But the rest of the months and dates gets a pass😃
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
