## Trabalho final EDA

Aluno: Andrei Villa

## Instruções

**Funções de menu** 
1) Permite incluir tarefas no programa
2) Imprime uma lista de tarefas
3) Exclui tarefas através do id
4) Edita tarefa através do id
5) Carrega arquivo("tarefas.txt") com todas as tarefas
6) Salva as tarefas rodando no programa, a função reinscreve o arquivo apagando as tarefas anteriores
7) Formula a agenda do dia e otimiza ela, ou pelo menos deveria
8) Salva as tarefas do dia', lembrando q a lista de tarefas do dia deve primeiramente ser gerada no item 7
0) Fecha o programa

## Avisos

**Arquivos**
O progrma gera dois arquivos com tarefas.txt e tarefasdia.txt (quando solicitado), contendo a lista de tarefas geral e a lista de tarefas do dia respectivamente.
Os arquivos seguem o formato:

ID, NOME, INÍCIO, DURAÇÃO, DEADLINE

Vc pode dar entrada em dados diretamente modificandooarquivo muitas vezes é mais rápido 

**Nota da versão**
O item 7 do menu não funciona corretamente 
A função *agenda_do_dia* funciona corretamene retornanado as tarefas do dia
A função *otimiza* também funciona corretamente 
Porem a função *mergeSort* possui um erro que elimina o ultimo no e aloca alguma forma de lixo no inicio