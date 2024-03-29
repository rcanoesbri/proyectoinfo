#include <iostream>
#include <fstream>
#include <vector>

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
   vector<string> paisospreferits;
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

   ofstream outfile("resultat.txt");
   outfile<<" ";

   //Cridem accions
   llegirdades(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); //generara el vector amb totes les dades de les ciutats
   int tamany = ciutats.size();
   llegirusuaris(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); //generara el vector amb tots els usuaris
   llegirpaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   cout<<"Et donem la benvinguda a la base de dades ACPODA, on podras trobar informacio sobre la poblacio activa de diverses ciutats europees."<<endl;
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
      string preferits, fin;
      
      UsuarisIN>>x.nom>>x.contrasenya>>preferits;
      while (preferits != "FIN")
      {
         x.ciutatspreferides.push_back(preferits);
         UsuarisIN>>preferits;
      }
      UsuarisIN>>preferits;
      while (preferits != "END")
      {        
         x.paisospreferits.push_back(preferits);
         UsuarisIN>>preferits;
      }
      usuaris.push_back(x);
   }
}

void llegirdades (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   ifstream Ptotal("poblacioactiva_total.csv");
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
      g = nomciutat;
      nomciutat.clear();
      char w;
      int y = g.size();
      for(int i = 0; i<y; i++){
         w = g[0];
         nomciutat.push_back(tolower(w));
         g.erase(g.begin() + 0);
      }
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
   string username, password;
   cout<<"Introdueix el teu nom d'usuari, sense fer servir espais."<<endl<<"Nom d'usuari: ";
   cin>>username;
   for (int i = 0; i<nusuaris; i++){
      if(username == usuaris[i].nom){
         cout<<"Ja existeix un usuari amb aquest mateix nom, tria un altre nom d'usuari."<<endl;
         nouusuari(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         return;
      }
   }
   cout<<endl<<"Escull una contrasenya amb lletres i numeros (evitar caracters especials)."<<endl<<"Contrasenya: ";
   cin>>password;
   usuariactual.nom = username;
   usuariactual.contrasenya = password;
   usuaris.push_back(usuariactual);
   nusuaris = usuaris.size();
   pos = nusuaris - 1;
   cout<<endl<<"Benvingut "<<username<<endl;
   finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
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
      cout<<endl<<"Benvingut "<<nomusuari;
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   }
}

void menu1(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   //Menu Inicial
   char seleccio;
   cout<<endl<<"MENU INICIAL: "<<endl;
   cout<<"Indica que vols fer escrivint el numero corresponent"<<endl;
   cout<<"1. Iniciar Sessio"<<endl;
   cout<<"2. Registrar Nou Usuari"<<endl;
   cout<<"3. Esborrar Usuari"<<endl;
   cout<<"4. Sortir"<<endl;

   cout<<"Que vols fer?: ";
   if(cin>>seleccio){
      cout<<endl;
      switch (seleccio){
         case '1': inicisessio(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); return;
            break;
         case '2': nouusuari(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); return;
            break;
         case '3': esborrarusuari(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); return;
            break;
         case '4': finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); cout<<"Gracies per utilitzar ACPODA."; exit(1);
            break;
         default: cout<<"Si us  plau, introdueix un numero valid"; menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); return;
      }//End switch
   }
}

void menu2(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   char seleccio;
   cout<<endl<<endl<<"MENU DE CERCA: "<<endl;
   cout<<"Indica que vols fer escrivint el numero corresponent"<<endl;
   cout<<"1. Cerca una ciutat o pais"<<endl;
   cout<<"2. Compara dos ciutats o paisos"<<endl;
   cout<<"3. Buscar llista de ciutats o paisos preferits"<<endl;
   cout<<"4. Editar perfil"<<endl;
   cout<<"5. Tornar al menu anterior"<<endl;
   cout<<"6. Sortir"<<endl;

   cout<<"Que vols fer?: ";
   cin>>seleccio;
   cout<<endl;
   char eleccio;
   switch (seleccio){
      case '1': eleccio = menupaisociutat();
         switch (eleccio)
         {
         case '1':
            cercapaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         case '2':
            cercaciutat(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         case '3':
            menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         default:
            cout<<"Numero introduit no valid."<<endl;
            menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         }
         break;
      case '2': eleccio = menupaisociutat();
         switch (eleccio)
         {
         case '1':
            comparapaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         case '2':
            comparaciutats(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         case '3':
            menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         default:
            cout<<"Numero introduit no valid."<<endl;
            menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         }
         break;
      case '3': eleccio = menupaisociutat();
         switch (eleccio)
         {
         case '1':
            if(usuariactual.paisospreferits.size() == 0){
               cout<<"No tens cap Pais guardat. ";
               menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            } else {
            paisosguardats(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            }
            break;
         case '2':
            if(usuariactual.ciutatspreferides.size() == 0){
               cout<<"No tens cap ciutat guardada. ";
               menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            } else {
            ciutatsguardades(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            }
            break;
         case '3':
            menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         default:
            cout<<"Numero introduit no valid."<<endl;
            menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         }
         break;
      case '4': editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         break;
      case '5': menu1(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         break;
      case '6': finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos); cout<<"Gracies per utilitzar ACPODA."; exit(1);
         break;
      default: cout<<"Si us  plau, introdueix un numero valid"; menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
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
      UsuarisOUT<<"FIN"<<" ";
      for(int npaisos = 0; npaisos < usuaris[i].paisospreferits.size(); npaisos++){
         UsuarisOUT<<usuaris[i].paisospreferits[npaisos]<<" ";
      }
      UsuarisOUT<<"END"<<endl;
   }
}

int menupaisociutat(){
   char eleccio;
   cout<<endl<<"Vols cercar informacio de ciutats o paisos?"<<endl;
   cout<<"1. Paisos"<<endl;
   cout<<"2. Ciutats"<<endl;
   cout<<"3. Tornar enrere"<<endl;
   cout<<"Introdueix el numero del que vols buscar: ";
   cin>>eleccio;
   return eleccio;
}

void cercaciutat(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   ofstream outfile;
   outfile.open("resultat.txt", std::ios_base::app);
   string nomciutat, seleccio;
   cout<<endl<<"Cercador de ciutats: "<<endl<<"Introdueix el nom de la ciutat que vulguis buscar. Fes servir _ en lloc d'espais."<<endl<<"Ciutat: ";
   cin>>nomciutat;
   string g = nomciutat;
   nomciutat.clear();
   char w;
   int y = g.size();
   for(int i = 0; i<y; i++){
      w = g[0];
      nomciutat.push_back(tolower(w));
      g.erase(g.begin() + 0);
   }
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
      cout<<"Vols tornar a intentar la cerca?  (Si/No): ";
      cin>>seleccio;
      if(seleccio == "Si" || seleccio == "SI" || seleccio == "sI" || seleccio == "Si." || seleccio == "SI." || seleccio == "sI." || seleccio == "si" || seleccio == "si."){
         cercaciutat(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      } else{
         menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         return;
      }
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
      bool ciutatguardada = false;
      for(int i=0; i<usuariactual.ciutatspreferides.size(); i++){
         if(nomciutat == usuariactual.ciutatspreferides[i]){
            ciutatguardada = true;
            break;
         }
      }
      if(!ciutatguardada){
         cout<<"Vols guardar la ciutat entre les teves preferides?  (Si/No): ";
         cin>>seleccio;
         if (seleccio == "Si" || seleccio == "SI" || seleccio == "sI" || seleccio == "Si." || seleccio == "SI." || seleccio == "sI." || seleccio == "si" || seleccio == "si."){
            usuariactual.ciutatspreferides.push_back(nomciutat);
            usuaris[pos] = usuariactual;
            finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         }
      } else if (ciutatguardada){
         cout<<"Ja tens guardada aquesta ciutat."<<endl;
      }
      string eleccio;
      cout<<"Vols guardar aquesta cerca al document resultat.txt ? (Si/No)";
      cin>>eleccio;
      if (eleccio == "Si" || eleccio == "SI" || eleccio == "sI" || eleccio == "Si." || eleccio == "SI." || eleccio == "sI." || eleccio == "si" || eleccio == "si."){
         outfile<<endl<<endl;
         outfile<<endl<<"Poblacio activa de "<<nomciutat<<" per anys (2013-2022):"<<endl;
         int any = 2013;
         for(int x = 0; x<10; x++){
            outfile<<"  "<<any<<": "<<endl;
            outfile<<"    Poblacio activa homes:"<<city.Phomes[x]<<endl;
            outfile<<"    Poblacio activa dones:"<<city.Pdones[x]<<endl;
            outfile<<"    Poblacio activa total:"<<city.Ptotal[x]<<endl;
            any++;
         }
      }
   }
   menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
}

void comparaciutats(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   ofstream outfile;
   outfile.open("resultat.txt", std::ios_base::app);
   string ciutat1, ciutat2;
   ciutat city1, city2;
   int any;
   cout<<endl<<"Comparacio de Ciutats:"<<endl;
   cout<<endl<<"Introdueix l'any en el que vulguis fer la comparacio (2013 - 2022): ";
   cin>>any;
   while(any < 2013 || any > 2022) {
      cout<<endl<<"Introdueix l'any en el que vulguis fer la comparacio (2013 - 2022): ";
      cin>>any;
      if (any < 2013 || any > 2022){
         cout<<"Introdueix un any valid: ";
         comparaciutats(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         return;
      }
   }
   cout<<"Quines dos ciutats vols comparar?"<<endl;
   cout<<"Ciutat 1: ";
   cin>>ciutat1;
   string g = ciutat1;
   ciutat1.clear();
   char w;
   int y = g.size();
   for(int i = 0; i<y; i++){
      w = g[0];
      ciutat1.push_back(tolower(w));
      g.erase(g.begin() + 0);
   }
   bool ciutattrobada = false;
   for(int i = 0; i<ciutats.size(); i++){
      if(ciutats[i].nom == ciutat1){
         ciutattrobada = true;
         city1 = ciutats[i];
         break;
      }
   }
   if (ciutattrobada == false){
      string seleccio;
      cout<<"Ciutat no trobada"<<endl;
      cout<<"Vols tornar a intentar la cerca?  (Si/No): ";
      cin>>seleccio;
      if(seleccio == "Si" || seleccio == "SI" || seleccio == "sI" || seleccio == "Si." || seleccio == "SI." || seleccio == "sI." || seleccio == "si" || seleccio == "si."){
         comparaciutats(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         return;
      } else{
         menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         return;
      }
   }
   if(city1.Ptotal[any-2013] == 0){
      cout<<"No hi ha dades d'aquesta ciutat per a l'any seleccionat. "<<endl;
      comparaciutats(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      return;
   }
   cout<<"Ciutat 2: ";
   cin>>ciutat2;
   g = ciutat2;
   ciutat2.clear();
   y = g.size();
   for(int i = 0; i<y; i++){
      w = g[0];
      ciutat2.push_back(tolower(w));
      g.erase(g.begin() + 0);
   }
   ciutattrobada = false;
   for(int i = 0; i<ciutats.size(); i++){
      if(ciutats[i].nom == ciutat2){
         ciutattrobada = true;
         city2 = ciutats[i];
         break;
      }
   }
   if (ciutattrobada == false){
      string seleccio;
      cout<<"Ciutat no trobada"<<endl;
      cout<<"Vols tornar a intentar la cerca?  (Si/No): ";
      cin>>seleccio;
      if(seleccio == "Si" || seleccio == "SI" || seleccio == "sI" || seleccio == "Si." || seleccio == "SI." || seleccio == "sI." || seleccio == "si" || seleccio == "si."){
         comparaciutats(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      } else{
         menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         return;
      }
   }
   if(city2.Ptotal[any-2013] == 0){
      cout<<"No hi ha dades d'aquesta ciutat per a l'any seleccionat. "<<endl;
      comparaciutats(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      return;
   }
   cout<<endl<<"Poblacio activa "<<ciutat1<<" a l'any "<<any<<endl;
   cout<<"   Homes: "<<city1.Phomes[any - 2013]<<endl;
   cout<<"   Dones: "<<city1.Pdones[any - 2013]<<endl;
   cout<<"   Total: "<<city1.Ptotal[any - 2013]<<endl;
   cout<<endl<<"Poblacio activa "<<ciutat2<<" a l'any "<<any<<endl;
   cout<<"   Homes: "<<city2.Phomes[any - 2013]<<endl;
   cout<<"   Dones: "<<city2.Pdones[any - 2013]<<endl;
   cout<<"   Total: "<<city2.Ptotal[any - 2013]<<endl<<endl;
   if(city1.Phomes[any - 2013] > city2.Phomes[any - 2013]) {
      double percent = (double(city1.Phomes[any - 2013]))/(double(city2.Phomes[any - 2013]))*100.00 - 100.00;
      cout<<"La poblacio activa d'homes de "<<city1.nom<<" es un "<<percent<<"% mes gran."<<endl;
   } else if (city1.Phomes[any - 2013] < city2.Phomes[any - 2013]) {
      double percent = (double(city2.Phomes[any - 2013]))/(double(city1.Phomes[any - 2013]))*100 - 100.00;
      cout<<"La poblacio activa d'homes de "<<city2.nom<<" es un "<<percent<<"% mes gran."<<endl;
   }
   if(city1.Pdones[any - 2013] > city2.Pdones[any - 2013]) {
      double percent = (double(city1.Pdones[any - 2013])/(city2.Pdones[any - 2013]))*100 - 100.00;
      cout<<"La poblacio activa de dones de "<<city1.nom<<" es un "<<percent<<"% mes gran."<<endl;
   } else if (city1.Pdones[any - 2013] < city2.Pdones[any - 2013]) {
      double percent = (double(city2.Pdones[any - 2013])/(city1.Pdones[any - 2013]))*100 - 100.00;
      cout<<"La poblacio activa de dones de "<<city2.nom<<" es un "<<percent<<"% mes gran."<<endl;
   }
   if(city1.Ptotal[any - 2013] > city2.Ptotal[any - 2013]) {
      double percent = (double(city1.Ptotal[any - 2013]))/(double(city2.Ptotal[any - 2013]))*100 - 100.00;
      cout<<"La poblacio activa total de "<<city1.nom<<" es un "<<percent<<"% mes gran."<<endl<<endl;
   } else if (city1.Ptotal[any - 2013] < city2.Ptotal[any - 2013]) {
      double percent = (double(city2.Ptotal[any - 2013]))/(double(city1.Ptotal[any - 2013]))*100 - 100.00;
      cout<<"La poblacio activa total de "<<city2.nom<<" es un "<<percent<<"% mes gran."<<endl<<endl<<endl;
   }
   string eleccio;
   cout<<"Vols guardar aquesta cerca al document resultat.txt ? (Si/No)";
   cin>>eleccio;
   if (eleccio == "Si" || eleccio == "SI" || eleccio == "sI" || eleccio == "Si." || eleccio == "SI." || eleccio == "sI." || eleccio == "si" || eleccio == "si."){
      outfile<<endl<<endl;
      outfile<<"Poblacio activa "<<ciutat1<<" a l'any "<<any<<endl;
      outfile<<"   Homes: "<<city1.Phomes[any - 2013]<<endl;
      outfile<<"   Dones: "<<city1.Pdones[any - 2013]<<endl;
      outfile<<"   Total: "<<city1.Ptotal[any - 2013]<<endl;
      outfile<<endl<<"Poblacio activa "<<ciutat2<<" a l'any "<<any<<endl;
      outfile<<"   Homes: "<<city2.Phomes[any - 2013]<<endl;
      outfile<<"   Dones: "<<city2.Pdones[any - 2013]<<endl;
      outfile<<"   Total: "<<city2.Ptotal[any - 2013]<<endl<<endl;
      if(city1.Phomes[any - 2013] > city2.Phomes[any - 2013]) {
         double percent = (double(city1.Phomes[any - 2013]))/(double(city2.Phomes[any - 2013]))*100.00 - 100.00;
         outfile<<"La poblacio activa d'homes de "<<city1.nom<<" es un "<<percent<<"% mes gran."<<endl;
      } else if (city1.Phomes[any - 2013] < city2.Phomes[any - 2013]) {
         double percent = (double(city2.Phomes[any - 2013]))/(double(city1.Phomes[any - 2013]))*100 - 100.00;
         outfile<<"La poblacio activa d'homes de "<<city2.nom<<" es un "<<percent<<"% mes gran."<<endl;
      }
      if(city1.Pdones[any - 2013] > city2.Pdones[any - 2013]) {
         double percent = (double(city1.Pdones[any - 2013])/(city2.Pdones[any - 2013]))*100 - 100.00;
         outfile<<"La poblacio activa de dones de "<<city1.nom<<" es un "<<percent<<"% mes gran."<<endl;
      } else if (city1.Pdones[any - 2013] < city2.Pdones[any - 2013]) {
         double percent = (double(city2.Pdones[any - 2013])/(city1.Pdones[any - 2013]))*100 - 100.00;
         outfile<<"La poblacio activa de dones de "<<city2.nom<<" es un"<<percent<<"% mes gran."<<endl;
      }
      if(city1.Ptotal[any - 2013] > city2.Ptotal[any - 2013]) {
         double percent = (double(city1.Ptotal[any - 2013]))/(double(city2.Ptotal[any - 2013]))*100 - 100.00;
         outfile<<"La poblacio activa total de "<<city1.nom<<" es un "<<percent<<"% mes gran."<<endl<<endl;
      } else if (city1.Ptotal[any - 2013] < city2.Ptotal[any - 2013]) {
         double percent = (double(city2.Ptotal[any - 2013]))/(double(city1.Ptotal[any - 2013]))*100 - 100.00;
         outfile<<"La poblacio activa total de "<<city2.nom<<" es un "<<percent<<"% mes gran."<<endl<<endl<<endl;
      }
   }
   menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
}

void ciutatsguardades(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   ofstream outfile;
   outfile.open("resultat.txt", std::ios_base::app);
   int seleccio;
   cout<<endl<<"Ciutats preferides: "<<endl;
   for(int i=0; i<usuariactual.ciutatspreferides.size(); i++){
      cout<<i+1<<". "<<usuariactual.ciutatspreferides[i]<<endl;
   }
   cout<<usuariactual.ciutatspreferides.size()+1<<". Tornar enrere"<<endl;
   cout<<"Introdueix el numero de la ciutat que vulguis buscar: ";
   cin>>seleccio;
   if(seleccio == (usuariactual.ciutatspreferides.size() + 1)){
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      return;
   }
   else if(seleccio>(usuariactual.ciutatspreferides.size() + 1) || seleccio == 0){
      cout<<endl<<"Numero incorrecte"<<endl;
      ciutatsguardades(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      return;
   }

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
      cout<<"Ciutat no trobada a la base de dades"<<endl<<endl;
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
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
   string eleccio;
   cout<<"Vols guardar aquesta cerca al document resultat.txt ? (Si/No)";
   cin>>eleccio;
   if (eleccio == "Si" || eleccio == "SI" || eleccio == "sI" || eleccio == "Si." || eleccio == "SI." || eleccio == "sI." || eleccio == "si" || eleccio == "si."){
      outfile<<endl<<endl;
      outfile<<endl<<"Poblacio activa de "<<nomciutat<<" per anys (2013-2022):"<<endl;
      int any = 2013;
      for(int x = 0; x<10; x++){
         outfile<<"  "<<any<<": "<<endl;
         outfile<<"    Poblacio activa homes:"<<city.Phomes[x]<<endl;
         outfile<<"    Poblacio activa dones:"<<city.Pdones[x]<<endl;
         outfile<<"    Poblacio activa total:"<<city.Ptotal[x]<<endl;
         any++;
      }
   }
   menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
}

void editarperfil(string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   char seleccio;
   string contranova;
   cout<<endl<<"Que vols editar? "<<endl;
   cout<<"1. Nom d'usuari"<<endl;
   cout<<"2. Contrasenya"<<endl;
   cout<<"3. Eliminar paisos/ciutats preferides"<<endl;
   cout<<"4. Eliminar usuari"<<endl;
   cout<<"5. Tornar al menu anterior"<<endl;
   cout<<"Introdueix el numero: ";
   cin>>seleccio;
   switch (seleccio)
   {
   case '1':
      cout<<endl<<"Nou nom d'usuari: ";
      cin>>nomusuari;
      usuariactual.nom = nomusuari;
      usuaris[pos] = usuariactual;
      finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      break;
   case '2':
      cout<<endl<<"Nova contrasenya: ";
      cin>>contranova;
      usuariactual.contrasenya = contranova;
      usuaris[pos] = usuariactual;
      finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      break;
   case '3':
      char eleccio;
      eleccio = menupaisociutat();
         switch (eleccio)
         {
         case '1':
            if(usuariactual.paisospreferits.size() == 0){
               cout<<"No ten cap pais guardat"<<endl;
               editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
               return;
            } else {
               cout<<endl<<"Paisos preferits: "<<endl;
               for(int i=0; i<usuariactual.paisospreferits.size(); i++){
               cout<<i+1<<". "<<usuariactual.paisospreferits[i]<<endl;
               }
               cout<<(usuariactual.paisospreferits.size()+1)<<". Tornar enrere."<<endl;
               cout<<endl<<"Introdueix el numero del pais que vulguis eliminar: ";
               int choice;
               cin>>choice;
               if(choice>usuariactual.paisospreferits.size() || choice<0){
                  cout<<"Nombre no valid. "<<endl;
                  editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
                  return;
               } else if (choice == usuariactual.paisospreferits.size()) {
                  menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
                  return;
               }
               usuariactual.paisospreferits.erase(usuariactual.paisospreferits.begin() + (choice - 1));
               usuaris[pos] = usuariactual;
               editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            }
            break;
         case '2':
            if(usuariactual.ciutatspreferides.size() == 0){
               cout<<"No ten cap ciutat guardada"<<endl;
               editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
               return;
            } else {
               cout<<endl<<"Ciutats preferides: "<<endl;
               for(int i=0; i<usuariactual.ciutatspreferides.size(); i++){
               cout<<i+1<<". "<<usuariactual.ciutatspreferides[i]<<endl;
               }
               cout<<(usuariactual.ciutatspreferides.size()+1)<<". Tornar enrere."<<endl;
               cout<<endl<<"Introdueix el numero de la ciutat que vulguis eliminar: ";
               int choice;
               cin>>choice;
               if(choice>usuariactual.ciutatspreferides.size() || choice<0){
                  cout<<"Nombre no valid. "<<endl;
                  editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
                  return;
               } else if (choice == usuariactual.ciutatspreferides.size()) {
                  menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
                  return;
               }
               usuariactual.ciutatspreferides.erase(usuariactual.ciutatspreferides.begin() + (choice - 1));
               usuaris[pos] = usuariactual;
               editarperfil(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            }
            break;
         default:
            cout<<"Numero introduit no valid."<<endl;
            menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
            break;
         }
   case '4':
      esborrarusuari(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      break;
   case '5':
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      break;
   default:
      cout<<endl<<"Si us  plau, introdueix un numero valid"<<endl;
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      break;
   }
}

void llegirpaisos (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   ifstream pactivapaisosIN("poblacioactivapaisos.csv");
   ifstream ptotalpaisosIN("poblaciontotalpaises.csv");
   string nompais, codipais, g;
   int any1, any2, any3, any4, any5, any6, any7, any8, any9, any10;
   long long int pactivatotal, pactivapaisos;
   pactivapaisosIN>>nompais>>codipais>>any1>>any2>>any3>>any4>>any5>>any6>>any7>>any8>>any9>>any10;
   ptotalpaisosIN>>nompais>>codipais>>any1>>any2>>any3>>any4>>any5>>any6>>any7>>any8>>any9>>any10;
   while(ptotalpaisosIN>>nompais){
      pais x;
      g = nompais;
      nompais.clear();
      char w;
      int y = g.size();
      for(int i = 0; i<y; i++){
         w = g[0];
         nompais.push_back(tolower(w));
         g.erase(g.begin() + 0);
      }
      x.nom = nompais;
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
   ofstream outfile;
   outfile.open("resultat.txt", std::ios_base::app);
   int seleccio;
   cout<<endl<<"Paisos preferits: "<<endl;
   for(int i=0; i<usuariactual.paisospreferits.size(); i++){
      cout<<i+1<<". "<<usuariactual.paisospreferits[i]<<endl;
   }
      cout<<usuariactual.paisospreferits.size()+1<<". Tornar enrere"<<endl;
   cout<<"Introdueix el numero del pais que vulguis buscar: ";
   cin>>seleccio;
   if(seleccio == (usuariactual.paisospreferits.size() + 1)){
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      return;
   }
   else if(seleccio>(usuariactual.paisospreferits.size() + 1) || seleccio == 0){
      cout<<endl<<"Numero incorrecte"<<endl;
      paisosguardats (name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      return;
   }
   pais country;
   string nompais = usuariactual.paisospreferits[seleccio-1];
   int npaisos = paisos.size();
   bool paistrobat = false;
   for(int i = 0; i<npaisos; i++){
      if(paisos[i].nom == nompais){
         paistrobat = true;
         country = paisos[i];
         break;
      }
   }
   if(paistrobat == false){
      cout<<"Pais no trobat a la base de dades"<<endl<<endl;
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   } else if(paistrobat == true){
      cout<<endl<<endl<<"Poblacio activa de "<<nompais<<" per anys (2013-2022):"<<endl;
      int any = 2013;
      for(int x = 0; x<10; x++){
         cout<<"  "<<any<<": "<<endl;
         cout<<"    Poblacio activa:"<<country.pactiva[x]<<endl;
         cout<<"    Poblacio total:"<<country.ptotal[x]<<endl;
      }
   }
   string eleccio;
   cout<<"Vols guardar aquesta cerca al document resultat.txt ? (Si/No)";
   cin>>eleccio;
   if (eleccio == "Si" || eleccio == "SI" || eleccio == "sI" || eleccio == "Si." || eleccio == "SI." || eleccio == "sI." || eleccio == "si" || eleccio == "si."){
      outfile<<endl<<endl;
      outfile<<endl<<endl<<"Poblacio activa de "<<nompais<<" per anys (2013-2022):"<<endl;
      int any = 2013;
      for(int x = 0; x<10; x++){
         outfile<<"  "<<any<<": "<<endl;
         outfile<<"    Poblacio activa:"<<country.pactiva[x]<<endl;
         outfile<<"    Poblacio total:"<<country.ptotal[x]<<endl;
      }
   }
   menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
};

void comparapaisos (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   ofstream outfile;
   outfile.open("resultat.txt", std::ios_base::app);
   string pais1, pais2;
   pais country1, country2;
   int any;
   cout<<endl<<"Comparacio de paisos:"<<endl;
   cout<<endl<<"Introdueix l'any en el que vulguis fer la comparacio (2013 - 2022): ";
   cin>>any;
   while(any < 2013 || any > 2022) {
      cout<<endl<<"Introdueix l'any en el que vulguis fer la comparacio (2013 - 2022): ";
      cin>>any;
      if (any < 2013 || any > 2022){
         cout<<"Introdueix un any valid: ";
      }
   }
   cout<<"Quins dos paisos vols comparar?"<<endl;
   cout<<"Pais 1: ";
   cin>>pais1;
   string g = pais1;
   pais1.clear();
   char w;
   int y = g.size();
   for(int i = 0; i<y; i++){
      w = g[0];
      pais1.push_back(tolower(w));
      g.erase(g.begin() + 0);
   }
   bool paistrobat = false;
   for(int i = 0; i<paisos.size(); i++){
      if(paisos[i].nom == pais1){
         paistrobat = true;
         country1 = paisos[i];
         break;
      }
   }
   if (paistrobat == false){
      string seleccio;
      cout<<"Pais no trobat"<<endl;
      cout<<"Vols tornar a intentar la cerca? (Si/No): ";
      cin>>seleccio;
      if(seleccio == "Si" || seleccio == "SI" || seleccio == "sI" || seleccio == "Si." || seleccio == "SI." || seleccio == "sI." || seleccio == "si" || seleccio == "si."){
         comparapaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      } else{
         menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         return;
      }
   }
   if(country1.ptotal[any-2013] == 0){
      cout<<"No hi ha dades d'aquest pais per a l'any seleccionat. "<<endl;
      comparapaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      return;
   }
   cout<<"Pais 2: ";
   cin>>pais2;
   g = pais2;
   pais2.clear();
   y = g.size();
   for(int i = 0; i<y; i++){
      w = g[0];
      pais2.push_back(tolower(w));
      g.erase(g.begin() + 0);
   }
   paistrobat = false;
   for(int i = 0; i<paisos.size(); i++){
      if(paisos[i].nom == pais2){
         paistrobat = true;
         country2 = paisos[i];
         break;
      }
   }
   if (paistrobat == false){
      string seleccio;
      cout<<"Pais no trobat"<<endl;
      cout<<"Vols tornar a intentar la cerca? (Si/No): ";
      cin>>seleccio;
      if(seleccio == "Si" || seleccio == "SI" || seleccio == "sI" || seleccio == "Si." || seleccio == "SI." || seleccio == "sI." || seleccio == "si" || seleccio == "si."){
         comparapaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      } else{
         menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         return;
      }
   }
   if(country2.ptotal[any-2013] == 0){
      cout<<"No hi ha dades d'aquest pais per a l'any seleccionat. "<<endl;
      comparapaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      return;
   }
   cout<<endl<<"Poblacio activa i total "<<pais1<<" a l'any "<<any<<endl;
   cout<<"   Activa: "<<country1.pactiva[any - 2013]<<endl;
   cout<<"   Total: "<<country1.ptotal[any - 2013]<<endl;
   cout<<endl<<"Poblacio activa i total "<<pais2<<" a l'any "<<any<<endl;
   cout<<"   Activa: "<<country2.pactiva[any - 2013]<<endl;
   cout<<"   Total: "<<country2.ptotal[any - 2013]<<endl<<endl;

   if(country1.pactiva[any - 2013] > country2.pactiva[any - 2013]) {
      double percent = (double(country1.pactiva[any - 2013]))/(double(country2.pactiva[any - 2013]))*100.00 - 100.00;
      cout<<"La poblacio activa de "<<country1.nom<<" es un "<<percent<<"% mes gran."<<endl;
   } else if (country1.pactiva[any - 2013] < country2.pactiva[any - 2013]) {
      double percent = (double(country2.pactiva[any - 2013]))/(double(country1.pactiva[any - 2013]))*100 - 100.00;
      cout<<"La poblacio activa de "<<country2.nom<<" es un "<<percent<<"% mes gran."<<endl;
   }
   if(country1.ptotal[any - 2013] > country2.ptotal[any - 2013]) {
      double percent = (double(country1.ptotal[any - 2013]))/(double(country2.ptotal[any - 2013]))*100 - 100.00;
      cout<<"La poblacio total de "<<country1.nom<<" es un "<<percent<<"% mes gran."<<endl<<endl;
   } else if (country1.ptotal[any - 2013] < country2.ptotal[any - 2013]) {
      double percent = (double(country2.ptotal[any - 2013]))/(double(country1.ptotal[any - 2013]))*100 - 100.00;
      cout<<"La poblacio total de "<<country2.nom<<" es un "<<percent<<"% mes gran."<<endl<<endl<<endl;
   }
   string eleccio;
   cout<<"Vols guardar aquesta cerca al document resultat.txt ? (Si/No)";
   cin>>eleccio;
   if (eleccio == "Si" || eleccio == "SI" || eleccio == "sI" || eleccio == "Si." || eleccio == "SI." || eleccio == "sI." || eleccio == "si" || eleccio == "si."){
      outfile<<endl<<endl;
      outfile<<"Poblacio activa i total "<<pais1<<" a l'any "<<any<<endl;
      outfile<<"   Activa: "<<country1.pactiva[any - 2013]<<endl;
      outfile<<"   Total: "<<country1.ptotal[any - 2013]<<endl;
      outfile<<endl<<"Poblacio activa i total "<<pais2<<" a l'any "<<any<<endl;
      outfile<<"   Activa: "<<country2.pactiva[any - 2013]<<endl;
      outfile<<"   Total: "<<country2.ptotal[any - 2013]<<endl<<endl;

      if(country1.pactiva[any - 2013] > country2.pactiva[any - 2013]) {
         double percent = (double(country1.pactiva[any - 2013]))/(double(country2.pactiva[any - 2013]))*100.00 - 100.00;
         outfile<<"La poblacio activa de "<<country1.nom<<" es un "<<percent<<"% mes gran."<<endl;
      } else if (country1.pactiva[any - 2013] < country2.pactiva[any - 2013]) {
         double percent = (double(country2.pactiva[any - 2013]))/(double(country1.pactiva[any - 2013]))*100 - 100.00;
         outfile<<"La poblacio activa de "<<country2.nom<<" es un "<<percent<<"% mes gran."<<endl;
      }
      if(country1.ptotal[any - 2013] > country2.ptotal[any - 2013]) {
         double percent = (double(country1.ptotal[any - 2013]))/(double(country2.ptotal[any - 2013]))*100 - 100.00;
         outfile<<"La poblacio total de "<<country1.nom<<" es un "<<percent<<"% mes gran."<<endl<<endl;
      } else if (country1.ptotal[any - 2013] < country2.ptotal[any - 2013]) {
         double percent = (double(country2.ptotal[any - 2013]))/(double(country1.ptotal[any - 2013]))*100 - 100.00;
         outfile<<"La poblacio total de "<<country2.nom<<" es un "<<percent<<"% mes gran."<<endl<<endl<<endl;
      }
   }
   menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
};

void cercapaisos (string& name, string& nomusuari, int& nusuaris, vector<usuari>& usuaris, vector<ciutat>& ciutats, usuari& usuariactual, int& pos, vector<pais>& paisos){
   ofstream outfile;
   outfile.open("resultat.txt", std::ios_base::app);
   string nompais, seleccio;
   cout<<endl<<"Cercador de paisos: "<<endl<<"Introdueix el nom del pais que vulguis buscar. Fes servir _ en lloc d'espais."<<endl<<"Pais: ";
   cin>>nompais;
   string g = nompais;
   nompais.clear();
   char w;
   int y = g.size();
   for(int i = 0; i<y; i++){
      w = g[0];
      nompais.push_back(tolower(w));
      g.erase(g.begin() + 0);
   }
   pais country;
   int npaisos = paisos.size();
   bool paistrobat = false;
   for(int i = 0; i<npaisos; i++){
      if(paisos[i].nom == nompais){
         paistrobat = true;
         country = paisos[i];
         break;
      }
   }
   if(paistrobat == false){
      cout<<endl<<"Pais no trobat a la base de dades."<<endl;
      cout<<"Vols tornar a intentar la cerca?  (Si/No): ";
      cin>>seleccio;
      if(seleccio == "Si" || seleccio == "SI" || seleccio == "sI" || seleccio == "Si." || seleccio == "SI." || seleccio == "sI." || seleccio == "si" || seleccio == "si."){
         cercapaisos(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
      } else{
         menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         return;
      }
   } else if(paistrobat == true){
      cout<<endl<<"Poblacio activa i total de "<<nompais<<" per anys (2013-2022):"<<endl;
      int any = 2013;
      for(int x = 0; x<10; x++){
         cout<<"  "<<any<<": "<<endl;
         cout<<"    Poblacio activa: "<<country.pactiva[x]<<endl;
         cout<<"    Poblacio total: "<<country.ptotal[x]<<endl;
         any++;
      }
      bool paisguardat = false;
      for(int i=0; i<usuariactual.paisospreferits.size(); i++){
         if(nompais == usuariactual.paisospreferits[i]){
            paisguardat = true;
            break;
         }
      }
      if(!paisguardat){
         cout<<"Vols guardar el pais entre els teus preferits? (Si/No): ";
         cin>>seleccio;
         if (seleccio == "Si" || seleccio == "SI" || seleccio == "sI" || seleccio == "Si." || seleccio == "SI." || seleccio == "sI." || seleccio == "si" || seleccio == "si."){
            usuariactual.paisospreferits.push_back(nompais);
            usuaris[pos] = usuariactual;
            finalitzar(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
         }
      } else if (paisguardat){
         cout<<"Ja tens guardat aquest pais."<<endl;
      }
      string eleccio;
      cout<<"Vols guardar aquesta cerca al document resultat.txt ? (Si/No)";
      cin>>eleccio;
      if (eleccio == "Si" || eleccio == "SI" || eleccio == "sI" || eleccio == "Si." || eleccio == "SI." || eleccio == "sI." || eleccio == "si" || eleccio == "si."){
         outfile<<endl<<endl;
         outfile<<endl<<"Poblacio activa i total de "<<nompais<<" per anys (2013-2022):"<<endl;
         int any = 2013;
         for(int x = 0; x<10; x++){
            outfile<<"  "<<any<<": "<<endl;
            outfile<<"    Poblacio activa: "<<country.pactiva[x]<<endl;
            outfile<<"    Poblacio total: "<<country.ptotal[x]<<endl;
            any++;
         }
      }
      menu2(name, nomusuari, nusuaris, usuaris, ciutats, usuariactual, pos, paisos);
   }
};