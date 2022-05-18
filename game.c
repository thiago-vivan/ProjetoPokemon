#include <stdio.h>
#include <stdlib.h>

    typedef struct              //Struck de tipo pokemon com seus dados
    {
        int vida;
        int danoAtaque;
        int danoUltimate;

    }pokemon;

int main(){                 //main, onde seram chamadas as funções que fazem o game
    pokemon jogador;        //inicializo o pokemon do jogador
    pokemon enemy;          //inicializado o pokemom enemy
    
    inicio(&jogador);       
    
    printf(" Seu dano de ataque: %d\n Seu dano de ultimate: %d\n Sua vida: %d\n", jogador.danoAtaque, jogador.danoUltimate, jogador.vida);

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
            printf("Voce escolheu o Charizard!\n");
            p->vida = 200;
            p->danoAtaque = 25;
            p->danoUltimate = 50;
            break;

        case 2:
            printf("Voce escolheu o Jigglypuff!\n");
            p->vida = 150;
            p->danoAtaque = 40;
            p->danoUltimate = 100;
            break;

        case 3:
            printf("Voce escolheu o Caterpie!\n");
            p->vida = 100;
            p->danoAtaque = 20;
            p->danoUltimate = 150;
            break;

        default:
            printf("coe vacilao, escolheu errado. Escolhe direito ai!\n");
            printf("tem que ser 1 2 ou 3!\n");
        
        }
    }while (opcao != 1 && opcao != 2 && opcao != 3);

  
    return p;
}






