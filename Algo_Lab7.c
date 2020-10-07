/*
M VENU GOPAL
17CS8064
ALGORITHM LAB ASSIGNMENT 7
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
   int rowidx;
   int colidx;
} pair;

typedef struct {
   int m, n;
   int **H;
   int **V;
   pair **P;
} maze;

typedef int **path;

maze initmaze ( int m, int n )
{
   maze M;
   int i, j;

   M.m = m; M.n = n;

   M.H = (int **)malloc((m-1)*sizeof(int *));
   for (i=0; i<m-1; ++i) {
      M.H[i] = (int *)malloc(n * sizeof(int));
      for (j=0; j<n; ++j) M.H[i][j] = 1;
   }

   M.V = (int **)malloc(m * sizeof(int *));
   for (i=0; i<m; ++i) {
      M.V[i] = (int *)malloc((n-1) * sizeof(int));
      for (j=0; j<n-1; ++j) M.V[i][j] = 1;
   }

   M.P = (pair **)malloc(m * sizeof(pair *));
   for (i=0; i<m; ++i) {
      M.P[i] = (pair *)malloc(n * sizeof(pair));
      for (j=0; j<n; ++j) M.P[i][j] = (pair){-1.-1};
   }

   return M;
}

char prncell ( int t )
{
   if (t == 1) return 'x';
   if (t == 2) return 'S';
   if (t == 3) return 'T';
   return ' ';
}

void prnmaze ( maze M, int **path )
{
   int i, j;

   printf("    +"); for (j=0; j<M.n; ++j) printf("---+"); printf("\n");
   for (i=0; i<M.m; ++i) {
      printf("    |");
      if (path == NULL) {
         for (j=0; j<M.n-1; ++j) printf("   %c", M.V[i][j] ? '|' : ' ');
         printf("   |\n");
      } else {
         for (j=0; j<M.n-1; ++j)
            printf(" %c %c", prncell(path[i][j]), M.V[i][j] ? '|' : ' ');
         printf(" %c |\n", prncell(path[i][M.n-1]));
      }
      if (i != M.m - 1) {
         printf("    +");
         for (j=0; j<M.n; ++j) printf("%s+", M.H[i][j] ? "---" : "   ");
         printf("\n");
      }
   }
   printf("    +"); for (j=0; j<M.n; ++j) printf("---+"); printf("\n");
}

void DFS( maze M, int i, int j, int **visited )
{
   int d, k, m, n, u, v;

   visited[i][j] = 1;

   m = M.m; n = M.n;
   d = rand() % 4;
   for (k=0; k<4; ++k) {
      switch (d) {
         case 0: u = i; v = j-1; break;
         case 1: u = i-1; v = j; break;
         case 2: u = i; v = j+1; break;
         case 3: u = i+1; v = j; break;
      }
      if ((u >= 0) && (u < m) && (v >= 0) && (v < n) && (visited[u][v] == 0)) {
         M.P[u][v] = (pair){i,j};
         switch (d) {
            case 0: M.V[u][v] = 0; break;
            case 1: M.H[u][v] = 0; break;
            case 2: M.V[i][j] = 0; break;
            case 3: M.H[i][j] = 0; break;
         }
         DFS(M, u, v, visited);
      }
      ++d; d %= 4;
   }
}

void genmaze ( maze M )
{
   int m, n, i, j;
   int **visited;

   m = M.m; n = M.n;
   visited = (int **)malloc(m * sizeof(int *));
   for (i=0; i<m; ++i) {
      visited[i] = (int *)malloc(n * sizeof(int));
      for (j=0; j<n; ++j) visited[i][j] = 0;
   }

   i = rand() % m; j = rand() % n;
   DFS(M,i,j,visited);
   for (i=0; i<m; ++i) free(visited[i]);
   free(visited);
}

path genpath ( maze M, int u, int v, int x, int y )
{
   int m, n, i, j;
   path p;
   pair t;

   m = M.m; n = M.n;
   p = (int **)malloc(m * sizeof(int *));
   for (i=0; i<m; ++i) {
      p[i] = (int *)malloc(n * sizeof(int));
      for (j=0; j<n; ++j) p[i][j] = 0;
   }

   t = (pair){u,v};
   while (t.rowidx >= 0) {
      p[t.rowidx][t.colidx] = 1;
      t = M.P[t.rowidx][t.colidx];
   }

   t = (pair){x,y};
   while (p[t.rowidx][t.colidx] == 0) {
      p[t.rowidx][t.colidx] = 1;
      t = M.P[t.rowidx][t.colidx];
   }

   t = M.P[t.rowidx][t.colidx];
   while (t.rowidx >= 0) {
      p[t.rowidx][t.colidx] = 0;
      t = M.P[t.rowidx][t.colidx];
   }

   return p;
}

int main ( int argc, char *argv[] )
{
   int m, n, u, v, x, y;
   maze M;
   path p;

   srand((unsigned int)time(NULL));

   if (argc >= 3) { m = atoi(argv[1]); n = atoi(argv[2]); }
   else { scanf("%d%d", &m, &n); }
   printf("m = %d\nn = %d\n", m, n);

   M = initmaze(m,n);
   printf("\n+++ Initial maze\n"); prnmaze(M,NULL);

   genmaze(M);
   printf("\n+++ Random maze generated\n"); prnmaze(M,NULL);

   do {
      u = rand() % m; v = rand() % n;
      x = rand() % m; y = rand() % n;
   } while ((u == x) && (v == y));
   p = genpath(M, u, v, x, y);
   p[u][v] = 2; p[x][y] = 3;
   printf("\n+++ Path from S = (%d,%d) to T = (%d,%d)\n", u, v, x, y);
   prnmaze(M,p);

   for (u=0; u<m; ++u) {
      if (u != m-1) free(M.H[u]);
      free(M.V[u]);
      free(M.P[u]);
      free(p[u]);
   }
   free(M.H); free(M.V); free(M.P); free(p);

   exit(0);
}