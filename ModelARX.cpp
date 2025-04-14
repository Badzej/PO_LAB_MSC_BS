#include "ModelARX.h"

double ModelARX::generujZaklocenie() const {
    if (sigma == 0.0) return 0.0;
    std::normal_distribution<double> dist(0.0, sigma);
    static std::default_random_engine gen;
    return dist(gen);
}

ModelARX::ModelARX(const std::vector<double>& a, const std::vector<double>& b, unsigned int opoznienie, double moc) : A(a), B(b), k(opoznienie), sigma(moc)
{
  u_hist.resize(b.size() + k, 0.0);
  y_hist.resize(a.size(), 0.0);
}

ModelARX::ModelARX(const std::string& sciezka) : ModelARX(deserializuj(sciezka)) {}

double ModelARX::symuluj(double u){
    u_hist.push_front(u);

    std::deque<double> u_opoznione(u_hist.begin() + k, u_hist.end());
    double wyjscie = B.oblicz(u_opoznione) - A.oblicz(y_hist) + generujZaklocenie();

    y_hist.push_front(wyjscie);
    return wyjscie;
}

void ModelARX::serializuj(const std::string& sciezka) const {
    nlohmann::json json_obj;
    json_obj["A"] = A.get_wsp();
    json_obj["B"] = B.get_wsp();
    json_obj["k"] = k;
    json_obj["sigma"] = sigma;

    std::ofstream plik(sciezka);
    plik << json_obj.dump(4); //. 4 oznacza formatowanie z 4 spacjami
    plik.close();
}

ModelARX ModelARX::deserializuj(const std::string& sciezka) {
        std::ifstream plik(sciezka);
        nlohmann::json json_obj;
        plik >> json_obj;
        plik.close();

        std::vector<double> a = json_obj["A"].get<std::vector<double>>();
        std::vector<double> b = json_obj["B"].get<std::vector<double>>();
        unsigned int k = json_obj["k"].get<unsigned int>();
        double sigma = json_obj["sigma"].get<double>();

        return ModelARX(a, b, k, sigma);
}
