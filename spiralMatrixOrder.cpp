#include <iostream>
using namespace std;

const int N = 6;
int square[N][N] = {
    {1, 2, 3, 4, 5, 6},
    {7, 8, 9, 10, 11, 12},
    {13, 14, 15, 16, 17, 18},
    {19, 20, 21, 22, 23, 24},
    {25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36},
};
enum dir
{
  RIGHT = 0,
  DOWN,
  LEFT,
  UP
};
int dir_r[] = {0, 1, 0, -1};
int dir_c[] = {1, 0, -1, 0};

void spiralOrder(int square[N][N], int N);

void spiralOrder(int square[N][N], int N)
{
  int r = 0, c = 0, steps = N, dir = 0, count;

  while (count < N * N)
  {
    for (int i = 0; i < 4 && count < N * N; i++)
    {
      int j = steps - 1;
      if (i == 3)
        j--;

      for (int k = 0; k < j && count < N * N; k++)
      {
        cout << square[r][c] << " ";
        count++, r += dir_r[dir], c += dir_c[dir];
      }

      dir = (dir + 1) % 4;
    }
    cout << square[r][c] << " ";
    count++, r += dir_r[dir], c += dir_c[dir];
    steps -= 2;
  }
  cout << "\n";
}

int main()
{

  spiralOrder(square, N);

  return 0;
}