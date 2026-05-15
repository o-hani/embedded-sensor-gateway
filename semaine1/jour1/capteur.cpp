#include <iostream>
#include <string>

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

        virtual void lireValeur() = 0;

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
        
        void lireValeur() override {
            m_valeur = 36.6;
        }

        double enFahrenheit() const {
            return (m_valeur * 9/5) + 32;
        }
};

int main() {
    CapteurTemperature* c = new CapteurTemperature("température");
    c->lireValeur();
    std::cout << c->getValeur() << "\n";
    std::cout << c->enFahrenheit() << "\n";
    delete c;
    return 0;
}