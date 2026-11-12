#include <iostream>
#include <string.h>
using namespace std;
 
//Display-------------------------------------------------------------------------------
class Display{
    private:
        string tipo;
    public:
        Display(string);
        string getTipo();
};

Display :: Display(string t){
	tipo = t;
}
 
string Display::getTipo(){
    return tipo;
}

//Hora---------------------------------------------------------------------------
class Hora{
    private:
        int hora;
        int minutos;
        int segundos;
    public:
        Hora(int, int, int);
        int getHora();
        int getMinutos();
        int getSegundos();
};
 
Hora :: Hora(int h, int m, int s){
    hora = h;
    minutos = m;
    segundos = s;
}

int Hora::getHora(){
	return hora;
}

int Hora::getMinutos(){
	return minutos;
}

int Hora::getSegundos(){
	return segundos;
}

//Reloj----------------------------------------------------------------
class Reloj{
    private:
        Display* pDisplay;
		Hora* pHora;
        int minutos;
        
    public:
        Reloj(int, int, int);
        void asignarDisplay(Display*);
        void mostrarReloj();
};
 
Reloj :: Reloj(int h, int m, int s){
    pDisplay = NULL;
    pHora = new Hora(h, m, s);
}

void Reloj::asignarDisplay(Display* pD){
	pDisplay = pD;
}

void Reloj::mostrarReloj(){
	if(pDisplay != NULL){
		if (pDisplay->getTipo() == "digital"){
			cout << "[";
			cout << pHora->getHora() << ":" ;
			cout << pHora->getMinutos() << ":" ;
			cout << pHora->getSegundos() << "]" << endl;
		}
	}
}


int main(){
    Display d1("digital");
    Display d2("analogico");
    
    Reloj reloj1(10,15,55);
    Reloj reloj2(10,15,55);
    
    reloj1.asignarDisplay(&d1);
    reloj2.asignarDisplay(&d2);
    
    reloj1.mostrarReloj();
    reloj2.mostrarReloj();
    return 0;
}
