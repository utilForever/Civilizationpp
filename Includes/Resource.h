#ifndef CIVILIZATIONPP_RESOURCE
#define CIVILIZATIONPP_RESOURCE

namespace Civilizationpp {
class Resource {
 private:
    int m_food;
    int m_production;
    int m_gold;

 public:
    Resource();
    int GetFood() const;
    int GetProduction() const;
    int GetGold() const;
};
}  // namespace Civilizationpp
#endif  // Resource
