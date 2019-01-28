#include <iostream>
#include <stack>

const int n = 6;

using namespace std;

void chaineaugmentante(int ch[n], int c[n][n], int f[n][n], int s, int t) {
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

int flotmax(int c[n][n], int f[n][n], int s, int t) {
    int ch[n];
    int flotmax = 0;
    bool stop = false;
    while (!stop) {
        chaineaugmentante(ch, c, f, s, t);
        if (ch[t] == -1) {
            stop = true;
        } else {
//            int x = increment(ch, c, f, s, t);
//            augmentation(ch, f, s, t, x);
//            flotmax += x
        }
    }
    return flotmax;
}

// Ne marche pas encore, il faut aussi gérer le cas des sens inverse
void augmenterIncrement(ch, c, f, s ,t, x) {
    for (int i = 0; i < n ; ++i) {
        if(ch[i == -1]){
            f[i][0] +=x
        } else {
            f[i][ch[i]] +=x;
        }
    }
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
    flotmax(c, f, s, t);
    return 0;
}