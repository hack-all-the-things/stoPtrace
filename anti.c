#define _GNU_SOURCE

#include <dlfcn.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

static long (*old_ptrace)(void *request, pid_t pid, void *addr, void *data);

long ptrace(void *request, pid_t pid, void *addr, void *data) {
  if(access("/etc/allow-debug", 0) != -1) {
    // Debugging is allowed.
    if(!old_ptrace) old_ptrace = dlsym(RTLD_NEXT, "ptrace");
    old_ptrace(request, pid, addr, data);
  } else {
    // Debugging is not allowed.
    printf("Debugging has been disabled globally by the system administrator!\n");
    exit(6);
  }
}
