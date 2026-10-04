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
    cout<<endl;
    for(int i=0; i<MAX;i++)
        cout<<x.elementos[i]<<", ";
}

bool pilaVacia(TDAPila x){
    bool valor=false;
    if(x.tope==-1)
        valor==true;
    return valor;
}

bool pilaLlena(TDAPila x){
    bool valor=false;
    if(x.tope==MAX-1)
        valor=true;
    return valor;
}

TDAPila pushPila(TDAPila x,char dato){
   
    if(pilaLlena(x)){
        cout<<"Desbordamiento de Pila\n";
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
    x=inicializaPila(x);
    x=pushPila(x,'a');
    x=pushPila(x,'b');
    x=pushPila(x,'c');
    x=pushPila(x,'d');
    x=pushPila(x,'e');
    x=popPila(x);
    x=popPila(x);
    x=pushPila(x,'f');
    x=pushPila(x,'x');
    x=popPila(x);
    x=pushPila(x,'y');
    x=pushPila(x,'z');

    imprimePila(x);
    return 1;
   
}