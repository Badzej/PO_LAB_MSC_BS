#pragma once
/**
 * @author Błażej Styrnol
 * @class ObiektSISO
 * @brief Wirtualna klasa interfejsu o jednym wejściu i jednym wyjściu (Single Input Single Output)
 */
class ObiektSISO
{
public:
    virtual ~ObiektSISO() = default; /// Destruktor klasy wirtualnej
    virtual double symuluj(double u) = 0; /// Wirtualna metoda symuluj przyjmująca wejście u i zwracająca wyjście y
};