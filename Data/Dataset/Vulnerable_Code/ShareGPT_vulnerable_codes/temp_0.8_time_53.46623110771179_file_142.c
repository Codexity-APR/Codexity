#include <avr/io.h>
#include <util/delay.h>

#define LED_PORT PORTB
#define LED_DDR DDRB
#define LED_PIN PB0

const char morseCode[26][5] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
};

void blink(char* morse) {
    for (int i = 0; morse[i] != '\0'; i++) {
        if (morse[i] == '.') {
            LED_PORT |= (1 << LED_PIN);
            _delay_ms(200);
            LED_PORT &= ~(1 << LED_PIN);
            _delay_ms(200);
        } else if (morse[i] == '-') {
            LED_PORT |= (1 << LED_PIN);
            _delay_ms(600);
            LED_PORT &= ~(1 << LED_PIN);
            _delay_ms(200);
        }
    }
}

int main() {
    LED_DDR |= (1 << LED_PIN); // set LED pin as output

    while (1) {
        char input;
        // code to get user input
        // ...

        if (input >= 'A' && input <= 'Z') {
            char* morse = morseCode[input - 'A'];
            blink(morse);
            _delay_ms(1000); // pause for 1 second
        }
    }

    return 0;
}