#include <stdio.h>
#include <stdlib.h>
void print_matrix(int **matrix, int n, int m) {
	int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
	int M,N,k,i,j;
	int r1;
	int r2;
	int toplam=0;
	int row_counter=0;
	int col_counter=0;
	int filtre_toplam=0;
	do{
		printf("goruntu matrisinin boyutlarini giriniz\n");
		scanf("%d",&M);
		scanf("%d",&N);
		printf("\nfiltre matrisinin boyutunu giriniz\n");
		scanf("%d",&k);
		if(k>M || k>N){//filtre matrisinin goruntu matrisinden b�y�k olmamas� kontrol�
			printf("\ngecersiz filtre matris boyutu\n");
		}
	}while(k>M || k>N);
	
	r1=M-k+1;//sonuc matrisinin boyutlar�
	r2=N-k+1;
	
	//matrisleri dinamik olarak olu�turuyoruz
	int **goruntu = (int **)malloc(M * sizeof(int *));
    for (i = 0; i < N; i++) {
        goruntu[i] = (int *)malloc(N * sizeof(int));
    }
    
	int **filtre = (int **)malloc(k * sizeof(int *));
    for (i = 0; i < k; i++) {
        filtre[i] = (int *)malloc(k * sizeof(int));
    }
	
	int **sonuc = (int **)malloc(r1 * sizeof(int *));
    for (i = 0; i < r2; i++) {
        sonuc[i] = (int *)malloc(r2 * sizeof(int));
    }
	
	printf("\ngoruntu matrisinin elemanlarini giriniz:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &goruntu[i][j]);
        }
    }
	
	printf("\nfiltre matrisinin elemanlarini giriniz:\n");
    for (i = 0; i < k; i++) {
        for (j = 0; j < k; j++) {
            scanf("%d", &filtre[i][j]);
            filtre_toplam+=filtre[i][j];
        }
    }
    
	printf("\ngoruntu matrisi:\n");
	print_matrix(goruntu,M,N);
	
	printf("\nfiltre matrisi:\n");
	print_matrix(filtre,k,k);
	
	for(row_counter=0;row_counter<r1;row_counter++){//filre matrisinin alt sat�rba��ndan devam etmesini sa�lar, ayn� zamanda matristen ta�may� engeller
		for(col_counter=0;col_counter<r2;col_counter++){//filre matrisinin bir sonraki s�tunundan devam etmesini sa�lar, ayn� zamanda matristen ta�may� engeller
			for(i=0;i<k;i++){//as�l �arpma ve toplama i�lemini yapar
				for(j=0;j<k;j++){
					toplam+=goruntu[i+row_counter][j+col_counter]*filtre[i][j];
				}
			}//sonuc matrisine ekleme
			sonuc[row_counter][col_counter]=toplam/filtre_toplam;
			toplam=0;
		}	
	}
	
	printf("\nsonuc matrisi:\n");
	print_matrix(sonuc,r1,r2);
		
	
	//dinamik matrisleri bellekten siliyoruz
	for (i = 0; i < N; i++) {
        free(goruntu[i]);
    }
    free(goruntu);
    
	for (i = 0; i < k; i++) {
        free(filtre[i]);
    }
    free(filtre);    
	
	for (i = 0; i < r2; i++) {
        free(sonuc[i]);
    }
    free(sonuc);
	
	
	
	
	return 0;
}
