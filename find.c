#include<stdio.h>
#include<malloc.h>


int main(){

  //  int i;
  long long i, j, n, k, a, b, c ,r;
  int N, K;

  scanf("%d", &N);
  K=N;

  while(N--){
    
    scanf("%lld %lld", &n, &k);
    scanf("%lld %lld %lld %lld", &a, &b, &c, &r);
    n = (n-1) % (k+1) + (k+1) + 1;

    long long *m = malloc(sizeof(long long) * n*2);
    int *tus = malloc(sizeof(int) * (k+1));
    
    for( i=0; i<=k; i++){
      tus[i]=0;
    }
    
    /* Get Elements */
    m[0] = a;
    if ( a <= k )
      tus[a] += 1;
    
    for ( i=1; i<k; i++ ){
      m[i] = (b*m[i-1] + c) % r;

      if( m[i] <= k ){
	tus[m[i]] += 1;
      }
    }
    
    /* Insert Minimum Element */
   //for ( j=k; j<n; j++ ){
  for ( j=k; j<2*(k+1); j++ ){
      
      for( i=0; i<=k; i++ ){
	if (tus[i] == 0){
	  tus[i] += 1;
	  m[j] = i;
	  break;
	}
      }
      
      if(m[j-k] <= k ){
	tus[m[j-k]] -= 1;
	if(tus[m[j-k]] < 0)
	  tus[m[j-k]] = 0;
      }
    }
    
    printf("Case #%d: %lld\n", K-N, m[n-1]);
    free(m);
    free(tus);
  }
  
  return 0;
}

