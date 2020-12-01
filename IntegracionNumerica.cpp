/*
 * nomprograma :Integracion Numerica
 * descripcion :Metodos:
 *					-Regla de los Trapecios
 *					-Regla de Simpson (1/3)
 *					-Regla de Simpson (3/8)
 *					-Integracion de Romberg(contiene la extrapolacion de richarson)
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

#define e 2.718281828
#define maximo 20

using namespace std ;

void RTrapecios();
void RS13();
void RS38();
void Romberg();

int menu(){
	int op;
	do{
		system("cls");
		printf("\tMENU DE INTEGRACION NUMERICA\n");
		printf("\tf(x)=(pow(e,-x))/x; a=1, b=2, sub-inter=10\n");
		printf("[1]: Regla de los Trapecios \n");
		printf("[2]: Regla de Simpson (1/3) \n");
		printf("[3]: Regla de Simpson (3/8) \n");
		printf("[4]: Integracion de Romberg \n");
		printf("[5]: salir\n");
		printf("\tElija opcion: ");
		scanf("%d",&op);
	}while(op<0 || op>5);
	return op;
}

int main(){
	int op;
	do{
		op=menu();
		switch(op){
			case 1:
				RTrapecios();
				break;
			case 2:
				RS13();
				break;
			case 3:
				RS38();
				break;
			case 4:
				Romberg();
				break;
			default:
				break;
		}
	}while(op!=5);
	
   return(0) ;
}

float f(float x){
   return (pow(e,-x))/x;
}

void RTrapecios(){
	float a,b,h,aprox,suma;
	int n,i;
	cout<<"\n\tREGLA DE LOS TRAPECIOS\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese el intervalo inicial [a, b]" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	cout<<"\nIngrese el numero de Sub-Intervalos: ";
	cin>>n;
	if(n>=1){
		h=(b-a)/n;
		if(n==1){
			aprox=(b-a)*(f(a)+f(b))/2;
		}else{
			suma=0;
			for(i=1;i<=n-1;i++){
				suma=suma+f(a+i*h);
			}
			aprox=h*(f(a)+f(b)+2*suma)/2;
		}
		cout<<"\n   la aproximacion es "<<aprox<<endl;
	}else{
		cout<<"Error..."<<endl;
	}
	getche();
}

void RS13(){
	float a,b,h,aprox,suma,sum1;
	int n,i;
	cout<<"\n\tREGLA DE SIMPSON (1/3)\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese el intervalo inicial [a, b]" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	cout<<"\nIngrese el numero de Sub-Intervalos: ";
	cin>>n;
	if(n>=2){
		h=(b-a)/n;
		if(n==2){
			aprox=(b-a)*(f(a)+f(b)+4*f((a+b)/2))/6;
		}else{
			suma=0;
			for(i=0;i<=(n-2)/2;i++){
				suma=suma+f(a+i*2*h+h);
			}
			sum1=0;
			for(i=1;i<=(n-2)/2;i++){
				sum1=sum1+f(a+i*2*h);
			}
			aprox=h*(f(a)+f(b)+4*suma+2*sum1)/3;
		}
		cout<<"\n   la aproximacion es "<<aprox<<endl;
	}else{
		cout<<"Error... n debe ser mayor o igual que 2"<<endl;
	}
	getche();
}

void RS38(){
	float a,b,h,aprox,suma,sum1,sum2;
	int n,i;
	cout<<"\n\tREGLA DE SIMPSON (3/8)\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese el intervalo inicial [a, b]" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	cout<<"\nIngrese el numero de Sub-Intervalos: ";
	cin>>n;
	if(n>=3){
		h=(b-a)/n;
		if(n==3){
			aprox=(b-a)*(f(a)+f(b)+3*f((2*a+b)/3)+3*f((a+2*b)/3))/8;
		}else{
			suma=0;
			for(i=0;i<=(n-3)/3;i++){
				suma=suma+f(a+i*3*h+h);
			}
			//cout<<suma<<endl;
			sum1=0;
			for(i=1;i<=(n-3)/3;i++){
				sum1=sum1+f(a+i*3*h+2*h);
			}
			//cout<<sum1<<endl;
			sum2=0;
			for(i=1;i<=(n-3)/3;i++){
				sum2=sum2+f(a+i*3*h);
			}
			//cout<<sum2<<endl;
			aprox=3*h*(f(a)+f(b)+3*suma+3*sum1+2*sum2)/8;
		}
		cout<<"\n   la aproximacion es "<<aprox<<endl;
	}else{
		cout<<"Error... n debe ser mayor o igual que 3"<<endl;
	}
	getche();
}

void Romberg(){
	float a,b,h,aprox,suma,sum1,sum2,r[maximo][maximo];
	int n,i,j,k;
	cout<<"\n\tIntegracion de Romberg\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese el intervalo inicial [a, b]" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	cout<<"\nIngrese el numero de Sub-Intervalos: ";
	cin>>n;
	h=b-a;
	r[1][1]=h*(f(a)+f(b))/2;
	//cout<<r[1][1]<<endl;
	for(i=2;i<=n;i++){
		suma=0;
		for(k=1;k<=pow(2,i-2);k++){
			suma=suma+f(a+(k-0.5)*h);
		}
		r[2][1]=(r[1][1]+h*suma)/2;
		for(j=2;j<=i;j++){
			r[2][j]=(pow(4,j-1)*r[2][j-1]-r[1][j-1])/(pow(4,j-1)-1);//extrapolacion de richarson
			//cout<<r[2][j]<<endl;
		}
		h=h/2;
		for(j=1;j<=i;j++){
			r[1][j]=r[2][j];
		}
	}
	cout<<"\n   la aproximacion es "<<r[2][n]<<endl;
	
	getche();
}
