#include "login.h"
#include <iostream>
<<<<<<< HEAD
#include <string.h>
#include <stdio.h>
using namespace std;


login::login(){
    nombre = new char[20];
    pass = new char[20];
}

login::login(char *n,char *p){
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
    cout << "Por favor ingrese su informacion de usuario" << endl;
    cout << endl;
    cout << "Nombre de usuario: ";
    cin >> nombre;
    if(strcmp(nombre,"admin")==0){
        cout << "Nombre de usuario correcto, por favor ingrese su contrasena:" << endl;
        cin >> pass;
        if(strcmp(pass,"admin123")==0){
            cout<<"Contraseña correcta, bienvenido"<<endl;
            system("pause>null");
        }else if(strcmp(pass,"admin123")!=0){
            cout << "Contrasena incorrecta, por favor ingrese un usuario y contrasena valida" << endl;
            system("pause>null");
        }
    }else if(strcmp(nombre,"admin")!=0){
        cout<<"Nombre de usuario incorrecto, por favor, intentelo de nuevo"<<endl;
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
=======
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>

#define ENTER 13
#define BACKSPACE 8

using namespace std;

void login:: iniciarSesion()
{
    vector<string> usuarios;
    vector<string> claves;

    // Se añaden usuarios al vector
    usuarios.push_back("luis");
    usuarios.push_back("jorge");
    usuarios.push_back("james");
    usuarios.push_back("johan");
    usuarios.push_back("kevin");

    // Se añaden claves al vector
    claves.push_back("123");
    claves.push_back("456");
    claves.push_back("789");
    claves.push_back("abc");
    claves.push_back("efg");


    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER) {

            if (caracter != BACKSPACE) {
                password.push_back(caracter);
                cout << "*";

            } else {
                if (password.length() > 0) {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++) {
            if (usuarios[i] == usuario && claves[i] == password) {
                ingresa = true;
                break;
            }
        }

        if (!ingresa) {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < 3);

    if (ingresa == false) {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    } else {
        cout << "\n\n\tBienvenido al sistema" << endl;
    }
>>>>>>> c68831e6c638678c331cee66569d4798e8f93f62

    cin.get();


<<<<<<< HEAD
login::~login()
{
    delete[] nombre;
    delete[] pass;

=======
>>>>>>> c68831e6c638678c331cee66569d4798e8f93f62
}
