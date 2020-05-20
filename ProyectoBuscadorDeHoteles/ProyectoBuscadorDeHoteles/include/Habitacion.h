#ifndef HABITACION_H
#define HABITACION_H


class Habitacion
{
    int numHabitacion;
    char *tipo;
    float precio;
    int ocupada;
    public:
        Habitacion();
        Habitacion(int nunH, char *t, float p);
        Habitacion(int nunH, char *t, float p,int ocupada);
        int getNumH() const;
        char * getTipo() const;
        float getPrecio() const;
        int getOcupada() const;
        void setOcupada(int o);
        void mostrarHabitacion();
        void pedirDatos();
        virtual ~Habitacion();

};

#endif // HABITACION_H
