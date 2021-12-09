#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <locale.h>
#include "funciones.h"
#include "herramientas.h"
using namespace std;


Herramientas::Herramientas(int _ID_herramienta){
    if(_ID_herramienta==0){
        FILE *p;
        p=fopen("herramientas.dat","rb");
        if(p==NULL){
            ID_herramienta=1;
        }
        else{
            fseek(p,0,SEEK_END);
            _ID_herramienta=ftell(p)/sizeof(Herramientas);
            ID_herramienta=_ID_herramienta+1;
        }
    }
}

bool Herramientas::escribir(){
	bool escribio;
	FILE* p;
	p=fopen("herramientas.dat","ab");
	if(p==NULL){
		cout << "ERROR- al abrir el archivo" << endl;
		return false;
	}
	escribio=fwrite(this,sizeof(Herramientas),1,p);
	fclose(p);
	return escribio;
}
bool Herramientas::sobre_escribir(int pos){
    bool escribio;
    FILE *p;
    p=fopen("herramientas.dat","rb+");
    if(p==NULL){
        return false;
    }
    fseek(p,sizeof(Herramientas)*pos,SEEK_SET);
    escribio=fwrite(this,sizeof(Herramientas),1,p);
    fclose(p);
    return escribio;
}
bool Herramientas::leer(int pos){
	bool leyo;
	FILE* p;
	p=fopen("herramientas.dat","rb");
	if(p==NULL) {
		cout << "No encontró ningún herramienta" << endl;
		return false;
	}
    fseek(p,sizeof(Herramientas)*pos,SEEK_SET);
	leyo=fread(this, sizeof(Herramientas), 1, p);
	fclose(p);
	return leyo;
}

void Herramientas::cargar(){
	cout << "Ingrese el codigo de marca: ";
	cin >> ID_marca;
	cout << "Ingrese el nombre de la herramienta: ";
	cin.ignore();
	cin.getline(nomherramienta,50);
	cout << "Ingrese el precio: ";
	cin >> precio;
	cout << "Ingrese stock: ";
	cin >> stock;
	fabricado.cargar();
	estado=true;
}

void Herramientas::mostrar(){
	if(estado==true){
        cout << "Codigo de herramienta: " << ID_herramienta << endl;
        cout << "Codigo de marca: " << ID_marca << endl;
        cout << "Herramienta: " << nomherramienta << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Stock: " << stock <<endl;
        fabricado.mostrar();
	}
}

bool Herramientas::backup_escribir(){
    bool escribio;
    FILE *p;
    p=fopen("backup/herramientas.dat","ab");
    if(p==NULL){
        return true;
    }
    escribio=fwrite(this,sizeof(Herramientas),1,p);
    fclose(p);
    return escribio;
}
