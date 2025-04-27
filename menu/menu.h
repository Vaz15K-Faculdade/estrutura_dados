#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include "utils/arquivo.h"
#include "busca/busca.h"
#include "ordenacao/avancado.h"
#include "ordenacao/simples.h"
#include "busca/filtro.h"

extern const char *arquivo;
void menu(Disp listaDisp[]);

#endif /* MENU_H */