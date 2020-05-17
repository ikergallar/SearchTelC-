#include <iostream>
#include "Buscador.h"
#include "Habitacion.h"
/*
    Que al salir del menú se vuelquen todos los datos aun fichero binario Buscador.dat
    Que al empezar el programa, si el fichero Buscador.dat existe, se carguen los datos del fichero en el buscador
*/
using namespace std;
char menu(){
    char opcion;

    cout<<"1. Ver todos los hoteles"<<endl;
    cout<<"2. Reservar una habitación en un hotel"<<endl;
    cout<<"3. Cancelar la reserva de una habitación"<<endl;
    cout<<"4. Añadir hotel al buscardor"<<endl;
    cout<<"5. Eliminar hotel del buscador"<<endl;
    cout<<"0. Salir"<<endl;

    do{
        cout<<"Elige una opcion: ";
        cin>>opcion;
    }while(opcion<'0' || opcion>'5');
    return opcion;
}
int main()
{
    int numHo,numHa,posHo,posHa;
    char opcion;
    char nombre[20],ciudad[20];
    Hotel *h;

    Buscador buscador(100);
    do{
        opcion =  menu();
        switch(opcion){
            case '0': cout<<"Gracias por usar nuestro buscador. ¡Hasta otra!"<<endl; break;
            case '1':
                buscador.mostrarHoteles();
            break;
            case '2':
                buscador.mostrarHoteles();
                cout<<"Introduce el hotel que deseas elegir: "<<endl;
                cin>>numHo;
                buscador.getHotel(numHo)->mostrarHabitaciones();
                cout<<" "<<endl;
                cout<<"Elige una habitacion: "<<endl;
                cin>>numHa;
                buscador.getHotel(numHo)->getHabitacion(numHa)->setOcupada(1);
                cout<<"Habitación reservada correctamente"<<endl;

                break;
            case '3':

                cout<<"Introduce el nombre del hotel: ";
                cin>>nombre;
                cout<<"Introduce la ciudad: ";
                cin>>ciudad;
                posHo = buscador.buscarHotel(nombre, ciudad);
                if(posHo==-1)
                    cout<<"Datos del hotel desconocidos"<<endl;
                else{
                    cout<<"Introduce el numero de habitacion cuya reserva quieres cancelar: ";
                    cin>>numHa;
                    posHa = buscador.getHotel(posHo)->buscarHabitacion(numHa);
                    if(posHa==-1)
                        cout<<"Datos de habitacion desconocida"<<endl;
                    else{
                        buscador.getHotel(posHo)->getHabitacion(posHa)->setOcupada(0);
                        cout<<"Reserva cancelada correctamente"<<endl;
                    }
                }

                break;
            case '4':
                h = new Hotel();
                h->pedirDatos();
                buscador.addHotel(h);
                      break;
            case '5': cout<<"Introduce el nombre del hotel: ";
                cin>>nombre;
                cout<<"Introduce la ciudad: ";
                cin>>ciudad;
                posHo = buscador.buscarHotel(nombre, ciudad);
                if(posHo==-1)
                    cout<<"Datos del hotel desconocidos"<<endl;
                else{

                    buscador.revomeHotel(posHo);
                    cout<<"Hotel eliminado del buscador"<<endl;
                }
            break;
        }
    }while(opcion!='0');
    return 0;
}
