# Proyecto Informática
  ### &nbsp;&nbsp;&nbsp; `Raúl Cano, Iker Doblas`
  ### &nbsp;&nbsp;&nbsp; `GrEVA - ESEIAAT - UPC`


## Tema: Població activa en ciutats i països d'Europa per sexes
El tema escollit ens permetrà organitzar una informació que pot ser de gran utilitat per
conèixer com està repartida la població a Europa i els patrons de gènere en la seva
evolució. Aquest coneixement pot ser de gran utilitat per predir en un futur pròxim com
evolucionarà demogràficament una regió, país o població concreta observant la seva
tendència en els anys anteriors. La cerca d’aquesta informació es farà variada i intuïtiva
gràcies al programa que donarà accés a filtrar les cerques segons el que vulgui l’usuari.

## Dades: (.xlsx)
Les dades han estat extretes de la base de dades DataEuropa i de ropa i de
https://www.bancomundial.org/es/home

- [Població Activa Total](https://docs.google.com/spreadsheets/d/1ZB8_-k0fX_-CrioSKYTamxH_YginviXG/edit#gid=1213063332)

- [Població Activa Homes](https://docs.google.com/spreadsheets/d/1BA49W5PgTZ-HYTZ75VWgO2pJtmDEJATZ/edit#gid=1911124909)

- [Població Activa Dones](https://docs.google.com/spreadsheets/d/1jwPTAQJ1xkP8atdHIibBxzgmWL7w45_I/edit#gid=1368044712)

- [Població Activa Països Europeus](https://datos.bancomundial.org/indicator/SL.TLF.TOTL.IN?end=2022&locations=EU&most_recent_year_desc=false&start=1990)
  
- [Població Total Països Europeus](https://datos.bancomundial.org/indicator/SP.POP.TOTL?end=2022&locations=EU&most_recent_year_desc=false&start=2013)

## Entitats:
Tenint en compte les dades recopilades hem definit les tres entitats següents, que permetran a l’usuari trobar informació amb relació a la població activa a Europa per ciutats o per països, podent en el primer cas trobar la informació dividida per sexes.
- Ciutats europees
- Països europeus
- Usuari


## Vectors i tuples:

1. Tupla pais:
   
   a) Nom del pais (string nom)
   
   b) Codi del pais (string codipais)
   
   c) Població activa (Vector <long long int> pactiva)
   
   d) Població total (Vector <long long int> ptotal)
   
3. Tupla ciutat:
   
   a) Nom de la ciutat (string nom)
   
   b) Població total (Vector <long long int> Ptotal)
   
   c) Població homes (Vector <long long int> Phomes)
   
   d) Població dones (Vector <long long int> Pdones)
   
5. Tupla usuari:
   
   a) Nom de l’usuari (string nom)
   
   b) Contrasenya de l’usuari (string contrasenya)
   
   c) Ciutats preferides (Vector <string> ciutatspreferides)
   
   d) Països preferits (Vector <string> paisospreferits)



## Funciones Proyecto:
   -   **Estudi població activa d’homes i dones de ciutats europees entre 2013 i 2022**

&nbsp;&nbsp;&nbsp;F1   Variació de la població activa total, d’homes i de dones en l’interval d’anys entre 2013 i 2022

&nbsp;&nbsp;&nbsp;F2   Treure les dades en aquest interval en un fitxer txt.

&nbsp;&nbsp;&nbsp;F3   Desar la població com a preferida

   -   **Estudi comparatiu de la població activa respecte de la total en països europeus entre 2013 i 2022**
     
&nbsp;&nbsp;&nbsp;F3   Creixements i decreixements de la població total i activa d’un país europeu entre 2013 i 2022

&nbsp;&nbsp;&nbsp;F2   Treure les dades en aquest interval en un fitxer txt.

&nbsp;&nbsp;&nbsp;F3   Desar la població com a preferida

  -    **Comparació entre dues ciutats europees de la població d’homes i dones en un any determinat**

&nbsp;&nbsp;&nbsp;F4  Comparació de les dades de la població activa total, d’homes i dones de dues ciutats en un any determinat escollit per l’usuari

&nbsp;&nbsp;&nbsp;F5  % de superació de la població activa total, d’homes i de dones de la ciutat més poblada en cada aspecte sobre la menys poblada.

  -   **Comparació de la població activa i total de dos països europeus en un any concret**
    
&nbsp;&nbsp;&nbsp;F6  Comparació de la població total i activa de dos països europeus en un any concret

&nbsp;&nbsp;&nbsp;F7  % de la població total i activa del país més poblat en cada aspecte sobre el menys poblat

   -   **Veure les dades de la població de les ciutats desades com a preferides**
     
&nbsp;&nbsp;&nbsp;F8   Ciutats → Població activa total, d’homes i de dones entre 2013 i 2022

&nbsp;&nbsp;&nbsp;F9   Països → Població total i activa entre 2013 i 2022
