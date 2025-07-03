#ifndef QR_H
#define QR_H

enum { QR_V1, QR_V2, QR_V4, QR_V10, QR_V25, QR_V40 };

char *decode_qr(const char *filename, int version);

#endif // !QR_H

#ifdef QR_IMPLEMENTATION

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>
#include <stdlib.h>

char *decode_qr(const char *filename, int version) {
  int width, height, channels;
  unsigned char *img = stbi_load(filename, &width, &height, &channels, 0);
  if (!img) {
    fprintf(stderr, "Failed to load image: %s\n", filename);
    return NULL;
  }

  stbi_image_free(img);
  return strdup("decoded-content");
}

#endif // QR_IMPLEMENTATION
