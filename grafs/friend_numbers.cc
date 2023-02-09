#include <iostream>
#include <vector>

using namespace std;
using VE = vector<int>;

int n;
VE factors;
VE repre;

int repre_f (int i) {
    if (repre[i] < 1) return i;
    int r = repre_f(repre[i]);
    repre[i] = r;
    
    return r;
}

int main() {
    factors = VE(100001, -1);
    factors[1] = 1;
    for (int i  = 2; i <= 100000; ++i) {
        if (factors[i] == -1) {
            for (int j = i; j <= 100000; j += i) {
                if (factors[j] == -1) factors[j] = i;
            }
        }
    }

    while (cin >> n) {
        int max_cc = 0;
        int max_n = 0;
        
        VE numbers = VE(n);
        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
            if (numbers[i] > max_n) max_n= numbers[i];
        }

        repre = VE(max_n+1, -1);

        for (int i = 2; i <= max_n; ++i) {
            if (factors[i] == i) repre[i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            int x = numbers[i];
            int m = x;
            while (m > 1) {
                int factor = factors[m];
                m /= factor;
                int rx = repre_f(x); 
                int rf = repre_f(factor);
                if (rx != rf) {
                    repre[rf] += repre[rx];
                    repre[rx] = rf;
                    
                }
            }

            int rx = repre_f(x);
            if (factors[x] == x) repre[rx] -= 1; 
            
            if (-repre[rx] > max_cc) {
                max_cc = -repre[rx];
            }
            
        }
        cout << max_cc << endl;
    }

}
