#ifndef CIVILIZATIONPP_HEX_TILE_H
#define CIVILIZATIONPP_HEX_TILE_H

#include <Terrain.h>

namespace Civilizationpp
{
	class HexTile
	{
	 private:
		Terrain* m_pTerrain;

	 public:
		HexTile();
		Terrain* GetTerrain() const;
		void SetTerrain(Terrain* terrain);
		void ChangeResource(Resource* resource);
	};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_HEX_TILE_H
