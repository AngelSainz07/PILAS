#include <iostream>
#include <cstdlib>
using namespace std;

// Definimos el valor del tamaño del arreglo
#define MAX 5

// TDA para representar la pila
struct TDAPila {
    int tope;
    char elementos[MAX];
};

TDAPila inicializaPila(TDAPila x){
   x.tope=-1;
   for(int i=0;i<MAX;i++){
       x.elementos[i]='0';
   }
   return x;
}
void imprimePila(TDAPila x){
    for(int i=0; i<MAX;i++)
        cout<<x.elementos[i]<<", ";
}

bool pilaVacia(TDAPila x){
    bool valor=false;
    if(x.tope==-1)
        valor=true;
    return valor;
}

bool pilaLlena(TDAPila x){
    bool valor=false;
    if(x.tope==MAX-1)
        valor=true;
    return valor;
}

TDAPila pushPila(TDAPila x){
    char dato;
    cout<<"Ingrese Un Valor: ";
    cin>>dato;
    if(pilaLlena(x)){
        cout<<"\nDesbordamiento de Pila\n";
    }
    else{
        x.tope++;
        x.elementos[x.tope]=dato;
    }
    return x;
}

TDAPila popPila(TDAPila x){
    if(pilaVacia(x))
        cout<<"Subdesbordamiento de Pila\n";
    else{
      cout<<"Dato eliminado de la pila: "<<x.elementos[x.tope]<<endl;
      x.elementos[x.tope]='0';
      x.tope--;
    }
    return x;    
}

int main(){
    TDAPila x;
    int Opcion;
    x=inicializaPila(x);
    do{
        cout<<"\nEliga Una Opcion: \n 1. Agregar Elemento (Push), \n 2. Eliminar Un Elemento (Pop). \n 3. Imprimir Pila. \n 4. Salir Del Programa. \n Eliga Una Opcion: ";
        cin >> Opcion;
        switch (Opcion){
        case 1:
            cout<<"\nEligio La Opcion 1: Agregar Elemento (Push). \n";
            x=pushPila(x);
            break;
        case 2:
            cout<<"\nEligio La Opcion 2: Eliminar Un Elemento (Pop). \n";
            x=popPila(x);
            break;
        case 3: 
            cout<<"\nEligio La Opcion 2: Imprimir Pila. \n";
            imprimePila(x);
            break;  
        case 4:
            cout<<"\nEligio La Opcion 3: Salir Del Programa. \nHasta Luego ;) \n ";
            imprimePila(x);
            return 0;
        default:
            cout<<"\nOpcion No Valida... \nIntentalo De Nuevo :( \n";
            break;
        }
    }while (Opcion!=3);
    return 1;
}