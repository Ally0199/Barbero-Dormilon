#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include "Barbero.h"

using namespace std;

Barbero* myBarbero= new Barbero;//Se crea un Barbero

int SillasEspera[4]; //Arreglo de Sillas de Espera
int SillaBarbero; // Silla del Barbero

int SemaforoCliente=0; //Semaforo que inidcara si un cliente encontro silla

int UltimaPos=0; //Guarda la ultima en la que se asigno un cliente en las sillas de espera

int Time,b; //Time se encarga del limite de trabajo del Barbero, mientras que b cuenta el trabajo del Barbero

//Funcion para acomodar las salidas de pantalla
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

//Se inician las sillas en 0 (Desocupadas)
void IniciarSillas()
{
    for(int i=0; i<=4; i++)
    {
        SillasEspera[i]=0;
    }
    SillaBarbero=0;
}

//Funcion para imprimir el estado de las Sillas y el estado del Barbero
void Imprimir()
{
    Sleep(2000);
    system("cls");
    int x=0;
    if(myBarbero->getEstado()==0)
    {
        cout<<"Barbero: DURMIENDO"<<endl;
        cout<<endl;
    }
    if(myBarbero->getEstado()==1)
    {
        cout<<"Barbero: TRABAJANDO"<<endl;
        cout<<endl;
    }
    for(int i=0; i<4; i++)
    {
        cout<<"   "<<SillasEspera[i];
    }
    //For para imprimir el numero de Sillas de Espera
    for(int a=2; a<=5; a++)
    {
        if(x<100)
        {
            gotoxy(x,3);
            cout<<"   _"<<endl;
            gotoxy(x,4);
            cout<<"   "<<a;
            x=x+4;
        }

    }
    cout<<endl;
    cout<<endl;
    gotoxy(6,7);
    cout<<"   "<<SillaBarbero;
    cout<<endl;
    gotoxy(6,8);
    cout<<"   _"<<endl;
    cout<<endl;
    gotoxy(6,9);
    cout<<"   1"<<endl;
    gotoxy(6,11);
    cout<<"Tiempo de Corte: "<<Time<<" Tiempo Restante: "<<b<<endl;
    gotoxy(12,12);
    cout<<"PRESIONE ESC PARA SALIR "<<endl;

}

//Funcion que asigna tiempo de trabajo al Barbero, numero random entre 2 y 5
int Tiempo()
{
    int num;
    num=2+rand()%(5-1);
    return num;
}

//Funcion que indica en cuanto tiempo ingresa un nuevo cliente, un numero random entre 1 y 5
int TiempoCliente()
{
    int num;
    num=1+rand()%(5-1);
    return num;
}

//Funcion que se encarga de pasar Clientes de las Sillas de Espera a la Silla del Barbero
void LlenarSillaBarbero()
{
    Imprimir();
    int a=0,d=0,c=0;
    a=myBarbero->getPosicion();
    c=a-1;
    while(c!=a)
    {
        if(SillasEspera[a]==1)
        {
            Imprimir();
            SillasEspera[a]=0;
            SillaBarbero=1;
            d=a+1;
            if(d==4)
            {
                d=0;
            }
            myBarbero->setPosicion(d);
            Imprimir();
            break;
        }
        if(SillasEspera[a]==0)
        {
            a=a+1;
            if(a==4)
            {
                a=0;
                c=a-1;
            }
        }
        if(c==-1)
        {
            c=0;
        }
    }
    Imprimir();
}

//Funcion que se encarga de buscar Silla cuando llega un nuevo Cliente
void LlegadaClientes()
{
    int a=UltimaPos;
    Imprimir();
    gotoxy(6,14);
    cout<<"Entra un nuevo cliente"<<endl;
    Imprimir();
    gotoxy(6,15);
    cout<<"Verificando sillas"<<endl;
    if(a<4)
    {
        if(SillasEspera[a]==0 && SemaforoCliente==0)
        {
            Imprimir();
            SillasEspera[a]=1;
            SemaforoCliente=1;
            UltimaPos=a+1;
            if(UltimaPos==4)
            {
                UltimaPos=0;
                a=0;
            }
            if(SillaBarbero==0)
            {
                LlenarSillaBarbero();
            }
        }
    }
    if(SemaforoCliente==0)
    {
        Imprimir();
        gotoxy(6,16);
        cout<<"Cliente Saliendo"<<endl;
    }
    SemaforoCliente=0;
}

int main()
{
    int TiempoEspera;//Variable que contara el tiempo para la llegada de un nuevo Cliente
    IniciarSillas();//Inician las Sillas
    TiempoEspera=TiempoCliente();//Se asigna el tiempo de espera para que llegue un nuevo Cliente
    do
    {
        //Si la silla del barbero esta ocupada
        if(SillaBarbero==1)
        {
            Time=Tiempo();//Se Asigna un tiempo de trabajo
            for(b=0; b<=Time; b++)//Inicia el trabajo del Barbero
            {
                myBarbero->setEstado(1);//El estado del Barbero Cambia a Despierto
                TiempoEspera=TiempoEspera-1;//El tiempo de espera para la llegada de un nuevo cliente disminuye mientras el Barbero trabaja
                if(TiempoEspera<0)//Si el tiempo de espera llega a ser negativo
                {
                    //Se asiganara un nuevo tiempo de espera
                    TiempoEspera=TiempoCliente();
                }
                if(TiempoEspera==0)//Si el tiempo se agota
                {
                    //LLega un nuevo cliente
                    LlegadaClientes();
                    //Se asigna un nuevo tiempo de espera
                    TiempoEspera=TiempoCliente();
                }
                //Se imprime las sillas y estado del Barbero
                Imprimir();
            }
            //Una vez que el Barbero termina su trabajo su Silla se vacia
            SillaBarbero=0;
        }
        //El tiempo de trabajo del barbero vuelve a 0
        b=0;
        Time=0;
        //Si la silla del Barbero esta vacia
        if(SillaBarbero==0)
        {
            Imprimir();
            myBarbero->setEstado(0);//Se cambia el estado del Barbero a Dormido
            LlenarSillaBarbero();//Se buscan clientes en la Sillas de Espera
            //Si el tiempo de espera para la llegada de un nuevo cliente se agota
            if(TiempoEspera==0)
            {

                LlegadaClientes();//Llega un cliente
                TiempoEspera=TiempoCliente();//Se renueva el tiempo para la llegada de otro cliente
            }
            //Si el tiempo de espera es mayor que 0 entonces el tiempo continua disminuyendo
            if(TiempoEspera!=0)
            {
                TiempoEspera=TiempoEspera-1;
            }
        }

    //Se recibe la tecla Esc para salir del programa
    }while(getch()!=27);
    return 0;
}
