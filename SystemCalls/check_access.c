//Author: Sreeram Mutya
//Purpose: Assignment#1 - System Calls
//Date: 1/15/2026
//1. Use access system call to check the read & write access for the file (Refer check_access.c)
//2. Use access system call to check the executable permission for the file (Modify check_access.c)
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *path = argv[1];
  int rval;

  // Added:  Check file existence,
  // for file exists, the return value from access function is F_OK
  rval = access(path, F_OK);
  if (rval == 0)
    printf("%s exists\n", path);
  else {
    if (errno == ENOENT)
      printf("%s does not exist\n", path);
    else if (errno == EACCES)
      printf("%s is not accessible\n", path);
    return 0;
  }
  // Added:  Check read access
   rval = access(path, R_OK);
   if (rval == 0)
    printf("%s is readable\n", path);
  else
    printf("%s is not readable (access denied)\n", path);
  // Added:  Check write access
  rval = access(path, W_OK);
  if (rval == 0)
    printf("%s is writable\n", path);
  else if (errno == EACCES)
    printf("%s is not writable (access denied)\n", path);
  else if (errno == EROFS)
    printf("%s is not writable (read-only filesystem)\n", path);
  // Added:  Check executable access
  rval = access(path, X_OK);
  if (rval == 0)
    printf("%s is Executable\n", path);
  else if (errno == EACCES)
    printf("%s is not Executable (access denied)\n", path);
  return 0;
}
