#pragma once
#include <vector>
#include <queue>
#include <numeric>
/**
 * @author Błażej Styrnol
 * @class Wielomian
 * @brief Reprezentuje wielomian wykorzystywany w modelu ARX
 */
class Wielomian{
    std::vector<double> wsp; /// Współczynniki wielomianu
public:
    /// @brief Konstruktor inicjalizujący wielomian na podstawie wektora współczynników.
    /// @param wspolczynniki Wektor współczynników, od najwyższej potęgi do najniższej.
    explicit Wielomian(const std::vector<double>& wspolczynniki);

    /// @brief Oblicza wartość wielomianu na podstawie historii wejść.
    /// @param poprzednie_wartosci Historia wartości – zgodnie z kolejnością współczynników.
    /// @return Suma iloczynów współczynników i wartości z historii.
    [[nodiscard]] double oblicz(const std::deque<double>& poprzednie_wartosci) const;

    /// @brief Zwraca rozmiar (rząd) wielomianu.
    /// @return Liczba współczynników.
    [[nodiscard]] size_t rozmiar() const;

    /// @brief Zwraca kopię wektora współczynników.
    /// @return Wektor współczynników wielomianu.
    [[nodiscard]] std::vector<double> get_wsp() const;
};
