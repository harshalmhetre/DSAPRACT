#include <iostream>
#include <cstdlib> // for exit(0)
using namespace std;

void obst();
void print(int , int );

float a[10], b[11], wt[10][10], c[10][10];
int r[10][10], n;

void obst() {
    for (int i = 0; i < n; i++) {
        wt[i][i] = b[i];
        c[i][i] = 0.0;
        r[i][i] = i;
        wt[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
        c[i][i + 1] = b[i] + b[i + 1] + a[i + 1];
        r[i][i + 1] = i + 1;
    }
    wt[n][n] = b[n];
    c[n][n] = 0.0;
    r[n][n] = 0;

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l;
            wt[i][j] = wt[i][j - 1] + a[j] + b[j];
            c[i][j] = 9999; // Initialize to a large value
            for (int k = i + 1; k <= j; k++) {
                float temp = c[i][k - 1] + c[k][j];
                if (temp < c[i][j]) {
                    c[i][j] = temp;
                    r[i][j] = k;
                }
            }
            c[i][j] += wt[i][j];
        }
    }

    cout << "Optimal BST:\n";
    cout << "Weight of tree: " << wt[0][n] << endl;
    cout << "Cost of tree: " << c[0][n] << endl;
    cout << "Root node of tree: " << r[0][n] << endl;
}

void print(int l, int r) {
    if (l >= r)
        return;
    cout << "Root: " << ::r[l][r] << endl;
    if (l < r - 1) {
        cout << "Left Child of " << ::r[l][r] << ": ";
        print(l, ::r[l][r] - 1);
    }
    if (r > l + 1) {
        cout << "Right Child of " << ::r[l][r] << ": ";
        print(::r[l][r], r);
    }
}


int main () {
    cout << "Enter the no. of nodes: ";
    cin >> n;
    cout << "Enter the probability of successful search: ";
    for (int i = 1; i <= n; i++) {
        cout << "p[" << i << "]: ";
        cin >> a[i];
    }
    cout << "Enter the probability of unsuccessful search: ";
    for (int i = 0; i <= n; i++) {
        cout << "q[" << i << "]: ";
        cin >> b[i];
    }
    obst();
    cout << "Structure of Optimal BST:\n";
    print(0, n);
    return 0;
}
