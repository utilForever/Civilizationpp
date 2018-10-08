#ifndef CIVILIZATIONPP_RESOURCE
#define CIVILIZATIONPP_RESOURCE

namespace Civilizationpp {
struct Resource {
 private:
    int m_Food;
    int m_Production;
    int m_Gold;

 public:
    int GetFood();
    int GetProduction();
    int GetGold();
};
}  // namespace Civilizationpp
#endif  // Resource
