#include "Forme.hpp"

class Disque : public Forme {
    private:
        double _rayon;

    public:
        Disque(double rayon);

        double aire() const override;

        double getRayon(){ return _rayon;}

        Description toDescription() const override;
};