//
// Created by Błażej on 12.04.2025.
//
#include <vector>
#include <queue>
#include <numeric>
#include <random>
#include "ObiektSISO.h"




//TODO: Serializacja, Podział na plik naglowkowy, Komentarze dla Doxygen

class Wielomian{
private:
    std::vector<double> wsp; // współczynniki wielomianu
public:
    explicit Wielomian(const std::vector<double>& wspolczynniki) : wsp(wspolczynniki) {}

    [[nodiscard]] double oblicz(const std::deque<double>& historia) const {
        size_t n = std::min(wsp.size(), historia.size());
        return std::inner_product(wsp.begin(), wsp.begin() + n, historia.begin(), 0.0);
    }

    [[nodiscard]] size_t rozmiar() const { return wsp.size(); }
};

class ModelARX : public ObiektSISO
{
    private:
        Wielomian A; //Wielomian A(z⁻¹) → mówi, jak bardzo przeszłe y wpływają na obecne
        Wielomian B; //Wielomian B(z⁻¹) → mówi, jak przeszłe u wpływają na y
        std::deque<double> y_hist;
        std::deque<double> u_hist;
        unsigned int k; //opoznienie
        double sigma; //odchylenie standardowe szumu

        [[nodiscard]] double generujZaklocenie() const {
            if (sigma == 0.0) return 0.0;
            std::normal_distribution<double> dist(0.0, sigma);
            static std::default_random_engine gen;
            return dist(gen);
        }

    public:
        //Konstruktor glowny
        ModelARX(const std::vector<double>& a, const std::vector<double>& b, int opoznienie, double moc) : A(a), B(b), k(opoznienie), sigma(moc)
        {
          u_hist.resize(b.size() + k, 0.0);
          y_hist.resize(a.size(), 0.0);
        }

        double symuluj(double u) override{
            u_hist.push_front(u);
            if(u_hist.size() > B.rozmiar() + k) u_hist.pop_back();

            std::deque<double> u_opoznione(u_hist.begin() + k, u_hist.end());
            double wyjscie = B.oblicz(u_opoznione) - A.oblicz(y_hist) + generujZaklocenie();

            y_hist.push_front(wyjscie);
            if (y_hist.size() > A.rozmiar()) y_hist.pop_back();
            return wyjscie;
        }
};