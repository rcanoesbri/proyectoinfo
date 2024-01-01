#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void alta (bool& t);
void baixa (bool& t);


struct poblacio{ //TUPLA ON ES GUARDEN LES DADES DE LA POBLACIÓ
   int years;
   double Ptotal;
   double Phomes;
   double Pdones;
};


int main (){
   //DECLAREM LES VARIABLES
string name;
int basic;
bool sortir, t=false;

   //MISSATGES INICIALS PER PANTALLA
cout<<"Et donem la benvinguda a la base de dades ___, on podras trobar informacio sobre la poblacio activa de diverses ciutats europees."<<endl;
cout<<"Si us plau, ingresa el teu nom: ";

   //RECONEIXEMENT DE L'USUARI
cin>>name;
cout<<""<<endl;
cout<<"Hola "<<name<<"."<<endl;
cout<<"Indica que vols fer escrivint el numero corresponent"<<endl;

   //MENÚ BÀSIC
while (!t){
 cout<<"1. Alta d'usuari"<<endl;
 cout<<"2. Baixa d'usuari"<<endl;
 cout<<"3. Sortir"<<endl;

 cout<<"Que vols fer?: ";
 cin>>basic;
 cout<<endl;

 switch (basic){
   case 1: t=true; alta(t);
      break;
   case 2: t=true; baixa(t);
      break;
   case 3: t=true; cout<<"Gracies per utilitzar ___."; sortir=true;
      break;
   default: cout<<"Si us  plau, introdueix un numero valid"<<endl;
   }//End switch
 }//End While
}//End main



//ACCIÓ ALTA
void alta (bool& t){
  //Variables propies de l'accio
  int numalta;

  //Dialegs inicials de l'accio
  cout<<"MENU D'ALTA"<<endl;
  cout<<"Indica que vols fer escrivint el numero corresponent"<<endl;

  //Menu Alta
  t=false;
  while (!t){
   cout<<"1. Iniciar sessio"<<endl;
   cout<<"2. Registrar nou usuari"<<endl;
   cout<<"3. Sortir"<<endl;

  cout<<"Que vols fer?: ";
  cin>>numalta;

 switch (numalta){
   case 1: t=true;
      break;
   case 2: t=true;
      break;
   case 3: t=true; cout<<endl<<"MENU D'INICI"<<endl;
      break;
   default: cout<<"Si us  plau, introdueix un numero valid"<<endl;
   }//End switch
 }//End While
t=false;
}



//ACCIÓ ALTA
void baixa (bool& t){
  //Variables propies de l'accio
  int numbaixa;

  //Dialegs inicials de l'accio
  cout<<"MENU DE BAIXA"<<endl;
  cout<<"Indica que vols fer escrivint el numero corresponent"<<endl;

  //Menu Alta
  t=false;
  while (!t){
   cout<<"1. Eliminar usuari"<<endl;
   cout<<"2. Sortir"<<endl;

  cout<<"Que vols fer?: ";
  cin>>numbaixa;

 switch (numbaixa){
   case 1: t=true;
      break;
   case 2: t=true; cout<<endl<<"MENU D'INICI"<<endl;
      break;
   default: cout<<"Si us  plau, introdueix un numero valid"<<endl;
   }//End switch
 }//End While
t=false;
}
