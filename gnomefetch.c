/* gnomefetch - a joke fetch program that I made because I was *very* bored.
 *
 * USAGE
 * gnomefetch [args]
 * 	-g	Use GNOME logo instead of actual gnome. Default if GNOME is detected as currently used DE.
 * 	-n	Use an actual gnome. Used by default
 * 	-h	Show help text
 * 	-v	Show version
 */

#define VERSION 1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

//Boolean type definition because why not
typedef enum {false, true} bool;

//Colors for output
#define COL_BLACK "\e[30m"
#define COL_RED "\e[31m"
#define COL_GREEN "\e[32m"
#define COL_YELLOW "\e[33m"
#define COL_BLUE "\e[34m"
#define COL_PURPLE "\e[35m"
#define COL_CYAN "\e[36m"
#define COL_WHITE "\e[37m"
#define COL_RESET "\e[m"

//Global variables
bool override = false;
bool forceGnome = false;
bool forceActualGnome = false;
bool usingGnome = false;

int main(int argc, char* argv[]) {
	/* PLAN:
	 * 	0. Check for correct syntax
	 * 	1. Check if using -hv
	 * 		YES - print appropriate text
	 * 			  exit
	 * 		NO - continue
	 * 	2. Check if using -gn
	 * 		YES - override=true; set force(Actual)Gnome accordingly
	 * 			HOWEVER: if both used together, error out
	 * 		NO - check if using GNOME; set usingGnome accordingly
	 * 	3. Define all variables (just the text wall shit)
	 * 	4. Print the correct text using printf or echo
	 * 	5. If usingGnome
	 * 			Check if ~/.cache/gnomefetch exists
	 * 				YES - continue
	 * 				NO - show gnome warning
	 * 	6. Exit
	 */

	if (argc > 1) {
		// Parse arguments
		for (int i=1; i<argc; ++i) {
			// Check if using -hv [plan step 1]
			if (strncmp(argv[i], "-h", 2) == 0) {
				printf("gnomefetch - a joke fetch program that I made because I was *very* bored.\n\nUSAGE: gnomefetch [args]\n"
						" -g\tUse GNOME logo instead of actual gnome. Default if GNOME is detected as currently used DE.\n -n\tUse an actual gnome. Used by default.\n"
						" -h\tShow help text\n -v\tShow version\n");
				return 1;
			} else if (strncmp(argv[i], "-v", 2) == 0) {
				printf("gnomefetch v%.1f\n", VERSION);
				return 1;
			}

			// Check if using -gn [plan step 2]
			if (strncmp(argv[i], "-g", 2) == 0) {
				override = forceGnome = true;
			}
			if (strncmp(argv[i], "-n", 2) == 0) {
				override = forceActualGnome = true;
			}

			// Check if using both -g and -n. If yes, error.
			if (forceGnome == forceActualGnome == true && override) {
				printf("Error: The arguments -g and -n cannot be used together.\n");
				return 2;
			}
		}
	}

	// Check if using GNOME as current DE
	if (!override) {
		usingGnome = !(getenv("GNOME_DESKTOP_SESSION_ID") == NULL);
	}

	char* icon[12];
	if (usingGnome || (override && forceGnome)) {
		icon[0]  = COL_BLACK"              ██"COL_RESET;
		icon[1]  = COL_BLACK"  ██  ████  ████"COL_RESET;
		icon[2]  = COL_BLACK"  ████  ██  ████"COL_RESET;
		icon[3]  = COL_BLACK"██              "COL_RESET;
		icon[4]  = COL_BLACK"████  ██████    "COL_RESET;
		icon[5]  = COL_BLACK"    ██████████  "COL_RESET;
		icon[6]  = COL_BLACK"  ████████████  "COL_RESET;
		icon[7]  = COL_BLACK"  ██████████    "COL_RESET;
		icon[8]  = COL_BLACK"  ████████      "COL_RESET;
		icon[9]  = COL_BLACK"  ████████████  "COL_RESET;
		icon[10] = COL_BLACK"    ██████████  "COL_RESET;
		icon[11] = COL_BLACK"      ██████    "COL_RESET;
	} else if (!usingGnome || (override && forceActualGnome)) {
		icon[0]  = "  "COL_RED"████████"COL_RESET"      ";
		icon[1]  = "  "COL_RED"██████████"COL_RESET"    ";
		icon[2]  = "  "COL_YELLOW"██████████"COL_RESET"    ";
		icon[3]  = "  "COL_WHITE"██"COL_YELLOW"██████"COL_WHITE"██"COL_RESET"    ";
		icon[4]  = COL_BLUE"████"COL_WHITE"████████"COL_BLUE"██"COL_RESET"  ";
		icon[5]  = COL_BLUE"██████"COL_WHITE"████"COL_BLUE"██"COL_YELLOW"████"COL_RESET;
		icon[6]  = COL_YELLOW"████"COL_BLUE"████████"COL_YELLOW"████"COL_RESET;
		icon[7]  = COL_YELLOW"████"COL_BLUE"██████"COL_RESET"      ";
		icon[8]  = "  "COL_BLUE"████████"COL_RESET"      ";
		icon[9]  = "  "COL_BLACK"████████"COL_RESET"      ";
		icon[10] = "  "COL_BLACK"████████"COL_RESET"      ";
		icon[11] = "  "COL_BLACK"██████████"COL_RESET"    ";
	}
	printf(
		"%s    Hoo hoo hoo\n"
		"%s                Ha ha ha!\n"
		"%s    \n"
		"%s    Hello me ol' chum!\n"
		"%s    \n"
		"%s    I'm gn'ot a gn'elf,\n"
		"%s    I'm gn'ot a gn'oblin,\n"
		"%s    I'm a gnome! And you've been\n"
		"%s  ___ _  _  ___  __  __ ___ ___  _ \n"
		"%s / __| \\| |/ _ \\|  \\/  | __|   \\| | \n"
		"%s| (_ | .` | (_) | |\\/| | _|| |) |_| \n"
		"%s \\___|_|\\_|\\___/|_|  |_|___|___/(_) \n"
		, icon[0], icon[1], icon[2], icon[3], icon[4], icon[5], icon[6], icon[7], icon[8], icon[9], icon[10], icon[11]
	);

	// Solution taken from Dan Lenski's answer on a StackOverflow question
	// https://stackoverflow.com/a/230581/15608830
	int fd = open("~/.cache/gnomefetch", O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
	if (fd >= 0) {
		if (usingGnome && !override) {
			printf(
				"The program has detected you are using the GNOME desktop environment.\n"
			    "As a pun, the gnome has been changed to the GNOME logo (equivalent of -g).\n"
				"Revert back to an actual gnome with the -n flag.\n"
				"This warning will not show again unless the file at ~/.cache/gnomefetch is removed.\n"
				"Happy gnoming!\n"
			);
		}
		FILE* f = fdopen(fd, "w");
		fprintf(
				f,
				"This is a dummy file created by gnomefetch that disables the GNOME logo warning.\n"
				"Remove this file to get the GNOME warning back.\n"
		);
	}

	return 0;
}
