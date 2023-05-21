#include <bits/stdc++.h>
#include "AVLTree.h"
using namespace std;

int const MAXN = 1e6;
int arr[MAXN];

int main()
{
    freopen("AVLTree.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 10; ++i)
    {
        string fileName = "test" + to_string(i) + ".txt";
        ifstream fi(fileName);

        Node<int> *root = NULL;
        for (int i = 0; i < MAXN; i++)
        {
            int x;
            fi >> x;
            root = root->insert(x);
        }
        fi.close();
        cout << "The height of AVL Tree in test case " << i << " is: " << root->getHeight() << '\n';
    }

    return 0;
}
