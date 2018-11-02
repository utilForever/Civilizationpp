#include <Resource.h>
using namespace Civilizationpp;

Resource::Resource()
{
    m_food = 0;
    m_gold = 0;
    m_production = 0;
}
int Resource::GetFood() const
{
    return m_food;
}
int Resource::GetProduction() const
{
    return m_production;
}
int Resource::GetGold() const
{
    return m_gold;
}
