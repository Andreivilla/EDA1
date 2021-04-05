typedef struct{
    int dado;
    struct nodo *prox;
}nodo;

nodo * split (nodo *l){
    nodo *x,*y,*p;
    x=y=l;
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

nodo * merge(nodo *e, nodo *d){
    nodo *l, *p;
    l=NULL;
    while(e!=NULL && d!=NULL){
        if(e->dado < d->dado){
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


node * mergeSort(node * l){
    node *e, *d, *mid;
    if(l==NULL || l->next ==NULL) 
        return l;
    mid=split(l);
    e = mergeSort(l);
    d = mergeSort(mid);
    l=merge(e,d);
    return(l);
}