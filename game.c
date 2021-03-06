#include <stdio.h>
#include <stdlib.h>

    typedef struct              //Struck de tipo pokemon com seus dados
    {
        int vida;
        int danoAtaque;
        int danoUltimate;
        int validaUltimate;

    }pokemon;

int main(){                 //main, onde seram chamadas as funções que fazem o game
    pokemon jogador;        //inicializo o pokemon do jogador
    pokemon enemy;          //inicializado o pokemom enemy
    
    inicio(&jogador);       
    
    
    printf(" Seu dano de ataque: %d\n Seu dano de ultimate: %d\n Sua vida: %d\n", jogador.danoAtaque, jogador.danoUltimate, jogador.vida);
    printf(" \n");
    printf(" Voce entra na arena e comeca sua primeira batalha\n");
    printf(" \n");
    printf(" Em cada turno voce tem 3 opcoes\n");
    printf(" 1- Ataque normal\n");
    printf(" 2- Curar 70 pontos de vida\n");
    printf(" 3- Ultimate(1 vez por partida)\n");
    printf("\n");

    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("voce comeca! digite 1, 2 ou 3 para escolher sua acao \n");
    
    generateEnemy(&enemy);

    fight(&jogador, &enemy);

}

int inicio(pokemon *p){         //Função de inicio, onde será escolhido o pokemon do jogador
    int opcao = 0;

    printf("Bem vindo a Batalha dos Pokemons!\n");
    printf("Voce tera que escolher seu companheiro de luta\n");
    printf("1- Charizard\n");
    printf("2- Jigglypuff\n");
    printf("3- Caterpie\n");
    printf("Digite o 1, 2 ou 3 para escolher seu pokemon\n");

    do{
        scanf("%d", &opcao);
        
            switch (opcao){
        case 1:
            
            system("clear||cls");
            printf("Voce escolheu o Charizard!\n");         
            p->vida = 200;
            p->danoAtaque = 25;
            p->danoUltimate = 50;
            p->validaUltimate = 1;
            break;

        case 2:
            system("clear||cls");
            printf("Voce escolheu o Jigglypuff!\n");
            p->vida = 150;
            p->danoAtaque = 40;
            p->danoUltimate = 100;
            p->validaUltimate = 1;
            break;

        case 3:
            system("clear||cls");
            printf("Voce escolheu o Caterpie!\n");
            p->vida = 100;
            p->danoAtaque = 20;
            p->danoUltimate = 150;
            p->validaUltimate = 1;
            break;

        default:
            printf("coe vacilao, escolheu errado. Escolhe direito ai!\n");
            printf("tem que ser 1 2 ou 3!\n");
        
        }
    }while (opcao != 1 && opcao != 2 && opcao != 3);

  
    return p;
}


int generateEnemy(pokemon *e){        //Função que inicializa o inimigo

    e->vida = 250;
    e->danoAtaque = 40;
    e->danoUltimate = 0;
    e->validaUltimate = 1;

    return e;
}


int fight(pokemon *player, pokemon *adversario){
  
    int escolha = 0;

    while (player->vida >= 0 && adversario->vida >= 0){

        scanf("%d", &escolha);

        switch (escolha){
            case 1:
                system("clear||cls");
                adversario->vida -= player->danoAtaque;
                printf("vida do inimigo e: %d\n", adversario->vida);
                printf("\n");
                break;


            case 2:
                system("clear||cls");
                player->vida += 70;
                printf("Sua vida e: %d\n", player->vida);
                printf("vida do inimigo e: %d\n", adversario->vida);
                printf("\n");
                break;

            
            case 3:
                system("clear||cls");
                if(player->validaUltimate == 1){
                    adversario->vida -= player->danoUltimate;
                    player->validaUltimate = 0;
                    printf("Sua vida e %d\n", player->vida);
                    printf("vida do inimigo e: %d\n", adversario->vida);
                    printf("\n");
                }else{
                    printf("voce ja usou a ultimate lerdao, perdeu o turno por bobeira\n");
                }

                break;
            
            default:
                printf("ja falei as opcoes! 1, 2 ou 3\n");
                printf("perdeu o turno por bobeira!\n");
                printf("\n");
                break;
        }


        if(adversario->vida <= 0){
            printf("Você venceu o combate!!! \n");
            printf("Volte novamente mais tarde para mais combates!!\n");
            printf("\n");
            break;
        }else

        
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

        printf("o Pika2 usa ataque!\n");        
        player->vida -= adversario->danoAtaque;
        printf("Sua vida e %d\n", player->vida);
        printf("\n");

        if (player->vida <= 0)
        {
            printf("Voce perdeu esse combate, treine mais e volte mais forte \n");
            break;
        }
        
    }               //while da função fight

    return 0;
}
