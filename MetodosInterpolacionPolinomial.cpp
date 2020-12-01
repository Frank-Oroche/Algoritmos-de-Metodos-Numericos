/*
 * nomprograma :Interpolacion Polinomial
 * descripcion :Metodos:
 *					-Forma de Lagrange
 *					-Forma de Newton
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

void PILagrange();
void PINewton();

int menu(){
	int op;
	do{
		system("cls");
		printf("\tMENU DE INTERPOLACION POLINOMIAL\n");
		printf("[1]: Forma de Lagrange \n");
		printf("[2]: Forma de Newton \n");
		printf("[3]: salir\n");
		printf("\tElija opcion: ");
		scanf("%d",&op);
	}while(op<0 || op>3);
	return op;
}

int main(){
	int op;
	do{
		op=menu();
		switch(op){
			case 1:
				PILagrange();
				break;
			case 2:
				PINewton();
				break;
			default:
				break;
		}
	}while(op!=3);
	
   return(0) ;
}

void PILagrange(){
	cout << setprecision(PRECISION);
	int n,i,k;
	char res;
	float x[maximo],f[maximo],l[maximo],p,c,suma,producto;
	cout<<"\n\tPOLINOMIO DE INTERPOLACION DE LAGRANGE\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese grado del polinomio: ";
	do{cin >> n;}while(n<=0);
	cout<<endl;
	for(i=0;i<=n;i++){
		cout<<"x["<<i<<"]= ";cin>>x[i];
		cout<<"f(x["<<i<<"])= ";cin>>f[i];
	}
	cout<<endl;
	for(i=0;i<=n;i++){
		cout<<"x["<<i<<"]= "<<x[i]<<" \t";
	}
	cout<<endl;
	for(i=0;i<=n;i++){
		cout<<"f(x["<<i<<"])= "<<f[i]<<" \t";
	}
	cout<<endl;
	do{
		cout<<"\nIngrese X de f(X) a aproximar: ";
		cin>>c;
		suma = 0;
		for(i=0;i<=n;i++){
			l[i]=1;
			for(k=0;k<=n;k++){
				if(k!=i){
					l[i]=l[i]*((c-x[k])/(x[i]-x[k]));
					cout<<"  L["<<i<<"]("<<c<<")= "<<l[i]<<endl;
				}
			}
			suma=suma+(f[i]*l[i]);
		}
		p=suma;
		cout<<"   el Polinomio P["<<n<<"]("<<c<<")= "<<p<<" aproxima a f("<<c<<")"<<endl;
		cout<<"\n\tdesea ingresar otro x?(S/N)  ";
		cin>>res;
	}while(res=='s' || res=='S');
}

float difDivProgresiva(int i0, int i1, float x[maximo], float f[maximo]) {
	if(i1-i0==0) {
        return f[i0];
    }else{
        return (difDivProgresiva(i0+1,i1,x,f)-difDivProgresiva(i0,i1-1,x,f))/(x[i1]-x[i0]);
    }
}

void PINewton(){
	cout << setprecision(PRECISION);
	int n,i,j;
	char res;
	float x[maximo],f[maximo],l[maximo],b[maximo],p,c,aprox;
	cout<<"\n\tPOLINOMIO DE INTERPOLACION DE NEWTON\n"<<endl;
	cout<<endl;
	cout<<"\nIngrese grado del polinomio: ";
	do{cin >> n;}while(n<=0);
	cout<<endl;
	for(i=0;i<=n;i++){
		cout<<"x["<<i<<"]= ";cin>>x[i];
		cout<<"f(x["<<i<<"])= ";cin>>f[i];
	}
	cout<<endl;
	for(i=0;i<=n;i++){
		cout<<"x["<<i<<"]= "<<x[i]<<" \t";
	}
	cout<<endl;
	for(i=0;i<=n;i++){
		cout<<"f(x["<<i<<"])= "<<f[i]<<" \t";
	}
	cout<<"\n"<<endl;
	for(i=0;i<=n;i++){
		b[i]=difDivProgresiva(0,i,x,f);
		cout<<"  b["<<i<<"]= "<<b[i]<<endl;
	}
	do{
		cout<<"\nIngrese X de f(X) a aproximar: ";
		cin>>c;
		aprox=0;
		p=0;
		for(i=0;i<=n;i++){
			aprox=b[i];
			for(j=0;j<i;j++){
				aprox*=(c-x[j]);
			}
			p+=aprox;
		}
		cout<<"   el Polinomio P["<<n<<"]("<<c<<")= "<<p<<" aproxima a f("<<c<<")"<<endl;
		cout<<"\n\tdesea ingresar otro x?(S/N)  ";
		cin>>res;
	}while(res=='s' || res=='S');
}
