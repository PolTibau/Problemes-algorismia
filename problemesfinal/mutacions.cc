#include <iostream>
#include <map>
#include <vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;

VI cicle;
VVI G;

int CICLE(int x, int y, int i)
{
    if (y == x)
        return i;
    int k = CICLE(x, G[y][0], i + 1);
    cicle[y] = k;
    return k;
}

int main()
{
    int n;
    while (cin >> n) {
        int m = n;
        map<string, string> N; //mapa de el bact x va al y;
        while (m--) {
            string x, y, fletxa;
            cin >> x >> fletxa >> y;
            N[x] = y;
        }
        map<string, int> M; //mapa que diu el string correspon a aquell numero al graf
        int i = 0;
        VS b(n); // cevtor que diu el numero i al graf es el bacteri b[i];
        for (auto it = N.begin(); it != N.end(); ++it) {
            M[it->first] = i;
            b[i] = it->first;
            ++i;
        }

        G = VVI(n); //graf en numeros de tota la vida

        for (auto it = N.begin(); it != N.end(); ++it) {
            int x = M[it->first];
            int y = M[it->second];
            G[x].push_back(y);
        }

        //calculem la longitud del cicle que pertanyen al graf de numeros;
        cicle = VI(n, -1);
        for (int x = 0; x < n; ++x) {
            if (cicle[x] == -1) {
                int k = CICLE(x, G[x][0], 1);
                cicle[x] = k;
            }
        }
        //calcular el temps
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            int cops = t % cicle[i];
            int mut = i;
            while (cops--) {
                mut = G[mut][0];
            }
            cout << b[i] << " -> " << b[mut] << endl;
        }
        cout << "--------------------" << endl;
    }
}
