#include <BasicResource.h>

using namespace Civilizationpp;

BasicResource::BasicResource()
{
    m_food = 0;
    m_gold = 0;
    m_production = 0;
}

int BasicResource::GetFood() const
{
    return m_food;
}

int BasicResource::GetProduction() const
{
    return m_production;
}

int BasicResource::GetGold() const
{
    return m_gold;
}
