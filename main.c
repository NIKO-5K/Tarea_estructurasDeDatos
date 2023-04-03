#include <stdio.h>
#include <string.h>

void morseToText(char* morse, int messageNum) {
    const char *morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; // Tabla de código Morse

    char letter[5]; // El código Morse de una letra no puede tener más de 4 caracteres
    int letterIndex = 0;

    printf("Message #%d:", messageNum);

    for (int i = 0; i <= strlen(morse); i++) {
        if (morse[i] == ' ' || morse[i] == '\0') {
            letter[letterIndex] = '\0';
            letterIndex = 0;

            int j = 0;
            while (j < 26 && strcmp(letter, morseCode[j]) != 0) {
                j++;
            }
            if (j < 26) {
                printf("%c", j + 'A');
            }
        } else {
            letter[letterIndex++] = morse[i];
        }
    }
    printf("\n");
}

int main() {
    int numMessages;
    char input[100][100];

    // Pedir al usuario que ingrese el número de mensajes
    printf("Ingrese el numero de mensajes: ");
    scanf("%d", &numMessages);
    getchar(); // Consumir el carácter de salto de línea que queda en el buffer después de scanf

    // Pedir al usuario que ingrese todos los mensajes
    for (int i = 0; i < numMessages; i++) {
        printf("Ingrese el codigo Morse #%d: ", i + 1);
        fgets(input[i], sizeof(input[i]), stdin);
        input[i][strcspn(input[i], "\n")] = 0;
    }

    // Imprimir los mensajes traducidos
    for (int i = 0; i < numMessages; i++) {
        morseToText(input[i], i + 1);
    }

    return 0;
}
