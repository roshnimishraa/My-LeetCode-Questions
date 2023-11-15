#include <bits/stdc++.h>
using namespace std;
void solve(string ip, string op)
{
    if (ip.size() == 0)
    {
        cout << op << "\n";
        return;
    }
    string op2 = op;
    string op1 = op;
    op1.push_back(toupper(ip[0]));
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1); // caps
    solve(ip, op2); // small
}
int main()
{
    string ip, op = "";
    cin >> ip;
    cout<<"required op:\n";
    solve(ip, op);
    return 0;
}
