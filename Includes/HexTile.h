#ifndef CIVILIZATIONPP_HEX_TILE_H
#define CIVILIZATIONPP_HEX_TILE_H

#include <Terrain.h>

namespace Civilizationpp {
	class HexTile {

	private:

		Terrain m_Terrain;

	public:

		Terrain GetTerrain() { return m_Terrain; }
		void ChangeTerrain(Terrain terrain) { m_Terrain = terrain; }

	};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_HEX_TILE_H