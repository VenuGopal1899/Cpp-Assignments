/*
M VENU GOPAL
17CS8064
ALGORITHM LAB ASSIGNMENT 8
*/

#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>
#include <time.h>

#define MAX_START_TIME 20
#define MAX_DURATION 10
#define VERBOSE 1

/* Data type interval */
typedef struct {
   int starttime;
   int finishtime;
} interval;

typedef struct _node {
   interval I;         
   int count;         
   int max;            
   struct _node *L;    
   struct _node *R;    
} node;

typedef node *evtree;


int intervalcmp ( interval I, interval J )
{
   if (I.starttime < J.starttime) return -1;
   if (I.starttime > J.starttime) return 1;
   if (I.finishtime < J.finishtime) return -1;
   if (I.finishtime > J.finishtime) return 1;
   return 0;
}


evtree insert ( evtree T, interval I )
{
   node *p, *q;
   int cmpres;

   printf("(%d,%d) ", I.starttime, I.finishtime);


   p = T; q = NULL;
   while (p) {
      cmpres = intervalcmp(I, p->I);
      if (cmpres == 0) {  
         ++(p -> count);  
         return T;        
      }
    
      if (I.finishtime > p -> max) p -> max = I.finishtime;
      q = p;
      if (cmpres < 0) p = p -> L; else p = p -> R;
   }

   p = (node *)malloc(sizeof(node));
   p -> I = I;
   p -> count = 1;
   p -> max = I.finishtime;
   p -> L = p -> R = NULL;

   if (T == NULL) return p;

   if (cmpres < 0) q -> L = p; else q -> R = p;
   return T;
}

int preorder ( evtree T, int nprinted )
{
   if (T == NULL) return nprinted;
   printf("[(%2d,%-2d),%d,%2d] ", (T -> I).starttime, (T -> I).finishtime, T -> count, T -> max);
   ++nprinted; if (nprinted == 5) { printf("\n               "); nprinted = 0; }
   nprinted = preorder(T -> L, nprinted);
   nprinted = preorder(T -> R, nprinted);
   return nprinted;
}

int inorder ( evtree T, int nprinted )
{
   if (T == NULL) return nprinted;
   nprinted = inorder(T -> L, nprinted);
   printf("[(%2d,%-2d),%d,%2d] ", (T -> I).starttime, (T -> I).finishtime, T -> count, T -> max);
   ++nprinted; if (nprinted == 5) { printf("\n               "); nprinted = 0; }
   nprinted = inorder(T -> R, nprinted);
   return nprinted;
}


int overlap ( interval I, interval J )
{
   return ((I.starttime < J.finishtime) && (J.starttime < I.finishtime));
}


int overlapcnt ( evtree T, interval I, int verbose, int *nprinted )
{
   int cnt = 0;

   if (T == NULL) return 0;


   if (overlap(T -> I, I)) {
      if (verbose) {
         printf("[(%2d,%-2d),%d] ", (T->I).starttime, (T->I).finishtime, T->count);
         ++(*nprinted);
         if (*nprinted == 5) {
            printf("\n                      ");
            *nprinted = 0;
         }
      }
      cnt = T -> count;
   }


   if ((T -> L) && (I.starttime < T -> L -> max))
      cnt += overlapcnt(T -> L, I, verbose, nprinted);

   if ((T -> R) && (I.starttime < T -> R -> max) && (I.finishtime > (T->I).starttime))
      cnt += overlapcnt(T -> R, I, verbose, nprinted);

   return cnt;
}


void minclasscnt ( evtree T, evtree p, interval *I, int *gmax )
{
   int max;
   interval J;

   if (p == NULL) return;

   J.starttime = (p -> I).starttime; J.finishtime = J.starttime + 1;
   max = overlapcnt(T, J, !VERBOSE, NULL);

   if (max > *gmax) {
      *gmax = max;
      *I = J;
   }

   minclasscnt(T, p->L, I, gmax);
   minclasscnt(T, p->R, I, gmax);
}

int main()
{

    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int i, n, s, f, q, c;
   evtree T = NULL;
   interval I;

   //((unsigned int)time(NULL));

    {
      printf("n = "); scanf("%d", &n);
      printf("q = "); scanf("%d", &q);
   }

   printf("\n+++ Insert   : ");
   for (i=0; i<n; ++i) {
      cin>>s>>f;
      T = insert(T,(interval){s,f});
   }

   printf("\n\n");
   printf("+++ Preorder : "); preorder(T,0); printf("\n");
   printf("+++ Inorder  : "); inorder(T,0); printf("\n\n");

   for (i=0; i<q; ++i) {
      s = rand() % MAX_START_TIME;
      f = s + 1 + rand() % MAX_DURATION;
      printf("+++ Overlap (%2d,%-2d) : ", s, f); n = 0;
      c = overlapcnt(T, (interval){s,f}, VERBOSE, &n);
      if (n) printf("\n                      ");
      printf("Overlap count = %d\n", c);
   }

   c = -1; minclasscnt(T,T,&I,&c);
   printf("\n+++ Minimum class count is %d\n", c);
   printf("+++ A busiest hour is (%d,%d)\n", I.starttime, I.finishtime);
   printf("+++ Overlap (%2d,%-2d) : ", I.starttime, I.finishtime); n = 0;
   c = overlapcnt(T, I, VERBOSE, &n);
   if (n) printf("\n                      ");
   printf("Overlap count = %d\n", c);

   exit(0);
}
