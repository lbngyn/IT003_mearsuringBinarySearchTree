#include <bits/stdc++.h>
#include "RedBlackTree.h"
using namespace std;

const int dataset = 10;
const int MAXN = 1e6;

int main()
{
    freopen("RedBlackTree.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; ++i)
    {
        string fileName = "test" + to_string(i) + ".txt";
        ifstream fi(fileName);

        RBTree<int> rbt;
        for (int j = 0; j < 1e6; j++)
        {
            int x;
            fi >> x;
            rbt.insertValue(x);
        }
        fi.close();
        cout << "The height of RedBlack Tree in test case " << i << " is: " << rbt.maxDepth() << '\n';
    }
    return 0;
}