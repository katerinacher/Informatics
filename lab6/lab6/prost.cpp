#include "prost.h"
#include <stdbool.h>

bool prost(int p) {
	for (int k = 2; k <= p / 2; k++) {
		if (p % k == 0) {
			return false;
		}
	}
	return true;
}
