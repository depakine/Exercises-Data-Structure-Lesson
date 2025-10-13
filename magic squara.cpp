#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "andaze <magice squara> ke mikhahid ra vared konid (fagat add fard ) ";
    cin >> n;
    if (n % 2 == 0 || n < 1 || n > 25) {
        cout << "fagat add fard mogaz ast" << endl;
        return 0;
    }

    int magic[25][25] = {0}; // حداکثر اندازه 25
    int row = 0;
    int col = n / 2;
    int num = 1;

    while (num <= n * n) {
        magic[row][col] = num;

        int nextRow = (row - 1 + n) % n;
        int nextCol = (col + 1) % n;

        if (magic[nextRow][nextCol] != 0) {
            row = (row + 1) % n; // اگر خونه پر بود، خونه ی پایینی پر میشه
        } else {
            row = nextRow;
            col = nextCol;
        }

        num++;
    }

    // چاپ مربع جادویی
    cout << " magic squara \n" << n << "×" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magic[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
