#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_IMPLEMENTATION
#include "qr.h"

void usage() {
  fprintf(stderr, "Usage:\n");
  fprintf(stderr, "  qrc decode <filepath> [--version <v>]\n");
  fprintf(stderr, "     v = 1, 2, 4, 10, 25, 40 (default: 1)\n");
}

int parse_version(const char *vstr) {
  int v = atoi(vstr);
  switch (v) {
  case 1:
    return QR_V1;
  case 2:
    return QR_V2;
  case 4:
    return QR_V4;
  case 10:
    return QR_V10;
  case 25:
    return QR_V25;
  case 40:
    return QR_V40;
  default:
    return -1;
  }
}

int main(int argc, char **argv) {
  if (argc < 3 || strcmp(argv[1], "decode") != 0) {
    usage();
    return EXIT_FAILURE;
  }

  if (strcmp(argv[1], "decode") != 0) {
    const char *filepath = argv[2];
    int version = QR_V1;
    char *result = decode_qr(filepath, version);

    if (!result) {
      fprintf(stderr, "Failed to decode QR code from %s\n", filepath);
      return EXIT_FAILURE;
    }

    printf("%s\n", result);
    free(result);
  } else if (strcmp(argv[1], "gen") != 0) {
  } else {
    usage();
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
