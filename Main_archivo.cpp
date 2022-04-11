#include <iostream>
#include <stdio.h>  
#include <string.h>
#include "Estudiante.cpp"
using namespace std;
const char *nombe_archivo = "archivo.dat";
	int opcion=0;
	int cod;
	struct Student {
	int codigo;
	char nombres[50];
	char apellidos[50];
	char direccion[20];
	int telefono;
	

};
 void menu_student();
 void ingresar_student();
 void abrir_student();
 void modificar_student();
 void buscar_codigo();
 void eliminar_student(); 
 main(){

menu_student();	
}

void menu_student(){
	system("cls");
cout<<"\t____________MENU DE OPCIONES____________"<<endl;
cout<<"\t\t1. Crear estudiante"<<endl;
cout<<"\t\t2. ver estudiantes"<<endl;
cout<<"\t\t3. Actualizar estudiante"<<endl;
cout<<"\t\t4. Buscar estudiante"<<endl;
cout<<"\t\t6. Salir"<<endl<<endl;
cout<<"\t\t\tDigite su opcion: ";
cin>>opcion; 
			
	system("cls");
	
	switch(opcion)
	{
		case 1: ingresar_student();		 	;break;
 		case 2: abrir_student();				;break;
 		case 3: modificar_student();	 		;break;
 		case 4: buscar_codigo();				;break;
 		case 5: exit(-1);				;break;  
		default:cout<<"Opcion no valida";  
	}
}

void abrir_student(){
	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Student student;
	int registro=0;
	fread ( &student, sizeof(Student), 1, archivo );
	cout<<"________________________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<<"      NOMBRE      "<<" "<<"      APELLIDO      "<<" "<<"      Direccion      "<<"  "<<"      TELEFONO      "<<" "<<endl;	
		do{
		cout<<"____________________________________________________________________________"<<endl;
		cout << registro <<" |  "<< student.codigo <<"  |  "<< student.nombres<<"    "<<student.apellidos<< "      "<<student.direccion<<"     "<<student.telefono<<endl;
        
        
		fread ( &student, sizeof(Student), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
		system("pause");
		
		menu_student();
	}

void ingresar_student(){
	
char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); 
	
	
		Student student;
		 string nombre,apellido,direccion;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo: ";
		cin>>student.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre: ";
		getline(cin,nombre);
    	strcpy(student.nombres, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido: ";
		getline(cin,apellido);
		strcpy(student.apellidos, apellido.c_str()); 
		
		cout<<"Ingrese la Direccion: ";
		cin>>student.direccion;
		cin.ignore();
		
		cout<<"Ingrese el Telefono: ";
		cin>>student.telefono;
		cin.ignore();
		
		fwrite( &student, sizeof(Student), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_student();	
	buscar_codigo();
	system("pause");
		
		menu_student();
	
}
		void modificar_student(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido,direccion;	
    	Student student;
    
		cout<<"Ingrese el Codigo: ";
		cin>>student.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre: ";
		getline(cin,nombre);
    	strcpy(student.nombres, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido: ";
		getline(cin,apellido);
		strcpy(student.apellidos, apellido.c_str()); 
		
		cout<<"Ingrese la Direccion: ";
		cin>>student.direccion;
		cin.ignore();
		
		cout<<"Ingrese el Telefono: ";
		cin>>student.telefono;
		cin.ignore();
		
		fwrite( &student, sizeof(Student), 1, archivo );
		
		fclose(archivo);
	
		system("pause");
		
		menu_student();
}
void buscar_codigo(){
	
		FILE* archivo = fopen(nombe_archivo,"rb");	
	int pos=0,indice=0,codi=0;
	int id,telefono,codigo;
	string nombres,apellidos,direccion;
	cout<<"Que codigo desea ver: ";
	cin>>codi;
	Student student;
	fread(&student,sizeof(Student),1,archivo);	
	do{
	   if(student.codigo == codi){
	  
	   	cout<<"Codigo: "<<student.codigo<<endl;
	   	cout<<"Nombres: "<<student.nombres<<endl;
	   	cout<<"Apellidos: "<<student.apellidos<<endl;
	   	cout<<"Direccion: "<<student.direccion<<endl;
	   	cout<<"Telefono: "<<student.telefono<<endl;
	   }
	   fread(&student,sizeof(Student),1,archivo);	
	} while(feof(archivo)==0);
	
	
	fclose(archivo);
	system("pause");
		
		menu_student();
}
