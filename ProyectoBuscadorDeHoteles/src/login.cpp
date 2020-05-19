#include "login.h"
#include <iostream>
#include <string.h>
using namespace std;

login::login(char *n,char *p)
{
    nombre = new char[strlen(n)+1];
    strcpy(nombre,n);
    pass = new char[strlen(n)+1];
    strcpy(pass,p);

}
void login::iniciarSesion(){

    int i;
    for(i=1; i<4; i++){
        system("cls");
        cout << endl;
        cout << "        BIENVENIDO AL SISTEMA DE LOGIN " << endl;
        cout << "___" << endl;
        cout << endl;
        cout << "Por favor ingrese su informacion de usuario" << endl;
        cout << endl;
        cout << "¿Nombre de usuario?" << endl;
        cin >> nombre;
    if(nombre == " iker"){
        cout << "Nombre de usuario correcto, por favor ingrese su contrasena:" << endl;
        cin >> pass;
    if(pass == "admin123"){
        cout << endl;
        cout << "Contrasena correcta, bienvenido, sera redirigido a la aplicacion" << endl;
        system("pause>null");
        exit(0);
    }
    else
        if(pass != "admin123"){
            cout << "Contrasena incorrecta, por favor ingrese un usuario y contrasena valida" << endl;
            system("pause>null");
        }
    }
    else
        if(nombre != "admin"){
            cout << "Nombre de usuario incorrecto, por favor ingrese su nombre de usuario nuevamente" << endl;
            system("pause>null");
        }

    if(i > 0){
        cout << endl;
        cout << "Ha realizado " << i << "/3 intentos" << endl;
        cout << endl;
        system("pause>null");
   }
    if(i == 3){
        cout << endl;
        cout << "Ha realizado 3 intentos, por seguridad el programa se cerrara..." << endl;
        system("pause>null");
        exit(0);
    }
    }

}

login::~login()
{
    delete[] nombre, pass;
}
