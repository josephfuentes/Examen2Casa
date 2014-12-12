#include <iostream>
#include <fstream>
using namespace std;
string arreglo[10][10];
string bombas[10][10];
int cont=0;


void inicializarTablero(){
for(int i=0;i<10;i++){
        for(int a=0;a<10;a++){
        arreglo[i][a] = "-";
        }
        }
}

void imprimirTablero(){
for(int i=0;i<10;i++){
        cout<<"  "<<i;
        }
        cout<<endl;
        for(int i=0;i<10;i++){
        cout<<i<<" ";
        for(int a=0;a<10;a++){
        cout<<arreglo[i][a]<<"  ";
        }
        cout<<endl;
        }
}

void imprimirTableroBombas(){
for(int i=0;i<10;i++){
        cout<<"  "<<i;
        }
        cout<<endl;
        for(int i=0;i<10;i++){
        cout<<i<<" ";
        for(int a=0;a<10;a++){
        cout<<bombas[i][a]<<"  ";
        }
        cout<<endl;
        }
}

void arregloBombas(){
for(int i=0;i<10;i++){
        for(int a=0;a<10;a++){
        bombas[i][a] = "-";
        }
        }

        bombas[2][2] = "x";
        bombas[4][5] = "x";
        bombas[6][7] = "x";
        bombas[8][5] = "x";
        bombas[5][9] = "x";

}

bool comprobarBomba(int f, int c){
   if(bombas[f][c]=="x"){
        cont+=1;
    return true;
   } else{
   return false;
   }


}

bool limite(int f,int c){
if(f>=0 && f<10 && c>=0 && c<10){
    return true;
}else{
return false;
}
}


void adyacentes(int f,int c){
    //centro
if(!comprobarBomba( f,  c) && limite(f,c)==true){
arreglo[f][c]=" ";

}
//derecha
if(!comprobarBomba( f+1,  c) && limite(f+1,c)==true){
arreglo[f+1][c]=" ";

}
//izquierda
if(!comprobarBomba( f-1,  c) && limite(f-1,c)==true){
arreglo[f-1][c]=" ";

}
//arriba
if(!comprobarBomba( f,  c+1) && limite(f,c+1)==true){
arreglo[f][c+1]=" ";

}
//abajo
if(!comprobarBomba( f,  c-1) && limite(f,c-1)==true){
arreglo[f][c-1]=" ";

}
//DIAGONALES
//esquina inferior derecha
if(!comprobarBomba( f+1,  c+1) && limite(f+1,c+1)==true){
arreglo[f+1][c+1]=" ";

}
//esquina inferior izquierda
if(!comprobarBomba( f-1,  c+1) && limite(f-1,c+1)==true){
arreglo[f-1][c+1]=" ";

}
//esquina superior izquierda
if(!comprobarBomba( f-1,  c-1) && limite(f-1,c-1)==true){
arreglo[f-1][c-1]=" ";

}
//esquina superior derecha
if(!comprobarBomba( f+1,  c-1) && limite(f+1,c-1)==true){
arreglo[f+1][c-1]=" ";

}
}

bool ganar(){
    int cont2=0;
        for(int i=0;i<10;i++){
        for(int a=0;a<10;a++){
        if(arreglo[i][a]=="-"){
            cont2+=1;
        }
        }
        }
        cout<<"Bombas Adyacentes "<<cont<<endl;
        cont=0;
        cout<<"CASILLAS SIN DESPEJAR "<<cont2<<endl;
        if(cont2==5){
            return true;
        }else{
        return false;
        }
}
int main()
{
                     int score=0;
                    int perder=0;



                ifstream in("archivo");
                 in.read((char*)&score,sizeof(int));
                  in.read((char*)&perder,sizeof(int));
                    cout<<"VECES GANADAS: "<<score<<endl;
                     cout<<"VECES PERDIDAS: "<<perder<<endl;
                    in.close();


inicializarTablero();
arregloBombas();

do{

    int f=0, c=0;
        imprimirTablero();


         if(ganar()){
                cout<<"FELICIDADES HAS GANADO";
                  score+=1;
                    ofstream out("archivo");
                    out.write((char*)&score,sizeof(int));
                    out.write((char*)&perder,sizeof(int));
                    out.close();

                break;
            }


    cout<<"Ingrese posicion fila: ";
        cin>>f;
        cout<<"Ingrese posicion columna ";
        cin>>c;
        //cout<<cont<<endl;;
        if(f>=10 || c>=10){
            cout<<"Fuera de rango"<<endl;
        }else{

        if(comprobarBomba(f,c)){
            cout<<"MINA ENCONTRADA...BOOM!"<<endl;
            cout<<":::::::::::::GAME OVER:::::::::::::::";

             perder+=1;
                    ofstream out("archivo");
                    out.write((char*)&score,sizeof(int));
                    out.write((char*)&perder,sizeof(int));
                    out.close();

            break;
        }else{
        adyacentes(f,c);
        }

        }
}while(true);
}
