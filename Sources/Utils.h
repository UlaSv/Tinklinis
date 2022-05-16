#pragma once

#ifndef Utils_H
#define Utils_H

#include "GameObjects.h"

namespace nmUtils
{
	bool IsBetween(float val, float rangeB, float rangeE);
	bool InOnNet(Ball ball, Net net);
	bool InOnNet2(Ball ball, Net net);
}
#endif