# include <stdio.h>
# include <stdlib.h>

int main(){
    
    char *str = NULL, c;
    int tamanho = 0;
    int AlfaIgual = 1;
    int Tipos_Dif = 0;

    char *vetordigito = (char*) malloc(tamanho * sizeof(char));
    int *vetornumero = (int*) malloc(tamanho * sizeof(int));

    printf("Digite um string (pressione Enter para finalizar):\n");
    while ((c = getchar()) != '\n') {
        str = (char *)realloc(str, (tamanho + 1) * sizeof(char));
        if (str == NULL) {
            printf("Erro de alocação!\n");
            return 1;
        }
        str[tamanho++] = c;
    }

    str = (char *)realloc(str, (tamanho + 1) * sizeof(char));
    str[tamanho] = ' ';
    tamanho++;
    str[tamanho] = '\0';

    char digito = str[0];

    for (int i = 1; i < tamanho; i++) { 
        if (str[i] == digito) {
            AlfaIgual++;
        } else {
            vetordigito[Tipos_Dif] = digito;
            vetornumero[Tipos_Dif] = AlfaIgual;
            Tipos_Dif++;
            digito = str[i];
            AlfaIgual = 1;
        }
    }
    for(int i = 0; i < Tipos_Dif; i++){
        if(i == Tipos_Dif - 1){
            printf("%c%d",vetordigito[i],vetornumero[i]);
            return 0;
        }
        printf("%c%d - ",vetordigito[i],vetornumero[i]);
    }

    free(str);
    return 0;
}