typedef struct Path {
  char* full_path;
} Path;

typedef struct Line {
  char* chars;
} Line;

typedef struct Content {
  int length;
  char* data;
} Content;

Path path_for_current_directory_file(char* name) ;
Content load_content_for_current_directory_file(char* name) ;
Content load_content_for_path(Path path) ;
void content_release(Content content) ;
