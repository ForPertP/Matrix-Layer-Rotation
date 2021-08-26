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

// https://www.hackerrank.com/challenges/matrix-rotation-algo/forum : From rustedwizard

void matrixRotation(vector<vector<int>> matrix, int r)
{
    int mStart = 0;
    int nStart = 0;
    int m = matrix.size() - 1;
    int n = matrix[0].size() - 1;
    
    while (mStart < m && nStart < n)
    {
        int t = r;
        
        if (t > (((m-mStart) + (n-nStart)) * 2))
        {
            t = t % (((m - mStart) + (n - nStart)) * 2);
        }
        
        while (t > 0)
        {
            int prev = matrix[mStart][nStart];

            // Shift top row
            for (int i = nStart; i <= n - 1; ++i)
            {
                matrix[mStart][i] = matrix[mStart][i + 1];
            }
            
            // Shift right most column
            for (int i = mStart; i <= m - 1; ++i)
            {
                matrix[i][n] = matrix[i + 1][n];
            }
            
            // Shift bottom row
            for (int i = n; i >= nStart + 1; --i)
            {
                matrix[m][i] = matrix[m][i - 1];
            }
            
            // Shift left most column
            for (int i = m; i > mStart + 1; --i)
            {
                matrix[i][nStart] = matrix[i - 1][nStart];
            }
            
            matrix[mStart + 1][nStart] = prev;
            t--;
        }
        
        mStart++;
        nStart++;
        m--;
        n--;
    }
    
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (const auto& e : matrix[i])
        {
            std::cout << e << " ";
        }
        
        std::cout << '\n';
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

    for (int i = 0; i < m; i++)
    {
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
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
