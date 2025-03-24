#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT 256
#define HISTORY_SIZE 5
#define MAX_REMINDERS 5

char history[HISTORY_SIZE][MAX_INPUT];
char reminders[MAX_REMINDERS][MAX_INPUT];
int history_count = 0;
int reminder_count = 0;

void get_time() {
    time_t t;
    time(&t);
    printf("Grok: The current time is %s", ctime(&t));
}

void tell_joke() {
    const char *jokes[] = {
        "Why don’t skeletons fight each other? They don’t have the guts.",
        "What do you call fake spaghetti? An impasta!",
        "Why don’t some fish play piano? Because you can’t tuna fish!",
        "Why did the scarecrow win an award? Because he was outstanding in his field!",
        "I told my wife she should embrace her mistakes. She gave me a hug.",
        "What do you get when you cross a snowman and a vampire? Frostbite!",
        "Why did the math book look sad? It had too many problems.",
        "How does a penguin build its house? Igloos it together!",
        "Why couldn’t the bicycle stand up by itself? It was two-tired!",
        "What did one wall say to the other wall? I'll meet you at the corner!"
    };
    int random_index = rand() % 10;
    printf("Grok: %s\n", jokes[random_index]);
}

void tell_fact() {
    const char *facts[] = {
        "Honey never spoils.",
        "Octopuses have three hearts.",
        "Bananas are berries, but strawberries aren't.",
        "A day on Venus is longer than a year on Venus.",
        "Water can boil and freeze at the same time.",
        "A single cloud can weigh over a million pounds.",
        "Your heartbeat syncs with the music you listen to.",
        "There are more trees on Earth than stars in the Milky Way.",
        "A shrimp's heart is in its head.",
        "Butterflies can taste with their feet."
    };
    int random_index = rand() % 10;
    printf("Grok: %s\n", facts[random_index]);
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Grok: Unable to open file %s for reading.\n", filename);
        return;
    }
    char line[MAX_INPUT];
    printf("Grok: Reading file %s:\n", filename);
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Grok: Unable to open file %s for writing.\n", filename);
        return;
    }
    fprintf(file, "%s\n", content);
    fclose(file);
    printf("Grok: File %s has been written successfully.\n", filename);
}

void append_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Grok: Unable to open file %s for appending.\n", filename);
        return;
    }
    fprintf(file, "%s\n", content);
    fclose(file);
    printf("Grok: Content appended to file %s successfully.\n", filename);
}

void respond_to_greeting() {
    const char *greetings[] = {
        "Hey there! How’s your day going?",
        "Hello! What can I do for you today?",
        "Hi! Need a joke, a fact, or just a chat?",
        "Greetings, human! How may I assist you?",
        "Yo! What’s up?",
        "Howdy! Ready to have some fun?",
        "Hi! I’m here and ready to chat!",
        "Oh, hey! Nice to see you again!",
        "Hey! Looking for something interesting today?",
        "Hello! What’s on your mind?"
    };
    int random_index = rand() % 10;
    printf("Grok: %s\n", greetings[random_index]);
}

int main() {
    char input[MAX_INPUT];
    srand(time(NULL)); // Initialize random seed
    printf("Grok: Hello! Type 'help' to see what I can do, or 'bye' to exit.\n");

    while (1) {
        printf("You: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strstr(input, "hello") || strstr(input, "hi") || strstr(input, "hey")) {
            respond_to_greeting();
        } else if (strstr(input, "joke")) {
            tell_joke();
        } else if (strstr(input, "fact")) {
            tell_fact();
        } else if (strstr(input, "read")) {
            char filename[MAX_INPUT];
            sscanf(input, "read %s", filename);
            read_file(filename);
        } else if (strstr(input, "write")) {
            char filename[MAX_INPUT], content[MAX_INPUT];
            sscanf(input, "write %s %[^]", filename, content);
            write_file(filename, content);
        } else if (strstr(input, "append")) {
            char filename[MAX_INPUT], content[MAX_INPUT];
            sscanf(input, "append %s %[^]", filename, content);
            append_file(filename, content);
        } else if (strstr(input, "help")) {
            printf("Grok: Here are some things I can do:\n");
            printf("- Say hello: 'hello', 'hi', 'hey'\n");
            printf("- Tell a joke: 'joke'\n");
            printf("- Share a fact: 'fact'\n");
            printf("- Tell the current time: 'time'\n");
            printf("- Read a file: 'read <filename>'\n");
            printf("- Write to a file: 'write <filename> \"content\"'\n");
            printf("- Append to a file: 'append <filename> \"content\"'\n");
            printf("- Exit: 'bye'\n");
        } else if (strstr(input, "bye")) {
            printf("Grok: Goodbye! Have a great day!\n");
            break;
        } else {
            printf("Grok: I'm not sure how to respond to that. Can you ask something else?\n");
        }
    }
    return 0;
}
