#include "DeleteError.h"

DeleteError::DeleteError()
{
    this->ErrorStr = "Delete Error!";
    this->ErrorTitle = "Delete Error";
    this->SetString();
    this->SetTitle();
}

DeleteError::~DeleteError()
{

}
