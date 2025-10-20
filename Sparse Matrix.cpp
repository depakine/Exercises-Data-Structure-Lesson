#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

class SparseMatrix {
private:
    int rows, cols;
    vector<Element> elements;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void addElement(int r, int c, int val) {
        if (val != 0)
            elements.push_back({r, c, val});
    }

    SparseMatrix add(const SparseMatrix& other) {
        SparseMatrix result(rows, cols);
        int i = 0, j = 0;

        while (i < elements.size() && j < other.elements.size()) {
            if (elements[i].row == other.elements[j].row &&
                elements[i].col == other.elements[j].col) {
                int sum = elements[i].value + other.elements[j].value;
                if (sum != 0)
                    result.addElement(elements[i].row, elements[i].col, sum);
                i++; j++;
            } else if (elements[i].row < other.elements[j].row ||
                      (elements[i].row == other.elements[j].row &&
                       elements[i].col < other.elements[j].col)) {
                result.addElement(elements[i].row, elements[i].col, elements[i].value);
                i++;
            } else {
                result.addElement(other.elements[j].row, other.elements[j].col, other.elements[j].value);
                j++;
            }
        }

        while (i < elements.size()) {
            result.addElement(elements[i].row, elements[i].col, elements[i].value);
            i++;
        }

        while (j < other.elements.size()) {
            result.addElement(other.elements[j].row, other.elements[j].col, other.elements[j].value);
            j++;
        }

        return result;
    }

    void print() const {
        for (const auto& e : elements) {
            cout << "(" << e.row << ", " << e.col << ") = " << e.value << endl;
        }
    }
};

int main() {
    SparseMatrix A(4, 4);
    A.addElement(0, 1, 5);
    A.addElement(1, 2, 8);
    A.addElement(3, 0, 6);

    SparseMatrix B(4, 4);
    B.addElement(0, 1, 3);
    B.addElement(1, 2, -8);
    B.addElement(2, 3, 7);

    SparseMatrix C = A.add(B);

    cout << "Matrix A + B:" << endl;
    C.print();

    return 0;
}
