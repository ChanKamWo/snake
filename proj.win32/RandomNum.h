#pragma once
#ifndef GUARD_RandomNum_h
#define GUARD_RandomNum_h

#include <cstdio>
#include <stdexcept>
#include <ctime>
using std::domain_error;

int nrand(int n){
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");
	
	static bool flag = false;
	if (!flag){
		srand((unsigned)time(NULL));
		flag = true;
	}

	const int bucket_size = RAND_MAX / n;
	int r;
	do r = rand() / bucket_size;
	while (r >= n);
	
	return r;
}

#endif