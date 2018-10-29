#ifndef CIVILIZATIONPP_RESOURCE
#define CIVILIZATIONPP_RESOURCE

namespace Civilizationpp {
struct Resource {
 private:
    int m_Food;
    int m_Production;
    int m_Gold;

 public:
    Resource();
    int GetFood() const;
    int GetProduction() const;
    int GetGold() const;
};
}  // namespace Civilizationpp
#endif  // Resource
