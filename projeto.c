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

    //char texto[1024];

    //printf("Digite uma frase para verificar o idioma: ");
    //fgets(texto, sizeof(texto), stdin);

    char texto[1024] = "  This amazing accomplishment is just one step on your journey. Your ability to relentlessly search for solutions to problems and find innovative ways to improve the world is the key to this success and many to come";

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
    

    printf("\nFrequência de cada letra no texto digitado:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %.0f\n", textolido[i].letra, textolido[i].chance);
    }


    //agora e necessario percorrer o textolido e comparar a diferenca de frequencia total em ingles e portugues

    float total_ingles = 0.0f;
    float total_portugues = 0.0f;
    for (int i = 0; i < 26; i++) {
        total_ingles += fabs(textolido[i].chance - ingles[i].chance) ;
        total_portugues += fabs(textolido[i].chance - portugues[i].chance) ;
    }
    printf("\nTotal de diferença em relação ao inglês: %.2f\n", total_ingles);
    printf("Total de diferença em relação ao português: %.2f\n", total_portugues);
    if (total_ingles < total_portugues) {
        printf("O texto digitado é mais semelhante ao inglês.\n");
    } else if (total_portugues < total_ingles) {
        printf("O texto digitado é mais semelhante ao português.\n");
    } else {
        printf("O texto digitado tem frequências semelhantes em inglês e português.\n");
    }


    return 0;
}