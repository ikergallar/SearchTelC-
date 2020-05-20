#include <iostream>
#include "Buscador.h"
#include "Habitacion.h"
#include "login.h"
#include "Hotel.h"
#include <fstream>


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

void volcarBuscadorAFichero(Buscador *buscador){
    ofstream f1;
    f1.open("Hoteles.txt",ios::out);
    f1<<buscador->getMaxHoteles()<<endl;
    f1<<buscador->getNumHoteles()<<endl;
    for(int i=0;i<buscador->getNumHoteles();i++){
            f1<<buscador->getHotel(i)->getNombre()<<endl;
            f1<<buscador->getHotel(i)->getDireccion()<<endl;
            f1<<buscador->getHotel(i)->getCiudad()<<endl;
            f1<<buscador->getHotel(i)->getNumEstrellas()<<endl;
            f1<<buscador->getHotel(i)->getMaxHabitaciones()<<endl;
            f1<<buscador->getHotel(i)->getNumHabitaciones()<<endl;
            for(int j=0;j<buscador->getHotel(i)->getNumHabitaciones();j++){
                f1<<buscador->getHotel(i)->getHabitacion(j)->getNumH()<<endl;
                f1<<buscador->getHotel(i)->getHabitacion(j)->getTipo()<<endl;
                f1<<buscador->getHotel(i)->getHabitacion(j)->getPrecio()<<endl;
                f1<<buscador->getHotel(i)->getHabitacion(j)->getOcupada()<<endl;
            }
    }
    f1.close();
}

Buscador *volcarFicheroABuscador(){
    Buscador *buscador=NULL;
    ifstream f1;
    f1.open("Hoteles.txt",ios::in);
    if(!f1.fail() && !f1.bad()){
        int maxH,numH;
        f1>>maxH;
        f1>>numH;
        buscador = new Buscador(maxH);
        for(int i=0;i<numH;i++){
                char nombre[20];
                char direccion[100];
                char ciudad[40];
                int numEstrellas;
                int maxHabitaciones;
                int numHabitaciones;
                f1>>nombre;
                f1>>direccion;
                f1>>ciudad;
                f1>>numEstrellas;
                f1>>numHabitaciones;
                f1>>maxHabitaciones;
                Hotel *h = new Hotel(nombre,direccion,ciudad,numEstrellas,maxHabitaciones);
                buscador->addHotel(h);
                for(int j=0;j<numHabitaciones;j++){
                        int numHabitacion;
                        char tipo[20];
                        float precio;
                        int ocupada;
                        f1>>numHabitacion;
                        f1>>tipo;
                        f1>>precio;
                        f1>>ocupada;
                        Habitacion *ha = new Habitacion(numHabitacion,tipo,precio,ocupada);
                        buscador->getHotel(i)->addHabitacion(ha);
                }
        }
    }
    f1.close();
    return buscador;
}
int main()
{
    int numHo,numHa,posHo,posHa;
    char opcion;
    char nombre[20],ciudad[20];
    Hotel *h;
    login *l = new login();

    Buscador *buscador= NULL;
    buscador = volcarFicheroABuscador();
    if(buscador==NULL){
        buscador = new Buscador(100);
    }
    l->iniciarSesion();
    do{
        opcion =  menu();
        switch(opcion){
            case '0': cout<<"Gracias por usar nuestro buscador. ¡Hasta otra!"<<endl; break;
            case '1':
                buscador->mostrarHoteles();
            break;
            case '2':
                buscador->mostrarHoteles();
                cout<<"Introduce el hotel que deseas elegir: "<<endl;
                cin>>numHo;
                buscador->getHotel(numHo)->mostrarHabitaciones();
                cout<<" "<<endl;
                cout<<"Elige una habitacion: "<<endl;
                cin>>numHa;
                buscador->getHotel(numHo)->getHabitacion(numHa)->setOcupada(1);
                cout<<"Habitación reservada correctamente"<<endl;

                break;
            case '3':

                cout<<"Introduce el nombre del hotel: ";
                cin>>nombre;
                cout<<"Introduce la ciudad: ";
                cin>>ciudad;
                posHo = buscador->buscarHotel(nombre, ciudad);
                if(posHo==-1)
                    cout<<"Datos del hotel desconocidos"<<endl;
                else{
                    cout<<"Introduce el numero de habitacion cuya reserva quieres cancelar: ";
                    cin>>numHa;
                    posHa = buscador->getHotel(posHo)->buscarHabitacion(numHa);
                    if(posHa==-1)
                        cout<<"Datos de habitacion desconocida"<<endl;
                    else{
                        buscador->getHotel(posHo)->getHabitacion(posHa)->setOcupada(0);
                        cout<<"Reserva cancelada correctamente"<<endl;
                    }
                }

                break;
            case '4':
                h = new Hotel();
                h->pedirDatos();
                buscador->addHotel(h);
                      break;
            case '5': cout<<"Introduce el nombre del hotel: ";
                cin>>nombre;
                cout<<"Introduce la ciudad: ";
                cin>>ciudad;
                posHo = buscador->buscarHotel(nombre, ciudad);
                if(posHo==-1)
                    cout<<"Datos del hotel desconocidos"<<endl;
                else{

                    buscador->revomeHotel(posHo);
                    cout<<"Hotel eliminado del buscador"<<endl;
                }
            break;
        }
    }while(opcion!='0');
    volcarBuscadorAFichero(buscador);
    return 0;

}
