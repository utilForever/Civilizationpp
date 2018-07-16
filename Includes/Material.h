namespace Civilizationpp {
	class Obtainable {
	public:
        virtual int GetFood() = 0;
        virtual int GetProduction() = 0;
        virtual int GetGold() = 0;
    };
}
