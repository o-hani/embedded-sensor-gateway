#include <iostream>
#include <string>
#include <memory>
#include <optional>

// Création calsse Capteur
class Capteur {
    public:
        Capteur(const std::string& nom)
            : m_nom(nom)
            , m_valeur(0.0)
        {
            std::cout << "Capteur " << m_nom << " créé\n";
        }

        virtual ~Capteur() {
            std::cout << "Capteur " << m_nom << " détruit\n";
        }

        virtual std::optional<double> lireValeur() = 0;

        double getValeur() const {
            return m_valeur;
        }

        std::string getId() const {
            return m_nom;
        }

    protected:
        std::string m_nom;
        double m_valeur;
};

// Création calsse fille CapteurTemperature
class CapteurTemperature : public Capteur {
    public:
        CapteurTemperature(const std::string& nom): Capteur(nom) {}

        std::optional<double> lireValeur() override {
            m_valeur = 36.6;
            if(m_valeur >= -40.0 && m_valeur <= 85.0) {
                return m_valeur;
            }
            else {
                return std::nullopt;
            }
        }

        double enFahrenheit() const {
            return (m_valeur * 9/5) + 32;
        }
};

int main() {
    std::unique_ptr<Capteur> c = std::make_unique<CapteurTemperature>("température");

    auto temperature = c->lireValeur();

    // Utilisation des méthodes de la classe std::optional: has_value() & .value()
    if(temperature.has_value()) {
        std::cout << "La valeur de la température est: " << temperature.value() << " °C\n";
    }
    else {
        std::cout << "La lecture échoue\n";
    }
    return 0;
}