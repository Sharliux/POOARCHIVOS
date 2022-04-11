#include "Persona.cpp"
#include <iostream>
using namespace std;

class Estudiante : Persona {
	private : int codigo;

	public :
	
		Estudiante(string nom,string ape,string dir,int tel, int cod) : Persona(nom,ape,dir,tel){
			codigo = cod;
		}

		void setCodigo(int cod){codigo = cod;}	
		void setNombres(string nom){nombres = nom;}
		void setApellidos(string ape){apellidos = ape;}
		void setDireccion(string dir){direccion = dir;}
		void setTelefono(int tel){telefono = tel;}	
		
		int getCodigo(){return codigo;}
		string getNombres(){return nombres;}
		string getApellidos(){return apellidos;}
		string getDireccion(){return direccion;}
		int getTelefono(){return telefono;}
		void mostrar(){
			cout<<"______________________"<<endl;
			cout<<codigo<<","<<nombres<<","<<apellidos<<","<<direccion<<","<<telefono<<endl;
		}
};
