#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

void mx_free(TMatrix *m) {
	if (m != NULL)
		if (m->a != NULL) {
			free(m->a);
			free(m);
		}
}

void mx_print(TMatrix *m) {
	unsigned int i, j;

	if (m != NULL) {
		if (m->a != NULL) {
			for (i = 0; i < m->m; i++) {
				for (j = 0; j < m->n; j++)
					printf("%8.2lf", m->a[i * m->n + j]);
				printf("\n");
			}
		}
	}
}

TMatrix *mx_identity(unsigned int n) {
	unsigned int i, j;
	TMatrix *m = NULL;

	m = (TMatrix*)malloc(sizeof(TMatrix));
	if (m != NULL) {
		m->a = (double*)malloc(n * n * sizeof(double));
		if (m->a != NULL) {
			m->n = m->m = n;
			for (i = 0; i < m->m; i++)
				for (j = 0; j < m->n; j++)
					m->a[i * n + j] = i == j ? 1 : 0;
		}
		else {
			free(m);
			m = NULL;
		}
	}

	return m;
}


void mx_sort(TMatrix *m)
{
    int size =m->n * m->m;
    
    bubbleSort(m->a, size);

    
    
    int x = 0;
    int y = 0;
    double array[m->n][m->m];

    for (int i =0; i < m->n; i++)
        for (int j =0; j < m->m; j++){
            array[i][j]=m->a[i + j * m->n];
        }


    

    int index = 0;
    while (index < size){
            m->a[x + y * m->n] = array[index%m->n][index/m->m];
        while (y > 0 && x < m->n - 1){
            y--;
            x++;
            index++;
            m->a[x + y * m->n] = array[index%m->n][index/m->m];
        }
        if (y==0 && x < m->n-1)
            x++;
        else
        y++;
        index++;
        m->a[x + y * m->n] = array[index%m->n][index/m->m];
        

        while (x > 0 && y < m->m - 1){
            y++;
            x--;
            index++;
            m->a[x + y * m->n] = array[index%m->n][index/m->m];
        }
        if (x==0 && y < m->m-1)
            y++;
        else
            x++;
        index++;
        m->a[x + y * m->n] = array[index%m->n][index/m->m];
        
    }

   
}

void bubbleSort(double *num, int size)
{
  // Для всех элементов
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
    {
      if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
      {
        int temp = num[j - 1]; // меняем их местами
        num[j - 1] = num[j];
        num[j] = temp;
      }
    }
  }
}