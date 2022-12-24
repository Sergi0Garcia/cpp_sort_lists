// PRACTICA 1 - ORDENAR LISTAS
// Sergio Garcia A01634768
// Metodo utilizado "Selection sort" 
// Guia y codigo ejemplo de https://softwaretestinghelp.com

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <ctime>
using namespace std;

void printList(float *array, int size);
void sortList(float *array, int size);
void homework_sortList(float *array, int size);
int findSamllestPosition(float *array, int index, int size);

int main()
{
	const int klist_size = 1500;
	const int num_experiments = 1000;
	const float boundary = 10.0f;
	float number_list[klist_size];

	clock_t begin;
	clock_t end;
	float total_time = 0.0;

	srand(time(NULL));

	for(int ide=0; ide < num_experiments; ide++)
	{
		for(int idx=0; idx < klist_size; idx++)
		{
			number_list[idx] = boundary * ((float)rand()/(float)RAND_MAX);
		}
		begin = clock();
		// printList(number_list, klist_size);
		// sortList(number_list, klist_size);
		homework_sortList(number_list, klist_size);
		//printList(number_list, klist_size);
		end = clock();
		total_time += (float)(end - begin) / CLOCKS_PER_SEC;
	}
	std::cout << "Average time: "<< total_time / float(num_experiments) << std::endl;
	return 0;
}

// Funcion de clase
// Metodo basico tambien llamado bubble sort
// Se va comparando cada elemento con su adyacente y si es menor se swipea
void sortList(float *array, int size)
{
	for(int idx=0; idx < size; idx++)
	{
		for(int idy = idx+1; idy<size; idy++)
		{
			if (array[idx] > array[idy])
			{
				float temporal = array[idx];
				array[idx] = array[idy];
				array[idy] = temporal;
			}
		}
	}
}

void printList(float *array, int size)
{
	for(int idx=0; idx<size; idx++)
	{
		std::cout << array[idx] << " ";
	}
	std::cout << std::endl;
}

// Funcion auxiliaria para metodo de seleccion
// Se hace un for por del indice que se le pasa en adelante
// Cuando se encuentra el valor minio, la funcion regrea ese valor
int findSamllestPosition(float *array, int index, int size)
{
	float smallest_element;
	int position;
	int j;
	smallest_element = array[index];
	position = index;
	for(j=index + 1; j<size; j++)
	{
		if (array[j]<smallest_element)
		{
			smallest_element = array[j];
			position = j;
		}
	}
	return position;
}

// Se utilizo el metodo de seleccion
// Guia y codigo ejemplo de https://softwaretestinghelp.com
// Se va buscando el valor mas pequeno y se va asignando a su posicion indicada
// El for asegura que ya no tome y cheque las posiciones ya acomodadas

void homework_sortList(float *array, int size)
{
	int pos;
	float temp;
	for(int i=0; i<size; i++)
	{
		pos = findSamllestPosition(array, i, size);
		temp = array[i];
		array[i] = array[pos];
		array[pos] = temp;
	}
}
