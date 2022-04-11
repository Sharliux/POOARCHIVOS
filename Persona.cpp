#include <iostream>
using namespace std;
	class Persona {

		protected : string nombres, apellidos, direccion;
				int telefono;

		protected :	
			Persona (string nom, string ape, string dir, int tel){
				nombres = nom;
				apellidos = ape;
				telefono = tel;
				direccion = dir;
				
				
			}	
			
	//metodo
	void mostrar();
};
