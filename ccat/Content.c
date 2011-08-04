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

Content content_for_current_directory_file(char* name) {
  Path path = path_for_current_directory_file(name);
  return content_for_path(path);
}

void content_release(Content content) {
  memory_free(content.data);
}

Content content_for_path(Path path) {
  Content content;
  int fd = open(path.full_path, O_RDONLY);
  if (0 > fd) {
  } else {
    struct stat stat_buf;
    if (0 > fstat(fd, &stat_buf)) {
      goto content_for_path_error;
    } else {
      if (0 < stat_buf.st_size && S_ISREG (stat_buf.st_mode)) {
        int file_size = stat_buf.st_size;
        int bytes_read = 0; 
        char* buf = memory_alloc(file_size + 1);
        while (bytes_read < file_size) {
          int rc = read (fd, buf + bytes_read, file_size - bytes_read);
          if (0 > rc) {
            memory_free(buf);
            goto content_for_path_error;
          } else if (0 == rc) {
            break;
          } else {
            bytes_read += rc;
          }
        }
        buf[bytes_read] = NULL_CHAR;
        close(fd);
        content.length = bytes_read;
        content.data = buf;
      }
    }
  }
  return content;

content_for_path_error:
  close(fd);
  return content;
}
