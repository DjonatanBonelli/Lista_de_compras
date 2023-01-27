/*
 Este Ã© um esqueleto que deve ser utilizado como base para implementaÃ§Ã£o do trabalho;
	- As funÃ§Ãµes nÃ£o tÃªm os parÃ¢metros definidos; se necessÃ¡rio, estes devem ser incluÃ­dos; Os tipos de retorno podem ser alterados, se necessÃ¡rio;
 	- Devem ser respeitados os nomes atribuÃ­dos Ã s funÃ§Ãµes e estruturas, porÃ©m, novas estruturas e funÃ§Ãµes podem ser criadas, caso julgue necessÃ¡rio;
	- FaÃ§a os includes necessÃ¡rios;
	- A organizaÃ§Ã£o das funÃ§Ãµes fica a critÃ©rio do programador;
	- A indentaÃ§Ã£o correta faz parte da nota;
	- NÃ£o sÃ£o permitidas variÃ¡veis globais;
	- Caso seja detectado plÃ¡gio, os grupos envolvidos receberÃ£o nota 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <locale.h>

#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

// Struct que representa um item de uma lista de compras armazenada em uma árvore binária de busca
struct item {
	char produto[50];
	int quantidade;
     struct item *esquerdo; 
	struct item *direito;
};
typedef struct item Item;

struct repeated{
  char produto[50];
  int quantidade;
  struct repeated *proximo;
}; 
typedef struct repeated Repeated;

// Apresenta o primeiro menu da aplicação e retorna a opção selecionada
int menu1()
{
     int op = 0;
     printf("\nMenu principal\n");
     // complete com as demais opcoes...
     printf("1 - Gerenciar lista A\n2 - Gerenciar lista B\n3 - Ver itens duplicados\n4 - Excluir listas\n");
     printf("%d - Sair do programa\n",EXIT);
     printf("\nDigite a opção: ");
     scanf("%d",&op);
     return op;
}

// Apresenta o segundo menu da aplicação e retorna a opção selecionada
int menu2()
{
     int op = 0;
     printf("Submenu - Gerenciar lista de compras\n");
     printf("1 - Inserir\n2 - Buscar\n3 - Atualizar\n4 - Listar\n5 - Deletar\n");
     printf("%d - Retornar para o menu principal\n",EXIT);
     printf("\nDigite a opção: ");
     scanf("%d",&op); 
     return op;
}

// Função padrão de inicializar a árvore como NULL
Item *inicializar(){
    //printf("inicializando\n");
    return NULL;
}

// Cria o item que será inserido como nó
Item criarItem(char produto[50], int quantidade){
    Item item;
    strcpy(item.produto, produto);
    item.quantidade = quantidade;
    item.direito = NULL;
    item.esquerdo = NULL;
    return item;
}

// Permite o cadastro de um item (caso o produto ainda nÃ£o exista) em uma lista de compas
Item *insert(Item *raiz, Item item)
{
     //printf("inserindo\n");
     if(raiz == NULL){
         Item *aux = (Item *)malloc(sizeof(Item));
         strcpy(aux->produto, item.produto);
         aux->quantidade = item.quantidade;
         aux->esquerdo = NULL;
         aux->direito = NULL;
         return aux;
     }
     else{
          if(strcmp(item.produto, raiz->produto) == 0){
               update(raiz, raiz->produto);
          }
          else{
               if(strcmp(item.produto, raiz->produto) < 0){
               raiz->esquerdo = insert(raiz->esquerdo, item);
          }
               else if(strcmp(item.produto, raiz->produto) > 0){
               raiz->direito = insert(raiz->direito, item);
          }
          }
          return raiz;
     }
}

// Permite consultar se um item estÃ¡ em uma lista de compras
int query(Item *raiz, char search[50])
{
     if(raiz == NULL){
          return -1;
     }
     else{
          if(strcmp(search, raiz->produto) == 0){
               return 0;
          }
          else if(strcmp(search, raiz->produto) < 0){
               return query(raiz->esquerdo, search);
          }
          else if(strcmp(search, raiz->produto) > 0){
               return query(raiz->direito, search); 
          }
     }
}

// Permite a atualizaÃ§Ã£o da quantidade de um produto (caso exista) na lista de compras
int update(Item *raiz, char search[50])
{
     if(raiz != NULL){
          if(strcmp(search, raiz->produto) == 0){
               printf("%s está na lista! Digite a nova quantidade: ", raiz->produto);
               scanf("%d", &raiz->quantidade);
               return 0;
          }
          else if(strcmp(search, raiz->produto) < 0){
               return update(raiz->esquerdo, search);
          }
          else if(strcmp(search, raiz->produto) > 0){
               return update(raiz->direito, search); 
          }
     }
     return;
}

// Listar todos os itens da lista de compras em ordem alfabÃ©tica;
int list(Item *raiz)
{
    if(raiz != NULL){
        list(raiz->esquerdo);
        printf("%s, %d\n", raiz->produto, raiz->quantidade);
        list(raiz->direito);
    }
     return 0;
}

// Permite excluir um item de uma lista de compras
Item *delete(Item *raiz, char key[50])
{
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
     }
    else{
          //procura o nó
        if(strcmp(raiz->produto, key) == 0){
            //remove folhas
            if(raiz->esquerdo == NULL && raiz->direito == NULL){
                free(raiz);
                printf("Produto deletado!\n");
                return NULL;
            }
            else{
                //remove nó com dois filhos
                if(raiz->esquerdo != NULL && raiz->direito != NULL){
                    Item *aux = raiz->esquerdo;
                        while(aux->direito != NULL){
                            aux = aux->direito;
                        }
                        strcpy(raiz->produto, aux->produto);
                        raiz->quantidade = aux->quantidade;
                        strcpy(aux->produto, key);
                        raiz->esquerdo = delete(raiz->esquerdo, key);
                        return raiz;     
                }
                else{
                        //remove nó com um filho
                        Item *aux;
                        if(raiz->esquerdo != NULL){
                            aux = raiz->esquerdo;
                        }
                        else{
                            aux = raiz->direito;  
                        }
                        free(raiz);
                        printf("Produto deletado!\n");
                        return aux;
                }
            }
        }
        else{            //encontrar nó
            if(strcmp(key, raiz->produto) < 0)
                raiz->esquerdo = delete(raiz->esquerdo, key);
            else
                raiz->direito = delete(raiz->direito, key); 
            return raiz;
        }
     }
     return;
}

//encontra itens duplicados
Repeated *intersect(Item *raizA, Item *raizB, Repeated *primeiro)
{
        if(raizA == NULL){
            return;
        }
        else{
            if(query(raizB, raizA->produto) == 0){      //percorre a lista A verificando pela função query
                    if(primeiro == NULL){              //primeiro nulo
                        primeiro = malloc(sizeof(Repeated));
                        strcpy(primeiro->produto, raizA->produto);
                        primeiro->proximo = NULL;

                        printf("\nProduto: %s\n", primeiro->produto);
                    }
                    else{                    //primeiro não nulo
                        Repeated *aux; //auxiliar
                        aux = malloc(sizeof(Repeated));
                        strcpy(aux->produto, raizA->produto);
                        aux->proximo = primeiro;
                        primeiro = aux;

                        printf("Produto: %s\n", aux->produto);
            }
    } 
            intersect(raizA->esquerdo, raizB, primeiro);
            intersect(raizA->direito, raizB, primeiro);
 }
}

//Libera a memória total 
void liberar(Item *raizA, Item *raizB){
     if(raizA != NULL){
          liberar(raizA->esquerdo, raizB);
          liberar(raizA->direito, raizB);
          free(raizA);
    }
     if(raizB != NULL){
          liberar(raizA, raizB->esquerdo);
          liberar(raizA, raizB->direito);
          free(raizB);
    }
}

// Programa principal
int main()
{
     setlocale(LC_ALL, "Portuguese");
     char produto[50];
     char search[50];
     int quantidade;
     int opcao1;
     int opcao2;
     Item *raizA = NULL;
     Item *raizB = NULL;
     Repeated *primeiro = NULL;

     opcao1 = 0;

    Item *raiz = inicializar();

    while (opcao1 != EXIT)
    {
          opcao1 = menu1();
               
          switch(opcao1)
          {
               case 1 : // gerenciar lista de compras A
                    opcao2 = 0;
                    while(opcao2 != EXIT){
                         printf("\n\n** Lista de Compras A **\n\n");
                         opcao2 = menu2();
                         switch(opcao2){ // operacoes sobre a arvore A
                              case 1 : 

                                   printf("\nNome do item a ser inserido: ");
                                   scanf("%s", produto);
                                   printf("Quantidade do item a ser inserido: ");
                                   scanf("%d", &quantidade);
                                   raizA = insert(raizA, criarItem(produto, quantidade));
                                   break;

                              case 2 :

                                   printf("Digite o produto a ser buscado:");
                                   scanf("%s", search);
                                   printf("Buscando por %s...\n", search);
                                   if(query(raizA, search) == 0){
                                    printf("O produto %s está na lista!", search);
                                   }
                                   else{
                                    printf("O produto %s não está na lista!", search);
                                   }
                                   break;

                              case 3 :

                                   printf("Digite o produto a ser atualizado: ");
                                   scanf("%s", search);
                                   update(raizA, search);

                                   break;

                              case 4 : 

                                   list(raizA);
                                   break;

                              case 5 : 
                                   
                                   printf("Digite o produto a ser deletado:");
                                   scanf("%s", search);
                                   delete(raizA, search);
                         }    
                    }
                    break;

               case 2 : // gerenciar lista de compras B
                    // idem ao caso 1, mas para a arvore B
                    opcao2 = 0;
                    while(opcao2 != EXIT){
                         printf("\n\n** Lista de Compras B **\n\n");
                         opcao2 = menu2();
                         switch(opcao2){ // operacoes sobre a arvore B
                              case 1 : 

                                   printf("\nNome do item a ser inserido: ");
                                   scanf("%s", produto);
                                   printf("Quantidade do item a ser inserido: ");
                                   scanf("%d", &quantidade);
                                   raizB = insert(raizB, criarItem(produto, quantidade));
                                   break;

                              case 2 :

                                   printf("Digite o produto a ser buscado:");
                                   scanf("%s", search);
                                   printf("Buscando por %s...\n", search);
                                   if(query(raizA, search) == 0){
                                    printf("O produto %s está na lista!", search);
                                   }
                                   else{
                                    printf("O produto %s não está na lista!", search);
                                   }
                                   break;

                              case 3 :

                                   printf("Digite o produto a ser atualizado: ");
                                   scanf("%s", search);
                                   update(raizA, search);
                                   break;

                              case 4 : 

                                   list(raizB);
                                   break;

                              case 5 : 
                                   
                                   printf("Digite o produto a ser deletado: ");
                                   scanf("%s", search);
                                   delete(raizB, search);
                         }    
                    }
                    break;
                    
               case 3 : // Visualizar itens duplicados
                    printf("Itens duplicados: ");
                    intersect(raizA, raizB, primeiro);

               break;
               
               case 4 :
                    liberar(raizA, raizB);
          }
    }

     return 0;
}
