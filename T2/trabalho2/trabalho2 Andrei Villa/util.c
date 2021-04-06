#include"util.h"
char menu(){
    int opiscoes[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int op;
    int i;
    fflush(stdin);
    printf("|-----------------------------------------|\n");
    printf("|        CADASTRO DE TAREFAS              |\n");
    printf("|_________________________________________|\n");
    printf("|           MENU DE OPCOES                |\n");
    printf("|-----------------------------------------|\n");
    printf("| 1 -INCLUIR NOVA TAREFA                  |\n");
    printf("| 2 -VISUALIZAR TAREFAS CADASTRADAS       |\n");
    printf("| 3 -EXCLUIR TAREFA                       |\n");
    printf("| 4 -EDITAR TAREFA                        |\n");
    printf("| 5 -CARREGAR ARQUIVO DE TAREFAS          |\n");
    printf("| 6 -GERAR ARQUIVO DE TAREFAS             |\n");
    printf("| 7 -COMPUTAR AGENDA DO DIA               |\n");
    printf("| 8 -SALVARA AGENDA DO DIA                |\n");
    printf("| 0 -SAIR                                 |\n");
    printf("|-----------------------------------------|\n");
    
    while (1){
        scanf("%d", &op);fflush(stdin);
        for(i=0; i<9;i++){
            if(opiscoes[i] == op)
                return (char) (op + 48);
        }
        printf("Opcao invalida\n");
    }    
}
void visualizar_tarefas(tarefa *lista){
    
    if(lista->prox == NULL || lista == NULL){
        printf("|-----------------------------------------|\n");
        printf("|           NAO POSSUI PAREFAS            |\n");
        printf("|-----------------------------------------|\n");
        return;
    }
    printf("|-----------------------------------------|\n");
    printf("|           TAREFAS CADASTRADAS           |\n");
    printf("|-----------------------------------------|\n");
    while(lista->prox != NULL){
        printf("|-----------------------------------------|\n");
        printf(" Tarefa: %s\n" ,lista->dados.nome);fflush(stdin);
        printf(" id: %d\n", lista->id);
        printf(" Inicio: %d/%d/%d - %d:%d\n", lista->dados.inicio.dia, lista->dados.inicio.mes, lista->dados.inicio.ano, lista->dados.inicio.hora, lista->dados.inicio.minuto);
        printf(" deadline: %d/%d/%d - %d:%d\n", lista->dados.deadline.dia, lista->dados.deadline.mes, lista->dados.deadline.ano, lista->dados.deadline.hora, lista->dados.deadline.minuto);
        printf(" Duracao: %d minutos\n", lista->dados.duracao);
        lista = lista->prox;
    }
    printf("|-----------------------------------------|\n"); 
}
void add_tarefa(tarefa *lista){
    int nid=0;
    while(lista->prox != NULL){
        nid = lista->id;
        lista = lista->prox;
    }
    printf("Tarefa: ");
    scanf("%s", lista->dados.nome);
    add_reg(&lista->dados);
    
    
    lista->id = nid+1;
    lista->prox = (tarefa*) malloc(sizeof(tarefa));
    lista = lista->prox;
    lista->prox = NULL;
}
void add_tempo(tempo *tmp){
    while(1){
        fflush(stdin);
        printf("Dia: ");
        scanf("%d", &tmp->dia);
        printf("Mes: ");
        scanf("%d", &tmp->mes);
        printf("Ano: ");
        scanf("%d", &tmp->ano);
        printf("Hora: ");
        scanf("%d", &tmp->hora);
        printf("Minuto: ");
        scanf("%d", &tmp->minuto);
        if(verifica_data(tmp->dia, tmp->mes, tmp->ano, tmp->hora, tmp->minuto) == 1)
            return;
    }
}
int verifica_data(int dia, int mes, int ano, int hora, int minuto){
    struct tm *local;
    time_t t;
    t = time(NULL);
    local=localtime(&t);

    if(hora > 24 || hora < 0){
        printf("ERRO: hora ivalida\n");
        return(0);
    }else if (minuto > 60 || minuto < 0){
        printf("ERRO: minuto invalido\n");
        return(0);
    }else if(mes > 12 || mes < 0 || mes < local->tm_mon+1){
        printf("ERRO: mes invalido\n");
        return(0);
    }else if(ano < local->tm_year+1900){
        printf("ERRO: ano invalido\n");
        return(0);
    }else if(dia > 31 || dia < 0 || dia < local->tm_mday){
        printf("ERRO: dia invalido\n");
        return(0);
    }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if(dia > 30){
            printf("ERRO: dia invalido\n");
            return(0);
        }
    }else if(mes == 2){
        if(ano%4==0){
            if(dia > 29){
                printf("ERRO: dia invalido\n");
                return(0);
            }
        }else{
            if(dia > 28){
                printf("ERRO: dia invalido\n");
                return(0);
            }
        }
    }else{
        return (1);
    }
    return(1);
}

void add_reg(reg *regis){
    printf("---Inicio---\n");
        add_tempo(&regis->inicio);
    printf("---Deadline---\n");
        add_tempo(&regis->deadline);
        
    printf("---Duracao---\n");
    scanf("%d", &regis->duracao);
}
tarefa* remove_tarefa(tarefa *lista, int id){
    tarefa *aux1 = (tarefa*) malloc(sizeof(tarefa));
    tarefa *aux2 = (tarefa*) malloc(sizeof(tarefa));
    aux1 = lista;
    aux2 = lista->prox;
    if(aux1->id == id){
        return aux2;
    }else{
        while(aux2 != NULL && aux2->id != id){
            aux1 = aux2;
            aux2 = aux2->prox;
        }
        if(aux2 != NULL){
            aux1->prox = aux2->prox;
            free(aux2);
        }
        return lista;
    }
}

void editar_tarefa(tarefa *lista, int id){
    while(lista->id != id && lista->prox != NULL){
        lista = lista->prox;
    }
    printf("Tarefa: ");
    scanf("%s", lista->dados.nome);
    add_reg(&lista->dados);
}

//arquivos
//salvar structs
void salvar_linha(tarefa *t, FILE *fl){
    //0, NOME, INÍCIO, DURAÇÃO, DEADLINE    
    fprintf(fl, "%d, %s, ", t->id, t->dados.nome);
    fprintf(fl, "%d/%d/%d %d:%d, ", t->dados.inicio.dia, t->dados.inicio.mes,t->dados.inicio.ano, t->dados.inicio.hora, t->dados.inicio.minuto);
    fprintf(fl, "%d, %d/%d/%d %d:%d \n",  t->dados.duracao, t->dados.deadline.dia, t->dados.deadline.mes, t->dados.deadline.ano,t->dados.deadline.hora,t->dados.deadline.minuto);
}
void salvar(tarefa *lista, int op){
    FILE *f;
    if(op == 1)
        f = fopen("tarefas.txt", "wb");
    else if(op == 2)
        f = fopen("tarefasdia.txt", "wb");
    else{
        printf("erro\n");
        return;
    }    
    if(f == NULL)
        printf("erro");
    while(lista->prox != NULL){
        salvar_linha(lista, f);
        lista = lista->prox;
    }
    fclose(f);
}

//carregar structs
void ler_linha(tarefa *t, FILE *fl){
    fscanf(fl, "%d, ", &t->id);
    fscanf(fl, "%[^,]s ", t->dados.nome);
    fscanf(fl, ", %d", &t->dados.inicio.dia);
    fscanf(fl, "/%d", &t->dados.inicio.mes);
    fscanf(fl, "/%d", &t->dados.inicio.ano);
    fscanf(fl, "%d", &t->dados.inicio.hora);
    fscanf(fl, ":%d", &t->dados.inicio.minuto);
    fscanf(fl, ",%d", &t->dados.duracao);
    fscanf(fl, ",%d", &t->dados.deadline.dia);
    fscanf(fl, "/%d", &t->dados.deadline.mes);
    fscanf(fl, "/%d", &t->dados.deadline.ano);
    fscanf(fl, "%d", &t->dados.deadline.hora);
    fscanf(fl, ":%d", &t->dados.deadline.minuto);
}

void carregar_arquivo(tarefa *lista){
    FILE *fl = fopen("tarefas.txt", "r");
    if(fl == NULL){
        printf("erro\n");
        return;
    }
    int i, n_linhas=0;
    char c;
    while(!feof(fl)){
        c = fgetc(fl);
        if(c == '\n')
            n_linhas++;        
    }
    rewind(fl);
    for(i=0; i<n_linhas;i++){
        ler_linha(lista, fl);
        //printa_tarefa(lista);
        lista->prox = (tarefa*) malloc(sizeof(tarefa));
        lista = lista->prox;
        lista->prox = NULL;
    }
    fclose(fl);
}
tarefa *agenda_do_dia(tarefa *lista){
    struct tm *local;
    tarefa *lista_dia = (tarefa*) malloc(sizeof(tarefa));
    lista_dia->prox = NULL;
    tarefa *a = lista_dia;
    time_t t;
    //pegando data atual
    t = time(NULL);
    local=localtime(&t);


    //criando lista do dia
    while(lista->prox != NULL){
        if(lista->dados.inicio.dia == local->tm_mday && lista->dados.inicio.mes == local->tm_mon+1 && lista->dados.inicio.ano == local->tm_year+1900){
            strcpy(lista_dia->dados.nome, lista->dados.nome);
            lista_dia->id = lista->id;
            lista_dia->dados.inicio.dia = lista->dados.inicio.dia;
            lista_dia->dados.inicio.mes = lista->dados.inicio.mes;
            lista_dia->dados.inicio.ano = lista->dados.inicio.ano;
            lista_dia->dados.inicio.hora = lista->dados.inicio.hora;
            lista_dia->dados.inicio.minuto = lista->dados.inicio.minuto;
            lista_dia->dados.deadline.dia = lista->dados.deadline.dia;
            lista_dia->dados.deadline.mes = lista->dados.deadline.mes;
            lista_dia->dados.deadline.ano = lista->dados.deadline.ano;
            lista_dia->dados.deadline.hora = lista->dados.deadline.hora;
            lista_dia->dados.deadline.minuto = lista->dados.deadline.minuto;
            lista_dia->dados.duracao = lista->dados.duracao;
            lista_dia->prox = (tarefa*) malloc(sizeof(tarefa));
            lista_dia = lista_dia->prox;
            lista_dia->prox = NULL;            
        }
        lista = lista->prox;
    }
    return a;
}

//ordenação
tarefa *merge(tarefa *e, tarefa *d){
    tarefa *l, *p;
    l=NULL;
    while(e!=NULL && d!=NULL){
        if((e->dados.deadline.hora*60 + e->dados.deadline.minuto) < (d->dados.deadline.hora*60 + d->dados.deadline.minuto)){
            if(l==NULL){
                p=l=e;
                e=e->prox;
            }
            else{
            p->prox=e;
            e=e->prox;
            p=p->prox;
            }
        }else{
            if(l==NULL){
                p=l=d;
                d=d->prox;
            }else{
                p->prox=d;
                d=d->prox;
                p=p->prox;
            }
        }
    }
    if(e==NULL){
        while(d!=NULL){
            p->prox=d;
            d=d->prox;
            p=p->prox;
        }
    }
    if(d==NULL){
        while(e!=NULL){
            p->prox=e;
            e=e->prox;
            p=p->prox;
        }
    }
    return(l);
}

tarefa *split(tarefa *l){
    tarefa *x,*y,*p;
    x=l;
    y=l;
    if(l==NULL) 
        return(l);
    while(y->prox!=NULL){
        y=y->prox;
        if(y->prox!=NULL){
            x=x->prox;
            y=y->prox;
        }
    }
    p=x->prox;
    x->prox=NULL;
    return(p);
}

tarefa *mergeSort(tarefa *l){
    tarefa *e, *d, *mid;
    if(l==NULL || l->prox==NULL){
        return l;
    }
    mid=split(l);
    e = mergeSort(l);
    d = mergeSort(mid);
    l=merge(e,d);
    return(l);
}

//apagar
void printa_tarefa(tarefa *t){
    printf("\n\n- %s -\n\n", t->dados.nome);
    printf("ID: %d\n", t->id);
    printf("Inicio: %d/%d/%d \t",  t->dados.inicio.dia, t->dados.inicio.mes, t->dados.inicio.ano);
    printf("%d:%d\n", t->dados.inicio.hora, t->dados.inicio.minuto);
    printf("Fim: %d/%d/%d \t", t->dados.deadline.dia, t->dados.deadline.mes, t->dados.deadline.ano);
    printf("%d:%d\n", t->dados.deadline.hora, t->dados.deadline.minuto);
    printf("Duracao: %d\n", t->dados.duracao);
}

tarefa *otimiza(tarefa *lista){
    int verif = 0;
    tarefa *a = (tarefa*) malloc(sizeof(tarefa));
    tarefa *b = a;
    if(lista == NULL)
        return 0;
    
    while(lista->prox != NULL){
        if(verif <= (lista->dados.inicio.hora*60+lista->dados.inicio.minuto)){
            strcpy(a->dados.nome, lista->dados.nome);
            a->id = lista->id;
            a->dados.inicio.dia = lista->dados.inicio.dia;
            a->dados.inicio.mes = lista->dados.inicio.mes;
            a->dados.inicio.ano = lista->dados.inicio.ano;
            a->dados.inicio.hora = lista->dados.inicio.hora;
            a->dados.inicio.minuto = lista->dados.inicio.minuto;
            a->dados.deadline.dia = lista->dados.deadline.dia;
            a->dados.deadline.mes = lista->dados.deadline.mes;
            a->dados.deadline.ano = lista->dados.deadline.ano;
            a->dados.deadline.hora = lista->dados.deadline.hora;
            a->dados.deadline.minuto = lista->dados.deadline.minuto;
            a->dados.duracao = lista->dados.duracao;
            a->prox = (tarefa*) malloc(sizeof(tarefa));
            a = a->prox;
            a->prox = NULL;
            verif = lista->dados.deadline.hora*60+lista->dados.deadline.minuto;
            lista = lista->prox;
        }else{
            lista = lista->prox;
        }
    }
    return(b);
}