#include <stdio.h>
#include <stdlib.h>
void print_matrix(int **add,int **arr, int row1, int col1,int **arr2, int row2, int col2, int **sub, int **trans,int **mul); 
// �Լ����� printf�� ����� ����ϴ� �Լ�
void addtion_matrix(int **add, int **arr,int **arr2,int row1, int col1);// A+B �Լ� ����
void subtraction_matrix(int **sub, int **arr,int **arr2,int row1, int col1);//A-b �Լ����� 
void transpose_matrix(int **trans, int **arr, int row1, int col1);//A�� ��ġ��� �Լ� ����
void multiply_matrix(int **mul, int **arr, int row1, int col1,int **arr2, int row2, int col2); //AxB �Լ� ����
int main()
{


    printf(" [----- [�����] [2017038092] -----]\n\n");
    int row1, col1;   //����� ��� ���̴�.
    int num1;         //����f�� ���� ���� �����Ѵ�.
    printf("�迭A�� ��� ���� �����ּ��� :");
    scanf_s("%d %d", &row1, &col1);           // scanf�� ����� ũ�⸦ ���Ѵ�. //���� ���� ���ڷ� ��� ���� �޴´�.
    int **arr = malloc(sizeof(int *) * row1); // ���� �����Ϳ� (int ������ ũ�� * row) ��ŭ ���� �޸� �Ҵ�. ����� �����̴�

    for (int i = 0; i < row1; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.   
    {
        arr[i] = malloc(sizeof(int) * col1);    //�迭�� ���θ� ���� �޸𸮸� �Ҵ�޴´�. 
    }


    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("�迭 A�� %d�� %d �� �Է�", j + 1, i + 1); // scanf�� ���ؼ� ����� ������ �޴´�.  
            scanf("%d", &num1);             
            arr[i][j] = num1;                               
        }
    }

    int row2, col2;                         //��� B�� ���� ���� ���� �����Ѵ�.
    int num2;                               //�۷� B�� ���� scanf�Ҷ� ����Ѵ�.
    printf("�迭B�� ��� ���� �����ּ��� :");
    scanf_s("%d %d", &row2, &col2);           // scanf�� ����� ũ�⸦ ���Ѵ�.
    int **arr2 = malloc(sizeof(int *) * row2); // ���� �����Ϳ� (int ������ ũ�� * row) ��ŭ ���� �޸� �Ҵ�. ����� �����̴�

    for (int i = 0; i < row2; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        arr2[i] = malloc(sizeof(int) * col2);   //����� ���� (���� ����)�̴�.
    }
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("�迭B�� %d�� %d �� �Է�", j + 1, i + 1); 
            scanf("%d", &num2);                     // scanf�� ���ؼ� ���B ������ num2�� �����Ѵ�.
            arr2[i][j] = num2;                      //num2�� ���� arr2(�迭 B)�� �ִ´�.
        }
    }


    int **add = malloc(sizeof(int *) * row1);  //A+B�� ����� ������ �޸� �Ҵ� 

    for (int i = 0; i < row1; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        add[i] = malloc(sizeof(int) * col1);
    }

    int **sub = malloc(sizeof(int *) * row1);   //A-b�� ����� ������ �޸� �Ҵ�

    for (int i = 0; i < row1; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        sub[i] = malloc(sizeof(int) * col1);
    }
    
    int **trans = malloc(sizeof(int *) * col1);  //A�� ��ġ����� ������ ���� �Ҵ�

    for (int i = 0; i < col1; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        trans[i] = malloc(sizeof(int) * row1 );
    }

    
    int **mul = malloc(sizeof(int *) * row1);   //A x B�� ������ ���� �Ҵ�

    for (int i = 0; i < row1; i++) // malloc�� ����Ͽ� �޸� �Ҵ��� �޴´�.
    {
        mul[i] = malloc(sizeof(int) * col2 );
    }
    
    addtion_matrix(add,arr,arr2,row1,col1 );        //A+B�� �ϱ� ���� �Լ�  
    subtraction_matrix(sub,arr,arr2,row1,col1);     //A-B�� �ϱ� ���� �Լ� 
    transpose_matrix(trans,arr, row1, col1);        //A����� ��ġ ����� ���ϱ� ���� �Լ� 
    multiply_matrix(mul, arr, row1, col1, arr2, row2, col2);    // AxB�� �ϱ� ���� �Լ� 
    print_matrix( add, arr, row1, col1, arr2, row2, col2, sub, trans,mul); // ��� ����� ����ϴ� �Լ� 
    

    for (int i = 0; i < row1; i++) // free�� �Ҵ���� 2���� ��� �޸𸮸� �ٽ� �����Ѵ�.
    {
        free(arr[i]);
    }
        for (int i = 0; i < row2; i++) // free�� �Ҵ���� 2���� ��� �޸𸮸� �ٽ� �����Ѵ�.
    {
        free(arr2[i]);
    }
    for (int i = 0; i < row1; i++) // free�� �Ҵ���� 2���� ��� �޸𸮸� �ٽ� �����Ѵ�.
    {
        free(add[i]);
    }
    for (int i = 0; i < row1; i++) // free�� �Ҵ���� 2���� ��� �޸𸮸� �ٽ� �����Ѵ�.
    {
        free(sub[i]);
    }
    for (int i = 0; i < col1; i++) // free�� �Ҵ���� 2���� ��� �޸𸮸� �ٽ� �����Ѵ�.
    {
        free(trans[i]);
    }
     for (int i = 0; i < col2; i++) // free�� �Ҵ���� 2���� ��� �޸𸮸� �ٽ� �����Ѵ�.
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


void print_matrix(int **add,int **arr, int row1, int col1,int **arr2, int row2, int col2, int **sub,int **trans, int **mul) // �࿭ ����ϴ� �Լ�
{//add �� A+b / arr = A �迭 / row1 = A�迭�� ���� ���� / col1�� A�迭�� ���� ���� / trans�� ���A�� ��ġ��� 
// arr2 = B �迭 / row2 = B�迭�� ���� ���� / colB�� A�迭�� ���� ���� / sub �� A-b ��� / mul�� AxB�� ��� 
    printf("�迭 A : \n");              //��� A�� ����Ѵ�.
    for (int i = 0; i < row1; i++) // row���� col���� �޾Ƽ� for���� �̿��� ����Ʈ�Ѵ�.
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", arr[i][j]);   
        }
        printf("\n");
    }

    printf("�迭 b : \n");              //��� B�� ����Ѵ�.
                                         // row���� col���� �޾Ƽ� for���� �̿��� ����Ʈ�Ѵ�.
        for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

if ((row1 == row2)&&(col1==col2)){                      //A ��İ� B����� ���� ����� ���ƾ߸� ����� ������ ������ �� �������Ƿ�  
    printf("A + B : \n");                               //if���� ����ؼ� A,B ��� nxn ����� ���Ë��� ����Ѵ�

        for (int i = 0; i < row1; i++)                  //A+b ����� ����Ѵ�.
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", add[i][j]);
        }
        printf("\n");
    }

    printf("A - B : \n");                               //A-B ����� ����Ѵ�.

        for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
}





    printf("A�� ��ġ��� : \n");                        //A����� ��ġ����� ���Ѵ�.

        for (int i = 0; i < col1; i++)
    {
        for (int j = 0; j < row1; j++)
        {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }


if(col1== row2){                                        //A����� NxM �̰� B����� KxJ �ϋ� AxB�� �����Ѵ� 
    printf("A x B : \n");                               //if ���� ����ؼ� NxJ�϶� AxB�� ����ϵ��� �ߴ�.

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

void subtraction_matrix(int **sub, int **arr,int **arr2,int row1, int col1){//����� �E��
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        { 
            sub[i][j] = arr[i][j] - arr2[i][j];
        }
    }
}

void transpose_matrix(int **trans, int **arr, int row1, int col1){//A����� ��ġ���
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        { 
            trans[j][i] = arr[i][j] ;
        }
    }
}

void multiply_matrix(int **mul, int **arr, int row1, int col1,int **arr2, int row2, int col2){//����� ����
        for(int i = 0; i < row1; i++)                   //mul���� ��� �ʱ�ȭ ���ش�. 
            for(int j = 0; j < col2; j++){
                mul[i][j] = 0;
            }

        for(int i = 0; i < row1; i++)
            for(int j = 0; j < col2; j++){
                for(int k = 0; k < col1; k++)
				    mul[i][j] = mul[i][j] + arr[i][k] * arr2[k][j];         //for���� �̿��ؼ� ����� ������ �������.
		}
}

