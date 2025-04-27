#include <stdio.h>

#include "menu/menu.h"
#include "utils/arquivo.h"

const char *arquivo = "dispositivos.csv";

int main(){
    Disp dispositivos[MAX_DISPOSITIVOS];

    ler_arquivo(arquivo, dispositivos);

    menu(dispositivos);

    return 0;
}