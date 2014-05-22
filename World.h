// world.h
// World object header file
// Samuel Cagle
// Juston Li
// Xu Junjie, Kevin
// University of Oregon
// 2014-04-30

#ifndef WORLD_H
#define WORLD_H
#include <vector>

#include "Components/PositionComponent.h"
#include "Components/NutrientComponent.h"
#include "Components/RenderComponent.h"
#include "Components/WaterComponent.h"
#include "Components/SurvivalComponent.h"
#include "Systems/WaterSystem.h"
#include "Systems/RenderSystem.h"

// 2D world, maybe add the third z dimension later
// width/height refers to the size of the world being simulated, but
// also the width/height of the window of the visualization - tie the 2 
// together

namespace gws {
	class World {
	public:
		const static int default_width = 640;
		const static int default_height = 480;
		World(SDL_Window* window, int width = default_width, int height = default_height);
		~World();
		int width;
		int height;
		int nextEntityID = 0;
		
		// Component vectors
		// We might not need concurrent_vectors since we try to make sure
		// there is no multithreaded writing to them. Performance-wise 
		// concurrent vectors are slower than contiguous STL vectors
		// Especially when we use polymorphism - the objects are not in contiguous memory at all!
		std::vector<PositionComponent> positions;
		std::vector<NutrientComponent> nutrients;
		std::vector<RenderComponent> renders;
		std::vector<WaterComponent> waters;
		std::vector<SurvivalComponent> survivors;
		
		// Systems
		WaterSystem waterSystem;
		RenderSystem renderSystem;

		// Functions
		void reserve(size_t size); // Reserve space for potential entities
		int addRandomLake();
		int addRandomPlant();
		void runSystems();		
	private:
		int addEntity();
	};
} /* gws */
#endif
