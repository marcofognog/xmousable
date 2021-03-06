#include "xmousable.h"

int display_alpha_layer = 1;
int display_grid = 1;
int display_letters = 1;
int cursor_step = 10;

#define PACKAGE "xmousable"
#define VERSION "0.1.0"

void show_usage(void) {
   fprintf(stdout,
           "Usage : " PACKAGE " [OPTIONS]\n"
           "  -h, --help                Display this help and exit.\n"
           "  -g, --no-grid             Do not display the grid.\n"
           "  -c, --no-cover            Do not display the transparent cover.\n"
           "  -l, --no-letters          Do not display the letters corresponding to each selectable area.\n"
           "  -s, --cursor-step         Set the unit, in pixels, of the length that the mouse pointer moves in each step.\n"
           "  Example:\n"
           "  " PACKAGE " -s 10 -a -l\n"
           "Once activated, the following keys map to mouse functions:\n"
           "  Space - click with left button\n"
           "  Enter - click with scroll button\n"
           "  Escape - leave without clicking\n"
           "This program is free software see the file MIT-LICENSE for licensing info.\n"
           "Copyright Marco Antonio F. Nogueira 2018\n"
           );
   exit(0);
}

void show_version(void) {
   printf(PACKAGE " version " VERSION "\n");
   exit(0);
}

void parse_options(int argc, char *argv[]){
  int c;
  while(1){
    static char stropts[] = "hvagls:";
    static struct option long_options[] =
      {
        {"no-grid",  no_argument, 0, 'g'},
        {"no-alpha",  no_argument, 0, 'a'},
        {"no-letters",  no_argument, 0, 'l'},
        {"cursor-step",    required_argument, 0, 's'},
        {"help",    no_argument, 0, 'h'},
        {"version",    no_argument, 0, 'v'},
        {0, 0, 0, 0}
      };
    int option_index = 0;

    c = getopt_long (argc, argv, stropts,
                     long_options, &option_index);
    switch (c) {
    case 'a':
      display_alpha_layer = 0;
      break;
    case 'g':
      display_grid = 0;
      break;
    case 'l':
      display_letters = 0;
      break;
    case 's':
      cursor_step = atoi(optarg);
      break;
    case 'h':
      show_usage();
    case 'v':
      show_version();
    }

    if (c == -1)
      break;
  }
}
