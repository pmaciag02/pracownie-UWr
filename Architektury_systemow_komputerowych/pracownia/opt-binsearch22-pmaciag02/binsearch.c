/*
 * Binary search with linearly placed tree levels.
 *
 * Intel® Core™ i5-6600 CPU @ 3.30GHz
 *
 * $ ./binsearch -S 0x5bab3de5da7882ff -n 23 -t 24 -v 0
 * Time elapsed: 7.616777 seconds.
 * $ ./binsearch -S 0x5bab3de5da7882ff -n 23 -t 24 -v 1
 * Time elapsed: 2.884369 seconds.
 */
#include "binsearch.h"

bool binsearch0(T *arr, long size, T x) {
  do {
    size >>= 1;
    T y = arr[size];
    if (y == x)
      return true;
    if (y < x)
      arr += size + 1;
  } while (size > 0);
  return false;
}

void linearize(T *dst, T *src, long size) {
  long n = 0, i=0, offset, s, e, m, k;
  
  while(size > (1<<n)){
  	k = 0;
  	offset = (size - 1) >> n;
  
  	for(int j=0; j<(1<<n); j++){
  		s = (j * offset) + k;
  		e = ((j + 1) * offset) + k;
  		m = (s + e) >> 1;
  		k++;
  		dst[i] = src[m];
  		i++;
  	}
  	n++;
  }	
}

bool binsearch1(T *arr, long size, T x) {
  long i = 1, j;
  int y;
  do{
  	y = arr[i - 1];
  	j = i * 2;
  	j|=(x > y);
  	i = j;
  	if(x == y) return true;
  }while(size >= i);
  return false;
}
