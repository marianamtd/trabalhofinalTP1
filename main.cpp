#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

const int QTD_MAX = 50;
const int MAX_LEN = 30;

//declaração das funções
void menu_listagem();
void lista_categoria();
void lista_descricao();
void abate_estoque();
void aplica_aumento_desconto();
void exclui_produto();

struct Produto {
    int codigo;
    char descricao[MAX_LEN];
    char categoria;
    int quantidade;
    float preco;
};

// funções que leem os dados do inclui_produtos
void le_codigo(Produto produto[], int qtd, int i)
{
    int j;
    int codigo_prod;

    // Le o codigo do produto
    do 
    {
        printf("Codigo %d: ", i+1);
        scanf("%d", &produto[i].codigo);

        if (produto[i].codigo < 10000 || produto[i].codigo > 1000000)
            puts("Codigo invalido: Insira novamente.");

        codigo_prod = produto[i].codigo;
        for (j = i; j > 0; j--)
        {
            if (codigo_prod == produto[j-1].codigo)
            {
                puts("Codigo ja existe no sistema");
                printf("Codigo %d: ", i+1);
                scanf("%d", &produto[i].codigo);
                i--;
            }
        }
    } while(produto[i].codigo < 10000 || produto[i].codigo > 1000000 || codigo_prod == produto[j-1].codigo);
}

void le_descricao(Produto produto[], int qtd, int i)
{
    do {
        printf("Descricao %d: ", i+1);
        gets(produto[i].descricao);

        strupr(produto[i].descricao);

        if (strlen(produto[i].descricao) < 4 || strlen(produto[i].descricao) > 30)
            puts("Descricao invalida: Insira novamente.");

    } while (strlen(produto[i].descricao) < 4 || strlen(produto[i].descricao) > 30);

    // imprime cada um pra conferir se ta tudo certo
    for (int i = 0; i < qtd; i++)
    {
        puts(produto[i].descricao);
    }
}

/* void le_categoria(Produto produto[], int qtd, int i)
{
    do
    {
        getchar();
        printf("Categoria %d: ", i+1);
        produto[i].categoria = getchar();

        if (categoria != 'A' || categoria != 'a' || categoria != 'B' || categoria != 'b' || categoria != 'C' || categoria != 'c' || categoria != 'D' || categoria != 'd' || categoria != 'E' || categoria != 'e');
            puts("Invalido");
        
    } while (categoria != 'A' || categoria != 'a' || categoria != 'B' || categoria != 'b' || categoria != 'C' || categoria != 'c' || categoria != 'D' || categoria != 'd' || categoria != 'E' || categoria != 'e');

    for (int i = 0; i < qtd; i++)
    {
        printf("%c ", produto[i].categoria);
    }
} */

void le_quantidade(Produto produto[], int qtd, int i)
{
    do
    {
        printf("Quantidade %d: ", i+1);
        scanf("%d", &produto[i].quantidade);

        if (produto[i].quantidade <= 0)
            puts("Quantidade menor ou igual a 0.");
        
    } while (produto[i].quantidade <= 0);
}

void le_preco(Produto produto[], int qtd, int i)
{
    do
    {
        printf("Preco %d: ", i+1);
        scanf("%f", &produto[i].preco);

        if (produto[i].preco <= 0)
            puts("Preco menor ou igual a 0.");
        
    } while (produto[i].preco <= 0);
}

void exclui_produto(Produto produto[], int qtd)
{
    int produto_excluir;

    puts("Produto a excluir");
    printf("Codigo: ");
    scanf("%d", &produto_excluir);

    int pos;
    int existe = 0;
    // loop para procurar esse codigo no vetor
    for (int i = 0; i < qtd; i++)
    {
        if (produto_excluir == produto[i].codigo)
        {
            pos = i;
            existe = 1;
        }
    }

    if (existe == 1)
    {
        // se a quantidade for > 0, copia o proximo elemento para o atual
        if (produto[pos].quantidade > 0)
            printf("Produto descricao tem %d em estoque!", produto[pos].quantidade);
        
        else // if quantidade <= 0
        {
            for (int i = 0; i < qtd-1; i++)
                produto[i].codigo = produto[i+1].codigo;

            printf("Produto excluido com sucesso!");
        }
    }
    
    else
        printf("Produto nao existe!");
}


void inclui_produto()
{
    int qtd;
    // int codigo_prod;

    printf("Quantidade de produtos: ");
    scanf("%d", &qtd);

    Produto produto[qtd];
    // Produto produto[qtd];

    for (int i = 0; i < qtd; i++)
    {
        le_codigo(produto, qtd, i);
        getchar();
        le_descricao(produto, qtd, i);
        // le_categoria(produto, qtd, i);
        le_quantidade(produto, qtd, i);
        le_preco(produto, qtd, i);
        printf("Produto cadastrado com sucesso!\n");
    } 
}

// menu principal
void menu_principal(Produto produto[], int qtd)
{
    int opcao;
    int codigo_prod;

    //Produto produto[qtd];
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
            inclui_produto();
            break;
        
        case 2: // excluir produto
            exclui_produto(produto, qtd);
            break;

        case 3: // abater do estoque

            break;

        case 4: // listar produtos -> menu_listagem
            
            break;

        case 5: // menu aumento/desconto

            break;

        case 6: // fim
            break;

        default: // opcao invalida
            puts("Opcao invalida");
        }
    } while (opcao != 6);
}

int main(Produto produto[], int qtd)
{
    menu_principal(produto, qtd);
}
