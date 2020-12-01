/*
 * nomprograma :Solucion Numerica de Problemas de Valor Inicial Para Ecuaciones Diferenciales Ordinarias
 * descripcion :Metodos:
 *					-Metodo de Euler
 *					-Metodo de Euler Mejorado
 *					-Metodo de Euler Modificado
 *					-Metodo de Runge Kutta
 *					-Metodo de Adams Bashforth
 *					-Metodo de Adams Moulton
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
#define PRECISION 5
#define maximo 9999

using namespace std ;

void MEuler();
void MEulerMejorado();
void MEulerModificado();
void MRungeKutta();
void MABashforth();
void MAMoulton();

int menu(){
	int op;
	do{
		system("cls");
		printf("\tMENU\n");
		printf("\t f(t,y)=2*(y/t)+pow(t,2)*pow(e,t) \n");
		printf("\t con solucion general: Y(t)=pow(t,2)*(pow(e,t)-e) \n");
		printf("\t a=1, b=2 \n");
		printf("[1]: Metodo de Euler \n");
		printf("[2]: Metodo de Euler Mejorado \n");
		printf("[3]: Metodo de Euler Modificado \n");
		printf("[4]: Metodo de Runge Kutta \n");
		printf("[5]: Metodo de Adams Bashforth \n");
		printf("[6]: Metodo de Adams Moulton \n");
		printf("[7]: salir\n");
		printf("\tElija opcion: ");
		scanf("%d",&op);
	}while(op<0 || op>7);
	return op;
}

int main(){
	int op;
	do{
		op=menu();
		switch(op){
			case 1:
				MEuler();
				break;
			case 2:
				MEulerMejorado();
				break;
			case 3:
				MEulerModificado();
				break;
			case 4:
				MRungeKutta();
				break;
			case 5:
				MABashforth();
				break;
			case 6:
				MAMoulton();
				break;
			default:
				break;
		}
	}while(op!=7);
	
   return(0) ;
}

float f(float t, float y){
   return 2*(y/t)+pow(t,2)*pow(e,t);
}

float Y(float t){
   return pow(t,2)*(pow(e,t)-e);
}

void MEuler(){
	cout << setprecision(PRECISION);
	float a,b,h,y,t,y0,n,error;
	int i,op;
	cout<<"\n\tMETODO DE EULER\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese el intervalo inicial [a, b]" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	do{cout<<"  Desea ingresar Sub-Intervalos...(1) o incremento h...(2)?  ";cin>>op;}while(op<1 || op>2);
	if(op==1){
		cout<<"\nIngrese el numero de Sub-Intervalos: ";
		cin>>n;
		h=(b-a)/n;
	}else{
		cout<<"\nIngrese el numero del incremento h: ";
		cin>>h;
		n=(b-a)/h;
	}
	t=a;
	y=Y(t);
	error=Y(t)-y;
	cout<<"\nk\tt[k]\t\tY[k]\t\tY(t[k])\t\terror"<<endl;
	cout<<0<<"|\t"<<t<<"\t\t"<<y<<"\t\t"<<Y(t)<<"\t\t"<<error<<endl;
	for(i=1;i<=n;i++){
		y=y+h*f(t,y);
		t=t+h;
		error=Y(t)-y;
		cout<<i<<"|\t"<<t<<"\t\t"<<y<<"\t\t"<<Y(t)<<"\t\t"<<error<<endl;
	}
	cout<<"\n  La aproximacion de Y(t[k]) es Y[k]"<<endl;
	getche();
}

void MEulerMejorado(){
	cout << setprecision(PRECISION);
	float a,b,h,y,y0,t,n,error;
	int i,op;
	cout<<"\n\tMETODO DE EULER MEJORADO\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese el intervalo inicial [a, b]" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	do{cout<<"  Desea ingresar Sub-Intervalos...(1) o incremento h...(2)?  ";cin>>op;}while(op<1 || op>2);
	if(op==1){
		cout<<"\nIngrese el numero de Sub-Intervalos: ";
		cin>>n;
		h=(b-a)/n;
	}else{
		cout<<"\nIngrese el numero del incremento h: ";
		cin>>h;
		n=(b-a)/h;
	}
	t=a;
	y=Y(t);
	error=Y(t)-y;
	cout<<"\nk\tt[k]\t\tY*[k]\t\tY[k]\t\tY(t[k])\t\terror"<<endl;
	cout<<0<<"|\t"<<t<<"\t\t"<<y<<"\t\t"<<y<<"\t\t"<<Y(t)<<"\t\t"<<error<<endl;
	for(i=1;i<=n;i++){
		y0=y+h*f(t,y);
		t=t+h;
		y=y+(h*(f(t-h,y)+f(t,y0)))/2;
		error=Y(t)-y;
		cout<<i<<"|\t"<<t<<"\t\t"<<y0<<"\t\t"<<y<<"\t\t"<<Y(t)<<"\t\t"<<error<<endl;
	}
	cout<<"\n  La aproximacion de Y(t[k]) es Y[k]"<<endl;
	getche();
}

void MEulerModificado(){
	cout << setprecision(PRECISION);
	float a,b,h,y,t,y0,n,error;
	int i,op;
	cout<<"\n\tMETODO DE EULER MODIFICADO\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese el intervalo inicial [a, b]" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	do{cout<<"  Desea ingresar Sub-Intervalos...(1) o incremento h...(2)?  ";cin>>op;}while(op<1 || op>2);
	if(op==1){
		cout<<"\nIngrese el numero de Sub-Intervalos: ";
		cin>>n;
		h=(b-a)/n;
	}else{
		cout<<"\nIngrese el numero del incremento h: ";
		cin>>h;
		n=(b-a)/h;
	}
	t=a;
	y=Y(t);
	error=Y(t)-y;
	cout<<"\nk\tt[k]\t\tY[k]\t\tY(t[k])\t\terror"<<endl;
	cout<<0<<"|\t"<<t<<"\t\t"<<y<<"\t\t"<<Y(t)<<"\t\t"<<error<<endl;
	for(i=1;i<=n;i++){
		y=y+h*f(t+(h/2),y+(h*f(t,y))/2);
		t=t+h;
		error=Y(t)-y;
		cout<<i<<"|\t"<<t<<"\t\t"<<y<<"\t\t"<<Y(t)<<"\t\t"<<error<<endl;
	}
	cout<<"\n  La aproximacion de Y(t[k]) es Y[k]"<<endl;
	getche();
}

void MRungeKutta(){
	cout << setprecision(PRECISION);
	float a,b,h,y,t,y0,n,error,k1,k2,k3,k4;
	int i,op;
	cout<<"\n\tMETODO DE RUNGE KUTTA\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese el intervalo inicial [a, b]" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	do{cout<<"  Desea ingresar Sub-Intervalos...(1) o incremento h...(2)?  ";cin>>op;}while(op<1 || op>2);
	if(op==1){
		cout<<"\nIngrese el numero de Sub-Intervalos: ";
		cin>>n;
		h=(b-a)/n;
	}else{
		cout<<"\nIngrese el numero del incremento h: ";
		cin>>h;
		n=(b-a)/h;
	}
	t=a;
	y=Y(t);
	error=Y(t)-y;
	cout<<"\nk\tt[k]\t\tY[k]\t\tY(t[k])\t\terror"<<endl;
	cout<<0<<"|\t"<<t<<"\t\t"<<y<<"\t\t"<<Y(t)<<"\t\t"<<error<<endl;
	for(i=1;i<=n;i++){
		k1=f(t,y);
		k2=f(t+(h/2),y+(k1*h/2));
		k3=f(t+(h/2),y+(k2*h/2));
		k4=f(t+h,y+(k3*h));
		cout<<"\n  k[1]="<<k1<<"\n  k[2]="<<k2<<"\n  k[3]="<<k3<<"\n  k[4]="<<k4<<endl;
		cout<<"\tY["<<t+h<<"]="<<y<<"+"<<(h/6)<<"("<<k1<<"+2("<<k2<<")+2("<<k3<<")+"<<k4<<")"<<endl;
		y=y+(h/6)*((k1)+2*(k2)+2*(k3)+(k4));
		t=t+h;
		error=Y(t)-y;
		cout<<i<<"|\t"<<t<<"\t\t"<<y<<"\t\t"<<Y(t)<<"\t\t"<<error<<endl;
	}
	cout<<"\n  La aproximacion de Y(t[k]) es Y[k]"<<endl;
	getche();
}

void MABashforth(){
	cout << setprecision(PRECISION);
	float a,b,h,y[maximo],t[maximo],y0,n,error[maximo],k1,k2,k3,k4;
	int i,op;
	cout<<"\n\tMETODO DE ADAMS BASHFORTH\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese el intervalo inicial [a, b]" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	do{cout<<"  Desea ingresar Sub-Intervalos...(1) o incremento h...(2)?  ";cin>>op;}while(op<1 || op>2);
	if(op==1){
		cout<<"\nIngrese el numero de Sub-Intervalos: ";
		cin>>n;
		h=(b-a)/n;
	}else{
		cout<<"\nIngrese el numero del incremento h: ";
		cin>>h;
		n=(b-a)/h;
	}
	t[0]=a;
	y[0]=Y(t[0]);
	error[0]=Y(t[0])-y[0];
	for(i=1;i<=n;i++){
		t[i]=a+i*h;
		y[i]=0;
	}
	for(i=0;i<=2;i++){
		k1=f(t[i],y[i]);
		k2=f(t[i]+(h/2),y[i]+(k1*h/2));
		k3=f(t[i]+(h/2),y[i]+(k2*h/2));
		k4=f(t[i]+h,y[i]+(k3*h));
		y[i+1]=y[i]+(h/6)*((k1)+2*(k2)+2*(k3)+(k4));
		error[i+1]=Y(t[i+1])-y[i+1];
	}
	for(i=3;i<n;i++){
		y[i+1]=y[i]+(h/24)*(55*f(t[i],y[i])-59*f(t[i-1],y[i]-1)+37*f(t[i-2],y[i-2])-9*f(t[i-3],y[i-3])+pow(h,2)*(24*i*i+24*i+8));
		error[i+1]=Y(t[i+1])-y[i+1];
	}
	cout<<"\nk\tt[k]\t\tY[k]\t\tY(t[k])\t\terror"<<endl;
	for(i=0;i<=n;i++){
		cout<<i<<"|\t"<<t[i]<<"\t\t"<<y[i]<<"\t\t"<<Y(t[i])<<"\t\t"<<error[i]<<endl;
	}
	cout<<"\n  La aproximacion de Y(t[k]) es Y[k]"<<endl;
	getche();
}

void MAMoulton(){
	cout << setprecision(PRECISION);
	float a,b,h,y[maximo],t[maximo],y0,n,error[maximo],k1,k2,k3,k4;
	int i,op;
	cout<<"\n\tMETODO DE ADAMS MOULTON\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese el intervalo inicial [a, b]" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	do{cout<<"  Desea ingresar Sub-Intervalos...(1) o incremento h...(2)?  ";cin>>op;}while(op<1 || op>2);
	if(op==1){
		cout<<"\nIngrese el numero de Sub-Intervalos: ";
		cin>>n;
		h=(b-a)/n;
	}else{
		cout<<"\nIngrese el numero del incremento h: ";
		cin>>h;
		n=(b-a)/h;
	}
	t[0]=a;
	y[0]=Y(t[0]);
	error[0]=Y(t[0])-y[0];
	for(i=1;i<=n;i++){
		t[i]=a+i*h;
		y[i]=0;
	}
	for(i=0;i<=2;i++){
		k1=f(t[i],y[i]);
		k2=f(t[i]+(h/2),y[i]+(k1*h/2));
		k3=f(t[i]+(h/2),y[i]+(k2*h/2));
		k4=f(t[i]+h,y[i]+(k3*h));
		y[i+1]=y[i]+(h/6)*((k1)+2*(k2)+2*(k3)+(k4));
		error[i+1]=Y(t[i+1])-y[i+1];
	}
	for(i=3;i<n;i++){
		y[i+1]=y[i]+(h/24)*(9*f(t[i+1],y[i+1])+19*f(t[i],y[i])-5*f(t[i-1],y[i]-1)+f(t[i-2],y[i-2])+pow(h,2)*(24*i*i+24*i+8));
		error[i+1]=Y(t[i+1])-y[i+1];
	}
	cout<<"\nk\tt[k]\t\tY[k]\t\tY(t[k])\t\terror"<<endl;
	for(i=0;i<=n;i++){
		cout<<i<<"|\t"<<t[i]<<"\t\t"<<y[i]<<"\t\t"<<Y(t[i])<<"\t\t"<<error[i]<<endl;
	}
	cout<<"\n  La aproximacion de Y(t[k]) es Y[k]"<<endl;
	getche();
}
