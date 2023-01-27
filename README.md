# Lista_de_compras
Com o objetivo de minimizar seus gastos mensais, os estudantes da UFFS costumam realizar suas compras em 2 supermercados diferentes: um mercado A (com preços melhores, porém mais distante), e um mercado B (mercadinho do bairro, porém mais caro). Desta forma, coube a você implementar um programa para gerenciar duas listas de compras.

Um item de uma lista de compras é representado por uma estrutura de dados contendo:

char produto[50]: nome do produto;
int quantidade: número de unidades do produto.
O programa deve conter um menu inicial com as seguintes opções:

Gerenciar lista de compras A;
Gerenciar lista de compras B;
Visualizar itens duplicados.
As opções 1 e 2 devem levar a um submenu que possibilita a realização das operações abaixo na respectiva lista de compras (A ou B):

Inserir item (caso o produto ainda não exista) na lista de compras;
Pesquisar se um produto está na lista de compras;
Atualizar a quantidade de um produto (caso exista) na lista de compras;
Listar todos os itens da lista de compras em ordem alfabética;
Deletar item da lista de compras.
Cada lista de compras deve ser armazenada em uma BST (árvore binária de busca) ordenada pelo nome do produto.

A opção 3 deve realizar a intersecção entre os itens presentes nas listas de compras A e B. Os produtos em duplicidade devem ser inseridos (uma única vez) em uma lista simplesmente encadeada. Em seguida, esta lista encadeada deve ser impressa.
