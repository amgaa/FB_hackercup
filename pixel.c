#include<stdio.h>
#include<malloc.h>



int main(){

  int T, M, N_real;
  int W, H, P, Q, N, X, Y, a, b, c, d;
  int all, delta;
  int i, j, k;

  scanf("%d", &T);
  M=T;
  
  while(T--){

    scanf("%d %d %d %d %d %d %d %d %d %d %d", &W, &H, &P, &Q, &N, &X, &Y, &a, &b, &c, &d);

    /* Generate dead pixcels */
    int *x = malloc(sizeof(int)*N);
    int *y = malloc(sizeof(int)*N);
    x[0] = X;
    y[0] = Y;

    for( i=1; i<N; i++){
      x[i] = ( x[i-1]*a + y[i-1]*b + 1 ) % W;
      y[i] = ( x[i-1]*c + y[i-1]*d + 1 ) % H;
    }


    all = (W-P+1) * (H-Q+1); //max possible variation
    
    
    /* Calculate pictures containing dead pixel(s) */
    delta = 0;
    for( i=0; i<=W-P; i++ ){ //for k-th dead pixel
      for( j=0; j<=H-Q; j++ ){
	for( k=0; k<N; k++ ){
	  // if a dot is inside this position
	  if( x[k] >= i && x[k] < i+P && y[k] >=j && y[k] < j+Q){
	    delta += 1;
	    break;
	  }
	}
      }
    } 
    
    all -= delta;
    
    printf("Case #%d: %d\n", M-T, all);
    free(x);
    free(y);
  }
  return 0;
}
