#include <HexTile.h>
namespace Civilizationpp {
	class Obtainable {
	public:
        virtual int GetFood(HexTile tile) = 0;
        virtual int GetProduction(HexTile tile) = 0;
        virtual int GetGold(HexTile tile) = 0;
    };
}
