#ifndef CIVILIZATIONPP_BASICRESOURCE_H
#define CIVILIZATIONPP_BASICRESOURCE_H

namespace Civilizationpp
{
class BasicResource
{
 public:
    BasicResource();

    int GetFood() const;
    int GetProduction() const;
    int GetGold() const;

 private:
    int m_food;
    int m_production;
    int m_gold;
};
}  // namespace Civilizationpp

#endif  // CIVILIZATIONPP_BASICRESOURCE_H
