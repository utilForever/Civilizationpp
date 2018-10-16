#ifndef CIVILAZATIONPP_BASE_UNIT
#define CIVILAZATIONPP_BASE_UNIT

#include <HexMap.h>
#include <tuple>

namespace Civilizationpp {
class BaseUnit {
 private:
    int m_positionX{0};
    int m_positionY{0};

 protected:
    HexMap* m_map;
 public:
    BaseUnit(HexMap* map, int x, int y);
    virtual ~BaseUnit() = default;
    
    virtual std::pair<int, int> Move(int x, int y) noexcept;
};
}  // namespace Civilizationpp

#endif  // CIVILAZATIONPP_BASE_UNIT