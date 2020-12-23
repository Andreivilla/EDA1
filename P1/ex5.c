//ex5
celula* inicio(celula *lista, int posi){
    celula *temp = (celula*) malloc(sizeof(celula));
    celula *percorre;
    int i;
    percorre = lista;
    for(i=0; i<posi; i++){
        percorre = percorre->prox;
    }
    temp->nome = percorre->nome;
    temp->matricula = percorre->matricula;
    temp->media = percorre->media;
    temp->prox = lista;
    
    for(i=0; i<posi-1; i++){
        lista = lista->prox;
    }
    lista->prox = lista->prox->prox;
    return temp;
}
