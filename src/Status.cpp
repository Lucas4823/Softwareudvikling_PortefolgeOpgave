#include "Status.h"

Status::Status(int varighed)
{
    this->varighed = varighed;
}

Status::~Status()
{
}

bool Status::erFaerdig() const
{
    return varighed <= 0;
}