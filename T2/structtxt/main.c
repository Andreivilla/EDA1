#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;    
}tempo;

typedef struct{
    char nome[100];
    int duracao;
    tempo inicio;
    tempo deadline;
}reg;

typedef struct x{
    int id;
    reg dados;
    struct x *prox;
}tarefa;
tarefa *criar_tarefa(void){
    tempo ini, fim;
    tarefa *t = (tarefa*) malloc(sizeof(tarefa));
    printf("Tarefa: ");
    scanf("%[^\n]s", t->dados.nome);
    printf("tarefa id: ");
    scanf("%d", &t->id);
    printf("\n");

    printf("----Tempo inicio---\n");
    printf("Dia: ");
    scanf("%d", &ini.dia);
    printf("Mes: ");
    scanf("%d", &ini.mes);
    printf("Ano: ");
    scanf("%d", &ini.ano);
    printf("Hora: ");
    scanf("%d", &ini.hora);
    printf("Minuto: ");
    scanf("%d", &ini.minuto);
    t->dados.inicio = ini;

    printf("----Tempo Fim---\n");
    printf("Dia: ");
    scanf("%d", &fim.dia);
    printf("Mes: ");
    scanf("%d", &fim.mes);
    printf("Ano: ");
    scanf("%d", &fim.ano);
    printf("Hora: ");
    scanf("%d", &fim.hora);
    printf("Minuto: ");
    scanf("%d", &fim.minuto);

    printf("bota qualquer inbteiro e a duracao : ");
    scanf("%d", &t->dados.duracao);
    t->dados.deadline = fim;
    return(t);
}

void printa_tarefa(tarefa *t){
    printf("\n\n-%s-\n\n", t->dados.nome);
    printf("ID: %d\n", t->id);
    printf("Inicio: %d/%d/%d \t",  t->dados.inicio.dia, t->dados.inicio.mes, t->dados.inicio.ano);
    printf("%d:%d\n", t->dados.inicio.hora, t->dados.inicio.minuto);
    printf("Fim: %d/%d/%d \t", t->dados.deadline.dia, t->dados.deadline.mes, t->dados.deadline.ano);
    printf("%d:%d\n", t->dados.deadline.hora, t->dados.deadline.minuto);
    printf("Duracao: %d\n", t->dados.duracao);
}

void salvar_linha(tarefa *t, FILE *fl){
    //0, NOME, INÍCIO, DURAÇÃO, DEADLINE    
    fprintf(fl, "%d, %s, ", t->id, t->dados.nome);
    fprintf(fl, "%d/%d/%d %d:%d, ", t->dados.inicio.dia, t->dados.inicio.mes,t->dados.inicio.ano, t->dados.inicio.hora, t->dados.inicio.minuto);
    fprintf(fl, "%d, %d/%d/%d %d:%d \n",  t->dados.duracao, t->dados.deadline.dia, t->dados.deadline.mes, t->dados.deadline.ano,t->dados.deadline.hora,t->dados.deadline.minuto);
}
/*void salvar(tarefa *t){
    FILE *f = fopen("test.txt", "wb");
    for(int i=0; i<3; i++){
        salvar_linha(t[i], f);
        fputc('\n');
    }
}*/

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

/*void carregar_arquivo(tarefa *t){
    FILE *fl = fopen("test.txt", "r");
    
}*/


int main(int agrv, char *argc[]){
    tarefa *t1 = (tarefa*) malloc(sizeof(tarefa)), *t2 = (tarefa*) malloc(sizeof(tarefa));
    FILE *fl = fopen("tarefas.txt", "r");
    
    //ler_linha(t1, fl);
    ler_linha(t2, fl);
    
    //salvar_linha(t1, fl2);
    
    //printa_tarefa(t1);
    printa_tarefa(t2);
    
    //fclose(fl);
   //fclose(fl2);
}

/*int casa_int(int n){
    int v=10, tam=1;
    while(1){
        if(n < v)
            break;
        tam++;
        v = v*10;
    }
    return(tam);
}
int string_pra_int(char *c){
    int n, i = 0;
    while(c[i] != '\0'){
        if(i==0)
            n = c[i]-48;
        else
            n = n*10 + (c[i]-48);
        i++;
    }    
    return(n);
}

void add_int_string(int n, char *str){
    char *c;
    int i=0, j;
    int tam = casa_int(n);
    c = (char*) malloc(tam*sizeof(char));
    itoa(n, c, 10);
    while(str[i] != '\0')
        i++;
    for(j=0; j<tam; j++){
        str[i+j] = c[j];
    }
}

char *converte_struct_string(tarefa *t){
    //0, NOME, INÍCIO, DURAÇÃO, DEADLINE
    //0#NOME#INÍCIO#DURAÇÃO#DEADLINE alterei pois dessa forma o nome pode ter ','
    //inicio/deadline dia#mes#ano#hora#minutos
    char *str;
    int tam_str = casa_int(t->id) + casa_int(t->dados.duracao) + 128; //define o tmanho da stringe
    str = (char*) calloc(tam_str, sizeof(char));
    add_int_string(t->id,str);
    strcat(str, "#");
    strcat(str, t->dados.nome);
    strcat(str, "#");
    //inicio
    add_int_string(t->dados.inicio.dia, str);
    strcat(str, "#");
    add_int_string(t->dados.inicio.mes, str);
    strcat(str, "#");
    add_int_string(t->dados.inicio.ano, str);
    strcat(str, "#");
    add_int_string(t->dados.inicio.hora, str);
    strcat(str, "#");    
    add_int_string(t->dados.inicio.minuto, str);
    strcat(str, "#");
    //duracao
    add_int_string(t->dados.duracao, str);
    strcat(str, "#");
    //deadline
    add_int_string(t->dados.deadline.dia, str);
    strcat(str, "#");
    add_int_string(t->dados.deadline.mes, str);
    strcat(str, "#");
    add_int_string(t->dados.deadline.ano, str);
    strcat(str, "#");
    add_int_string(t->dados.deadline.hora, str);
    strcat(str, "#");
    add_int_string(t->dados.deadline.minuto, str);
    
    return(str);
}

void salvar_arquivo(tarefa *t){
    FILE *fl = fopen("test.txt", "wb");
    char *s = converte_struct_string(t);
    fputs(s,fl);
    fputc('\n', fl);
    fputs(s,fl);
    fclose(fl);
}

void carregar_arquivo(tarefa *t){
    char *s, *s2;
    FILE *fl = fopen("test.txt", "r");    
    rewind(fl);
    s = (char*) calloc(300, sizeof(char));
    s2 = (char*) calloc(300, sizeof(char));
    fgets(s, 300, fl);
    fgets(s2, 300, fl);
    printf("\nstring: %s\n", s);
    fgetc(fl);
    printf("\nstring2: %s\n", s);
}
*/