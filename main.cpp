#include <iostream>
#include "src/Solver.h"

using namespace std;

int main() {
    string alpha;
    char X;
    size_t K;
    cin >> alpha >> X >> K;
    Solver automat(alpha);
    try {
        size_t answer = automat.Solve(X, K);
        if (answer == NOT_FOUND) {
            cout << "NOT_FOUND\n";
        } else {
            cout << answer << '\n';
		}
    } catch (exception& error) {
        cout << error.what();
    }
    return 0;
}
