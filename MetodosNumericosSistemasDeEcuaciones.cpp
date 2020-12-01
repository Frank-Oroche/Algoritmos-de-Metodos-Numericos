/*
 * nomprograma :Solucion Numerica de Sistemas de Ecuaciones
 * descripcion :Metodos:
 *					-Eliminacion Gaussiana sin Pivoteo
 *					-Eliminacion Gaussiana con Pivoteo Parcial
 *					-Eliminacion Gaussiana con Pivoteo Escalado
 *					-Factorizacion A=LU
 *					-Factorizacion PA=LU
 *					-Factorizacion de Choleski
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
#define maximo 50

using namespace std ;

void EGaussiana();
void EGaussianaPP();
void EGaussianaPE();
void FALU();
void FPALU();
void FCholeski();

int menu(){
	int op;
	do{
		system("cls");
		printf("\tMENU\n");
		printf("[1]: Eliminacion Gaussiana sin Pivoteo\n");
		printf("[2]: Eliminacion Gaussiana con Pivoteo Parcial\n");
		printf("[3]: Eliminacion Gaussiana con Pivoteo Escalado\n");
		printf("[4]: Factorizacion A=LU\n");
		printf("[5]: Factorizacion PA=LU\n");
		printf("[6]: Factorizacion de Choleski\n");
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
				EGaussiana();
				break;
			case 2:
				EGaussianaPP();
				break;
			case 3:
				EGaussianaPE();
				break;
			case 4:
				FALU();
				break;
			case 5:
				FPALU();
				break;
			case 6:
				FCholeski();
				break;
			default:
				break;
		}
	}while(op!=7);
	
   return(0) ;
}

void ver_matriz(float m[maximo][maximo], int n){
	int i,j;
	cout<<"\n   matriz : \n";
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			if(j==n){
				cout<<"|"<<m[i][j];
			}else{
				cout<<m[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

void leer_matriz(float m[maximo][maximo], int n){
	int i,j;
	cout<<"\n";
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			if(j==n){
				cout<<"b["<<(i+1)<<","<<(j+1)<<"]= ";
				cin>>m[i][j];
			}else{
				cout<<"m["<<(i+1)<<","<<(j+1)<<"]= ";
				cin>>m[i][j];
			}
		}
	}
	ver_matriz(m,n);
}

void cambiar_fila(float m[maximo][maximo], int n, int a, int b){
	int i,j;
	float aux;
	for(i=0;i<=n;i++){
		aux=m[a][i];
		m[a][i]=m[b][i];
		m[b][i]=aux;
	}
	cout<<"\nSe a cambiado la fila["<<b+1<<"] por la fila["<<a+1<<"]"<<endl;
	ver_matriz(m,n);
}

int MaxColumna(float m[maximo][maximo], int n){
	float mayor=0;
	int i,fila;
	for(i=0;i<n;i++){
		if(abs(m[i][0])>mayor){
			mayor=m[i][0];
			fila=i;
		}
	}
	return fila;
}

bool matriz_simetrica(float m[maximo][maximo], int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(m[i][j]!=m[j][i]){
				return false;
			}
		}
	}
}

bool matriz_positiva(float m[maximo][maximo], int n){
    float suma;
    int i,k;
    for(i=0;i<n;i++){
    	suma=0;
    	for(k=0;k<i;k++){
    		suma = suma + (m[i][k])*(m[i][k]);
		}
		if(m[i][i]<suma){
			return false;
		}
	}
}

void EGaussiana(){
	float m[maximo][maximo],aux;
	int n,i,j,k;
	cout<<"\n Matriz cuadrada de orden N= ";
	cin>>n;
	cout<<"\n Digite los elementos de la matriz en la posicion ";
	leer_matriz(m,n);
	for(i=0;i<n;i++){
		if(m[i][i]!=0){
			aux=1/m[i][i];
			for(j=0;j<n+1;j++){
				m[i][j]=aux*m[i][j];
			}
 			for(j=0;j<n;j++){
				if(j!=i){
					aux=-m[j][i];
					for(k=0;k<n+1;k++){
						m[j][k]=m[j][k]+aux*m[i][k];
					}
				}
			}
		}
	}
	ver_matriz(m,n);
	cout<<"\nEl valor de las incognitas es : \n";
	for(i=0;i<n;i++){
		cout<<"X["<<i+1<<"] = "<<m[i][n]<<"\n";
	}
	getche();
}

void EGaussianaPP(){
	float m[maximo][maximo],aux;
	int n,i,j,k,p,fila;
	cout<<"\n Matriz cuadrada de orden N= ";
	cin>>n;
	cout<<"\n Digite los elementos de la matriz en la posicion ";
	leer_matriz(m,n);
	fila=MaxColumna(m,n);
	cambiar_fila(m,n,fila,0);
	for(i=0;i<n;i++){
		if(m[i][i]!=0){
			aux=1/m[i][i];
			for(j=0;j<n+1;j++){
				m[i][j]=aux*m[i][j];
			}
 			for(j=0;j<n;j++){
				if(j!=i){
					aux=-m[j][i];
					for(k=0;k<n+1;k++){
						m[j][k]=m[j][k]+aux*m[i][k];
					}
				}
			}
		}
	}
	ver_matriz(m,n);
	cout<<"\nEl valor de las incognitas es : \n";
	for(i=0;i<n;i++){
		cout<<"X["<<i+1<<"] = "<<m[i][n]<<"\n";
	}
	getche();
}

void EGaussianaPE(){
	float m[maximo][maximo],aux;
	float s[maximo],a[maximo];
	int n,i,j,k,p,fila,mayor=0;
	cout<<"\n Matriz cuadrada de orden N= ";
	cin>>n;
	cout<<"\n Digite los elementos de la matriz en la posicion ";
	leer_matriz(m,n);
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			if(abs(m[j][i])>s[j]){
				s[j]=m[j][i];
			}
		}
	}
	for(i=0;i<n;i++){
		a[i]=abs(m[i][0])/s[i];
	}
	for(i=0;i<n;i++){
		if(abs(a[i])>mayor){
			mayor=m[i][0];
			fila=i;
		}
	}
	cambiar_fila(m,n,fila,0);
	for(i=0;i<n;i++){
		if(m[i][i]!=0){
			aux=1/m[i][i];
			for(j=0;j<n+1;j++){
				m[i][j]=aux*m[i][j];
			}
 			for(j=0;j<n;j++){
				if(j!=i){
					aux=-m[j][i];
					for(k=0;k<n+1;k++){
						m[j][k]=m[j][k]+aux*m[i][k];
					}
				}
			}
		}
	}
	ver_matriz(m,n);
	cout<<"\nEl valor de las incognitas es : \n";
	for(i=0;i<n;i++){
		cout<<"X["<<i+1<<"] = "<<m[i][n]<<"\n";
	}
	getche();
}

void FALU(){
	float A[maximo][maximo],L[maximo][maximo],U[maximo][maximo],e[maximo][maximo],aux;
	int n,i,j,k;
	cout<<"\n Matriz cuadrada de orden N= ";
	cin>>n;
	cout<<"\n Digite los elementos de la matriz en la posicion ";
	leer_matriz(A,n);
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			U[i][j]=A[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			if(i==j){
				e[i][j]=1;
			}else{
				e[i][j]=0;
			}
		}
	}
	for(k=1;k<n;k++){
		for(j=k;j<n;j++){
			aux=(U[j][k-1]/U[k-1][k-1]);
			e[j][k-1]=aux;
			for(i=0;i<=n;i++){
				U[j][i]=U[j][i]-U[k-1][i]*aux;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			L[i][j]=e[i][j];
		}
	}
	cout<<"\n   matriz L: \n";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n   matriz U: \n";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<U[i][j]<<" ";
		}
		cout<<endl;
	}
	for(i=0;i<n;i++){
		if(A[i][i]!=0){
			aux=1/A[i][i];
			for(j=0;j<n+1;j++){
				A[i][j]=aux*A[i][j];
			}
 			for(j=0;j<n;j++){
				if(j!=i){
					aux=-A[j][i];
					for(k=0;k<n+1;k++){
						A[j][k]=A[j][k]+aux*A[i][k];
					}
				}
			}
		}
	}
	cout<<"\nEl valor de las incognitas es : \n";
	for(i=0;i<n;i++){
		cout<<"X["<<i+1<<"] = "<<A[i][n]<<"\n";
	}
	getche();
}

void FPALU(){
	float P[maximo][maximo],A[maximo][maximo],L[maximo][maximo],U[maximo][maximo],e[maximo][maximo],aux;
	int n,i,j,k;
	cout<<"\n Matriz cuadrada de orden N= ";
	cin>>n;
	cout<<"\n Digite los elementos de la matriz en la posicion ";
	leer_matriz(A,n);
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			if(i==j){
				P[i][j]=1;
			}else{
				P[i][j]=0;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			U[i][j]=A[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			if(i==j){
				e[i][j]=1;
			}else{
				e[i][j]=0;
			}
		}
	}
	for(k=1;k<n;k++){
		for(j=k;j<n;j++){
			aux=(U[j][k-1]/U[k-1][k-1]);
			e[j][k-1]=aux;
			for(i=0;i<=n;i++){
				if(U[j][i]==0){
					cambiar_fila(A,n,j,j-1);
					cambiar_fila(U,n,j,j-1);
					cambiar_fila(P,n,j,j-1);
				}else{
					U[j][i]=U[j][i]-U[k-1][i]*aux;
				}
			}
		}
	}
	system("cls");
	for(i=0;i<n;i++){
		for(j=0;j<=n;j++){
			L[i][j]=e[i][j];
		}
	}
	ver_matriz(A,n);
	cout<<"\n   matriz P: \n";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<P[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n   matriz U: \n";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<U[i][j]<<" ";
		}
		cout<<endl;
	}
	for(i=0;i<n;i++){
		if(A[i][i]!=0){
			aux=1/A[i][i];
			for(j=0;j<n+1;j++){
				A[i][j]=aux*A[i][j];
			}
 			for(j=0;j<n;j++){
				if(j!=i){
					aux=-A[j][i];
					for(k=0;k<n+1;k++){
						A[j][k]=A[j][k]+aux*A[i][k];
					}
				}
			}
		}
	}
	cout<<"\nEl valor de las incognitas es : \n";
	for(i=0;i<n;i++){
		cout<<"X["<<i+1<<"] = "<<A[i][n]<<"\n";
	}
	getche();
}

void FCholeski(){
	float A[maximo][maximo],L[maximo][maximo],Lt[maximo][maximo],aux,suma=0,sum=0;
	int n,i,j,k;
	cout<<"\n Matriz cuadrada de orden N= ";
	cin>>n;
	cout<<"\n Digite los elementos de la matriz en la posicion ";
	cout<<"\n";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<"m["<<(i+1)<<","<<(j+1)<<"]= ";
			cin>>A[i][j];
		}
	}
	if(matriz_simetrica(A,n)){
		cout<<"la matriz es simetrica";
		if(matriz_positiva(A,n)){
			cout<<" y definida positiva"<<endl;
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					L[i][j]=A[i][j];
				}
			}
			cout<<"\n   matriz A: \n";
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					cout<<L[i][j]<<" ";
				}
				cout<<endl;
			}
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(i<j){
						L[i][j]=0;
					}
				}
			}
			L[0][0]=sqrt(A[0][0]);
			for(i=1;i<n;i++){
				L[i][0]=A[i][0]/L[0][0];
			}
			L[1][1]=sqrt(A[1][1]-pow(L[1][0],2));
			for(i=2;i<n;i++){
				for(j=1;j<i;j++){
					suma = 0;   
				    for(k=0;k<j;k++){
				        suma=suma+(L[i][k])*(L[j][k]);
				    }
					L[i][j]=(A[i][j]-suma)/L[j][j];
				}
				suma = 0;   
			    for(k=0;k<i;k++){
			        suma=suma+(L[i][k])*(L[i][k]);
			    }
				L[i][i]=sqrt(A[i][i]-suma);
			}
			cout<<"\n   matriz L: \n";
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					cout<<L[i][j]<<" ";
				}
				cout<<endl;
			}
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					Lt[j][i]=L[i][j];
				}
			}		
			cout<<"\n   matriz L transpuesta: \n";
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					cout<<Lt[i][j]<<" ";
				}
				cout<<endl;
			}
		}else{
			cout<<" y no es definida positiva"<<endl;
			cout<<"  No se puede realizar la Factorizacion de Choleski"<<endl;
			getche();
			return;
		}
	}else{
		cout<<"la matriz no es simetrica"<<endl;
		cout<<"  No se puede realizar la Factorizacion de Choleski"<<endl;
		getche();
		return;
	}
	getche();
}
