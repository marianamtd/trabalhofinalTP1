#include <stdio.h>
#include <string.h>

//constantes
const int QTD_MAX = 50;

//declaração das funções
void menu_listagem();
void lista_categoria();
void lista_descricao();

struct Produto {
  int codigo;
  char descricao[30];
  char categoria;
  int quantidade;
  float preco;
};

void inclui_produto()
{
  int qtd;

  // Pergunta quantos produtos serao cadastrados
  do {
    printf("Quantidade de produtos: ");
    scanf("%d", &qtd);

    if (qtd <= 0)
      puts("Valor invalido");    
  } while(qtd <= 0);

  if (qtd > 50)
    qtd = 50;

  // Cria o vetor com a quantidade de produtos
  Produto produto[qtd];
  
  // Varre o vetor da qtd de produto e le os dados de cada um
  for (int i = 0; i < qtd; i++)
  {
    printf("DADOS DO PRODUTO %d\n", i+1);
    // Le o codigo do produto
    do 
    {
        printf("Codigo:  ");
        scanf("%d", &produto[i].codigo);

        if (produto[i].codigo > 99999 && produto[i].codigo < 1000000)
            puts("Codigo invalido: Insira novamente.");
    } while (produto[i].codigo > 99999 && produto[i].codigo < 1000000);

    // Le a descricao do produto
    do {
        printf("Descricao: ");
        gets(produto[i].descricao);

        if (strlen(produto[i].descricao) < 4 && strlen(produto[i].descricao) > 30)
            puts("Descricao invalida: Insira novamente.");
    } while (strlen(produto[i].descricao) < 4 && strlen(produto[i].descricao) > 30);

    // Le a quantidade do produto
    do
    {
        printf("Quantidade: ");
        scanf("%d", &produto[i].quantidade);
    } while (produto[i].quantidade <= 0);
        
    // Le o preco do produto
    do
    {
        printf("Preço: ");
    } while (produto[i].preco <= 0);
  }
}

void menu_principal()
{
  do
  {

    int opcao;
      puts("\nMenu Principal");
      puts("1-Incluir Produto");
      puts("2-Excluir Produto");
      puts("3-Abater do estoque");
      puts("4-Listar produtos");
      puts("5-Aplicar aumento/desconto");
      puts("6-Fim");
      printf("Qual operação você deseja realizar?: ");
      scanf("%d", &opcao);

      switch(opcao) {
          case 1: // incluir produto
                  inclui_produto();
                  break;

          case 2: // excluir produto
                  exclui_produto();
                  break;

          case 3: // abater do estoque
                  abate_estoque();
                  break;

          case 4: // Menu de listagem
                  menu_listagem();
                  break;

          case 5: // Aplicar aumento/desconto
                  aplica_aumento();
                  break;

          case 6: // Fim
                  break;    

          default: // Opcao invalida
                    puts("Opcao invalida");
        }
  } while (opcao != 6);
}
void menu_listagem()
{
  int opcao;
  do
  {
    //input da opção
    puts("\nMenu Listagem");
    puts("1-Listar todos os produtos (ordenado por descrição)");
    puts("2-Listar todos os produtos (ordenado por categoria/descrição)");
    puts("3-Listar produtos com estoque baixo");
    puts("4-Voltar");
    printf("Qual operação você deseja realizar?: ");
    scanf("%d", &opcao);

    switch(opcao)
    {
      case 1: // Listar todos os produtos (descrição)
              lista_descricao();
              break;

      case 2: // Listar produtos (categoria/descrição)
              lista_categoria();
              break;

      case 3: // produto do estoque
              break;

      case 4: // voltar
              break;

      default: // Opcao invalida
                puts("Opcao invalida");
    }
  }
  while (opcao != 4);
}

int main() 
{
  menu_principal();
}