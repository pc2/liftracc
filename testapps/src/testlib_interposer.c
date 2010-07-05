
#include <dlfcn.h>
#include <stdio.h>

unsigned long long fib_rec(unsigned long long n) {
    
    void *handle = 0;
    char *error = 0;

    handle = dlopen("libtestlib.so", RTLD_LAZY);

    if (!handle)
        printf("%s\n", dlerror());
    else
        ; //printf("libtestlib.so loaded.\n");

    unsigned long long (*fib_iter)(unsigned long long)=0;
    *(void **) (&fib_iter) = dlsym(handle, "fib_iter");

    if ((error = dlerror()) != 0)  {
        printf("dlerror %s\n", error);
    }

   
    unsigned long long ret = fib_iter(n);

    //printf("fib_iter(%d) returned %llu\n", n, ret);
    
    return ret;
}

