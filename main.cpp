#include <iostream>
#include <limits>
#include <string>
#include <ctime>

#include <fstream>
#include <iomanip>

using namespace std;

//Obtiene la fecha y la hora actuales
string currentDateTime(){
	
	time_t t = time(0);
	tm* now = localtime(&t);
	
	char buffer[128];
	strftime(buffer, sizeof(buffer), "%d-%m-%y %X", now);
	return buffer;
	
}

//Verifica que el documento de "Datos.txt" este creado al inicio del codigo y si no es asi lo crea
void fileCreator(){
	
	ifstream archivo("Datos.txt", std::ios::in); //constructor
 
	//ios::in es para lectura

	if (!archivo){ //verifica que el archivo exista
    	archivo.close();
    	archivo.open("Datos.txt", std::ios::out);  // ios::out es para escritura
	}
	
	ifstream temp("temp.txt", std::ios::in);
	
	if(!temp){
		temp.close();
		temp.open("temp.txt", std::ios::out);
	}
	
}

//Modifica el archivo de "Datos.txt"
void fileModificator(string str, int estado){
	string sestado = "";
	
	std::fstream archivo("Datos.txt", std::ios::app);  // ios::app es para agregar texto
    
	archivo.seekp(0, ios::end); //Se mueve hasta el final del documento
	
	if (estado){
		sestado = "ACTIVO" ;
	}else{
		sestado = "INACTIVO" ;
	}
	
	int id = id++;
		
    archivo << "{ ";
	
	archivo << "id: '" << id << "'; "; // graba la info en el documento
	archivo << "registro:'" << str << "'; "; 
	archivo << "estado: '" << sestado << "'; ";
	archivo << "fecha: '" << currentDateTime() <<"'; ";
	
	archivo << " }" << endl;      
    
    archivo.close();
    system ("cls");
    
    std::fstream temp("temp.txt", std::ios::app);
    archivo.seekp(0, ios::end);
    
    temp << "last id: " << id << endl;
    
    archivo.close();
	
}


int main() {
	
	int iopc = 0;
	int iestado = 0;
	bool out = true;
	string sactividad = "";
	string sestado = "";
	
	fileCreator();
	printf ("Bienvenido al task tracker \n") ;
	while (true){
		
		printf ("Elige una Opcion \n");
		printf ("[1].........Agregar un registro \n");
		printf ("[2].........Eliminar un registro \n");
		printf ("[3].........Actualizar un registro \n");
		printf ("[4].........Cambiar el estado de un registro \n");
		printf ("[5].........Salir \n");
		scanf ("%d", &iopc);
		cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Espera a que se presione enter para continuar
		system ("cls");

		switch (iopc){
			case 0: //en caso de que se ingresen letras lo reconoce como 0
				printf("La opcion ingresada es INVALIDA, Porfavor Introduce un numero \n" );
				cout << "Press Enter to Continue";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				break;
			case 1:
				printf (" ***OPCION Agregar un Registro*** \n ");
				printf ("-----------------------------------\n ");
				printf("Introduce el registro: \n");
				getline(cin, sactividad);
				fileModificator(sactividad, iestado);
				
				break;
			case 2:
				printf (" ***OPCION Eliminar un Registro*** \n ");
				printf ("-----------------------------------\n ");
				cout << "Press Enter to Continue";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				break;
			case 3:
				printf (" ***OPCION Actualizar un Registro*** \n ");
				printf ("-----------------------------------\n ");
				cout << "Press Enter to Continue";
				cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
				break;
			case 4:
				while (out ){
					printf (" ***OPCION Cambiar el estado de un Registro*** \n ");
					printf ("-----------------------------------\n ");
					printf("Que estado deseas registrar ? \n");
					printf ("Elige una Opcion \n");
					printf ("[1].........ACTIVO \n");
					printf ("[2].........INACTIVO \n");
					printf ("[3].........FINALIZADO \n");
					scanf("%d", &iestado);
					system ("cls");
				
					if (iestado == 1){
						sestado = "ACTIVO";
						out = false;
					}else if (iestado == 2){
						sestado = "INACTIVO";
						out = false;
					}else if (iestado == 3){
						sestado = "FINALIZADO";
						out = false;
					}else{
						printf ("Escoge una opcion entre 1 - 3 \n");
						cout << "Press Enter to Continue";
						cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
						system ("cls");
					}
				}
				system("cls");
				break;
			case 5:
				printf("Gracias por utilzar Task Tracker ;p \n");
				return 0;
				break;
			default:
				printf("Opcion no valida, porfavor de escoger un numero entre 1 y 5 \n");
				break;
		}
	}
}
