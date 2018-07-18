#include "InsertError.h"

InsertError::InsertError()
{
    this->ErrorStr = "Insert Error!";
    this->ErrorTitle = "Insert Error";
    this->SetString();
    this->SetTitle();
}

InsertError::~InsertError()
{
}
