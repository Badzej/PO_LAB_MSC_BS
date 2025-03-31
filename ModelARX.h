#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <ObiektSISO.h>

class ModelARX : public ObiektSISO
{
    public:
        ModelARX::ModelARX(std::vector<double> parametryMianownika,std::vector<double> parametryLicznika, unsigned int opoznienie, double mocZaklocenia);
        ModelARX::~ModelARX();
        double ModelARX::symuluj(double wartoscWejsciowa){

        }
    private:
        std::vector<double> wartosciWielomianuA;
        std::vector<double> wartosciWielomianuB;
        std::queue<double> sygnalWejsciowy;
        std::queue<double> sygnalWyjsciowy;
        std::vector<unsigned int> opoznienieTransportowe;
        unsigned int rzadOpoznieniaTransportowego;
        double mocZaklocenia = 0.0;

};

class WielomianDyskretny
{
    public:
        void obliczWartoscWielomianu();
        double zwrocWartoscWielomianu();
    private:
        std::vector<double> wspolczynnikiWielomianu;
        double wartoscWielomianu;

};

