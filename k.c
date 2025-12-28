#include<stdio.h>

int main(int argc, char *argv[]) {

	// Falls keine Argumente gegeben werden
	if (argc <= 1) {
		printf("    \033[31;1mError:\033[0m Keine Vorgabe vorhanden!\n");
		return 0;
	}

	FILE *file;
	
	// Jedes Argument beachten
	for (int i = 1; i < argc; i++) {
		file = fopen(argv[i], "r");
		
		// Wenn die Datei existiert
		if (file != NULL) {
			// String to store the info
			char charString[1000];
			
			// Jede Zeile in der Datei ausgeben
			while (fgets(charString, 1000, file)) {
				printf("%s", charString);
			}
		} else {
			// Fehler ausgeben wenn die Datei nicht gefunden wurde
			printf("    \033[31;1mError:\033[33;1m '%s'\033[0m Datei wurde nicht gefunden!\n", argv[i]);
		}
	}
}
