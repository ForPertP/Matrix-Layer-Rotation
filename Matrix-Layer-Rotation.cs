using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'matrixRotation' function below.
     *
     * The function accepts following parameters:
     *  1. 2D_INTEGER_ARRAY matrix
     *  2. INTEGER r
     */

    public static void matrixRotation(List<List<int>> matrix, int r)
    {
        int m = matrix.Count;
        int n = matrix[0].Count;

        List<List<int>> result = new List<List<int>>(m);
        for (int i = 0; i < m; i++)
        {
            result.Add(new List<int>(new int[n]));
        }

        for (int layer = 0; layer < Math.Min(m, n) / 2; ++layer)
        {
            List<int> elements = new List<int>();

            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;

        foreach (var row in result)
        {
            foreach (var val in row)
            {
                Console.Write(val + " ");
            }
            Console.WriteLine();
        }
    }

}


class Solution
{
    public static void Main(string[] args)
    {
        string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');

        int m = Convert.ToInt32(firstMultipleInput[0]);

        int n = Convert.ToInt32(firstMultipleInput[1]);

        int r = Convert.ToInt32(firstMultipleInput[2]);

        List<List<int>> matrix = new List<List<int>>();

        for (int i = 0; i < m; i++)
        {
            matrix.Add(Console.ReadLine().TrimEnd().Split(' ').ToList().Select(matrixTemp => Convert.ToInt32(matrixTemp)).ToList());
        }

        Result.matrixRotation(matrix, r);
    }
}
