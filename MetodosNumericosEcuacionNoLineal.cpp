/*
 * nomprograma :Solucion Numerica de una Ecuacion no Lineal en una Variable
 * descripcion :Metodos:
 *					-Metodo de Biseccion
 *					-Metodo de Posicion falsa
 *					-Metodo del punto fijo
 *					-Metodo de Newton Raphson
 *					-Metodo de Newton Raphson Modificado
 *					-Metodo de la Secante
 *				Se cambia la funcion en codigo
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
#define metro 1 // 1 metro = 3.28084 pies

using namespace std ;

int hallarN(float, float, float);
float f(float);
float df(float);
float ddf(float);
float g(float);
void mBiseccion();
void mPFalsa();
void mPuntoFijo();
void mNewtonRaphson();
void mNewtonRaphsonM();
void mSecante();

int menu(){
	int op;
	do{
		system("cls");
		printf("\tMENU\n");
		printf("\tf(x)=pow(x,3)-9*metro*pow(x,2)+(90*metro/M_PI)  x[aprox]=2\n");
		printf("[1]: Metodo de Biseccion\n");
		printf("[2]: Metodo de Posicion falsa\n");
		printf("[3]: Metodo del punto fijo\n");
		printf("[4]: Metodo de Newton Raphson\n");
		printf("[5]: Metodo de Newton Raphson Modificado\n");
		printf("[6]: Metodo de la Secante\n");
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
				mBiseccion();
				break;
			case 2:
				mPFalsa();
				break;
			case 3:
				mPuntoFijo();
				break;
			case 4:
				mNewtonRaphson();
				break;
			case 5:
				mNewtonRaphsonM();
				break;
			case 6:
				mSecante();
				break;
			default:
				break;
		}
	}while(op!=7);
	
   return(0) ;
}

int hallarN(float a, float b, float tol){
	int n;
	n=ceil(-(log(tol/(b-a))/log(2)));
	return n;
}

float f(float x){
   return pow(x,3)-9*metro*pow(x,2)+(90*metro/M_PI);
}

float df(float x){
   return 3*pow(x,2)-18*metro*x;
}

float ddf(float x){
   return 6*x-18*metro;
}

float g(float x){
   return pow((9*metro*pow(x,2)-(90*metro/M_PI)),(1/3));
}

void mBiseccion(){
	system("cls");
	cout << setprecision(PRECISION);
	int n,i=1;
	float a,b,x,tol;
	cout<<"\n\tMETODO DE LA BISECCION\n"<<endl;
	cout<<endl;
	printf("\tf(x)=x-2^(-x);  x[raiz]=0.641186...\n");
	cout<<"\nIngrese el intervalo inicial [a, b] y la tolerancia" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	do{cout<<"tolerancia (0 < tol < 1) = ";cin >> tol;}while(tol<=0 || tol>=1);
	n=hallarN(a,b,tol);
	cout<<"\na\t\tx\t\tb\t\tf(a)\t\tf(x)\t\tf(b)"<<endl;
	while(i<=n){
		x=(a+b)/2;
		if((f(a)>0 && f(x)>0 && f(b)>0) || (f(a)<0 && f(x)<0 && f(b)<0) || (f(a)*f(b)>0)){
			cout<<"\nNo se encontro raiz en el intervalo ["<<a<<","<<b<<"]"<<endl;
			getche();
			return;
		}
		cout<<a<<"\t\t"<<x<<"\t\t"<<b<<"\t\t"<<f(a)<<"\t\t"<<f(x)<<"\t\t"<<f(b)<<endl;
		if(f(x)==0 || (b-a)/2<tol || i==n){
			cout<<"\nla raiz aproximada de la ecuacion dada es: "<<x<<endl;
			getche();
			return;
		}
		if(f(a)*f(x)<0){
			b=x;
		}else{
			a=x;
		}
		i++;		
	}
	cout<<"\nse llego al limite de iteraciones y no se ah encontrado un aproximacion adecuada..."<<endl;
	getche();
}

void mPFalsa(){
	system("cls");
	cout << setprecision(PRECISION);
	int n,i=1;
	float a,b,x,tol;
	cout<<"\n\tMETODO DE LA BISECCION\n"<<endl;
	printf("\tf(x)=x-2^(-x);  x[raiz]=0.641186...\n");
	cout<<"\nIngrese el intervalo inicial [a, b] y la tolerancia" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	do{cout<<"tolerancia (0 < tol < 1) = ";cin >> tol;}while(tol<=0 || tol>=1);
	n=hallarN(a,b,tol);
	cout<<"\na\t\tx\t\tb\t\tf(a)\t\tf(x)\t\tf(b)"<<endl;
	while(i<=n){
		x=(a*f(b)-b*f(a))/(f(b)-f(a));
		if((f(a)>0 && f(x)>0 && f(b)>0) || (f(a)<0 && f(x)<0 && f(b)<0) || (f(a)*f(b)>0)){
			cout<<"\nNo se encontro raiz en el intervalo ["<<a<<","<<b<<"]"<<endl;
			getche();
			return;
		}
		cout<<a<<"\t\t"<<x<<"\t\t"<<b<<"\t\t"<<f(a)<<"\t\t"<<f(x)<<"\t\t"<<f(b)<<endl;
		if(f(x)==0 || (b-a)/2<tol || i==n){
			cout<<"\nla raiz aproximada de la ecuacion dada es: "<<x<<endl;
			getche();
			return;
		}
		if(f(a)*f(x)<0){
			b=x;
		}else{
			a=x;
		}
		i++;		
	}
	cout<<"\nse llego al limite de iteraciones y no se ah encontrado un aproximacion adecuada..."<<endl;
	getche();
}

void mPuntoFijo(){
	system("cls");
	cout << setprecision(PRECISION);
	int i=1;
	float a,p,tol;
	cout<<"\n\tMETODO DE PUNTO FIJO\n"<<endl;
	printf("\tf(x)=x-2^(-x);  x[raiz]=0.641186...\n");
	cout<<"\nIngrese aproximacion inicial y toleracia:" << endl;
	cout<<"c = ";cin >> a;
	do{cout<<"tolerancia (0 < tol < 1) = ";cin >> tol;}while(tol<=0 || tol>=1);
	cout<<"\np\t\tg(p)"<<endl;
	do{
		p=g(a);
		cout<<a<<"\t\t"<<p<<endl;
		if(abs(p-a)<tol){
			cout<<"\nla raiz aproximada de la ecuacion dada es: "<<a<<endl;
			cout<<"con una iteracion de: "<<i<<endl;
			getche();
			return;
		}
		a=p;
		i++;
	}while(abs(p-a)<tol);

	cout<<"\nse llego al limite de iteraciones y no se ah encontrado un aproximacion adecuada..."<<endl;
	getche();
}

void mNewtonRaphson(){
	system("cls");
	cout << setprecision(PRECISION);
	int i=1;
	float c,x,e,d,tol,error;
	cout<<"\n\tMETODO DE NEWTON RAPSH\n"<<endl;
	printf("\tf(x)=x-2^(-x);  x[raiz]=0.641186...\n");
	cout<<"\nIngrese aproximacion inicial y toleracia:" << endl;
	cout<<"x = ";cin >> x;
	do{cout<<"tolerancia (0 < tol < 1) = ";cin >> tol;}while(tol<=0 || tol>=1);
	cout<<"\np\t\tg(p)\t\tE"<<endl;
	do{
		e=f(x);d=df(x);
		if(d==0){
			cout<<"no se puede continuar con el metodo..."<<endl;
			getche();
			return;
		}
		c=x-(e/d);
		error=abs(c-x);
		cout<<x<<"\t\t"<<c<<"\t\t"<<error<<endl;
		if(abs(c-x)<tol){
			cout<<"\nla raiz aproximada de la ecuacion dada es: "<<c<<endl;
			cout<<"con una iteracion de: "<<i<<endl;
			getche();
			return;
		}
		x=c;
		i++;
	}while(abs(c-x)<tol);

	cout<<"\nse llego al limite de iteraciones y no se ah encontrado un aproximacion adecuada..."<<endl;
	getche();
}

void mNewtonRaphsonM(){
	system("cls");
	cout << setprecision(PRECISION);
	int i=1;
	float c,x,k,e,d,tol,error;
	cout<<"\n\tMETODO DE NEWTON RAPSH MODIFICADO\n"<<endl;
	printf("\tf(x)=x-2^(-x);  x[raiz]=0.641186...\n");
	cout<<"\nIngrese aproximacion inicial y toleracia:" << endl;
	cout<<"x = ";cin >> x;
	do{cout<<"tolerancia (0 < tol < 1) = ";cin >> tol;}while(tol<=0 || tol>=1);
	cout<<"\np\t\tg(p)\t\tE"<<endl;
	do{
		if(d==0){
			cout<<"no se puede continuar con el metodo..."<<endl;
			getche();
			return;
		}
		c=x-((f(x)*df(x))/((df(x)*df(x))-(f(x)*ddf(x))));
		error=abs(c-x);
		cout<<x<<"\t\t"<<c<<"\t\t"<<error<<endl;
		if(abs(c-x)<tol){
			cout<<"\nla raiz aproximada de la ecuacion dada es: "<<c<<endl;
			cout<<"con una iteracion de: "<<i<<endl;
			getche();
			return;
		}
		x=c;
		i++;
	}while(abs(c-x)<tol);

	cout<<"\nse llego al limite de iteraciones y no se ah encontrado un aproximacion adecuada..."<<endl;
	getche();
}

void mSecante(){
	system("cls");
	cout << setprecision(PRECISION);
	int i=1;
	float a,b,p,p0,q0,q1,tol,error;
	cout<<"\n\tMETODO DE LA SECANTE\n"<<endl;
	printf("\tf(x)=x-2^(-x);  x[raiz]=0.641186...\n");
	cout<<"\nIngrese el intervalo inicial [a, b] y la tolerancia" << endl;
	cout<<"a = ";cin >> a;
	do{cout<<"b = ";cin >> b;}while(b<=a);
	do{cout<<"tolerancia (0 < tol < 1) = ";cin >> tol;}while(tol<=0 || tol>=1);
	if(f(a)>0){
		p0=b;q0=f(a);q1=f(b);
	}else{
		p0=a;q0=f(b);q1=f(a);
	}
	do{
		if(f(a)>0){
			p=p0-(q1/(q1-q0))*(p0-a);
		}else{
			p=p0-(q1/(q0-q1))*(b-p0);
		}
		if(abs(p-p0)<tol){
			cout<<"\nla raiz aproximada de la ecuacion dada es: "<<p<<endl;
			cout<<"con una iteracion de: "<<i<<endl;
			getche();
			return;
		}
		p0=p;q1=f(p);
		i++;
	}while(abs(p-p0)<tol);

	cout<<"\nse llego al limite de iteraciones y no se ah encontrado un aproximacion adecuada..."<<endl;
	getche();
}
