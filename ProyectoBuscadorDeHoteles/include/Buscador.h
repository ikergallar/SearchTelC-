#ifndef BUSCADOR_H
#define BUSCADOR_H

#include "Hotel.h"
class Buscador
{
    Hotel ** hoteles;
    int numHoteles;
    int maxHoteles;
    public:
        Buscador(int maxH);
        int getNumHoteles() const;
        int getMaxHoteles() const;
        void addHotel(Hotel *h);
        void revomeHotel(int pos);
        void mostrarHoteles();
        Hotel *getHotel(int pos);
        int buscarHotel(char *nom, char *ciu);
        virtual ~Buscador();

};

#endif // BUSCADOR_H
