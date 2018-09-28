#ifndef CIVILIZATIONPP_HEX_TILE_H
#define CIVILIZATIONPP_HEX_TILE_H

#include <Terrain.h>

namespace Civilizationpp {
	class HexTile {

	private:

		BasicTerrain m_Terrain;

	public:

		BasicTerrain GetTerrain() { return m_Terrain; }
		void ChangeTerrain(BasicTerrain Terrain) { m_Terrain = Terrain; }

	};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_HEX_TILE_H