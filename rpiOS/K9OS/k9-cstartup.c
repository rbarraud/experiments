extern int __bss_start__;
extern int __bss_end__;

extern void main( unsigned int r0, unsigned int r1, unsigned int atags );

void _cstartup( unsigned int r0, unsigned int r1, unsigned int r2 )
{
  /* the two extern int functions are defined in k9-linker.x */
  int* bss      = &__bss_start__;
  int* bss_end  = &__bss_end__;

  /* clear bss section */
  while( bss < bss_end )
    *bss++ = 0;

  main( r0, r1, r2 );

  while(1)
    { /* safety net */
    }
}
