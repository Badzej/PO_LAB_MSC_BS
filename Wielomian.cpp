#include "Wielomian.h"

Wielomian::Wielomian(const std::vector<double>& wspolczynniki): wsp(wspolczynniki) {};

double Wielomian::oblicz(const std::deque<double>& poprzednie_wartosci) const {
    size_t n = std::min(wsp.size(), poprzednie_wartosci.size());
    return std::inner_product(wsp.begin(), wsp.begin() + n, poprzednie_wartosci.begin(), 0.0);  ///iloczyn skalarny n wspolczynnikow wielomianu i poprzednich wartosci
}

std::vector<double> Wielomian::get_wsp() const { return wsp; }

size_t Wielomian::rozmiar() const { return wsp.size(); }