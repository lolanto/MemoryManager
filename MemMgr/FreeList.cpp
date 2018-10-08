#include "FreeList.h"
using namespace FL;

size_t FreeList::upperRound(size_t size) {
	if (size <= 4) return 4;
	return (size_t)(ceilf(float(size) / 8.0f) * 8);
}

void FreeList::init() {
	m_head = 
}