#include "Forme.cpp"

class Rectangle : public Forme {
    private:
        double _largeur;
        double _hauteur;

    public:
        Rectangle(double largeur, double hauteur);

        double aire() const override;

        double getLargeur(){ return _largeur;}

        double getHauteur(){ return _hauteur;}

        Description toDescription() const override;
};
