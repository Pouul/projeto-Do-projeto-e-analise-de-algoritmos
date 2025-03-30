# include <stdio.h>
# include <stdlib.h>

int main(){

    // iniciação do variaveis e ponteiro
    char *str;
    char c;
    int tamanho = 0;
    int AlfaIgual = 1;
    int Tipos_Dif = 0;
    
    // alocação de memoria para vetores
    char *vetordigito = (char*) malloc(tamanho * sizeof(char));
    int *vetornumero = (int*) malloc(tamanho * sizeof(int));

    printf("Digite um string (pressione Enter para finalizar):\n");

    // leitura de string
    while ((c = getchar()) != '\n') {
        str = (char *)realloc(str, (tamanho + 1) * sizeof(char));
        // verificação de erro
        if (str == NULL) {
            printf("Erro de alocação!\n");
            return 1;
        }
        str[tamanho++] = c;
    }

    str = (char *)realloc(str, (tamanho + 1) * sizeof(char));
    // gerando fator diferencial no final do string
    str[tamanho] = ' ';
    str = (char *)realloc(str, (tamanho + 1) * sizeof(char));
    str[tamanho] = '\0';

    // iniciação do variavel digito
    char digito = str[0];
    
    // lê o string enquando a entrada for igual o numero de alfabeto igual
    // aumenta se for diferente guarda digito e AlfaIgual nos vetores 
    // digito e numero reinicia o contador e substitui o digito e repete
    // até varrer o string inteiramente
    // isso funciona porque foi colocado no final do string um espaço entes do \0
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
    //print do resultado se for o ultimo printa sem -
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