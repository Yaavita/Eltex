#include <stdio.h>

#define N 5

void first_dz (size_t m)
{   puts("Первое задание:\n");
    //заполняем матрицу
    int arr[m][m];
    int x = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = x;
            x += 1;
        }
    }
   //выводим матрицу
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", arr[i][j]);
        }
    printf ("\n");
    }
    printf ("\n");
}

void second_dz (size_t m)
{
    puts("Второе задание:\n");
    puts("Введите значения элементов массива:");
    int arr[m];
      for (int i = 0; i < m; i++)
      {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
      }

    for(int i = 1; i < m; ++i) //метод пузырька
    {
        for(int j = 0; j < m-i; j++)
        {
            if(arr[j] < arr[j+1])
            {
                // Обмен местами с помощью переменой темп
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < m; i++){
        printf(" %d ", arr[i]);
    }
    printf ("\n\n");
}

void third_dz(size_t m)
{
    puts("Третье задание:\n");
    int arr[m][m];
    //заполняем матрицу единичками
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = 1;
        }
    }
    //заполняем нужную часть матрицы нулями
    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < m-i-1; j++) {
            arr[i][j] = 0;
        }
    }
    
    //выводим матрицу
     for (int i = 0; i < m; i++) {
         for (int j = 0; j < m; j++) {
             printf("%5d", arr[i][j]);
         }
     printf ("\n");
     }
     printf ("\n");
}

void fourth_dz(size_t m)
{
    puts("Четвертое задание:\n");
    int arr[m][m];
    int i = 1;
    int k = 0;//счетчик
    int p = (int) m/2;
    
    for(k = 1; k <= p; k++)// идем по счетчику к
    {
        // верхняя сторона
        for (int j = k-1; j < m-k+1; j++) {
            arr[k-1][j] = i++;
        }
        // правая сторона
        for (int j = k; j < m-k+1; j++) {
            arr[j][m-k] = i++;
        }
        // нижняя сторона
        for (int j = (int)(m-k-1); j >= k-1; --j) {
            arr[m-k][j] = i++;
        }
        // левая сторона
        for (int j = (int)(m-k-1);j >= k; j--) {
            arr[j][k-1] = i++;
        }
    }
    if (m % 2 == 1) {
        arr[p][p] = (int)(m * m);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0;j < m; j++)
        {
            printf("%5d", arr[i][j]);
            if (j == m-1) {
                printf("\n");
            }
        }
    }
}
    

int main(void)
{
    first_dz(N);
    second_dz(N);
    third_dz(N);
    fourth_dz(N);
    
    return 0;
}
