#include <tuple>
namespace Civilizationpp {
class BaseUnit {
 private:
    int m_positionX{0};
    int m_positionY{0};

 public:
    std::tuple<int, int> Move(int x, int y);
};
}  // namespace Civilizationpp