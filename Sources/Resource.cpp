#include <Resource.h>
Civilizationpp::Resource::Resource()
{
    m_food = 0;
    m_gold = 0;
    m_production = 0;
};
int Civilizationpp::Resource::GetFood() const { return m_food; }
int Civilizationpp::Resource::GetProduction() const { return m_production; }
int Civilizationpp::Resource::GetGold() const { return m_gold; }