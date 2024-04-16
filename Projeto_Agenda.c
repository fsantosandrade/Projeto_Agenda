#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Declarando a struct contato que armazena as informações do contato
struct contato{
    char nome[40];
    char tel[20];
    char apelido[40];
    char email[40];
    char cidade[20];
};

// Declaração do ponteiro para a agenda, que vai armazena os contatos
struct contato *agenda = NULL;

int main(){
    // Declarando as variáveis
    int op, opp, editar, exluir, visualizar, contatos_quantidade = 0;
    char nome[40], tel[20], apelido[40], email[40], cidade[20];

    // Aloca 10 espaços para a agenda
    agenda = (struct contato*)malloc(sizeof(struct contato) * 100);

    // Ponteiros para os campos da struct contato
    char *n, *t, *a, *e, *c;
    n = &agenda[contatos_quantidade].nome[0];
    t = &agenda[contatos_quantidade].tel[0];
    a = &agenda[contatos_quantidade].apelido[0];
    e = &agenda[contatos_quantidade].email[0];
    c = &agenda[contatos_quantidade].cidade[0];

    // Apresentação do menu principal
    printf("Bem Vindo(a) a Agenda!\n");
    printf("Digite 1 para salvar um novo contato\n");
    printf("Digite 2 para ver os contatos salvos\n");
    printf("Digite 3 para editar um contato\n");
    printf("Digite 4 para excluir um contato\n");
    printf("Digite 5 para fechar a agenda\n");
    scanf("%d", &op);
    
    // Loop principal do programa, que só é interrompido quando a opção 5 é selecionada
    while(op != 5){
        switch(op){
            case 1:
                // Adiciona um novo contato à agenda
                printf("--Digite tudo junto!!!--\n");
                printf("Digite o nome do contato: ");
                scanf("%s", agenda[contatos_quantidade].nome);
                printf("Digite o telefone do contato: ");
                scanf("%s", agenda[contatos_quantidade].tel);
                printf("Digite o apelido do contato: ");
                scanf("%s", agenda[contatos_quantidade].apelido);
                printf("Digite o email do contato: ");
                scanf("%s", agenda[contatos_quantidade].email);
                printf("Digite a cidade do contato: ");
                scanf("%s", agenda[contatos_quantidade].cidade);
                contatos_quantidade++;

                // Atualiza os ponteiros para os campos da struct contato
                n = &agenda[contatos_quantidade-1].nome[0];
                t = &agenda[contatos_quantidade-1].tel[0];
                a = &agenda[contatos_quantidade-1].apelido[0];
                e = &agenda[contatos_quantidade-1].email[0];
                c = &agenda[contatos_quantidade-1].cidade[0];

                printf("Contato salvo com sucesso!\n\n");
                break;

            case 2:
                // Lista todos os contatos da agenda
                if(contatos_quantidade == 0){
                    printf("Nenhum contato salvo!\n\n");
                    break;
                }
                //Mostra os contatos salvos atualmente
                printf("Contatos salvos:\n");
				for(int i = 0; i < contatos_quantidade; i++){
					printf("%d. %s\n", i+1, agenda[i].nome);
				}
				printf("\n");
				printf("Digite 1 para mais informacoes sobre o contato\n");
				printf("Digite 2 para voltar ao menu principal\n");
				scanf("%d", &opp);
				//Switch para mostrar ou não mais informações do contato pra deixar a aparência mais limpa
				switch(opp){
					case 1:
						printf("Gostaria de ver as informacoes de qual contato? Digite o numero correspondente: \n");
						scanf("%d", &visualizar);
						if(visualizar > contatos_quantidade || visualizar <= 0){
							printf("Numero invalido!\n");
						}else{
							printf("%d. %s - Tel: %s\n Apelido: %s\n Email: %s\n Cidade: %s\n",visualizar, agenda[visualizar-1].nome, agenda[visualizar-1].tel, agenda[visualizar-1].apelido, agenda[visualizar-1].email, agenda[visualizar-1].cidade);
						}
				}
				
				printf("\n");
				break;	
				
			case 3:
				//Editar os contatos da agenda
				if(contatos_quantidade == 0){
				printf("Nenhum contato foi salvo ainda!");
				printf("\n");
			}
			//mostra os contatos salvos
				printf("Contatos salvos: \n");
				for(int i = 0; i < contatos_quantidade; i++){
					printf("%d. %s", i+1, agenda[i].nome);
					printf("\n");
				}
				//Seleciona o contato desejado e armazena ele em "editar"
				printf("Qual contato voce deseja alterar? Digite o numero: ");	
				scanf("%d", &editar);
				//Salva o novo contato
				
			if(editar <=0 || editar > contatos_quantidade){
				printf("Valor invalido"); 
				printf("\n");
			}else{
				printf("--Digite tudo junto!!!--\n");
				printf("Digite o novo nome do contato: ");
				scanf("%s", agenda[editar-1].nome);
				printf("Digite o novo telefone do contato: ");
				scanf("%s", agenda[editar-1].tel);
				printf("Digite o novo apelido do contato: ");
				scanf("%s", agenda[editar-1].apelido);
				printf("Digite o novo email do contato: ");
				scanf("%s", agenda[editar-1].email);
				printf("Digite a nova cidade do contato: ");
				scanf("%s", agenda[editar-1].cidade);
				printf("\n");
			}
			    printf("Contato editado com sucesso!");
			    printf("\n");
				break;
				
			case 4:
				//Exluir um contato
			    if(contatos_quantidade == 0){
			    	printf("Nenhum contato foi salvo ainda!");
			    	printf("\n");
				}
				//Novamente mostra os contatos salvos
				printf("Contatos salvos: \n");
   				 for (int i = 0; i < contatos_quantidade; i++) {
      			 printf("%d. %s\n", i+1, agenda[i].nome);
			}
			//Seleciona o contato desejado e armazena em "excluir"
				printf("Qual contato deseja exluir? Digite o numero correspondente: ");
				scanf("%d", &exluir);
				//Exlui o contato usando a função free
				if(exluir > 0 && exluir <= contatos_quantidade){
					exluir--;
					printf("O contato excluido foi: %s", agenda[exluir].nome);
					printf("\n");
					free(&agenda[exluir]);
					
					for(int i = exluir; i<contatos_quantidade-1; i++){
						agenda[i]=agenda[i+1];
					}
				contatos_quantidade--;	
				}else{
					printf("Valor invalido");
				}
				printf("\n");
				break;
				//Default de opção inválida
				default:
					printf("Digite uma opcao valida!");
					break;	
		}
		//Repete o menu principal
	printf("O que deseja fazer?\n");	
	printf("Digite 1 para salvar um novo contato\n");
	printf("Digite 2 para ver os contatos salvos\n");
	printf("Digite 3 para editar um contato\n");
	printf("Digite 4 para excluir um contato\n");
	printf("Digite 5 para fechar a agenda\n");
	scanf("%d", &op);
	}
	//Limpa a agenda usando o free de novo e fecha no return 0
	free(agenda);
	printf("Agenda fechada");
	return 0;
}
