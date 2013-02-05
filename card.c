#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h>
#include <assert.h>

/* qsort int comparison function */ 
int llong_cmp(const void *a, const void *b) 
{ 
  const long long *ia = (const long long *)a;
  const long long *ib = (const long long *)b;
  return *ia  - *ib; 
} 


int main(){

  int T, n, k;
  long long a[10000];
  int i, j;
  long long ** table; 
  long long sum;
  int N; 

  table = malloc(sizeof(long long*)*10001);  
  for( i=0; i<=10000; i++){
    table[i] = malloc(sizeof(long long)*10001);	
  }

  for( i=0; i<=10000; i++ ){
    for( j=0; j<=10000; j++ ){
      table[i][j] = 0;
    }
    table[0][i] = 0;
    table[i][0] = 1;
    table[i][i] = 1;
  }

  for ( i=1; i<=10000; i++){
    for ( j=1; j<=10000; j++){
      table[i][j] = (table[i-1][j-1] + table[i-1][j])%1000000007;	
    }
  }	
  scanf("%d", &T);
  N = T;
 
 // printf("table initialized\n");

  while(T--){
    sum = 0;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++){
      scanf("%lld", &a[i]);
    }
    qsort(a, n, sizeof(long long), llong_cmp);

    
    for (i=k; i<=n; i++){
      sum += (a[i-1]%1000000007)*(table[i-1][k-1] % 1000000007) % 1000000007;
      assert(sum > 0);
      sum = sum % 1000000007;
//            printf("n,: %d,k: %d, a[i]: %lld, C_a_b: %lld\n", n, k, a[i-1], table[i-1][k-1]);
    }
    
    printf("Case #%d: %lld\n", N-T, sum);

  }

  return 0;
}
