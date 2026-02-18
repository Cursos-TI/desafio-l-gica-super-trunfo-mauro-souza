/*
🏅 Nível Aventureiro
No nível Aventureiro, você expandirá o sistema para incluir a comparação aninhada e a criação de um menu interativo usando switch.

🆕 Diferença em relação ao Nível Novato:
Menu Interativo: O usuário poderá escolher diferentes atributos para comparação através de um menu.
Comparação Aninhada: Implementação de lógica de comparação mais complexa, utilizando estruturas aninhadas para tomar decisões 
baseadas em múltiplos atributos.

🚩 Novas Funcionalidades:
Cadastro de Cartas: Similar ao nível Novato, com a adição de comparação de múltiplos atributos.
Menu Interativo: Uso de switch para criar um menu que permite ao jogador escolher os atributos a serem comparados.
Exibição de Resultados: O sistema exibirá o resultado da comparação, indicando qual carta venceu e qual atributo foi utilizado.

Requisitos funcionais
Menu Interativo: Criar um menu interativo no terminal usando a estrutura switch que permita ao jogador escolher qual atributo 
será usado para comparar as cartas. O menu deve ser claro e fácil de usar.

Comparação de Atributos: Implementar a lógica de comparação entre duas cartas com base no atributo selecionado pelo jogador. 
Os atributos disponíveis são:
Nome do país (string - usado apenas para exibir informações, não para comparação direta)
População (int)
Área (float)
PIB (float)
Número de pontos turísticos (int)
Densidade demográfica (float - já calculada no desafio anterior).

Regras de Comparação: A regra geral é: vence a carta com o maior valor no atributo escolhido. Porém, para a Densidade Demográfica, 
a regra inverte: vence a carta com o menor valor.
 
Exibição do Resultado: Mostrar na tela, de forma clara, o resultado da comparação, incluindo:
 
O nome dos dois países.
O atributo usado na comparação.
Os valores do atributo para cada carta.
Qual carta venceu.
Em caso de empate, exibir a mensagem "Empate!".

Requisitos não funcionais

Usabilidade: O menu e as mensagens exibidas no terminal devem ser intuitivos e fáceis de entender.
Performance: O sistema deve responder rapidamente às ações do usuário.
Manutenibilidade: Escreva um código limpo, organizado e bem comentado.
Segurança: (Embora menos crítico neste nível, comece a pensar em como seu código poderia lidar com entradas inválidas do usuário, 
como a escolha de uma opção inexistente no menu. Um default no switch pode ajudar).

Simplificações para o nível intermediário
Você pode usar as cartas que já foram cadastradas no desafio anterior. Não é necessário implementar o cadastro novamente neste nível.
Foque na criação do menu com switch e na lógica de comparação com if-else (incluindo comparações aninhadas onde fizer sentido).
Implemente a comparação para apenas duas cartas.
*/
#include<stdio.h>
#include<string.h>

int main() {
    // Declaração de variáveis
    char nome_pais_carta1[101]= {0}, nome_pais_carta2[101]= {0}; // armazena o nome do país
    long long int populacao_carta1, populacao_carta2; // armazena o número de habitantes da cidade
    float area_carta1, area_carta2; // armazena a área da cidade em kilometros quadrados
    double pib_carta1, pib_carta2; // armazena o PIB (Produto Interno Bruto) da cidade
    int pontos_turisticos_carta1, pontos_turisticos_carta2; // armazena o número de pontos turísticos da cidade
    float densidade_populacional_carta1, densidade_populacional_carta2; // armazena a densidade populacional da cidade ou seja população / área da cidade
    char resultado_populacao[200], resultado_area[200], resultado_pib[200], resultado_pontos_turisticos[200],resultado_densidade_populacional[200]; // armazena o resultado das comparações
    int opcao; // armazena a opção de atributo escolhido pelo usuário no Menu

    // Informações gerais
    printf("\n\n****** Super Trunfo de Países ******\n\n");
    // Coletando informações da primeira carta
    printf("Digite os dados da primeira carta\n\n");
    printf("-=== Carta1 ===-\n");

    // Observação sobre o campo nome_pais_carta1
    printf("\nDigite o nome do País com no máximo 100 caracteres.\n\n");
    // Nome do País
    printf("Nome do País: ");
    fgets(nome_pais_carta1, 101, stdin);
    nome_pais_carta1[strcspn(nome_pais_carta1, "\n")] = '\0'; // remove a quebra de linha na variavel
    printf("\n");

    // Observação sobre o campo populacao_carta1
    printf("\nDigite o número de habitantes do País.\n\n");
    // População
    printf("População: ");
    scanf("%lli", &populacao_carta1);
    printf("\n");

    // Observação sobre o campo area_carta1
    printf("\nDigite a área do País em quilômetros quadrados.\n\n");
    // Área
    printf("Área: ");
    scanf("%f", &area_carta1);
    printf("\n");

    // Observação sobre o campo pib_carta1
    printf("\nDigite o PIB (Produto Interno Bruto) do País.\n\n");
    // PIB
    printf("PIB: ");
    scanf("%lf", &pib_carta1);
    printf("\n");

    // Observações sobre o campo pontos_turisticos_carta1 
    printf("\nDigite a quantidade de pontos turísticos no País.\n\n");
    // Pontos turísticos
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos_carta1);
    printf("\n\n");

    // Campos calculados
    densidade_populacional_carta1 = (float) populacao_carta1 / area_carta1; // calcula a densidade populacional da carta 1
 
    // Coletando informações da segunda carta
    printf("Digite os dados da segunda carta\n\n");
    printf("-=== Carta2 ===-\n");

    // Observação sobre o campo nome_pais_carta2
    printf("\nDigite o nome do País com no máximo 100 caracteres.\n\n");
    // limpa o buffer
    getchar();
    // Nome do País
    printf("Nome do País: ");
    fgets(nome_pais_carta2, 101, stdin);
    nome_pais_carta2[strcspn(nome_pais_carta2, "\n")] = '\0'; // remove a quebra de linha na variavel
    printf("\n");

    // Observação sobre o campo populacao_carta2
    printf("\nDigite o número de habitantes da cidade.\n\n");
    // População
    printf("População: ");
    scanf("%lli", &populacao_carta2);
    printf("\n");

    // Observação sobre o campo area_carta2
    printf("\nDigite a área da cidade em quilômetros quadrados.\n\n");
    // Área
    printf("Área: ");
    scanf("%f", &area_carta2);
    printf("\n");

    // Observação sobre o campo pib_carta2
    printf("\nDigite o PIB (Produto Interno Bruto) da cidade.\n\n");
    // PIB
    printf("PIB: ");
    scanf("%lf", &pib_carta2);
    printf("\n");
    
    // Observações sobre o campo pontos_turisticos_carta2
    printf("\nDigite a quantidade de pontos turísticos na cidade.\n\n");
    // Pontos turísticos
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos_carta2);
    printf("\n\n");

    // Campos calculados
    densidade_populacional_carta2 = (float) populacao_carta2 / area_carta2; // calcula a densidade populacional da carta 2

    // Menu
    printf("*** Menu Interativo ***\n\n");
    printf("Escolha o número relativo ao atributo que deseja comparar\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. Sair\n");
    printf("\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    printf("\n");

    //Menu Interativo
    switch (opcao) {
        case 1:
            // Comparando os atributos de cada carta
            printf("*** Comparação de cartas (Atributo: População) ***\n");
            printf("Carta 1 (%s) X Carta 2 (%s)\n",nome_pais_carta1, nome_pais_carta2);
            printf("Carta 1 - %s - População: %lli\n",nome_pais_carta1, populacao_carta1);
            printf("Carta 2 - %s - População: %lli\n",nome_pais_carta2, populacao_carta2);
            printf("\n\n");
            // População
            if (populacao_carta1 != populacao_carta2){

                if (populacao_carta1 > populacao_carta2){

                    sprintf(resultado_populacao, "Vencedor %s com %lli habitantes\n",nome_pais_carta1, populacao_carta1);

                } else{

                    sprintf(resultado_populacao, "Vencedor %s com %lli habitantes\n",nome_pais_carta2, populacao_carta2);

                }

            } else {

                sprintf(resultado_populacao, "Empate!\n");

            }
            printf("Resultado: %s\n", resultado_populacao);
            break;
        case 2:
            // Comparando os atributos de cada carta
            printf("*** Comparação de cartas (Atributo: Área) ***\n");
            printf("Carta 1 (%s) X Carta 2 (%s)\n", nome_pais_carta1, nome_pais_carta2);
            printf("Carta 1 - %s - Área: %.2f km²\n",nome_pais_carta1, area_carta1);
            printf("Carta 2 - %s - Área: %.2f km²\n",nome_pais_carta2, area_carta2);
            printf("\n\n"); 
            // Área
            if (area_carta1 != area_carta2){

                if (area_carta1 > area_carta2){

                    sprintf(resultado_area, "Vencedor %s com %.2f km²\n",nome_pais_carta1, area_carta1);

                } else{

                    sprintf(resultado_area, "Vencedor %s com %.2f km²\n",nome_pais_carta2, area_carta2);

                }

            } else {

                sprintf(resultado_area, "Empate!\n");

            }
            printf("Resultado: %s\n", resultado_area);
            break;
        case 3:
            // Comparando os atributos de cada carta
            printf("*** Comparação de cartas (Atributo: PIB) ***\n");
            printf("Carta 1 (%s) X Carta 2 (%s)\n", nome_pais_carta1, nome_pais_carta2);
            printf("Carta 1 - %s - PIB: %.2lf de dolares\n",nome_pais_carta1, pib_carta1);
            printf("Carta 2 - %s - PIB: %.2lf de dolares\n",nome_pais_carta2, pib_carta2);
            printf("\n\n");
            // PIB
            if (pib_carta1 != pib_carta2){

                if (pib_carta1 > pib_carta2){

                    sprintf(resultado_pib, "Vencedor %s com %.2lf de dolares\n",nome_pais_carta1, pib_carta1);

                } else{ 

                    sprintf(resultado_pib, "Vencedor %s com %.2lf de dolares\n",nome_pais_carta2, pib_carta2);

                }

            } else {

                sprintf(resultado_pib, "Empate!\n");

            }            
            printf("Resultado: %s\n", resultado_pib);
            break;
        case 4:
            // Comparando os atributos de cada carta
            printf("*** Comparação de cartas (Atributo: Pontos Turísticos) ***\n");
            printf("Carta 1 (%s) X Carta 2 (%s)\n", nome_pais_carta1, nome_pais_carta2);
            printf("Carta 1 - %s - Pontos Turísticos: %d\n",nome_pais_carta1, pontos_turisticos_carta1);
            printf("Carta 2 - %s - Pontos Turísticos: %d\n",nome_pais_carta2, pontos_turisticos_carta2);
            printf("\n\n");
            // Pontos Turisticos
            if (pontos_turisticos_carta1 != pontos_turisticos_carta2){
            
                if (pontos_turisticos_carta1 > pontos_turisticos_carta2){

                    sprintf(resultado_pontos_turisticos, "Vencedor %s com %d pontos turísticos\n",nome_pais_carta1, pontos_turisticos_carta1);

                } else{

                    sprintf(resultado_pontos_turisticos, "Vencedor %s com %d pontos turísticos\n",nome_pais_carta2, pontos_turisticos_carta2);

                }

            } else {

                sprintf(resultado_pontos_turisticos, "Empate!\n");

            }
            printf("Resultado: %s\n", resultado_pontos_turisticos);
            break;
        case 5:
            // Comparando os atributos de cada carta
            printf("*** Comparação de cartas (Atributo: Densidade Populacional) ***\n");
            printf("Carta 1 (%s) X Carta 2 (%s)\n", nome_pais_carta1, nome_pais_carta2);
            printf("Carta 1 - %s - Densidade Populacional: %.2f hab/km²\n",nome_pais_carta1, densidade_populacional_carta1);
            printf("Carta 2 - %s - Densidade Populacional: %.2f hab/km²\n",nome_pais_carta2, densidade_populacional_carta2);
            printf("\n\n");
            // Densidade Populacional
            if (densidade_populacional_carta1 != densidade_populacional_carta2){    
            
                if (densidade_populacional_carta1 < densidade_populacional_carta2){

                    sprintf(resultado_densidade_populacional, "Vencedor %s com %.2f hab/km²\n",nome_pais_carta1, densidade_populacional_carta1);

                } else{

                    sprintf(resultado_densidade_populacional, "Vencedor %s com %.2f hab/km²\n",nome_pais_carta2, densidade_populacional_carta2);

                }

            } else {

                sprintf(resultado_densidade_populacional, "Empate!\n");

            }
            printf("Resultado: %s\n", resultado_densidade_populacional);
            break;
        case 6:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }
 
    return 0;

}
