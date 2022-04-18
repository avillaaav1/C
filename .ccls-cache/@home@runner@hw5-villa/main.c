#include <stdio.h>
#include <strings.h>

int main() {

  char fileName[50],
    searchFor[50],
    flag,
    output[500];
  FILE * fp;

  printf(">> ENTER FLAG:\n");
  printf("-");
  scanf("%c", & flag);

  switch (flag) {

  case 'i':
  case 'I':
    printf(">> ENTER PATTERN:\n");
    scanf("%s", searchFor);

    printf(">> ENTER FILENAME:\n");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");

    while (!feof(fp)) {
      fgets(output, 500, fp);

      if (strstr(output, searchFor)) {
        printf("OUTPUT(s) -> %s", output);
      }
    }
    fclose(fp);

    return 0;
    break;

  case 'v':
  case 'V':
    printf(">> ENTER PATTERN:\n");
    scanf("%s", searchFor);

    printf(">> ENTER FILENAME:\n");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");

    while (!feof(fp)) {
      fgets(output, 500, fp);
      if (!strstr(output, searchFor)) {
        printf("OUTPUT(s) -> %s ", output);
      }
    }
    fclose(fp);

    return 0;
    break;

  case 'x':
  case 'X':

    printf(">> ENTER PATTERN:\n");
    scanf("%s", searchFor);

    printf(">> ENTER FILENAME:\n");
    scanf("%s", fileName);

    fp = fopen(fileName, "r");

    while (!feof(fp)) {
      fgets(output, 500, fp);

      char * p = strstr(output, searchFor);
      if ((p == output) || (p != NULL && !isalnum((unsigned char) p[-1]))) {
        p += strlen(searchFor);
        if (!isalnum((unsigned char) * p)) {
          printf("OUTPUT(s) -> %s", output);
        }
      }
    }
    return 0;

    break;

  default:
    printf("Oops! The only flags that work are -i, -v and -x.\n");
    return 0;
    break;

  }
}
