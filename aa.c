#include <stdio.h>
#include <stdlib.h>
void print_matrix(int **add,int **arr, int row1, int col1,int **arr2, int row2, int col2, int **sub, int **trans,int **mul); 
// 함수선언 printf로 행렬을 출력하는 함수
void addtion_matrix(int **add, int **arr,int **arr2,int row1, int col1);// A+B 함수 선언
void subtraction_matrix(int **sub, int **arr,int **arr2,int row1, int col1);//A-b 함수선언 
void transpose_matrix(int **trans, int **arr, int row1, int col1);//A의 전치행렬 함수 선언
void multiply_matrix(int **mul, int **arr, int row1, int col1,int **arr2, int row2, int col2); //AxB 함수 선언
int main()
{


    printf(" [----- [김승진] [2017038092] -----]\n\n");
    int row1, col1;   //행렬의 행과 열이다.
    int num1;         //스켄f로 받은 값을 저장한다.
    printf("배열A의 행과 열을 정해주세요 :");
    scanf_s("%d %d", &row1, &col1);           // scanf로 행렬의 크기를 정한다. //숫자 엔터 숫자로 행과 열을 받는다.
    int **arr = malloc(sizeof(int *) * row1); // 이중 포인터에 (int 포인터 크기 * row) 만큼 동적 메모리 할당. 행렬의 세로이다

    for (int i = 0; i < row1; i++) // malloc를 사용하여 메모리 할당을 받는다.   
    {
        arr[i] = malloc(sizeof(int) * col1);    //배열의 가로를 동적 메모리를 할당받는다. 
    }


    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("배열 A의 %d열 %d 행 입력", j + 1, i + 1); // scanf를 통해서 행렬의 값들을 받는다.  
            scanf("%d", &num1);             
            arr[i][j] = num1;                               
        }
    }

    int row2, col2;                         //행렬 B의 열과 행의 수를 저장한다.
    int num2;                               //핼렬 B의 값을 scanf할때 사용한다.
    printf("배열B의 행과 열을 정해주세요 :");
    scanf_s("%d %d", &row2, &col2);           // scanf로 행렬의 크기를 정한다.
    int **arr2 = malloc(sizeof(int *) * row2); // 이중 포인터에 (int 포인터 크기 * row) 만큼 동적 메모리 할당. 행렬의 세로이다

    for (int i = 0; i < row2; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        arr2[i] = malloc(sizeof(int) * col2);   //행렬의 가로 (행의 갯수)이다.
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("배열B의 %d열 %d 행 입력", j + 1, i + 1); 
            scanf("%d", &num2);                     // scanf를 통해서 행렬B 값들을 num2에 저장한다.
            arr2[i][j] = num2;                      //num2의 값을 arr2(배열 B)에 넣는다.
        }
    }


    int **add = malloc(sizeof(int *) * row1);  //A+B의 결과를 저장할 메모리 할당 

    for (int i = 0; i < row1; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        add[i] = malloc(sizeof(int) * col1);
    }

    int **sub = malloc(sizeof(int *) * row1);   //A-b의 결과를 저장할 메모리 할당

    for (int i = 0; i < row1; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        sub[i] = malloc(sizeof(int) * col1);
    }
    
    int **trans = malloc(sizeof(int *) * col1);  //A의 전치행렬을 저장할 공간 할당

    for (int i = 0; i < col1; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        trans[i] = malloc(sizeof(int) * row1 );
    }

    
    int **mul = malloc(sizeof(int *) * row1);   //A x B를 저장할 공간 할당

    for (int i = 0; i < row1; i++) // malloc를 사용하여 메모리 할당을 받는다.
    {
        mul[i] = malloc(sizeof(int) * col2 );
    }
    
    addtion_matrix(add,arr,arr2,row1,col1 );        //A+B를 하기 위한 함수  
    subtraction_matrix(sub,arr,arr2,row1,col1);     //A-B를 하기 위한 함수 
    transpose_matrix(trans,arr, row1, col1);        //A행렬의 전치 행렬을 구하기 위한 함수 
    multiply_matrix(mul, arr, row1, col1, arr2, row2, col2);    // AxB를 하기 위한 함수 
    print_matrix( add, arr, row1, col1, arr2, row2, col2, sub, trans,mul); // 모든 결과를 출력하는 함수 
    

    for (int i = 0; i < row1; i++) // free로 할당받은 2차원 행렬 메모리를 다시 해제한다.
    {
        free(arr[i]);
    }
        for (int i = 0; i < row2; i++) // free로 할당받은 2차원 행렬 메모리를 다시 해제한다.
    {
        free(arr2[i]);
    }
    for (int i = 0; i < row1; i++) // free로 할당받은 2차원 행렬 메모리를 다시 해제한다.
    {
        free(add[i]);
    }
    for (int i = 0; i < row1; i++) // free로 할당받은 2차원 행렬 메모리를 다시 해제한다.
    {
        free(sub[i]);
    }
    for (int i = 0; i < col1; i++) // free로 할당받은 2차원 행렬 메모리를 다시 해제한다.
    {
        free(trans[i]);
    }
     for (int i = 0; i < col2; i++) // free로 할당받은 2차원 행렬 메모리를 다시 해제한다.
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


void print_matrix(int **add,int **arr, int row1, int col1,int **arr2, int row2, int col2, int **sub,int **trans, int **mul) // 행열 출력하는 함수
{//add 는 A+b / arr = A 배열 / row1 = A배열의 행의 갯수 / col1은 A배열의 열의 갯수 / trans은 행렬A의 전치행렬 
// arr2 = B 배열 / row2 = B배열의 행의 갯수 / colB은 A배열의 열의 갯수 / sub 는 A-b 행렬 / mul은 AxB한 행렬 
    printf("배열 A : \n");              //행렬 A를 출력한다.
    for (int i = 0; i < row1; i++) // row값과 col값을 받아서 for문을 이용해 프린트한다.
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", arr[i][j]);   
        }
        printf("\n");
    }

    printf("배열 b : \n");              //행렬 B를 출력한다.
                                         // row값과 col값을 받아서 for문을 이용해 프린트한다.
        for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

if ((row1 == row2)&&(col1==col2)){                      //A 행렬과 B행렬의 열과 행렬이 같아야만 행렬의 덧셈과 뺄셈을 할 수있으므로  
    printf("A + B : \n");                               //if문을 사용해서 A,B 모두 nxn 행렬이 나올떄만 출력한다

        for (int i = 0; i < row1; i++)                  //A+b 행렬을 출력한다.
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", add[i][j]);
        }
        printf("\n");
    }

    printf("A - B : \n");                               //A-B 행렬을 출력한다.

        for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
}





    printf("A의 전치행렬 : \n");                        //A행렬의 전치행렬을 구한다.

        for (int i = 0; i < col1; i++)
    {
        for (int j = 0; j < row1; j++)
        {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }


if(col1== row2){                                        //A행렬이 NxM 이고 B행렬이 KxJ 일떄 AxB가 가능한다 
    printf("A x B : \n");                               //if 문을 사용해서 NxJ일때 AxB가 출력하도록 했다.

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

void subtraction_matrix(int **sub, int **arr,int **arr2,int row1, int col1){//행렬의 뺼셈
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        { 
            sub[i][j] = arr[i][j] - arr2[i][j];
        }
    }
}

void transpose_matrix(int **trans, int **arr, int row1, int col1){//A행렬의 전치행렬
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        { 
            trans[j][i] = arr[i][j] ;
        }
    }
}

void multiply_matrix(int **mul, int **arr, int row1, int col1,int **arr2, int row2, int col2){//행렬의 곱셈
        for(int i = 0; i < row1; i++)                   //mul값을 모두 초기화 해준다. 
            for(int j = 0; j < col2; j++){
                mul[i][j] = 0;
            }

        for(int i = 0; i < row1; i++)
            for(int j = 0; j < col2; j++){
                for(int k = 0; k < col1; k++)
				    mul[i][j] = mul[i][j] + arr[i][k] * arr2[k][j];         //for문을 이용해서 행렬의 곱셈을 만들었다.
		}
}

