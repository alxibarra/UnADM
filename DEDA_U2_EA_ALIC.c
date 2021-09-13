#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//funcion para eliminar elementos de los arreglo se colocara un 0 en su lugar

void eliminarelementos(int a[],int tam){
	int contador = 0;
	int i,j,k;
	int cam;
	for( i = 0; i < tam-1; i++){
		for( j = 0; j < tam-2; j++){
			if(a[i]==a[j]){
				contador++;
			}
		}
		cam = 0;
		if(contador > 1){
			for(k = 0; k < tam; k++){
				if(a[i]==a[k]){
					cam++;
					if(cam > 1){
						a[i] = a[k+1];
					}
				}
			}
		    a[tam-1]=0;
		}
	}
}

//funcion para buscar de manera secuancial
int buscar(int a[],int tam, int loc){
	int indice = 0;
	int i;
	for(i = 1; i <= tam; i++){
		if(loc == a[i-1]){
			indice = i;
			i = tam;
		}
	}
	
	return indice;
	 	
}

//funcion para ordenar lo elemento quicksort
int ordenRapido(int a[], int primero, int ultimo){
		
	int central = (primero + ultimo)/2;	
    int pivote = a[central];
	int i = primero;
	int j = ultimo;
	int tmp;
	int contador = 0;
	do {
		while (a[i] < pivote) i++;
		while (a[j] > pivote) j--;
		if (i <= j){	
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
	    }
	    contador++;
	}while (i <= j);
	if (primero < j){
		ordenRapido(a, primero, j);
	}
	    
	if (i < ultimo){
		ordenRapido(a, i, ultimo);
	}
	return contador;
} 

//funcion para ver que gana mas
void ganamas(int a[],int b[],int tam){
	int sum1 = 0;
	int sum2 = 0;
	int i, res;
	for(i = 0; i<tam; i++){
		sum1 = sum1 + a[i];
		sum2 = sum2 + b[i];
	}
	
	if(sum1>sum2){
		res = sum1-sum2;
		printf("\n El sueldo de Claudia es mayor al de Juan por una diferencia de: %d",res);
	}else{
		res = sum2-sum1;
		printf("\n El sueldo de Juan es mayor al de Claudia por una diferencia de: %d",res);
	}
}

//funcion para validar el promedio de los sueldos
void promedio(int a[],int b[],int tam){
	int sum1 = 0;
	int sum2 = 0;
	int i;
	float res1, res2;
	for(i = 0; i<tam; i++){
		sum1 = sum1 + a[i];
		sum2 = sum2 + b[i];
	}
	
	res1 = (float)sum1/(float)tam;
	res2 = (float)sum2/(float)tam;
	
	printf("\n El sueldo promedio de Claudia es de: %f",res1);
	printf("\n El sueldo promedio de Juan es de: %f",res2);
	
}

//funcion poara identifica si son iguales en la posicion 5
void identificar(int a[],int b[],int tam){
	int r1 = ordenRapido(a,0,tam-1);
	int r2 = ordenRapido(b,0,tam-1);
	if(a[4] == b[4]){
		printf("\n Son iguales: %d",a[4]);
	}else{
		printf("\n No son iguales. Claudia %d  Juan %d",a[4],b[4]);
	}
	
}
				


int main(){	
	
	printf(" Universidad Abierta y a Distancia de México \n");
	printf(" Estructura de datos \n");
	printf(" Evidencia de aprendizaje: Metodos de ordenacion y busqueda de datos.\n");
	printf(" Alumno Alejandro Ibarra Cruz \n");
	printf(" Docente Alfredo Orozco Escobar\n");
	printf(" \n");	
	int el = 20;
	int sueldoClaudia[el];
	int sueldoJuan[el];
	int temp1[el],temp2[el];
	int temp, i, j, res;
	int indice, aux;
	printf("Ingrese los sueldos de Claudia: \n");
	
	for(i = 0; i < el; i++){
		printf("\nSueldo %d :",i+1);
		scanf("%d", &sueldoClaudia[i]);
		temp1[i] = sueldoClaudia[i];
	}
	printf("Ingrese los sueldos de Juan: \n");
	for(i = 0; i < el; i++){
		printf("\nSueldo %d :",i+1);
		scanf("%d", &sueldoJuan[i]);
		temp2[i] = sueldoJuan[i];
	}
	system("cls");
	
	int opcion = 1;
	
	do{
		printf("\nIngrese una opcion:");
		printf("\n1. Imprimir arreglos en pantalla");
		printf("\n-------------------------------");
		printf("\n-Ordenar por");
		printf("\n2. Burbuja");
		printf("\n3. Insercion");
		printf("\n4. Seleccion");
		printf("\n5. Quicksort");
		printf("\n-------------------------------");
		printf("\n6. Eliminar sueldo repetido");
		printf("\n-------------------------------");
		printf("\nBuscar sueldo de");
		printf("\n7. Suledo Claudia");
		printf("\n8. Sueldo Juan");
		printf("\n-------------------------------");
		printf("\n9. Operaciones Complementarias");
		printf("\n-------------------------------");
		printf("\n0. Salir \n");
		
		scanf("%d", &opcion);
	
		switch(opcion){
			//imprime datos en pantalla
			case 1:
				system("cls");
			    printf("\n#Sueldo  Claudia    Juan\n");
				for(i = 0; i < el; i++){
					printf("\n %d       %d         %d ",i+1,sueldoClaudia[i],sueldoJuan[i]);
				}
			    printf("\n");
			    system("pause");
			    system("cls");
				break;
			//Metodo de ordenamiento de burbuja
			case 2:
				system("cls");
			    printf("\nOrdenamiento por burbuja\n");
				int ciclo1 = 0;
				int ciclo2 = 0;
				
				for(i = 0; i< el-1;i++){
				    for(j=el-1;j>i;j--){
				       if(temp1[j]<temp1[j-1]){
				          temp = temp1[j];
				          temp1[j] = temp1[j-1];
				          temp1[j-1] = temp;
				       	  ciclo1++;
					   }
					     
				    }
				}
				for(i = 0; i< el-1;i++){
				    for(j=el-1;j>i;j--){
				       if(temp2[j]<temp2[j-1]){
				          temp = temp2[j];
				          temp2[j] = temp2[j-1];
				          temp2[j-1] = temp;
				       	  ciclo2++;  
					   }
					   
				    }
				}

				printf("\n#Sueldo  Claudia    Juan\n");
				for(i = 0; i < el; i++){
					printf("\n %d       %d         %d ",i+1,temp1[i],temp2[i]);
				}
				printf("\nNumero de iteraciones Claudia: %d Juan: %d",ciclo1,ciclo2);
				int op = 0;
				printf("\nDesea aplicar el ordenamiento (1)Si o intentar con uno nuevo (2)No");
				scanf("%d", &op);
				
				if(op == 1){
					for(i = 0; i < el; i++){
						sueldoClaudia[i] = temp1[i];	
						sueldoJuan[i] = temp2[i];
					}
					printf("\n Se aplico el ordenamiento burbuja");
				}else{
					for(i = 0; i < el; i++){
						temp1[i] = sueldoClaudia[i];	
						temp2[i] = sueldoJuan[i];
					}
					printf("\n No se aplico el ordenamiento");
				}
					
			    printf("\n");
			    system("pause");
			    system("cls");
				break;
			
			//Metodo de ordenamiento por inserción
			case 3:
				system("cls");
			    printf("\nOrdenamiento por insercion\n");
				ciclo1 = 0;
				ciclo2 = 0;
				
				for(i = 0; i< el; i++){
				    j = i;
				    aux = temp1[i];
				    while (j > 0 && aux < temp1[j-1]){
				      temp1[j] = temp1[j-1];
					  j--;
					  ciclo1++;
				    }
				    temp1[j] = aux;
				    
				}
				for(i = 0; i< el; i++){
				    j = i;
				    aux = temp2[i];
				    while (j > 0 && aux < temp2[j-1]){
				      temp2[j] = temp2[j-1];
				      j--;
				      ciclo2++;
					}
				    temp2[j] = aux;
				   	
				}

				printf("\n#Sueldo  Claudia    Juan\n");
				for(i = 0; i < el; i++){
					printf("\n %d       %d         %d ",i+1,temp1[i],temp2[i]);
				}
				printf("\nNumero de iteraciones Claudia: %d Juan: %d",ciclo1,ciclo2);
				op = 0;
				printf("\nDesea aplicar el ordenamiento (1)Si o intentar con uno nuevo (2)No");
				scanf("%d", &op);
				
				if(op == 1){
					for(i = 0; i < el; i++){
						sueldoClaudia[i] = temp1[i];	
						sueldoJuan[i] = temp2[i];
					}
					printf("\n Se aplico el ordenamiento insercion");
				}else{
					for(i = 0; i < el; i++){
						temp1[i] = sueldoClaudia[i];	
						temp2[i] = sueldoJuan[i];
					}
					printf("\n No se aplico el ordenamiento");
				}
					
			    printf("\n");
			    system("pause");
			    system("cls");
				break;
				
			//Metodo de ordenamiento por selección
			case 4:
				system("cls");
			    printf("\nOrdenamiento por seleccion\n");
				ciclo1 = 0;
				ciclo2 = 0;
				
				for(i = 0; i< el; i++){
				    indice = i;
					for (j = i+1; j < el; j++){
						if (temp1[j] < temp1[indice]){
						   indice = j;
						   if (i != indice){
						      aux = temp1[i];
						      temp1[i] = temp1[indice];
						      temp1[indice] = aux ;
						      ciclo1++;
						   }
						}
					}
				}
				for(i = 0; i< el; i++){
				    indice = i;
					for (j = i+1; j < el; j++){
						if (temp2[j] < temp2[indice]){
						   indice = j;
						   if (i != indice){
						      aux = temp2[i];
						      temp2[i] = temp2[indice];
						      temp2[indice] = aux;
						      ciclo2++;
						   }
						}
					}
				}

				printf("\n#Sueldo  Claudia    Juan\n");
				for(i = 0; i < el; i++){
					printf("\n %d       %d         %d ",i+1,temp1[i],temp2[i]);
				}
				printf("\nNumero de iteraciones Claudia: %d Juan: %d",ciclo1,ciclo2);
				op = 0;
				printf("\nDesea aplicar el ordenamiento (1)Si o intentar con uno nuevo (2)No");
				scanf("%d", &op);
				
				if(op == 1){
					for(i = 0; i < el; i++){
						sueldoClaudia[i] = temp1[i];	
						sueldoJuan[i] = temp2[i];
					}
					printf("\n Se aplico el ordenamiento seleccion");
				}else{
					for(i = 0; i < el; i++){
						temp1[i] = sueldoClaudia[i];	
						temp2[i] = sueldoJuan[i];
					}
					printf("\n No se aplico el ordenamiento");
				}
					
			    printf("\n");
			    system("pause");
			    system("cls");
				break;
				
				//Metodo de ordenamiento por quicksort
			case 5:
				system("cls");
			    printf("\nOrdenamiento por QuickSort\n");
				ciclo1 = ordenRapido(temp1,0,el-1);
				ciclo2 = ordenRapido(temp2,0,el-1);
				
				
				
				printf("\n#Sueldo  Claudia    Juan\n");
				for(i = 0; i < el; i++){
					printf("\n %d       %d         %d ",i+1,temp1[i],temp2[i]);
				}
				printf("\nNumero de iteraciones Claudia: %d Juan: %d",ciclo1,ciclo2);
				op = 0;
				printf("\nDesea aplicar el ordenamiento (1)Si o intentar con uno nuevo (2)No");
				scanf("%d", &op);
				
				if(op == 1){
					for(i = 0; i < el; i++){
						sueldoClaudia[i] = temp1[i];	
						sueldoJuan[i] = temp2[i];
					}
					printf("\n Se aplico el ordenamiento QuickSort");
				}else{
					for(i = 0; i < el; i++){
						temp1[i] = sueldoClaudia[i];	
						temp2[i] = sueldoJuan[i];
					}
					printf("\n No se aplico el ordenamiento");
				}
					
			    printf("\n");
			    system("pause");
			    system("cls");
				break;
				
			//Eliminar elemntos repetidos
			case 6:
				system("cls");
			    printf("\nEliminar elementos repetidos\n");
				
				eliminarelementos(temp1,el);
				eliminarelementos(temp2,el);
				for(i = 0; i < el; i++){
					sueldoClaudia[i] = temp1[i];	
					sueldoJuan[i] = temp2[i];
				}
				
				printf("\n#Sueldo  Claudia    Juan\n");
				for(i = 0; i < el; i++){
					printf("\n %d       %d         %d ",i+1,sueldoClaudia[i],sueldoJuan[i]);
				}		
			    printf("\n");
			    system("pause");
			    system("cls");
				break;
			case 7:
				system("cls");
			    printf("\nBuscar Sueldo de Claudia");
				printf("\nTeclee el sueldo a buscar: ");
				scanf("%d", &op);
				
				res = buscar(temp1,el,op);
				
				if(res == 0){
					printf("\nEl sueldo a buscar no se encuentra registrado");
				}else{
					printf("\nEl sueldo a buscar se localiza en la posicion: %d",res);	
				}
				
			    printf("\n");
			    system("pause");
			    system("cls");
				break;
			case 8:
				system("cls");
			    printf("\nBuscar Sueldo de Juan");
				printf("\nTeclee el sueldo a buscar: ");
				scanf("%d", &op);
				
				res = buscar(temp2,el,op);
				
				if(res == 0){
					printf("\nEl sueldo a buscar no se encuentra registrado");
				}else{
					printf("\nEl sueldo a buscar se localiza en la posicion: %d",res);	
				}
				
			    printf("\n");
			    system("pause");
			    system("cls");
				break;
			case 9:
				system("cls");
			    printf("\nOperaciones complementarias");
			    
			    ganamas(temp1,temp2,el);
				promedio(temp1,temp2,el);
				identificar(temp1,temp2,el);
					
			    printf("\n");
			    system("pause");
			    system("cls");
				break;	

	    }
	}while(opcion!=0);
	
	return 0;
}
