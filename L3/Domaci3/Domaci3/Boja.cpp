#include "Boja.h"

bool Boja::operator==(const Boja& db)
{
    return (this->r == db.r && this->g == db.g && this->b == db.b);
}

Boja Boja::operator+(Boja& db)
{
    int red = (r + db.r);
    int green = (g + db.g);
    int blue = (b + db.b);
    return Boja(red,green,blue);
}
