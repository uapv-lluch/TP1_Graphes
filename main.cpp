#include <iostream>
#include <stack>

const int n = 6;

using namespace std;

void chaineaugmentante(int (&ch)[n], int c[n][n], int (&f)[n][n], int s, int t) {
    bool visites[n];
    stack<int> P;
    bool stop = false;
    for (unsigned i = 0 ; i < n ; ++i) {
        visites[i] = false;
        ch[i] = -1;
    }
    P.push(s);
    while (!P.empty() && !stop) {
        int i = P.top();
        P.pop();
        if (i == t) {
            stop = true;
        } else if (!visites[i]) {
            visites[i] = true;
            for (unsigned j = 0 ; j < n ; ++j) {
                if (!visites[j]) {
                    if ((c[i][j] > 0 && c[i][j] > f[i][j]) || (c[j][i] > 0 && f[i][j] > 0)) {
                        P.push(j);
                        ch[j] = i;
                    }
                }
            }
        }
    }
}


int increment(const int (&ch)[n], int c[n][n], int (&f)[n][n], int s, int t) {
    int x = 0;
    int i = n-1;
    while (i > 0) {
        if (ch[i] != -1) {
            if (c[ch[i]][i] == 0) { // Sens inverse
                if (c[i][ch[i]] - f[i][ch[i]] < x || x == 0) {
                    x = c[i][ch[i]] - f[i][ch[i]];
                }
            }
            else {
                if (c[ch[i]][i] - f[ch[i]][i] < x || x == 0) {
                    x = c[ch[i]][i] - f[ch[i]][i];
                }
            }
            i = ch[i];
        }
    }
    return x;
}

void augmentation(const int (&ch)[n], int c[n][n], int (&f)[n][n], int s, int t, int x) {
    int i = n-1;
    while (i > 0 && ch[i] != -1) {
        if (c[ch[i]][i] == 0) { // Sens inverse
            f[i][ch[i]] -= x;
        } else {
            f[ch[i]][i] += x;
        }
        i = ch[i];
    }
}

int flotmax(int c[n][n], int (&f)[n][n], int s, int t) {
    int ch[n];
    int flotmax = 0;
    bool stop = false;
    while (!stop) {
        chaineaugmentante(ch, c, f, s, t);
        if (ch[t] == -1) {
            stop = true;
        } else {
            int x = increment(ch, c, f, s, t);
            augmentation(ch, c, f, s, t, x);
            flotmax += x;
        }
    }
    return flotmax;
}

int main() {
    // initialisation de la matrice des capacités à 0
    int c[n][n];
    for (unsigned i = 0 ; i < n ; ++i) {
        for (unsigned j = 0 ; j < n ; ++j) {
            c[i][j] = 0;
        }
    }
    // Initialisation des capacités non nulles 
    c[0][1] = 6;
    c[0][2] = 6;
    c[1][3] = 5;
    c[2][3] = 4;
    c[2][4] = 3;
    c[3][5] = 7;
    c[4][5] = 4;

    int f[n][n];
    for (unsigned i = 0 ; i < n ; ++i) {
        for (unsigned j = 0 ; j < n ; ++j) {
            f[i][j] = 0;
        }
    }
    int s = 0;
    int t = 5;
    cout << "Flot max = " << flotmax(c, f, s, t) << endl;
    return 0;
}