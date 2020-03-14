#pragma once

#include "FCB.h"
#include "File.h"
#include<vector>
#include<string>


class Folder : public FCB {
public:
    vector<FCB *> child;

    void addChild(FCB *file);

    Folder(string _name, FileType _type);

    bool count(FCB *file);

    FCB *find(FCB *file);

    bool erase(FCB *file);

    int size();

private:
    int childSize;
};
