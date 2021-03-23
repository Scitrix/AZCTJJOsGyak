#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys.stat.h>
#include <fcnt1.h>

#define FILE "AZCTJJ.txt"

size_t write (int, void*, size_t);
size_t read (int, void*, size_t);

off_t lseek(int, off_t, int);

int open(const char *, int, mode_t);
int close(int);

int main()
{
    int openFile = open(FILE, O_RDWR);
    if(openFile == -1)
    {
        printf("Nem sikerult megnyitni a(z) \"%s\" fajlt!\n", FILE);
        return 1;
    } else printf("Megnyitottam a(z) \"%s\" fajlt!\n", FILE);

    char content[64];
    int readText = read(openFile, content, sizeof(content));

    content[readText] = '\0';
    printf("beolvasott tartalom: \"%s\" osszesen \"%i\" byte.\n", content, readText);

    lseek(openFile, 0, SEEK_SET);
    printf("A fajl elejere allitottuk a mutatot\n");

    char text[] = "Rendszerhivassal iras fajlba";
    int wrote = write(openFile, text, sizeof(text));
    printf("A fajlba irtuk a(z) \"%s\" szoveget. osszesen \"%i\" byte.\n", text, wrote);
    close(openFile);
    return 0;
}