#include "Content.h"
#include "Memory.h"
#include "StringExt.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

Path path_for_current_directory_file(char* name) {
  Path path;
  path.full_path = name;
  return path;
}

String string_for_current_directory_file(char* name) {
  Path path = path_for_current_directory_file(name);
  return string_for_path(path);
}

String string_for_path(Path path) {
  String string;
  int fd = open(path.full_path, O_RDONLY);
  if (0 > fd) {
  } else {
    struct stat stat_buf;
    if (0 > fstat(fd, &stat_buf)) {
      goto string_for_path_error;
    } else {
      if (0 < stat_buf.st_size && S_ISREG (stat_buf.st_mode)) {
        int file_size = stat_buf.st_size;
        int bytes_read = 0; 
        char* buf = memory_alloc(file_size + 1);
        while (bytes_read < file_size) {
          int rc = read (fd, buf + bytes_read, file_size - bytes_read);
          if (0 > rc) {
            memory_free(buf);
            goto string_for_path_error;
          } else if (0 == rc) {
            break;
          } else {
            bytes_read += rc;
          }
        }
        buf[bytes_read] = NULL_CHAR;
        close(fd);
        string.length = bytes_read;
        string.chars = buf;
      }
    }
  }
  return string;

string_for_path_error:
  close(fd);
  return string;
}
