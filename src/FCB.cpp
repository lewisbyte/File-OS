#pragma once

#include "FCB.H"

FCB::FCB() {
    this->access = Write;
    this->modifyDate = getTime();
    this->size = N;
}

FCB::~FCB() {

}

string FCB::getTime() {
    time_t t = time(0);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y/%m/%d %X", localtime(&t));
    return tmp;
}