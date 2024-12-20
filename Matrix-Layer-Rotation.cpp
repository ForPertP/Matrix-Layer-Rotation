#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> result(m, vector<int>(n));

    for (int layer = 0; layer < min(m, n) / 2; ++layer) {
        vector<int> elements;

        int top = layer;
        int left = layer;
        int bottom = m - layer - 1;
        int right = n - layer - 1;

        for (int i = left; i <= right; ++i) {
            elements.push_back(matrix[top][i]);
        }

        for (int i = top + 1; i <= bottom; ++i) {
            elements.push_back(matrix[i][right]);
        }

        for (int i = right - 1; i >= left; --i) {
            elements.push_back(matrix[bottom][i]);
        }

        for (int i = bottom - 1; i > top; --i) {
            elements.push_back(matrix[i][left]);
        }

        int rotation = r % elements.size();

        vector<int> rotated_elements(elements.size());
        for (int i = 0; i < elements.size(); ++i) {
            rotated_elements[i] = elements[(i + rotation) % elements.size()];
        }

        int idx = 0;

        for (int i = left; i <= right; ++i) {
            result[top][i] = rotated_elements[idx++];
        }

        for (int i = top + 1; i <= bottom; ++i) {
            result[i][right] = rotated_elements[idx++];
        }

        for (int i = right - 1; i >= left; --i) {
            result[bottom][i] = rotated_elements[idx++];
        }

        for (int i = bottom - 1; i > top; --i) {
            result[i][left] = rotated_elements[idx++];
        }
    }

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}


int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

std::string rtrim(const std::string &str)
{
    std::string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    std::istringstream iss(str);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}
