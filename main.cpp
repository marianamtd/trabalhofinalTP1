#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

const int QTD_MAX = 50;
const int MAX_LEN = 30;

struct Produto {
    int codigo;
    char descricao[MAX_LEN] = {0};
    char categoria;
    int quantidade;
    float preco;
};

void listar_por_descricao(Produto produto[], int max_len, int &qtd)
{
    char temp[MAX_LEN];
    // int i;

    bool trocou = true;

    produto[qtd].codigo = '\0';
    for (int k = qtd-1; k>0 && trocou; k--)	
    {
    trocou = false;
    for (int i = 0; i < k; i++)
        if (strcmp(produto[i].descricao, produto[i+1].descricao) > 0)
        {
            // descricao
            strcpy(temp, produto[i+1].descricao);
            strcpy(produto[i+1].descricao, produto[i].descricao);
            strcpy(produto[i].descricao, temp);

            // codigo
            int temp2;
            temp2 = produto[i+1].codigo;
            produto[i+1].codigo = produto[i].codigo;
            produto[i].codigo = temp2;

            // categoria
            char temp3;
            temp3 = produto[i+1].categoria;
            produto[i+1].categoria = produto[i].categoria;
            produto[i].categoria = temp3;
            trocou = true;

            // quantidade
            int temp4;
            temp4 = produto[i+1].quantidade;
            produto[i+1].quantidade = produto[i].quantidade;
            produto[i].quantidade = temp4;

            // preco
            float temp5;
            temp2 = produto[i+1].preco;
            produto[i+1].preco = produto[i].preco;
            produto[i].preco = temp5;

            trocou = true;
        }
    }
    
    putchar('\n');

    puts("--------------------------------------------------------");
    puts("Codigo Descricao                      Categ  Qtd   Preco");

    puts("--------------------------------------------------------");
    for (int i = 0; i < qtd; i++)
    {
        printf("%d %-30s   %c   %4d %.2f\n", produto[i].codigo, produto[i].descricao, produto[i].categoria, produto[i].quantidade, produto[i].preco);
    }

    puts("--------------------------------------------------------");   
}

/* --------------------------------------------------------
Codigo Descricao Categ Qtd Preco
--------------------------------------------------------
999999 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx c 9999 9999,99
999999 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx c 9999 9999,99
999999 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx c 9999 9999,99
999999 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx c 9999 9999,99
-------------------------------------------------------- */

// listagem dos produtos 
void menu_listagem(Produto produto[], int max_len, int &qtd)
{
    printf("Menu da Listagem\n");
    printf("1-Listar todos os produtos (ordenado por descricao)\n");
    printf("2-Listar todos os produtos (ordenado por categoria/descricao\n");
    printf("3-Listar produtos com estoque baixo\n");
    printf("4-Voltar\n");

    int operacao;
    do
    {
        printf("Qual operacao voce deseja realizar? ");
        scanf("%d", &operacao);

        if (operacao != 1 && operacao != 2 && operacao != 3 && operacao != 4)
            puts("Operacao invalida");
        
    } while (operacao != 1 && operacao != 2 && operacao != 3 && operacao != 4);
    
    switch (operacao)
    {
    case 1: // listar por ordem de descricao
        listar_por_descricao(produto, max_len, qtd);
        break;
    
    case 2: // listar por odem de categoria/descricao
        break;

    case 3: // listar por estoque baixo
        break;

    case 4: // voltar
        break;
    }
}


int main()
{
    Produto produto[QTD_MAX];
    int opcao;
    int codigo_prod;
    int qtd;

    do
    {
        puts("\nMenu Principal");
        puts("1-Incluir Produto");
        puts("2-Excluir Produto");
        puts("3-Abater do estoque");
        puts("4-Listar produtos");
        puts("5-Aplicar aumento/desconto");
        puts("6-Fim");

        printf("Qual operacao voce deseja realizar? ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: // incluir produto
            inclui_produto(produto, QTD_MAX, qtd);
            break;

        case 2: // excluir produto
            exclui_produto(produto, QTD_MAX, qtd);
            break;

        case 3: // abater do estoque
            abate_estoque(produto, QTD_MAX, qtd);
            break;

        case 4: // listar produtos -> menu_listagem
            menu_listagem(produto, QTD_MAX, qtd);
            break;

        case 5: // menu aumento/desconto
            aplica_aumento_desconto(produto);
            break;

        case 6: // fim
            break;

        default: // opcao invalida
            puts("Opcao invalida");
        }
    } while (opcao != 6);
}

