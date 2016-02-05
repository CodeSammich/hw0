#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  /* Creates ppm file with random rgb coordinates using x and y coordinates */
  int file = open( "hw0_coolio.ppm", O_CREAT | O_WRONLY, 0777);
  int xres = 500;
  int yres = 500;
  int max_color = 255;
  
  //header
  char buffer[256];
  sprintf( buffer, "P3 %i %i %i", xres, yres, max_color );
  write( file, buffer, strlen(buffer) );

  //rgb body
  int x, y, red, green, blue;

  for(x = 0; x < xres; x++ ) {
    for(y = 0; y < yres; y++ ) {
      red = x % max_color;
      green = y % max_color;
      blue = (x * y) % max_color;

      sprintf( buffer, " %d %d %d ", red, green, blue);
      printf("%s\n", buffer);
      write( file, buffer, strlen(buffer));
    }
  }

  close( file );
  
  return 0;
}
