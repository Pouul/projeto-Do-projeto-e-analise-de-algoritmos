# include <stdio.h>
# include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("Uso: %s <string>\n", argv[0]);
        return 1;
    }
    char *entrada = argv[1];
    char digito = entrada[0];
}