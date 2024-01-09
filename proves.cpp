#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    string palabra = "Hol";
    palabra.push_back('a');
    cout<<palabra<<endl;
    int x = palabra.size();
    for( int i = 0; i<x; i++){
        palabra.pop_back();
        cout<<palabra<<endl;
    }
}