#include <bits/stdc++.h>

using namespace std;

vector<long> two;

// Complete the counterGame function below.
string counterGame(long n) {
    if ( n == 1) {
        return "Richard";
    }
    int turn = 0;
    while (n != 1) {
        if (ceil(log2(n)) == floor(log2(n))) {
            n /= 2;
        }
        else {
            n -= long(pow(double(2), floor(log2(n))));
        }
        turn = !turn;
    }
    return turn ? "Louise" : "Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
