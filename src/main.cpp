#include "Spil.h"
#include <ctime>

int main()
{
    srand(time(nullptr)); // Initialiser tilfældighedsgeneratoren

    Spil spil;

    spil.start();

    return 0;
}