#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
int const MAXN = 1e6;

int generate()
{
    return rand() * 1000 + rand();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));

    // generate first 8 test that randomly
    for (int i = 0; i < 8; ++i)
    {
        string fileName = "test" + to_string(i) + ".txt";
        ofstream fo(fileName);
        for (int j = 0; j < MAXN; j++)
            fo << generate() << " ";
        fo.close();
    }

    vector<int> a;         // create vector a that is nunber-container
    a = vector<int>(MAXN); // a contains MAXN integers

    // generate 1 test that increasing
    {

        string fileName = "test" + to_string(8) + ".txt";
        ofstream fo(fileName);
        for (int j = 0; j < MAXN; j++)
            a[j] = generate();
        sort(a.begin(), a.end()); // Sort up ascending
        for (int j = 0; j < MAXN; j++)
            fo << a[j] << " ";
        fo.close();
    }

    a.clear();             // clear vector a
    a = vector<int>(MAXN); // resize a to MAXN

    // generate 1 test that decreasing
    {
        a = vector<int>(MAXN);
        string fileName = "test" + to_string(9) + ".txt";
        ofstream fo(fileName);
        for (int j = 0; j < MAXN; j++)
            a[j] = generate();                    // generate an integer
        sort(a.begin(), a.end(), greater<int>()); // sort descending
        for (int j = 0; j < MAXN; j++)
            fo << a[j] << " ";
        fo.close();
    }
}
