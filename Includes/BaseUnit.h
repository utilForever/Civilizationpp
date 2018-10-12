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
    BaseUnit(int x, int y);
    virtual std::pair<int, int> Move(int x, int y) noexcept;
    std::pair<int, int> GetPosition();
};
}  // namespace Civilizationpp

#endif  // CIVILAZATIONPP_BASE_UNIT