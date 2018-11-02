#ifndef CIVILIZATIONPP_RESOURCE_H
#define CIVILIZATIONPP_RESOURCE_H

namespace Civilizationpp
{
class Resource
{
 public:
    Resource();

    int GetFood() const;
    int GetProduction() const;
    int GetGold() const;

 private:
    int m_food;
    int m_production;
    int m_gold;
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_RESOURCE_H
