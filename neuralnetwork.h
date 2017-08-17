#ifndef NetworkNeural_h
#define NetworkNeural_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class NetworkNeural
{
public:
	//NetworkNeural();
	void MultiplyMatrix(float* A, float* B, int m, int p, int n, float* C);
  void Print(float* A, int m, int n, String label);
};

extern NetworkNeural Matrix;
#endif
