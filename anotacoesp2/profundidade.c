int profundidade(arvore r, nodo *n){
    int valor = n->info;
    if(r == NULL)
        printf("arvore vazia");
    else if(valor = r.info)
        return 0;
    else if(valor < n->info)
        return(1+profundidade(r.esq, *n));
    else
        return(1+profundidade(r.esq, *n));
}