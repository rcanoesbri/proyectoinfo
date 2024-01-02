#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
using namespace std;

typedef basic_iostream<wchar_t> wiostream;
typedef basic_fstream<wchar_t> wfstream;

struct ciutat{ //TUPLA ON ES GUARDEN LES DADES DE LA POBLACI�
   string nom;
   vector<double> Ptotal;
   vector<double> Phomes;
   vector<double> Pdones;
};

struct usuari{ //TUPLA ON ES GUARDEN LES DADES DE LA POBLACI�
   string nom;
   string contrasenya;
   vector<string> ciutatspreferides;
};

void llegirusuaris (int& nusuaris, vector<usuari>& usuaris);
void llegirdades (vector<ciutat>& ciutats);
void nouusuari ();
void esborrarusuari ();
void inicisesio(string& nomusuari, usuari& usuariactual);

int main (){
   //Declarar Variables
   char seleccio;
   string name, nomusuari;
   int nusuaris;
   vector<usuari> usuaris;
   vector<ciutat> ciutats;

   usuari usuariactual;

   //Cridem accions inicialitzacio
   llegirdades(ciutats); //generara el vector amb totes les dades de les ciutats
   int tamany = ciutats.size();
   cout<<"numero ciutats: "<<tamany;
   //llegirusuaris(nusuaris, usuaris); //generara el vector amb tots els usuaris

   //RECONEIXEMENT DE L'USUARI
   cout<<"Et donem la benvinguda a la base de dades ___, on podras trobar informacio sobre la poblacio activa de diverses ciutats europees."<<endl;
   cout<<"Si us plau, ingresa el teu nom: ";
   cin>>name;
   cout<<""<<endl;
   cout<<"Hola "<<name<<"."<<endl;

   //Menu Inicial
   cout<<"Indica que vols fer escrivint el numero corresponent"<<endl;
   cout<<"1. Iniciar Sesio"<<endl;
   cout<<"2. Registrar Nou Usuari"<<endl;
   cout<<"3. Esborrar Usuari"<<endl;
   cout<<"4. Sortir"<<endl;

   cout<<"Que vols fer?: ";
   cin>>seleccio;
   cout<<endl;

   switch (seleccio){
      case 1: inicisesio(string& nomusuari, usuari& usuariactual);
         break;
      case 2: nouusuari();
         break;
      case 3: esborrarusuari();
         break;
      case 4: cout<<"Gracies per utilitzar ___.";
         break;
      default: cout<<"Si us  plau, introdueix un numero valid"<<endl;
   }//End switch
}//End main

/*void llegirusuaris (int& nusuaris, vector<usuari>& usuaris){
   wifstream UsuarisIN("usuaris.txt");
   UsuarisIN>>nusuaris;
   for(int i=0; i<nusuaris; i++){
      usuari x;
      string ciutat;
      UsuarisIN>>x.dni>>x.nom>>ciutat;
      while (ciutat != "FIN")
      {
         x.ciutatspreferides.push_back(ciutat);
         UsuarisIN>>ciutat;
      }
      usuaris.push_back(x);
   }
}
*/
void llegirdades (vector<ciutat>& ciutats){
   ifstream Ptotal("poblacioactiva_total.csv");
   ifstream Phomes("poblacioactiva_homes.csv");
   ifstream Pdones("poblacioactiva_dones.csv");
   string g, nomciutat;
   int any1, any2, any3, any4, any5, any6, any7, any8, any9, any10, pactivatotal, pactivahomes, pactivadones;
   Ptotal>>g>>any1>>any2>>any3>>any4>>any5>>any6>>any7>>any8>>any9>>any10;
   cout<<g<<any1<<any2<<any3<<any4<<any5<<any6<<any7<<any8<<any9<<any10;
   while(Ptotal>>nomciutat){
      ciutat x;
      x.nom = nomciutat;
      Phomes>>nomciutat;
      Pdones>>nomciutat;
      for(int i=0; i<10; i++){
         Ptotal>>pactivatotal;
         x.Ptotal.push_back(pactivatotal);
         Phomes>>pactivahomes;
         x.Phomes.push_back(pactivahomes);
         Pdones>>pactivadones;
         x.Pdones.push_back(pactivadones);
      }
      ciutats.push_back(x);
   }
}

void nouusuari (){
   string username, password;
   cout<<"Introdueix el teu nom d'usuari, sense fer servir espais."<<endl<<"Nom d'usuari: ";
   cin>>username;
   cout<<endl<<"Escull una contrasenya amb lletres i numeros (evitar caracters especials)."<<endl<<"Contrasenya: ";
   cin>>password;
   usuari x;
   x.nom = username;
   x.contrasenya = password;
   usuaris.push_back(x);
}

void esborrarusuari (){
   string username, password;
   cout<<"Nom d'usuari: ";
   cin>>username;
   cout<<endl<<"Contrasenya: ";
   cin>>password;
   
}

void inicisesio(string& nomusuari, usuari& usuariactual){
   string username, password;
   cout<<"Nom d'usuari: ";
   cin>>username;
   cout<<endl<<"Contrasenya: ";
   cin>>password;
   nomusuari = username;
}
