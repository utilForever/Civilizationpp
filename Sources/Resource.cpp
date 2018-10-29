#include <Resource.h>
Civilizationpp::Resource::Resource():m_Food(0),m_Gold(0),m_Production(0){};
int Civilizationpp::Resource::GetFood() const { return m_Food; }
int Civilizationpp::Resource::GetProduction() const { return m_Production; }
int Civilizationpp::Resource::GetGold() const { return m_Gold; }