/*
 * nomprograma :Derivacion Numerica
 * descripcion :Metodos:
 *					-Formula Centrada de Orden 0(h2)
 *					-Formula Centrada de Orden 0(h4)
 *					-Extrapolacion de Richardson
 *
 * auntor :Oroche Quispe Frank Anthony
 * fecha :..2019
 */
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <cmath>
#include <math.h>

#define PRECISION 6
#define maximo 9999

using namespace std ;

void FCOrden0h2();
void FCOrden0h4();
void ERichardson();

int menu(){
	int op;
	do{
		system("cls");
		printf("\tMENU DE DERIVACION NUMERICA\n");
		printf("\tf(x)=x-2^(-x) -> df(x)=2^(-x)ln(2)+1\n");
		printf("[1]: Formula Centrada de Orden 0(h2) \n");
		printf("[2]: Formula Centrada de Orden 0(h4) \n");
		printf("[3]: Extrapolacion de Richardson \n");
		printf("[4]: salir\n");
		printf("\tElija opcion: ");
		scanf("%d",&op);
	}while(op<0 || op>4);
	return op;
}

int main(){
	int op;
	do{
		op=menu();
		switch(op){
			case 1:
				FCOrden0h2();
				break;
			case 2:
				FCOrden0h4();
				break;
			case 3:
				ERichardson();
				break;
			default:
				break;
		}
	}while(op!=4);
	
   return(0) ;
}

float f(float x){
   return x-pow(2,-x);
}

float df(float x){
   return pow(2,-x)*log(2)+1;
}

float dddf(float x){
   return pow(2,-x)*pow(log(2),3);
}

float dddddf(float x){
   return pow(2,-x)*pow(log(2),5);
}

void FCOrden0h2(){
	float h,x,aprox,error;
	char res;
	cout<<"\n\tFORMULA CENTRADA DE ORDEN 0(H2)\n"<<endl;
	cout<<endl;
	do{
		cout<<"\nIngrese X de df(X) a aproximar: ";
		cin>>x;
		cout<<"\nIngrese h: ";
		cin >> h;
		aprox=(f(x+h)-f(x-h))/(2*h);
		error=-(pow(h,2)*dddf(x))/6;
		cout<<"   la aproximacion es "<<aprox<<" que aproxima a df("<<x<<") y el error es de : "<<error<<endl;
		cout<<"\n\tdesea ingresar otro h?(S/N)  ";
		cin>>res;
	}while(res=='s' || res=='S');
}

void FCOrden0h4(){
	float h,x,aprox,error;
	char res;
	cout<<"\n\tFORMULA CENTRADA DE ORDEN 0(H4)\n"<<endl;
	cout<<endl;
	do{
		cout<<"\nIngrese X de df(X) a aproximar: ";
		cin>>x;
		cout<<"\nIngrese h: ";
		cin >> h;
		aprox=(-f(x+2*h)+8*f(x+h)-8*f(x-h)+f(x-2*h))/(12*h);
		error=-(pow(h,4)*dddddf(x))/30;
		cout<<"   la aproximacion es "<<aprox<<" que aproxima a df("<<x<<") y el error es de : "<<error<<endl;
		cout<<"\n\tdesea ingresar otro h?(S/N)  ";
		cin>>res;
	}while(res=='s' || res=='S');
}

void ERichardson(){
	float h,n,k,x,aprox,error,Dh[maximo],D2h[maximo],D4h[maximo];
	int i;
	char res;
	cout<<"\n\tEXTRAPOLACION DE RICHARSON\n"<<endl;
	cout<<endl;
	do{
		cout<<"\nIngrese X de f´(X) a aproximar: ";
		cin>>x;
		cout<<"\nIngrese h: ";
		cin >> h;
		cout<<"\nIngrese orden: ";
		cin >> n;
		k=(n-2)/2;
		Dh[0]=(f(x+h)-f(x-h))/(2*h);
		D2h[0]=(f(x+2*h)-f(x-2*h))/(4*h);
		D4h[0]=(f(x+4*h)-f(x-4*h))/(8*h);
		for(i=1;i<=k;i++){
			Dh[i]=(pow(4,i)*Dh[i-1]-D2h[i-1])/(pow(4,i)-1);
			D2h[i]=(pow(4,i)*D2h[i-1]-D4h[i-1])/(pow(4,i)-1);
			D4h[i]=(pow(4,i)*D2h[i-1]-D4h[i-1])/(pow(4,i)-1);
		}
		
		for(i=0;i<=k;i++){
			aprox=(pow(4,i)*Dh[i]-D2h[i])/(pow(4,i)-1);
		}
		cout<<aprox<<endl;
		//aprox=(pow(4,k)*asd(h)-asd(2h))/(pow(4,k)-1);
		/*for(i=0;i<=k;i++){
			for(j=0;j<=k;j++){
				r[i][j]=(pow(4,j-1)*r[2][j-1]-r[1][j-1])/(pow(4,j-1)-1);
				//cout<<r[2][j]<<endl;
			}
		}*/
		
		cout<<"   la aproximacion es "<<aprox<<" que aproxima a f´("<<x<<") y el error es de : "<<error<<endl;
		cout<<"\n\tdesea ingresar otro h?(S/N)  ";
		cin>>res;
	}while(res=='s' || res=='S');
}
