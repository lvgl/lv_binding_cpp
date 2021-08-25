/*
 * operators.cpp
 *
 *      Author: fstuffdev
 */

#ifdef CONFIG_OS_FREERTOS

#include <malloc.h>
#include <new>

#include <FreeRTOS.h>

extern "C" void* malloc(size_t size) {

    void* ptr = NULL;
    if(size > 0)
        ptr = pvPortMalloc(size);
    return ptr;
}

extern "C" void free(void* ptr) {
    if(ptr)
    	pvPortFree(ptr);
}

void * operator new( size_t size ){
	return pvPortMalloc( size );
}

void * operator new[]( size_t size ){
	return pvPortMalloc(size);
}

void operator delete( void * ptr ){
	vPortFree ( ptr );
}

void operator delete[]( void * ptr ){
	vPortFree ( ptr );
}

#endif

