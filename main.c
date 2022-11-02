#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char str[24];
    int strl;
    int index;
    struct node *next;
};

struct node *initList(char *str) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    strcpy(link->str, str);
    link->index = 0;
    link->next = NULL;
    return link;
}

struct node *appendNode(char *str, struct node *end) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    strcpy(link->str, str);
    link->strl = strlen(str);
    link->index = end->index + 1;
    end->next = link;
    link->next = NULL;
    return link;
}

void printList(struct node *start) {
    struct node *link = start;
    while (link->next != NULL) {
        printf("%s, %d, %d\n", link->str, link->strl, link->index);
        link = link->next;
    }
}

unsigned int countList(struct node *start) {
    struct node *link = start;
    unsigned int rnum = 0;
    while (link->next != NULL) {
        rnum++;
        link = link->next;
    }
    return rnum;
}

int main() {
	puts(" _______   ___      ___ ___  ___               ___  ___  ________  ________   ________  _____ ______   ________  ________     \n"
"|\\  ___ \\ |\\  \\    /  /|\\  \\|\\  \\             |\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\    \n"
"\\ \\   __/|\\ \\  \\  /  / | \\  \\ \\  \\            \\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n"
" \\ \\  \\_|/_\\ \\  \\/  / / \\ \\  \\ \\  \\            \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n"
"  \\ \\  \\_|\\ \\ \\    / /   \\ \\  \\ \\  \\____        \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n"
"   \\ \\_______\\ \\__/ /     \\ \\__\\ \\_______\\       \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\\n"
"    \\|_______|\\|__|/       \\|__|\\|_______|        \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__|\n\n\n1. Start game\n2. Exit");

    FILE* dict = fopen("corncob_lowercase.txt", "r");
    if (dict==NULL) {
        printf("dictionary not found");
        return -1;
    }
    struct node *head = initList("");
    struct node *start = head;
    char str[24];
    for (int i = 0; fgets(str, sizeof(str), dict); i++) {
        str[strcspn(str, "\n")] = 0;
        head = appendNode(str, head);
    }
    printList(start);
    printf("(%d)\n", countList(start));

}

/*
int mayin() {
    puts("loading....");
    char strs[58110][24];
    char tempstrs[58110][24];
    unsigned char strl[58110];
	puts(" _______   ___      ___ ___  ___               ___  ___  ________  ________   ________  _____ ______   ________  ________     \n"
"|\\  ___ \\ |\\  \\    /  /|\\  \\|\\  \\             |\\  \\|\\  \\|\\   __  \\|\\   ___  \\|\\   ____\\|\\   _ \\  _   \\|\\   __  \\|\\   ___  \\    \n"
"\\ \\   __/|\\ \\  \\  /  / | \\  \\ \\  \\            \\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n"
" \\ \\  \\_|/_\\ \\  \\/  / / \\ \\  \\ \\  \\            \\ \\   __  \\ \\   __  \\ \\  \\\\ \\  \\ \\  \\  __\\ \\  \\\\|__| \\  \\ \\   __  \\ \\  \\\\ \\  \\  \n"
"  \\ \\  \\_|\\ \\ \\    / /   \\ \\  \\ \\  \\____        \\ \\  \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \n"
"   \\ \\_______\\ \\__/ /     \\ \\__\\ \\_______\\       \\ \\__\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\\n"
"    \\|_______|\\|__|/       \\|__|\\|_______|        \\|__|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|__|\\|__|\\|__| \\|__|\n\n\n1. Start game\n2. Exit");
	bool play = false;
    while (true) {
		char c = getchar();
		if (c == '1') {
            play = true;
            break;
		} else if (c == '2') {
			break;
		}
	}
    if (play) {
        printf("How long should our word be? ");
        char userselect[10];
        while (getchar() != '\n') {
        }
        if (fgets(userselect, 10, stdin) == NULL) {
            printf("bad input\n");
        }
        int len = atoi(userselect);
        FILE* dict = fopen("corncob_lowercase.txt", "r");
        if (dict==NULL) {
            printf("dictionary not found");
            return -1;
        }
        char str[24];
        for (int i = 0; fgets(str, sizeof(str), dict); i++) {
            str[strcspn(str, "\n")] = 0;
            strl[i] = strcspn(str, " ");
            if (strl[i] == len) {
                strcpy(strs[i], str);
            } else {
                strcpy(strs[i], "");
            }
        }
        fclose(dict);
        char word[24];
        while (true) {
            char guess = getchar(); getchar();
            printf("%c", guess);
            for (int i = 0; i < 58110; i++) {
                strcpy(tempstrs[i], strs[i]);
                int count = 0;
                if (strcmp(strs[i], "") != 0) {
                    count += 1;
                    for (int j = 0; j < 24; j++) {
                        if (guess == strs[i][j]) {
                            strcpy(strs[i], "");
                        }
                    }
                }
            }
            int resum = 0;
            for (int i = 0; i < 58110; i++) {
                if (strcmp(strs[i], "") != 0) {
                    resum += 1;
                }
            }
            if (resum == 0) {
                for (int i = 0; i < 58110; i++) {
                    strcpy(strs[i], tempstrs[i]);
                }
                
            }
            for (int i = 0; i < 58110; i++) {
                if (strcmp(strs[i], "") != 0) {
                    printf("%s, %hhu\n", strs[i], strl[i]);
                }
            }
        }
    }
    return 0;
}
*/
