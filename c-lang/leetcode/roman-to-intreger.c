#include <stdio.h>
int value(char c) { 
    switch (c) { 
        case 'I': return 1; 
        case 'V': return 5; 
        case 'X': return 10; 
        case 'L': return 50; 
        case 'C': return 100; 
        case 'D': return 500; 
        case 'M': return 1000; 
        default: return 0;
    } 
} 
int romanToInt(const char* s) { 
    int result = 0; 
    for (int i = 0; s[i] != '\0'; i++) { 
        int current = value(s[i]); 
        int next = value(s[i + 1]); 
        if (current < next) { 
            result -= current; 
        } else { 
            result += current; 
        } 
    } 
    return result; 
}
int main() {
    // Array to store up to 99 characters + 1 null terminator
    char userInput[100]; 
    
    printf("Enter a Roman numeral (e.g., IX, MCMXCIV): ");
    
    // Reads a string from the terminal and stores it in userInput
    // %99s ensures the program won't crash if you type more than 99 characters
    scanf("%99s", userInput); 
    
    int output = romanToInt(userInput);
    
    printf("Integer value: %d\n", output);
    return 0;
}
