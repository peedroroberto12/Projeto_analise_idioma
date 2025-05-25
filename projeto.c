// Projeto: Verificador de idioma 

//se possivel textar com textos razoavelmente longos, textos muito curtos tendem a gerar confusão devido a baixa amostra

//Pedro Roberto Fernandes Noronha Ra: 10443434
//Alice de Oliveira Duarte Ra: 10419323
//Guilherme Silveira Giancomini Ra: 10435311



#include <stdio.h>
#include <ctype.h>
#include <math.h>


typedef struct {
    char letra;
    float chance;
} letrachance;

int main(){

    letrachance textolido[26];

    for (int i = 0; i < 26; i++) {
        textolido[i].letra = 'a' + i;
        textolido[i].chance = 0.0f;
    }

    letrachance ingles[26] = {
        {'a', 8.167f},
        {'b', 1.492f},
        {'c', 2.782f},
        {'d', 4.253f},
        {'e', 12.702f},
        {'f', 2.228f},
        {'g', 2.015f},
        {'h', 6.094f},
        {'i', 6.966f},
        {'j', 0.153f},
        {'k', 0.772f},
        {'l', 4.025f},
        {'m', 2.406f},
        {'n', 6.749f},
        {'o', 7.507f},
        {'p', 1.929f},
        {'q', 0.095f},
        {'r', 5.987f},
        {'s', 6.327f},
        {'t', 9.056f},
        {'u', 2.758f},
        {'v', 0.978f},
        {'w', 2.360f},
        {'x', 0.150f},
        {'y', 1.974f},
        {'z', 0.074f}
    };

    letrachance portugues[26] = {
        {'a', 14.63f},
        {'b', 1.04f},
        {'c', 3.88f},
        {'d', 4.99f},
        {'e', 12.57f},
        {'f', 1.02f},
        {'g', 1.30f},
        {'h', 1.28f},
        {'i', 6.18f},
        {'j', 0.40f},
        {'k', 0.02f},
        {'l', 2.78f},
        {'m', 4.74f},
        {'n', 5.05f},
        {'o', 10.73f},
        {'p', 2.52f},
        {'q', 1.20f},
        {'r', 6.53f},
        {'s', 7.81f},
        {'t', 4.34f},
        {'u', 4.63f},
        {'v', 1.67f},
        {'w', 0.01f},
        {'x', 0.21f},
        {'y', 0.01f},
        {'z', 0.47f}
    };

    //comente as 3 linhas abaixo e descomente a linha 84 ou 85 para testar o programa com um texto fixo
    char texto[1024];
    printf("Digite uma frase para verificar o idioma: ");
    fgets(texto, sizeof(texto), stdin);

    //char texto[1024] = "A newly ordained priest was assigned to a town far from the city. It was his first assignment. He was determined to do his best to serve the town. When he arrived there, he was devastated to find a church that’s almost crumbling down. He asked the mayor who the last priest was and he said he couldn’t remember. No one had gone to church for years. The mayor wouldn’t help him rebuild the church. He called his seniors and they said he had to make do with what he had. But the priest wanted to make changes. So every day, he would saw, hammer, and dust the church. The people started to notice him and the clean church. On the 10th Sunday, he finished repairing the small bell tower. He rang the bell loudly. Few people came at first. But soon, he was able to fill the old church.";
    //char texto[1024] = "Um padre recém-ordenado foi designado para uma cidade distante da capital. Era sua primeira missão. Ele estava determinado a fazer o seu melhor para servir a cidade. Quando chegou lá, ficou devastado ao encontrar uma igreja quase em ruínas. Perguntou ao prefeito quem tinha sido o último padre e ele disse que não se lembrava. Ninguém ia à igreja há anos. O prefeito não o ajudaria a reconstruir a igreja. Ele ligou para seus superiores e eles disseram que ele tinha que se contentar com o que tinha. Mas o padre queria fazer mudanças. Então, todos os dias, ele serrava, martelava e limpava a igreja. As pessoas começaram a notar ele e a igreja limpa. No décimo domingo, ele terminou de consertar o pequeno campanário. Ele tocou o sino alto. Poucas pessoas vieram no começo. Mas logo, ele conseguiu encher a velha igreja.";

    printf("Você digitou: %s", texto);

    int letras = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
    if (isalpha(texto[i])) {
        letras++;
    }
}

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = tolower(texto[i]);
        if (c >= 'a' && c <= 'z') {
            textolido[c - 'a'].chance += 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        textolido[i].chance = (textolido[i].chance / letras) * 100;
    }

    //agora e necessario percorrer o textolido e comparar a diferenca de frequencia total em ingles e portugues

    float total_ingles = 0.0f;
    float total_portugues = 0.0f;
    for (int i = 0; i < 26; i++) {
        total_ingles += fabs(textolido[i].chance - ingles[i].chance) ;
        total_portugues += fabs(textolido[i].chance - portugues[i].chance) ;
    }

    if (total_ingles < total_portugues) {
        printf("O texto digitado deve ser inglês.\n");
    } else if (total_portugues < total_ingles) {
        printf("O texto digitado deve ser português.\n");
    } else {
        printf("Impossivel de determinar\n");
    }


    return 0;
}