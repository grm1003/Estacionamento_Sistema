//Gabriel Rezende Machado
//12121BSI217

#include <stdio.h>
#include <stdlib.h>

typedef struct Horario{
        int anos;
        int mes;
        int dias;
        int horas;
        int minutos;
}horario;


typedef struct Carro{
    char placa[8];
    char modelo[10];
    char cor[10];
    horario entrada;
    horario saida;
    char status;
}carro;


//Não estava colocando o horário direito
//void colocahorario(horario a){
//    printf("Digite o ano: ");
//    scanf("%d", &a.anos);
//
//    printf("Digite o mes: ");
//    scanf("%d", &a.mes);
//    while(a.mes>12 || a.mes<1){
//        printf("Mes invalido\n");
//        printf("Digite o mes: ");
//        scanf("%d", &a.mes);
//    }
//
//    printf("Digite o dia: ");
//    scanf("%d", &a.dias);
//    while(verificadia(a.dias, a.mes,  a.anos) == -1){
//        printf("Digite o dia: ");
//        scanf("%d", &a.dias);
//    }
//
//     printf("Digite quantas horas: ");
//     scanf("%d", &a.horas);
//     while(a.horas > 24|| a.horas<0){
//        printf("Digite quantas horas: ");
//        scanf("%d", &a.horas);
//     }
//
//     printf("Digite quantos minutos: ");
//     scanf("%d", &a.minutos);
//     while(a.minutos > 59 || a.minutos<0){
//        printf("Digite quantos minutos: ");
//        scanf("%d", &a.minutos);
//     }
//
//
//
//}

void colocahorariosaida(carro user){
    printf("Digite o horario de saida: \n");
    printf("Digite o ano: ");
    scanf("%d", &user.saida.anos);

    printf("Digite o mes: ");
    scanf("%d", &user.saida.mes);
    while(user.saida.mes>12 || user.saida.mes<1){
        printf("Mes invalido\n");
        printf("Digite o mes: ");
        scanf("%d", &user.saida.mes);
    }

    printf("Digite o dia: ");
    scanf("%d", &user.saida.dias);
    while(verificadia(user.saida.dias, user.saida.mes,  user.saida.anos) == -1){
        printf("Digite o dia: ");
        scanf("%d", &user.saida.dias);
    }

     printf("Digite quantas horas: ");
     scanf("%d", &user.saida.horas);
     while(user.saida.horas > 24|| user.saida.horas<0){
        printf("Digite quantas horas: ");
        scanf("%d", &user.saida.horas);
     }

     printf("Digite quantos minutos: ");
     scanf("%d", &user.saida.minutos);
     while(user.entrada.minutos > 59 || user.entrada.minutos <0){
        printf("Digite quantos minutos: ");
        scanf("%d", &user.saida.minutos);
     }





}

int verificadia(int dias, int mes ,  int anos){
    int bissexto;

    if (((anos) % 400 == 0) || (((anos) % 4 == 0) && ((anos) % 100 != 0))){
        bissexto = 1;
    }else{
        bissexto = 0;
    }


    // Dia
    if (bissexto == 1 && mes == 2){
        if(dias>29 || dias<=0)return -1;
        else return 0;
    }
    else if (mes == 2){
        if(dias>28 || dias<=0)return -1;
        else return 0;
    }
    else if ((mes) == 1 || (mes) == 3 || (mes) == 1 || (mes) == 5 || (mes) == 7 || (mes) == 8 || (mes) == 10 || (mes) == 12){
        if(dias>31 || dias<=0)return -1;
        else return 0;
    }
    else
    {
        if(dias>30 || dias<=0)return -1;
        else return 0;
    }

}


void inserir(FILE *f){
    carro user;
    printf("Digite a placa: ");
    scanf("%s", user.placa);
    printf("\n");
    printf("Digite o modelo do carro: ");
    scanf("%s", &user.modelo);
     printf("\n");
    printf("Digite a cor: ");
    scanf("%s", &user.cor);
     printf("\n");
    printf("Digite o horario de entrada: \n");
    printf("Digite o ano: ");
    scanf("%d", &user.entrada.anos);

    printf("Digite o mes: ");
    scanf("%d", &user.entrada.mes);
    while(user.entrada.mes>12 || user.entrada.mes<1){
        printf("Mes invalido\n");
        printf("Digite o mes: ");
        scanf("%d", &user.entrada.mes);
    }

    printf("Digite o dia: ");
    scanf("%d", &user.entrada.dias);
    while(verificadia(user.entrada.dias, user.entrada.mes,  user.entrada.anos) == -1){
        printf("Digite o dia: ");
        scanf("%d", &user.entrada.dias);
    }

     printf("Digite quantas horas: ");
     scanf("%d", &user.entrada.horas);
     while(user.entrada.horas > 24|| user.entrada.horas<0){
        printf("Digite quantas horas: ");
        scanf("%d", &user.entrada.horas);
     }

     printf("Digite quantos minutos: ");
     scanf("%d", &user.entrada.minutos);
     while(user.entrada.minutos > 59 || user.entrada.minutos <0){
        printf("Digite quantos minutos: ");
        scanf("%d", &user.entrada.minutos);
     }
     printf("\n");
     //se inserir um carro o carro deve estar presente e valor horario de saida indefinido = NULO
     user.saida.anos = NULL;
     user.saida.mes = NULL;
     user.saida.dias = NULL;
     user.saida.horas = NULL;
     user.saida.minutos = NULL;

    user.status = 'P';
    fseek(f, sizeof(carro), SEEK_END);
    fwrite(&user, sizeof(carro), 1, f);
    }

void tempodeestadia(carro user){
   horario a;
   a.anos = user.saida.anos - user.entrada.anos;
   a.mes = user.saida.mes - user.entrada.mes;
   a.dias =  user.saida.dias - user.entrada.dias;
   a.horas = user.saida.horas - user.entrada.horas;
   a.minutos = user.saida.minutos - user.entrada.minutos;
   mostrahorario(a);



}


void listar(FILE *f){
    carro user;

    rewind(f);
    while (fread(&user , sizeof(user), 1, f) > 0){
        if (user.status == 'P' || user.status == 'A'){
            mostracarro(user);
        }
    }

}

void mostracarro (carro user){

 printf("Placa: %s \nModelo: %s \nCor: %s \n",user.placa,user.modelo,user.cor);
 printf("Entrada: \n");
 mostrahorario(user.entrada);
 printf("Saida: \n");
 mostrahorario(user.saida);
 printf("Status: %c\n", user.status);
  printf("\n\n");



}

void mostrahorario (horario a){
     printf("Ano : %d\n", a.anos);
     printf("Mes: %d\n", a.mes);
     printf("Dia:%d\n", a.dias);
     printf("Horas:%d\n", a.horas);
     printf("Minuto: %d\n", a.minutos);

}

void buscar(FILE *f){
    char placauser[8];
    printf("Digite placa a ser localizada: ");
    scanf("%s", placauser);

    rewind(f);
    carro user;
    while (fread(&user, sizeof(user), 1, f) > 0){
        int a = strcmp(user.placa, placauser);
        char b = user.status;
        if (a == 0 && b == 'P'){
            printf("\n");
            mostracarro(user);
        }
    }

}

void remover(FILE *f){
    char placauser[8];
    printf("Digite a placa a ser removida: ");
    scanf("%s", placauser);
    printf("\n");

    carro user;


    int c = 1;
    rewind(f);
    while (fread(&user, sizeof(user), 1, f) > 0){
        int a = strcmp(user.placa, placauser);

        char b = user.status;
        if (a == 0 && b == 'P'){
            long d = ftell(f)-1;
            printf("Carro %d: \n", c);
            mostracarro(user);

            printf("Deseja apagar registro? \n 1 - Sim\n  2 - Nao\n");
            int escolha;
            scanf("%d", &escolha);

            if (escolha == 1){
                int size = sizeof(user);
                user.status = 'I';
                fseek(f, -sizeof(user), SEEK_CUR);
                fwrite(&user, sizeof(user),1, f);
            }else{
                break;
            }
        }
         c++;
    }
}

void alterar(FILE *f){
    char placauser[8];
    printf("Digite a placa a ser alterada: ");
    scanf("%s", placauser);
    printf("\n");

    carro user;


    rewind(f);

    while (fread(&user, sizeof(user), 1, f) > 0){
        int a = strcmp(user.placa, placauser);
        char b = user.status;
        if (a == 0 && b == 'P'){
            long c = ftell (f);
            mostracarro(user);

            printf("Deseja alterar registro?\n");
            printf("Digite:\n 1- Sim\n 2-Nao\n");
            int escolha;
            scanf("%d", &escolha);

            if(escolha == 1){
            while(1){
                printf("Digite o que quer alterar:\n 1-Placa\n 2- Modelo \n 3-Cor \n 4-Entrada \n 5-Saida");
                int alteracao;
                scanf("%d", &alteracao);
                if(alteracao == 1){
                    printf("Digite a placa: ");
                    scanf("%s", user.placa);
                    fseek(f, -sizeof(user), SEEK_CUR);
                    fwrite(&user, sizeof(user),1, f);
                }else
                if(alteracao == 2){
                    printf("Digite o modelo do carro: ");
                    scanf("%s", &user.modelo);
                    fseek(f, -sizeof(user), SEEK_CUR);
                    fwrite(&user, sizeof(user),1, f);
                }else
                if(alteracao == 3){
                    printf("Digite a cor: ");
                    scanf("%s", &user.cor);
                    fseek(f, -sizeof(user), SEEK_CUR);
                    fwrite(&user, sizeof(user),1, f);
                }else
                if(alteracao == 4){
                    printf("Digite o horario de entrada: \n");
                    printf("Digite o ano: ");
                    scanf("%d", &user.entrada.anos);

                   printf("Digite o mes: ");
                   scanf("%d", &user.entrada.mes);
                   while(user.entrada.mes>12 || user.entrada.mes<1){
                       printf("Mes invalido\n");
                        printf("Digite o mes: ");
                            scanf("%d", &user.entrada.mes);
                   }

                       printf("Digite o dia: ");
                      scanf("%d", &user.entrada.dias);
                      while(verificadia(user.entrada.dias, user.entrada.mes,  user.entrada.anos) == -1){
                            printf("Digite o dia: ");
                            scanf("%d", &user.entrada.dias);
                        }

                        printf("Digite quantas horas: ");
                        scanf("%d", &user.entrada.horas);
                         while(user.entrada.horas > 24|| user.entrada.horas<0){
                            printf("Digite quantas horas: ");
                            scanf("%d", &user.entrada.horas);
                        }

                        printf("Digite quantos minutos: ");
                        scanf("%d", &user.entrada.minutos);
                         while(user.entrada.minutos > 59 || user.entrada.minutos <0){
                            printf("Digite quantos minutos: ");
                            scanf("%d", &user.entrada.minutos);
                        }
                        fseek(f, -sizeof(user), SEEK_CUR);
                        fwrite(&user, sizeof(user),1, f);

                }else
                if(alteracao == 5){
                    colocahorariosaida(user);
                    user.status = 'A';
                    fseek(f, -sizeof(user), SEEK_CUR);
                    fwrite(&user, sizeof(user),1, f);
                }


                printf("Deseja alterar mais algo?\n 1-Sim\n 2-Nao\n");
                int sair;
                scanf("%d", &sair);
                if(sair != 1){
                    break;
                }
            }
            }else break;

        }
    }
}


int main(){


    FILE *f;
    f = fopen("estacionamento.dat", "rb+");
    if (f == NULL){
        printf("Erro na abertura do arquivo\n");
        f = fopen("estacionamento.dat", "wb+");

        if (f == NULL){
            system("pause");
        exit(1);
        }
    }

    int opcao = -1;
    while (opcao != 0) {
        printf("\n\n 0-sair\n 1-insere\n 2-altera\n 3-remove\n 4-busca\n 5-lista\n");
        printf("\n Opcao: "); scanf("%d",&opcao);
        switch(opcao) {
            case 1: inserir(f); break;
            case 2: alterar(f); break;
            case 3: remover(f); break;
            case 4: buscar(f); break;
            case 5: listar(f); break;
            printf("\n\n\n");
        }
    }

    fclose(f);
    return 0;

}
