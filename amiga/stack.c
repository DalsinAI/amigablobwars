/* A Shell gives 4 KB of stack; libnix's startup sets this much up instead.
 * The AmiCradle Team. GPL 2 or later, like Blob Wars. */
unsigned long __stack = 512 * 1024;
static const char version[] __attribute__((used)) = "$VER: Blob Wars 2.00 Amiga (05.11.2026)";
