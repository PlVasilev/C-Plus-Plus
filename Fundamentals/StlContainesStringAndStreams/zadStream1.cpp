#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void readMatrix(vector< vector<int> >& matrix)
{
    int rows;
    cin >> rows;
    cin.ignore();

    while (rows) {

        string row;
        getline(cin, row); // get the next row from the matrix

        istringstream strRow(row); // create a stream to read the line of the matrix
        vector<int> currentRow; // this is the current row of the matrix
        while (!strRow.eof()) {
            int element;
            strRow >> element;
            currentRow.push_back(element);
        }

        matrix.push_back(currentRow);
        rows--;
    }
}

bool compareMatrices(vector< vector<int> >& A, vector< vector<int> >& B)
{
    // check if dimensions match
    if (A.size() != B.size() || // if rows mismatch
        (A.size() != 0 && A[0].size() != B[0].size() ) ) // if we have at least one row, and columns mismatch
        return false;

    vector< vector<int> >::iterator itA = A.begin();
    vector< vector<int> >::iterator itB = B.begin();

    while (itA != A.end()) {

        vector<int>::iterator itRowA = itA->begin();
        vector<int>::iterator itRowB = itB->begin();

        while (itRowA != itA->end()) {
            if (*itRowA != *itRowB)
                return false;
            itRowA++;
            itRowB++;
        }

        itA++;
        itB++;
    }

    return true;
}


int main_zadStream1()
{
    vector< vector<int> > A;
    vector< vector<int> > B;

    readMatrix(A);
    readMatrix(B);

    if (compareMatrices(A, B))
        cout << "equal";
    else
        cout << "not equal";

    return 0;
}

