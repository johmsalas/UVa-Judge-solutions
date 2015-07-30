//============================================================================
// Name        : 3n+1.cpp
// Author      : Johny Salas
// Version     :
// Copyright   : No copy
// Description : 3n+1 in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <algorithm>
using namespace std;

int cyclelength(unsigned int n) {

	unsigned int length = 0;

	while(n > 1) {
		if( n%2 == 1) {
			// Instead of n = 3 * n + 1, let's do this step
			// and the next one (n/2), given that after every
			// 3n+1 there is always an n/2
			n = 1.5 * n + 0.5;
			length = length + 2;
		} else {
			n = n / 2;
			length++;
		}
	}

	return (length+1);

}

unsigned int maxcycleLengthBetween(unsigned int i, unsigned int j) {

	if(i > j) swap(i, j);

	unsigned int max = 1;
	for(unsigned int n = i; n <= j; n++) {
		unsigned int cl = cyclelength(n);
		if( cl > max ) {
			max = cl;
		}
	}
	return max;
}

int main() {

	int i, j;

	while ( scanf ("%d %d", &i, &j) != EOF ) {
		unsigned int max = maxcycleLengthBetween( i, j);
		printf ("%d %d %d\n", i, j, max);
	}
	return 0;
}


