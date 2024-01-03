#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <ctype.h>
using namespace std;

struct ciutat{
   string nom;
   vector<long long int> Ptotal;
   vector<long long int> Phomes;
   vector<long long int> Pdones;
};

struct usuari{
   string nom;
   string contrasenya;
   vector<string> ciutatspreferides;
};

struct pais{
   string nom;
   string codipais;
   vector<long long int> pactiva;
   vector<long long int> ptotal;
};

void llegirusuaris (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void llegirdades (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void llegirpaisos (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void nouusuari (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void esborrarusuari (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void inicisessio(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void finalitzar(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void menu1(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void menu2(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void cercaciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void comparaciutats(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void ciutatsguardades(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void creixementpactivaciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void editarperfil(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
int menupaisociutat();
void cercapaisos(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void comparapaisos(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);
void paisosguardats(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos);

int main (){
   //Declarar Variables
   int seleccio;
   string name, nomusuari;
   int nusuaris;
   vector<usuari> usuaris;
   vector<ciutat> ciutats;
   vector<pais> paisos;

   usuari usuariactual;
   int pos;

   //Cridem accions
   llegirdades(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); //generara el vector amb totes les dades de les ciutats
   int tamany = ciutats.size();
   llegirusuaris(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); //generara el vector amb tots els usuaris
   llegirpaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   cout<<"Et donem la benvinguda a la base de dades ___, on podras trobar informacio sobre la poblacio activa de diverses ciutats europees."<<endl;
   cout<<"Si us plau, ingresa el teu nom: ";
   cin>>name;
   cout<<""<<endl;
   cout<<"Hola "<<name<<"."<<endl;
   menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
}//End main

void llegirusuaris (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
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

void llegirdades (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   ifstream Ptotal("poblacioactiva_total.csv"); //TODO treure accents (replace)
   ifstream Phomes("poblacioactiva_homes.csv");
   ifstream Pdones("poblacioactiva_dones.csv");
   string g, nomciutat;
   int any1, any2, any3, any4, any5, any6, any7, any8, any9, any10;
   long long int pactivatotal, pactivahomes, pactivadones;
   Ptotal>>g>>any1>>any2>>any3>>any4>>any5>>any6>>any7>>any8>>any9>>any10;
   Phomes>>g>>any1>>any2>>any3>>any4>>any5>>any6>>any7>>any8>>any9>>any10;
   Pdones>>g>>any1>>any2>>any3>>any4>>any5>>any6>>any7>>any8>>any9>>any10;
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

void nouusuari (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
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
   menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
}

void esborrarusuari (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
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
      menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   } else {
      cout<<endl<<"Usuari eliminat."<<endl<<endl;
      finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   }
}

void inicisessio(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   string password;
   cout<<"Nom d'usuari: ";
   cin>>nomusuari;
   cout<<"Contrasenya: ";
   cin>>password;
   bool found = false;
   for(int i = 0; i<nusuaris; i++){
      if(usuaris[i].nom == nomusuari && usuaris[i].contrasenya == password){
         found = true;
         usuariactual = usuaris[i];
         pos = i;
      }
   }
   if(found == false){
      cout<<endl<<"Usuari no trobat. Usuari o contrasenya erronia."<<endl;
      menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   } else if(found == true){
      cout<<endl<<"Benvingut "<<nomusuari<<endl;
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   }
}

void menu1(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
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
      case 1: inicisessio(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         break;
      case 2: nouusuari(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         break;
      case 3: esborrarusuari(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         break;
      case 4: finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); cout<<"Gracies per utilitzar ___.";
         break;
      default: cout<<"Si us  plau, introdueix un numero valid"<<endl; menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   }//End switch
}

void menu2(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   int seleccio;
   cout<<endl<<endl<<"Indica que vols fer escrivint el numero corresponent"<<endl;
   cout<<"MENU DE CERCA: "<<endl;
   cout<<"1. Cerca una ciutat o pais"<<endl;
   cout<<"2. Compara dos ciutats o paisos"<<endl;
   cout<<"3. Buscar llista ciutats preferides"<<endl;
   cout<<"4. Editar perfil"<<endl;
   cout<<"5. Tornar al menu anterior"<<endl;
   cout<<"6. Sortir"<<endl;

   cout<<"Que vols fer?: ";
   cin>>seleccio;
   cout<<endl;
   int eleccio;
   switch (seleccio){  //TODO crear menus pais o ciutat
      case 1: eleccio = menupaisociutat();
         switch (eleccio)
         {
         case 1:
            cercapaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         case 2:
            cercaciutat(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         default:
            cout<<"Numero introduit no valid."<<endl;
            menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         }
         break;
      case 2: eleccio = menupaisociutat();
         switch (eleccio)
         {
         case 1:
            comparapaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         case 2:
            comparaciutats(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         default:
            cout<<"Numero introduit no valid."<<endl;
            menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         }
         break;
      case 3: eleccio = menupaisociutat();
         switch (eleccio)
         {
         case 1:
            paisosguardats(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         case 2:
            ciutatsguardades(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         default:
            cout<<"Numero introduit no valid."<<endl;
            menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         }
         break;
      case 4: editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         break;
      case 5: menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         break;
      case 6: finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); cout<<"Gracies per utilitzar ___.";
         break;
      default: cout<<"Si us  plau, introdueix un numero valid"<<endl;
   }
}

void finalitzar(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
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

int menupaisociutat(){
   int eleccio;
   cout<<endl<<"Vols cercar informacio de ciutats o paisos?"<<endl;
   cout<<"1. Paisos"<<endl;
   cout<<"2. Ciutats"<<endl;
   cout<<"Introdueix el numero del que vols buscar: ";
   cin>>eleccio;
   return eleccio;
}

void cercaciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   string nomciutat, seleccio;
   cout<<"Cercador de ciutats: "<<endl<<"Introdueix el nom de la ciutat que vulguis buscar. Fes servir _ en lloc d'espais."<<endl<<"Ciutat: ";
   cin>>nomciutat;
   ciutat city;
   int nciutats = ciutats.size();
   bool ciutattrobada = false;
   for(int i = 0; i<nciutats; i++){
      if(ciutats[i].nom == nomciutat){
         ciutattrobada = true;
         city = ciutats[i];
         break;
      }
   }
   if(ciutattrobada == false){
      cout<<endl<<"Ciutat no trobada a la base de dades."<<endl;
   } else if(ciutattrobada == true){
      cout<<endl<<"Poblacio activa de "<<nomciutat<<" per anys (2013-2022):"<<endl;
      int any = 2013;
      for(int x = 0; x<10; x++){
         cout<<"  "<<any<<": "<<endl;
         cout<<"    Poblacio activa homes:"<<city.Phomes[x]<<endl;
         cout<<"    Poblacio activa dones:"<<city.Pdones[x]<<endl;
         cout<<"    Poblacio activa total:"<<city.Ptotal[x]<<endl;
         any++;
      }
      cout<<"Vols guardar la ciutat entre les teves preferides? "; //TODO que fer si ja esta guardada
      cin>>seleccio;
      if (seleccio == "Si" || seleccio == "SI" || seleccio == "sI" || seleccio == "Si." || seleccio == "SI." || seleccio == "sI." || seleccio == "si" || seleccio == "si."){
         usuariactual.ciutatspreferides.push_back(nomciutat);
         usuaris[pos] = usuariactual;
         finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      }
   }
   menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
}

void comparaciutats(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   
} // TODO comparar ciutats

void ciutatsguardades(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   int seleccio;
   cout<<"Ciutats preferides: "<<endl;
   for(int i=0; i<usuariactual.ciutatspreferides.size(); i++){
      cout<<i+1<<". "<<usuariactual.ciutatspreferides[i]<<endl;
   }
   cout<<endl<<"Introdueix el numero de la ciutat que vulguis buscar: ";
   cin>>seleccio;
   
   ciutat city;
   string nomciutat = usuariactual.ciutatspreferides[seleccio-1];
   int nciutats = ciutats.size();
   bool ciutattrobada = false;
   for(int i = 0; i<nciutats; i++){
      if(ciutats[i].nom == nomciutat){
         ciutattrobada = true;
         city = ciutats[i];
         break;
      }
   }
   if(ciutattrobada == false){
      cout<<endl<<"Ciutat no trobada a la base de dades."<<endl;
   } else if(ciutattrobada == true){
      cout<<endl<<"Poblacio activa de "<<nomciutat<<" per anys (2013-2022):"<<endl;
      int any = 2013;
      for(int x = 0; x<10; x++){
         cout<<"  "<<any<<": "<<endl;
         cout<<"    Poblacio activa homes:"<<city.Phomes[x]<<endl;
         cout<<"    Poblacio activa dones:"<<city.Pdones[x]<<endl;
         cout<<"    Poblacio activa total:"<<city.Ptotal[x]<<endl;
         any++;
      }
   }
   menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
}

void creixementpactivaciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){

}// TODO creixement poblacio activa d'una ciutat

void editarperfil(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   int seleccio;
   string contranova;
   cout<<endl<<"Que vols editar? "<<endl;
   cout<<"1. Nom d'usuari"<<endl;
   cout<<"2. Contrasenya"<<endl;
   cout<<"3. Eliminar paisos/ciutats preferides"<<endl;
   cout<<"4. Tornar al menu anterior"<<endl;
   cout<<"Introdueix el numero: ";
   cin>>seleccio;
   switch (seleccio)
   {
   case 1:
      cout<<endl<<"Nou nom d'usuari: ";
      cin>>nomusuari;
      usuariactual.nom = nomusuari;
      usuaris[pos] = usuariactual;
      editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      break;
   case 2:
      cout<<endl<<"Nova contrasenya: ";
      cin>>contranova;
      usuariactual.contrasenya = contranova;
      usuaris[pos] = usuariactual;
      editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      break;
   case 3:  //TODO eliminar paisos
      int seleccio;
      cout<<endl<<"Ciutats preferides: "<<endl;
      for(int i=0; i<usuariactual.ciutatspreferides.size(); i++){
         cout<<i+1<<". "<<usuariactual.ciutatspreferides[i]<<endl;
      }
      cout<<endl<<"Introdueix el numero de la ciutat o pais que vulguis eliminar: ";
      cin>>seleccio;
      usuariactual.ciutatspreferides.erase(usuariactual.ciutatspreferides.begin() + (seleccio - 1));
      usuaris[pos] = usuariactual;
      editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      break;
   case 4:
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      break;
   default:
      break;
   }
}

//TODO accions paisos
void llegirpaisos (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   ifstream pactivapaisosIN("poblacioactivapaisos.csv");
   ifstream ptotalpaisosIN("poblaciontotalpaises.csv");
   string nompais, codipais;
   int any1, any2, any3, any4, any5, any6, any7, any8, any9, any10;
   long long int pactivatotal, pactivapaisos;
   pactivapaisosIN>>nompais>>codipais>>any1>>any2>>any3>>any4>>any5>>any6>>any7>>any8>>any9>>any10;
   ptotalpaisosIN>>nompais>>codipais>>any1>>any2>>any3>>any4>>any5>>any6>>any7>>any8>>any9>>any10;
   while(ptotalpaisosIN>>nompais){
      pais x;
      x.nom = nompais;
      cout<<nompais<<endl;
      pactivapaisosIN>>nompais;
      ptotalpaisosIN>>codipais;
      pactivapaisosIN>>codipais;
      x.codipais = codipais;
      for(int i=0; i<10; i++){
         ptotalpaisosIN>>pactivatotal;
         x.ptotal.push_back(pactivatotal);
         pactivapaisosIN>>pactivapaisos;
         x.pactiva.push_back(pactivapaisos);
      }
      paisos.push_back(x);
   }
}

void paisosguardats (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){

}

void comparapaisos (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){

}

void cercapaisos (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){

}