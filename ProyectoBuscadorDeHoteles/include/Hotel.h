#ifndef HOTEL_H
#define HOTEL_H
#include "Habitacion.h"

class Hotel
{
    char *nombre;
    char *direccion;
    char *ciudad;
    int numEstrellas;
    int maxHabitaciones;
    int numHabitaciones;
    Habitacion ** habitaciones;
    public:
        Hotel();
        Hotel(char *n, char *d, char *c, int numE, int maxH);
        char *getNombre() const;
        char *getDireccion() const;
        char *getCiudad() const;
        void pedirDatos();
        Habitacion * getHabitacion(int pos) const;
        int buscarHabitacion(int numH);
        void addHabitacion(Habitacion *h);
        void reservarHabitacion(int pos);
        void mostrarHabitaciones();
        void mostrarHotel();
        virtual ~Hotel();

    protected:

    private:
};

#endif // HOTEL_H
