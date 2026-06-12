/*
 * ============================================================
 *  DICAS DO CELULAR PARA A TERCEIRA IDADE
 *  Projeto Final - CMP1044 Algoritmos - PUC Goias 2026/1
 *  Integrantes: Matheus Henrique, Joao Pedro, Hugo Helio, Davi Cesario, Pedro Gabriel
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

/* ---- CONSTANTES ---- */
#define TOTAL_DICAS   20
#define MAX_DUVIDAS   50
#define TAM_TITULO   100
#define TAM_TEXTO    300
#define TAM_NOME      80

/* ---- MATRIZES QUE GUARDAM AS DICAS (como tabelas) ---- */
char categorias[TOTAL_DICAS][TAM_TITULO] = {
    "Redes Sociais",
    "Redes Sociais",
    "Redes Sociais",
    "Redes Sociais",
    "Redes Sociais",
    "Redes Sociais",
    "Seguranca Digital",
    "Seguranca Digital",
    "Seguranca Digital",
    "Seguranca Digital",
    "Seguranca Digital",
    "Uso da Internet",
    "Uso da Internet",
    "Uso da Internet",
    "Uso da Internet",
    "Uso da Internet",
    "Duvidas Gerais",
    "Duvidas Gerais",
    "Duvidas Gerais",
    "Duvidas Gerais"
};

char titulos[TOTAL_DICAS][TAM_TITULO] = {
    "Como enviar mensagem no WhatsApp",
    "Como enviar foto no WhatsApp",
    "Como fazer videochamada no WhatsApp",
    "O que e o Instagram",
    "O que e o Facebook",
    "O que e TikTok e Kwai",
    "Como identificar um golpe no WhatsApp",
    "Nunca clique em links suspeitos",
    "Proteja sua senha",
    "Golpe do falso suporte tecnico",
    "Como criar uma senha segura",
    "Como pesquisar no Google",
    "Como assistir videos no YouTube",
    "Como aumentar a fonte do celular",
    "O que e Wi-Fi e como conectar",
    "Como economizar bateria",
    "Como tirar foto com o celular",
    "Como ligar para o SAMU",
    "Como silenciar o celular",
    "O celular travou, o que fazer"
};

char textos[TOTAL_DICAS][TAM_TEXTO] = {
    "Abra o WhatsApp, toque no icone de conversa, escolha o contato e digite sua mensagem. Aperte o botao verde para enviar.",
    "Dentro da conversa, toque no icone de clipe (anexo). Escolha Galeria, selecione a foto e toque em enviar.",
    "Abra a conversa com o contato. Toque no icone de camera no canto superior direito. A videochamada ira iniciar.",
    "Instagram e uma rede social de fotos e videos. Voce pode seguir amigos e curtir publicacoes. Cuidado com perfis desconhecidos.",
    "Facebook e uma rede social onde voce pode postar textos e fotos. Muito usado para manter contato com familiares distantes.",
    "TikTok e Kwai sao aplicativos de videos curtos e divertidos. Voce pode ver receitas e dicas de saude. Nao precisa de conta para assistir.",
    "ATENCAO: Desconfie de mensagens pedindo dinheiro urgente, mesmo de filhos ou netos. Ligue para a pessoa antes de transferir qualquer valor!",
    "Se receber mensagem com link dizendo que voce ganhou premio, NAO clique. Delete a mensagem. Bancos nunca pedem senha por mensagem.",
    "Nunca compartilhe sua senha com ninguem. Use senhas com letras e numeros. Troque sua senha se suspeitar que alguem descobriu.",
    "Se alguem ligar dizendo que seu celular tem virus e pedir para instalar um app, DESLIGUE o telefone. Isso e um golpe! Consulte um familiar.",
    "Use pelo menos 8 caracteres. Misture letras e numeros. Exemplo: Rosa2024 e uma senha forte. Evite datas de aniversario ou 123456.",
    "Abra o Google no celular. Na barra, digite o que quer encontrar. Exemplo: remedio para pressao ou receita de bolo. Toque em pesquisar.",
    "Abra o YouTube, toque na lupa e pesquise o que quer ver. Exemplo: musicas anos 70 ou exercicios para joelho. Toque no video. E gratuito!",
    "Va em Configuracoes, Acessibilidade, Tamanho da fonte. Arraste para a direita para aumentar as letras. Facilita muito a leitura!",
    "Wi-Fi e a internet sem fio de casa. Va em Configuracoes, Wi-Fi, ative e escolha sua rede. Digite a senha. Usando Wi-Fi nao gasta seus dados.",
    "Reduza o brilho da tela e feche aplicativos que nao usa. Ative o modo economia de bateria em Configuracoes. Carregue ao chegar em 20%.",
    "Abra o aplicativo Camera. Aponte o celular para o que quer fotografar. Toque no botao redondo branco para tirar a foto.",
    "Em emergencia medica, abra o telefone e disque 192 (SAMU) ou 193 (Bombeiros). E gratuito e funciona mesmo sem credito no celular.",
    "Pressione o botao de volume para baixo ate aparecer o icone de sino riscado. Ou deslize a barra de cima para baixo e toque no som.",
    "Se o celular travar, pressione e segure o botao de ligar por 10 segundos ate reiniciar. Se nao funcionar, consulte um familiar ou tecnico."
};

/* ---- VETORES PARA GUARDAR AS DUVIDAS DOS USUARIOS ---- */
char nomeDuvida[MAX_DUVIDAS][TAM_NOME];
char textoDuvida[MAX_DUVIDAS][TAM_TEXTO];
int totalDuvidas = 0;

/* ============================================================
 *  FUNCAO: exibir uma dica pelo indice
 * ============================================================ */
void exibirDica(int i) {
    printf("\n  ------------------------------------------\n");
    printf("  Dica %d: %s\n", i + 1, titulos[i]);
    printf("  Categoria: %s\n", categorias[i]);
    printf("  ------------------------------------------\n");
    printf("  %s\n", textos[i]);
    printf("  ------------------------------------------\n");
}

/* ============================================================
 *  FUNCAO: listar dicas de uma categoria
 * ============================================================ */
void listarPorCategoria() {
    int opcao, i, encontrou;
    char catEscolhida[TAM_TITULO];

    do {
        printf("\n  === ESCOLHA A CATEGORIA ===\n");
        printf("  1. Redes Sociais\n");
        printf("  2. Seguranca Digital\n");
        printf("  3. Uso da Internet\n");
        printf("  4. Duvidas Gerais\n");
        printf("  5. Voltar\n");
        printf("  Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            sprintf(catEscolhida, "Redes Sociais");
        } else if (opcao == 2) {
            sprintf(catEscolhida, "Seguranca Digital");
        } else if (opcao == 3) {
            sprintf(catEscolhida, "Uso da Internet");
        } else if (opcao == 4) {
            sprintf(catEscolhida, "Duvidas Gerais");
        } else if (opcao < 1 || opcao > 5) {
            printf("  Opcao invalida!\n");
        } else if (opcao == 5) {
            return;
    }
    } while(opcao < 1 || opcao > 5);

    printf("\n  === DICAS: %s ===\n", catEscolhida);
    encontrou = 0;

    for (i = 0; i < TOTAL_DICAS; i++) {
        if (strcmp(categorias[i], catEscolhida) == 0) {
            exibirDica(i);
            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("  Nenhuma dica encontrada nessa categoria.\n");
    }
}

/* ============================================================
 *  FUNCAO: buscar dica por palavra-chave
 * ============================================================ */
void buscarDica() {
    char palavra[TAM_TITULO];
    int i, encontrou;

    /* limpa o Enter que ficou no buffer do scanf anterior */
    while (getchar() != '\n');

    printf("\n  === BUSCAR DICA ===\n");
    printf("  Digite uma palavra (ex: WhatsApp, golpe, foto):\n");
    printf("  > ");
    fgets(palavra, TAM_TITULO, stdin);
    /* remove o Enter do final */
    palavra[strlen(palavra) - 1] = '\0';

    encontrou = 0;
    printf("\n  Resultados para: %s\n", palavra);

    for (i = 0; i < TOTAL_DICAS; i++) {
        /* strstr verifica se a palavra aparece dentro do texto */
        if (strstr(titulos[i], palavra) != NULL ||
            strstr(textos[i],  palavra) != NULL) {
            exibirDica(i);
            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("  Nenhuma dica encontrada para \"%s\".\n", palavra);
        printf("  Tente palavras como: foto, video, senha, golpe, Google.\n");
    }
}

/* ============================================================
 *  FUNCAO: cadastrar uma duvida do usuario
 * ============================================================ */
void cadastrarDuvida() {
    FILE *arq;
    int j;

    /* limpa o Enter do buffer */
    while (getchar() != '\n');

    if (totalDuvidas >= MAX_DUVIDAS) {
        printf("  Limite de duvidas atingido.\n");
        return;
    }

    printf("\n  === ENVIAR SUA DUVIDA ===\n");
    printf("  Nos ajudamos voce!\n\n");

    printf("  Seu nome: ");
    fgets(nomeDuvida[totalDuvidas], TAM_NOME, stdin);
    nomeDuvida[totalDuvidas][strlen(nomeDuvida[totalDuvidas]) - 1] = '\0';

    printf("  Sua duvida: ");
    fgets(textoDuvida[totalDuvidas], TAM_TEXTO, stdin);
    textoDuvida[totalDuvidas][strlen(textoDuvida[totalDuvidas]) - 1] = '\0';

    totalDuvidas++;

    /* salva todas as duvidas no arquivo duvidas.txt */
    arq = fopen("duvidas.txt", "w");
    if (arq != NULL) {
        for (j = 0; j < totalDuvidas; j++) {
            fprintf(arq, "Nome: %s\n", nomeDuvida[j]);
            fprintf(arq, "Duvida: %s\n", textoDuvida[j]);
            fprintf(arq, "---\n");
        }
        fclose(arq);
    }

    printf("\n  Duvida registrada! Numero: #%d\n", totalDuvidas);
    printf("  Obrigado, %s!\n", nomeDuvida[totalDuvidas - 1]);
}

/* ============================================================
 *  FUNCAO: listar todas as duvidas cadastradas
 * ============================================================ */
void listarDuvidas() {
    int i;

    printf("\n  === DUVIDAS CADASTRADAS ===\n");

    if (totalDuvidas == 0) {
        printf("  Nenhuma duvida cadastrada ainda.\n");
        return;
    }

    printf("  Total: %d duvidas\n\n", totalDuvidas);

    for (i = 0; i < totalDuvidas; i++) {
        printf("  [#%d] Nome: %s\n", i + 1, nomeDuvida[i]);
        printf("       Duvida: %s\n", textoDuvida[i]);
        printf("  ----------------------------------------\n");
    }
}

/* ============================================================
 *  MAIN - programa principal
 * ============================================================ */
int main() {
    int opcao;

    do {
        printf("\n  ================================================\n");
        printf("   DICAS DO CELULAR PARA A TERCEIRA IDADE\n");
        printf("  ================================================\n");
        printf("   Ola! Como posso te ajudar hoje?\n\n");
        printf("   1. Ver dicas por categoria\n");
        printf("   2. Buscar dica por palavra\n");
        printf("   3. Enviar uma duvida\n");
        printf("   4. Ver duvidas cadastradas\n");
        printf("   0. Sair\n");
        printf("  ================================================\n");
        printf("   Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            listarPorCategoria();
        } else if (opcao == 2) {
            buscarDica();
        } else if (opcao == 3) {
            cadastrarDuvida();
        } else if (opcao == 4) {
            listarDuvidas();
        } else if (opcao == 0) {
            printf("\n  Ate logo! Qualquer duvida, estamos aqui.\n\n");
        } else {
            printf("  Opcao invalida. Tente de novo.\n");
        }

    } while (opcao != 0);

    return 0;
}