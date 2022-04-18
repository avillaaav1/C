#include <stdio.h>
#include <strings.h>

void print_array(char * cp[], int len) {
  while (len--) {
    printf("%s \n", * cp);
    cp++;
  }
  printf("\n");
}

int main(int argc, char * argv[]) {

  char fileName[50],
    searchFor[50],
    flag,
    output[500];
  FILE * fp;

  // output argv
  //printf("-> ./main -> '%s'\n",argv[0]);
  //printf("-> flag -> '%s'\n",argv[1]);
  //printf("-> pattern -> '%s'\n",argv[2]);
  //printf("-> file -> '%s'\n",argv[3]);

  if (strcmp(argv[1], "-i") == 0) {
    printf("SUCCESS #1\n");

    fp = fopen(argv[3], "r");

    while (!feof(fp)) {
      fgets(output, 500, fp);

      if (strstr(output, argv[2])) {
        printf("OUTPUT(s) -> %s", output);
      }
    }
    fclose(fp);

    return 0;

  }

  if (strcmp(argv[1], "-v") == 0) {
    printf("SUCCESS #2\n");

    fp = fopen(argv[3], "r");

    while (!feof(fp)) {
      fgets(output, 500, fp);

      if (!strstr(output, argv[2])) {
        printf("OUTPUT(s) -> %s ", output);
      }
    }
    fclose(fp);
    printf("OUTPUT(s) -> %s ", output);
    return 0;
  }

  if (strcmp(argv[1], "-x") == 0) {
    printf("SUCCESS #3\n");

    fp = fopen(argv[3], "r");

    while (!feof(fp)) {
      fgets(output, 500, fp);

      char * p = strstr(output, argv[2]);
      if ((p == output) || (p != NULL && !isalnum((unsigned char) p[-1]))) {
        p += strlen(argv[2]);
        if (!isalnum((unsigned char) * p)) {
          printf("OUTPUT(s) -> %s", output);
        }
      }
    }
    return 0;

  }

}