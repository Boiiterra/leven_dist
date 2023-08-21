#include <limits.h>
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
  int r = INT_MAX;
  r = (a < r) ? a : r;
  r = (b < r) ? b : r;
  r = (c < r) ? c : r;
  return r;
}

int lev(char *a, char *b) {
  if (a == b)
    return 0;

  int n = strlen(a);
  int m = strlen(b);

  if (n == 0 || m == 0)
    return -1;

  int table[n + 1][m + 1];

  for (int i = 0; i <= m; i++) {
    table[0][i] = i;
  }
  for (int j = 0; j <= n; j++) {
    table[j][0] = j;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        table[i][j] = table[i - 1][j - 1];
      } else {
        table[i][j] =
            min(table[i][j - 1], table[i - 1][j], table[i - 1][j - 1]) + 1;
      }
    }
  }

#ifdef LEV_SHOW
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
#endif

  return table[n][m];
}

int main() {
  printf("RESULT -> %d\n", lev("kitten", "sitting"));
  return 0;
}
