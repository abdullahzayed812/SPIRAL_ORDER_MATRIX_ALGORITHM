#include <iostream>
using namespace std;

const int N = 3;

int sumRow(int i, int square[N][N])
{
  int sum = 0;
  for (int j = 0; j < N; j++)
  {
    sum += square[i][j];
    // cout << square[i][j] << " ";
  }
  // cout << "\n";
  return sum;
}

int sumColumn(int j, int square[N][N])
{
  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    sum += square[i][j];
    // cout << square[i][j] << " ";
  }
  // cout << "\n";
  return sum;
}

int sumMainDiagonal(int square[N][N])
{
  int sum = 0, pos = 0;
  for (int i = 0; i < N; i++)
  {
    sum += square[pos][pos];
    pos++;
  }
  return sum;
}

int sumAntiDiagonal(int square[N][N])
{
  int sum = 0, pos = 0;
  for (int i = 0; i < N; i++)
  {
    sum += square[i][N - pos - 1];
    pos++;
  }
  return sum;
}

bool validate(int square[N][N])
{
  int result = sumRow(0, square);

  for (int i = 0; i < N; i++)
  {
    if (result != sumRow(i, square))
      return false;
    if (result != sumColumn(i, square))
      return false;
  }

  if (result != sumMainDiagonal(square))
    return false;
  if (result != sumAntiDiagonal(square))
    return false;

  return true;
}

int main()
{
  int square[N][N] = {
      {8, 1, 6},
      {3, 5, 7},
      {4, 9, 2}};

  if (validate(square))
    cout << "Valid.";
  else
    cout << "Not valid.";

  square[0][0] += 10;
  cout << "\nAfter editing be: ";

  if (validate(square))
    cout
        << "Valid.";
  else
    cout << "Not valid.";

  return 0;
}