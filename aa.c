#include <stdio.h>
#include <stdlib.h>
void print_matrix(int **add,int **arr, int row1, int col1,int **arr2, int row2, int col2, int **sub, int **trans,int **mul); // �Լ����� printf�� �迭�� ����ϴ� �Լ�
void addtion_matrix(int **add, int **arr,int **arr2,int row1, int col1);
void subtraction_matrix(int **sub, int **arr,int **arr2,int row1, int col1);
void transpose_matrix(int **trans, int **arr, int row1, int col1);
void multiply_matrix(int **mul, int **arr, int row1, int col1,int **arr2, int row2, int col2);
int main()
{
    int row1, col1;
    int num1;
    printf("�迭A�� ��� ���� �����ּ��� :");
    scanf_s("%d %d", &row1, &col1);           // scanf�� �迭�� ũ�⸦ ���Ѵ�.
    int **arr = malloc(sizeof(int *) * row1); // ���� �����Ϳ� (int ������ ũ�� * row) ��ŭ ���� �޸� �Ҵ�. �迭�� �����̴�

    for (int i = 0; i < row1; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        arr[i] = malloc(sizeof(int) * col1);
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("�迭 A�� %d�� %d �� �Է�", j + 1, i + 1); // scanf�� ���ؼ� �迭�� ������ �޴´�.
            scanf("%d", &num1);

            arr[i][j] = num1;
        }
    }

    int row2, col2;
    int num2;
    printf("�迭B�� ��� ���� �����ּ��� :");
    scanf_s("%d %d", &row2, &col2);           // scanf�� �迭�� ũ�⸦ ���Ѵ�.
    int **arr2 = malloc(sizeof(int *) * row2); // ���� �����Ϳ� (int ������ ũ�� * row) ��ŭ ���� �޸� �Ҵ�. �迭�� �����̴�

    for (int i = 0; i < row2; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        arr2[i] = malloc(sizeof(int) * col2);
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("�迭B�� %d�� %d �� �Է�", j + 1, i + 1); // scanf�� ���ؼ� �迭�� ������ �޴´�.
            scanf("%d", &num2);

            arr2[i][j] = num2;
        }
    }


    int **add = malloc(sizeof(int *) * row1);

    for (int i = 0; i < row1; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        add[i] = malloc(sizeof(int) * col1);
    }

    int **sub = malloc(sizeof(int *) * row1);

    for (int i = 0; i < row1; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        sub[i] = malloc(sizeof(int) * col1);
    }
    
    int **trans = malloc(sizeof(int *) * col1);

    for (int i = 0; i < col1; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        trans[i] = malloc(sizeof(int) * row1 );
    }

    
    int **mul = malloc(sizeof(int *) * row1);

    for (int i = 0; i < row1; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        mul[i] = malloc(sizeof(int) * col2 );
    }
    
    addtion_matrix(add,arr,arr2,row1,col1 );
    subtraction_matrix(sub,arr,arr2,row1,col1);
    transpose_matrix(trans,arr, row1, col1);
    multiply_matrix(mul, arr, row1, col1, arr2, row2, col2);

    print_matrix( add, arr, row1, col1, arr2, row2, col2, sub, trans,mul); // ����ϴ� �Լ� ȣ��
    

    for (int i = 0; i < row1; i++) // free�� �Ҵ���� 2���� �迭 �޸𸮸� �ٽ� �����Ѵ�.
    {
        free(arr[i]);
    }
        for (int i = 0; i < row2; i++) // free�� �Ҵ���� 2���� �迭 �޸𸮸� �ٽ� �����Ѵ�.
    {
        free(arr2[i]);
    }
    for (int i = 0; i < row1; i++) // free�� �Ҵ���� 2���� �迭 �޸𸮸� �ٽ� �����Ѵ�.
    {
        free(add[i]);
    }
    for (int i = 0; i < row1; i++) // free�� �Ҵ���� 2���� �迭 �޸𸮸� �ٽ� �����Ѵ�.
    {
        free(sub[i]);
    }
    for (int i = 0; i < col1; i++) // free�� �Ҵ���� 2���� �迭 �޸𸮸� �ٽ� �����Ѵ�.
    {
        free(trans[i]);
    }
     for (int i = 0; i < col2; i++) // free�� �Ҵ���� 2���� �迭 �޸𸮸� �ٽ� �����Ѵ�.
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


void print_matrix(int **add,int **arr, int row1, int col1,int **arr2, int row2, int col2, int **sub,int **trans, int **mul) // �迭 ����ϴ� �Լ�
{
    printf("�迭 A : \n");
    for (int i = 0; i < row1; i++) // row���� col���� �޾Ƽ� ����Ʈ�Ѵ�.
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("�迭 b : \n");

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
    printf("A�� ��ġ��� : \n");

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


void addtion_matrix(int **add, int **arr,int **arr2,int row1, int col1){ //����� ���� 
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

