#include "fan.h"
#include <iostream>
#include <random>
using namespace std;

namespace fan {
	int fan(int a) {
		int b = rand() % a;
		return a;
	}
}