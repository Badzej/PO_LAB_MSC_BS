#include <ModelARX.h>


class ModelARX : public ObiektSISO
{
    public:
        ModelARX::ModelARX(std::vector<double> parametryMianownika,std::vector<double> parametryLicznika, unsigned int opoznienie, double mocZaklocenia)
        {
            WielomianDyskretny wielomianB(parametryLicznika);
            WielomianDyskretny wielomianA(parametryMianownika);
        };
        ModelARX::~ModelARX();
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
        WielomianDyskretny::WielomianDyskretny(std::vector<double> parametry){
            wspolczynnikiWielomianu.assign(parametry.begin(),parametry.end());
        }
        void obliczWartoscWielomianu()
        {
            wartoscWielomianu = std::accumulate(wspolczynnikiWielomianu.begin(),wspolczynnikiWielomianu.end(),0);
        };
        double zwrocWartoscWielomianu()
        {
            return wartoscWielomianu;
        };
    private:
        std::vector<double> wspolczynnikiWielomianu;
        double wartoscWielomianu;
};

