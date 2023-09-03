#include <iostream>
using namespace std;

const int N = 3;
int square[N][N] = {
    {8, 1, 6},
    {3, 5, 7},
    {4, 9, 2}};

enum dir
{
  UP = 0,
  RIGHT,
  DOWN,
  LEFT,
  UP_RIGHT,
  UP_LEFT,
  DOWN_RIGHT,
  DOWN_LEFT
};
int dir_r[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dir_c[] = {0, 1, 0, -1, 1, -1, 1, -1};

int sumWithDir(int r, int c, int dir, int steps, int square[N][N]);
bool validate(int square[N][N]);

int sumWithDir(int r, int c, int dir, int steps, int square[N][N])
{
  int sum = 0;
  for (int i = 0; i < steps; i++)
  {
    sum += square[r][c];
    // cout << square[r][c] << " ";
    r += dir_r[dir];
    c += dir_c[dir];
  }
  // cout << endl;
  return sum;
}

bool validate(int square[N][N])
{
  int result = sumWithDir(0, 0, RIGHT, N, square);

  for (int i = 0; i < N; i++)
  {
    if (result != sumWithDir(i, 0, RIGHT, N, square))
      return false;
    if (result != sumWithDir(0, i, DOWN, N, square))
      return false;
  }

  if (result != sumWithDir(0, 0, DOWN_RIGHT, N, square))
    return false;
  if (result != sumWithDir(0, N - 1, DOWN_LEFT, N, square))
    return false;

  return true;
}

int main()
{
  if (validate(square))
    cout << "Valid.";
  else
    cout << "Not Valid.";

  return 0;
}