#include <stdio.h>
#include <stdlib.h>
void print_matrix(int **add,int **arr, int row1, int col1,int **arr2, int row2, int col2, int **sub, int **trans,int **mul); // 함수선언 printf로 배열을 출력하는 함수
void addtion_matrix(int **add, int **arr,int **arr2,int row1, int col1);
void subtraction_matrix(int **sub, int **arr,int **arr2,int row1, int col1);
void transpose_matrix(int **trans, int **arr, int row1, int col1);
void multiply_matrix(int **mul, int **arr, int row1, int col1,int **arr2, int row2, int col2);
int main()
{
    int row1, col1;
    int num1;
    printf("배열A의 행과 열을 정해주세요 :");
    scanf_s("%d %d", &row1, &col1);           // scanf로 배열의 크기를 정한다.
    int **arr = malloc(sizeof(int *) * row1); // 이중 포인터에 (int 포인터 크기 * row) 만큼 동적 메모리 할당. 배열의 세로이다

    for (int i = 0; i < row1; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        arr[i] = malloc(sizeof(int) * col1);
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("배열 A의 %d열 %d 행 입력", j + 1, i + 1); // scanf를 통해서 배열의 값들을 받는다.
            scanf("%d", &num1);

            arr[i][j] = num1;
        }
    }

    int row2, col2;
    int num2;
    printf("배열B의 행과 열을 정해주세요 :");
    scanf_s("%d %d", &row2, &col2);           // scanf로 배열의 크기를 정한다.
    int **arr2 = malloc(sizeof(int *) * row2); // 이중 포인터에 (int 포인터 크기 * row) 만큼 동적 메모리 할당. 배열의 세로이다

    for (int i = 0; i < row2; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        arr2[i] = malloc(sizeof(int) * col2);
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("배열B의 %d열 %d 행 입력", j + 1, i + 1); // scanf를 통해서 배열의 값들을 받는다.
            scanf("%d", &num2);

            arr2[i][j] = num2;
        }
    }


    int **add = malloc(sizeof(int *) * row1);

    for (int i = 0; i < row1; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        add[i] = malloc(sizeof(int) * col1);
    }

    int **sub = malloc(sizeof(int *) * row1);

    for (int i = 0; i < row1; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        sub[i] = malloc(sizeof(int) * col1);
    }
    
    int **trans = malloc(sizeof(int *) * col1);

    for (int i = 0; i < col1; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        trans[i] = malloc(sizeof(int) * row1 );
    }

    
    int **mul = malloc(sizeof(int *) * row1);

    for (int i = 0; i < row1; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        mul[i] = malloc(sizeof(int) * col2 );
    }
    
    addtion_matrix(add,arr,arr2,row1,col1 );
    subtraction_matrix(sub,arr,arr2,row1,col1);
    transpose_matrix(trans,arr, row1, col1);
    multiply_matrix(mul, arr, row1, col1, arr2, row2, col2);

    print_matrix( add, arr, row1, col1, arr2, row2, col2, sub, trans,mul); // 출력하는 함수 호출
    

    for (int i = 0; i < row1; i++) // free로 할당받은 2차원 배열 메모리를 다시 해제한다.
    {
        free(arr[i]);
    }
        for (int i = 0; i < row2; i++) // free로 할당받은 2차원 배열 메모리를 다시 해제한다.
    {
        free(arr2[i]);
    }
    for (int i = 0; i < row1; i++) // free로 할당받은 2차원 배열 메모리를 다시 해제한다.
    {
        free(add[i]);
    }
    for (int i = 0; i < row1; i++) // free로 할당받은 2차원 배열 메모리를 다시 해제한다.
    {
        free(sub[i]);
    }
    for (int i = 0; i < col1; i++) // free로 할당받은 2차원 배열 메모리를 다시 해제한다.
    {
        free(trans[i]);
    }
     for (int i = 0; i < col2; i++) // free로 할당받은 2차원 배열 메모리를 다시 해제한다.
    {
        free(mul[i]);
    }
    
    free(arr);
    free(arr2);
    free(add);
    free(sub);
    free(trans);
    free(mul);
}


void print_matrix(int **add,int **arr, int row1, int col1,int **arr2, int row2, int col2, int **sub,int **trans, int **mul) // 배열 출력하는 함수
{
    printf("배열 A : \n");
    for (int i = 0; i < row1; i++) // row값과 col값을 받아서 프린트한다.
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("배열 b : \n");

        for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
if (row1 == col1){
    printf("A + B : \n");

        for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", add[i][j]);
        }
        printf("\n");
    }

    printf("A - B : \n");

        for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
}
    printf("A의 전치행렬 : \n");

        for (int i = 0; i < col1; i++)
    {
        for (int j = 0; j < row1; j++)
        {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }

if(col1== row2){
    printf("A x B : \n");

        for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
}

}


void addtion_matrix(int **add, int **arr,int **arr2,int row1, int col1){ //행렬의 덧셈 
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        { 
            add[i][j] = arr[i][j] + arr2[i][j];
        }
    }

}

void subtraction_matrix(int **sub, int **arr,int **arr2,int row1, int col1){
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        { 
            sub[i][j] = arr[i][j] - arr2[i][j];
        }
    }
}

void transpose_matrix(int **trans, int **arr, int row1, int col1){
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        { 
            trans[j][i] = arr[i][j] ;
        }
    }
}

void multiply_matrix(int **mul, int **arr, int row1, int col1,int **arr2, int row2, int col2){
        for(int i = 0; i < row1; i++)
            for(int j = 0; j < col2; j++){
                mul[i][j] = 0;
            }

        for(int i = 0; i < row1; i++)
            for(int j = 0; j < col2; j++){
                for(int k = 0; k < col1; k++)
				    mul[i][j] = mul[i][j] + arr[i][k] * arr2[k][j];
		}
}

