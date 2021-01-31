#ifndef LAYER_H
#define LAYER_H

#include "app/Event.h"

namespace engine
{
	class Layer
	{
	public:
		virtual void onUpdate(float delta) = 0;
		virtual void onEvent(Event &e) = 0;
	};
} // namespace engine

#endif
