#include <BaseResource.h>

using namespace Civilizationpp;

BaseResource::BaseResource()
{
    m_food = 0;
    m_gold = 0;
    m_production = 0;
}

int BaseResource::GetFood() const
{
    return m_food;
}

int BaseResource::GetProduction() const
{
    return m_production;
}

int BaseResource::GetGold() const
{
    return m_gold;
}
