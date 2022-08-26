#pragma once
#include <queue>
#include "ZugSador.h"

class PriorityQueue : public std::priority_queue<ZugSador>
{
	void increaseKey(ZugSador pair);
};

