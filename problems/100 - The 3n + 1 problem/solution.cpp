//============================================================================
// Name        : 3n+1.cpp
// Author      : Johny Salas
// Version     : 1.0
// Copyright   : No copy
// Description : 3n+1 in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <algorithm>
using namespace std;

#define SIZE 913557212

static unsigned short cache[SIZE];

unsigned short cyclelength(unsigned int n) {

	// If the number was already calculated, return last result
	if(n < SIZE && cache[n])
		return cache[n];

	if( n%2 == 1) {
		// Instead of n = 3 * n + 1, let's do this both step in one
		// and the next one (n/2), given that after every
		// 3n+1 there is always an n/2
		cache[n] = 2 + cyclelength(1.5 * n + 0.5);
	} else {
		cache[n] = 1 + cyclelength(n / 2);
	}

	return cache[n];

}

unsigned short maxcycleLengthBetween(unsigned int i, unsigned int j) {

	//j can be smaller than i
	if(i > j) swap(i, j);

	unsigned short max = 1;
	for(unsigned int n = i; n <= j; n++) {
		unsigned short cl = cyclelength(n);
		if( cl > max ) {
			max = cl;
		}
	}
	return max;
}

int main() {

	int i, j;
	cache[1] = 1;

	while ( scanf ("%d %d", &i, &j) != EOF ) {
		unsigned short max = maxcycleLengthBetween( i, j);
		printf ("%d %d %d\n", i, j, max);
	}
	return 0;
}


