#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
using namespace std;

struct ciutat{
   string nom;
   vector<double> Ptotal;
   vector<double> Phomes;
   vector<double> Pdones;
};

struct usuari{
   string nom;
   string contrasenya;
   vector<string> ciutatspreferides;
};

void llegirusuaris (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void llegirdades (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void nouusuari (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void esborrarusuari (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void inicisessio(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void finalitzar(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void menu1(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void menu2(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void cercaciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void comparaciutats(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void guardarciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void ciutatsguardades(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);
void mostrarciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual);

int main (){
   //Declarar Variables
   int seleccio;
   string name, nomusuari;
   int nusuaris;
   vector<usuari> usuaris;
   vector<ciutat> ciutats;

   usuari usuariactual;

   //Cridem accions
   llegirdades(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual); //generara el vector amb totes les dades de les ciutats
   int tamany = ciutats.size();
   llegirusuaris(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual); //generara el vector amb tots els usuaris
   cout<<"Et donem la benvinguda a la base de dades ___, on podras trobar informacio sobre la poblacio activa de diverses ciutats europees."<<endl;
   cout<<"Si us plau, ingresa el teu nom: ";
   cin>>name;
   cout<<""<<endl;
   cout<<"Hola "<<name<<"."<<endl;
   menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
   finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
}//End main

void llegirusuaris (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){
   ifstream UsuarisIN("usuaris.txt");
   UsuarisIN>>nusuaris;
   for(int i=0; i<nusuaris; i++){
      usuari x;
      string ciutat;
      UsuarisIN>>x.nom>>x.contrasenya>>ciutat;
      while (ciutat != "FIN")
      {
         x.ciutatspreferides.push_back(ciutat);
         UsuarisIN>>ciutat;
      }
      usuaris.push_back(x);
   }
}

void llegirdades (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){
   ifstream Ptotal("poblacioactiva_total.csv");
   ifstream Phomes("poblacioactiva_homes.csv");
   ifstream Pdones("poblacioactiva_dones.csv");
   string g, nomciutat;
   int any1, any2, any3, any4, any5, any6, any7, any8, any9, any10, pactivatotal, pactivahomes, pactivadones;
   Ptotal>>g>>any1>>any2>>any3>>any4>>any5>>any6>>any7>>any8>>any9>>any10;
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

void nouusuari (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){
   cout<<endl<<"Numero d'usuaris: "<<usuaris.size()<<endl;
   string username, password;
   cout<<"Introdueix el teu nom d'usuari, sense fer servir espais."<<endl<<"Nom d'usuari: ";
   cin>>username;
   cout<<endl<<"Escull una contrasenya amb lletres i numeros (evitar caracters especials)."<<endl<<"Contrasenya: ";
   cin>>password;
   usuari x;
   x.nom = username;
   x.contrasenya = password;
   usuaris.push_back(x);
   cout<<endl<<"Numero d'usuaris: "<<usuaris.size()<<endl;
   nusuaris = usuaris.size();
   cout<<endl<<"Benvingut "<<username<<endl;
   menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
}

void esborrarusuari (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){
   string username, password;
   cout<<"Nom d'usuari: ";
   cin>>username;
   cout<<"Contrasenya: ";
   cin>>password;
   bool trobat = false;
   int indice = 0;
   for (int i = 0; i < nusuaris; i++)
   {
      if(usuaris[i].nom == username && usuaris[i].contrasenya == password){
         trobat = true;
         usuaris.erase(usuaris.begin() + indice);
         nusuaris--;
         break;
      }
      indice++;
   }
   if (trobat == false){
      cout<<"Usuari no trobat, nom d'usuari o contrasenya incorrecte."<<endl;
      menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
   } else {
      cout<<endl<<"Usuari eliminat."<<endl<<endl;
      finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
      menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
   }
}

void inicisessio(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){
   string username, password;
   cout<<"Nom d'usuari: ";
   cin>>username;
   cout<<"Contrasenya: ";
   cin>>password;
   nomusuari = username;
   bool found = false;
   for(int i = 0; i<nusuaris; i++){
      if(usuaris[i].nom == username && usuaris[i].contrasenya == password){
         found = true;
      }
   }
   if(found == false){
      cout<<endl<<"Usuari no trobat. Usuari o contrasenya erronia."<<endl;
      menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
   } else if(found == true){
      cout<<endl<<"Benvingut "<<username<<endl;
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
   }
}

void menu1(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){
   //Menu Inicial
   int seleccio;
   cout<<endl<<"Indica que vols fer escrivint el numero corresponent"<<endl;
   cout<<"MENU INICIAL: "<<endl;
   cout<<"1. Iniciar Sessio"<<endl;
   cout<<"2. Registrar Nou Usuari"<<endl;
   cout<<"3. Esborrar Usuari"<<endl;
   cout<<"4. Sortir"<<endl;

   cout<<"Que vols fer?: ";
   cin>>seleccio;
   cout<<endl;

   switch (seleccio){
      case 1: inicisessio(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
         break;
      case 2: nouusuari(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
         break;
      case 3: esborrarusuari(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
         break;
      case 4: finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual); cout<<"Gracies per utilitzar ___.";
         break;
      default: cout<<"Si us  plau, introdueix un numero valid"<<endl;
   }//End switch
}

void menu2(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){
   int seleccio;
   cout<<"Indica que vols fer escrivint el numero corresponent"<<endl;
   cout<<"MENU DE CERCA: "<<endl;
   cout<<"1. Cerca una ciutat o pais"<<endl;
   cout<<"2. Compara dos ciutats o paisos"<<endl;
   cout<<"3. Buscar llista ciutats preferides"<<endl;
   cout<<"4. Tornar al menu anterior"<<endl;
   cout<<"5. Sortir"<<endl;

   cout<<"Que vols fer?: ";
   cin>>seleccio;
   cout<<endl;

   switch (seleccio){
      case 1: cercaciutat(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
         break;
      case 2: comparaciutats(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
         break;
      case 3: ciutatsguardades(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
         break;
      case 4: menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual);
         break;
      case 5: finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual); cout<<"Gracies per utilitzar ___.";
         break;
      default: cout<<"Si us  plau, introdueix un numero valid"<<endl;
   }
}

void finalitzar(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){
   ofstream UsuarisOUT("usuaris.txt");
   UsuarisOUT<<nusuaris<<endl;
   for(int i = 0; i<nusuaris; i++){
      UsuarisOUT<<usuaris[i].nom<<" "<<usuaris[i].contrasenya<<" ";
      for(int nciutats = 0; nciutats < usuaris[i].ciutatspreferides.size(); nciutats++){
         UsuarisOUT<<usuaris[i].ciutatspreferides[nciutats]<<" ";
      }
      UsuarisOUT<<"FIN"<<endl;
   }
}

void cercaciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){

}

void mostrarciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){

}

void comparaciutats(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){
   
}

void guardarciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){

}

void ciutatsguardades(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual){

}