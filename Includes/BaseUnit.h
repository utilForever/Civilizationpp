#include <HexMap.h>
#include <tuple>
namespace Civilizationpp {
class BaseUnit {
 private:
    int m_positionX{0};
    int m_positionY{0};

 protected:
    HexMap m_world;

 public:
    BaseUnit(int x, int y, HexMap map);
    std::pair<int, int> Move(int x, int y);
};
}  // namespace Civilizationpp