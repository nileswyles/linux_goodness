#include <stdio.h>
#include <unistd.h>


const static char * path = "/dev/input/by-path/pci-0000:00:1e.3-platform-pxa2xx-spi.5-cs-00-event-kbd";

int main(void) {
  char buf[100] = {};

  while (1) {
    int bytes_read = read(path, buf, 1);
    if (bytes_read > 0) {
      printf("loopy\n");
      for (int i = 0; i < bytes_read; i++) {
        printf("%x ", buf[i]);
      }
      printf("loopn\n");
    }
  }
  return 0;
}
