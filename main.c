#include <stdio.h>
#include <strings.h>

void print_array(char *cp[], int len) {
  while (len--) {
    printf("%s \n", *cp);
    cp++;
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  
  char output[500];
  FILE* fp;

  
  if (strcmp(argv[1], "-i") == 0) {

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

    fp = fopen(argv[3], "r");

    while (!feof(fp)) {
      fgets(output, 500, fp);

      char *p = strstr(output, argv[2]);
      if ((p == output) || (p != NULL && !isalnum((unsigned char) p[-1]))) {
        p += strlen(argv[2]);
        if (!isalnum((unsigned char) *p)) {
          printf("OUTPUT(s) -> %s", output);
        }
      }
    }
    return 0;

  }

}