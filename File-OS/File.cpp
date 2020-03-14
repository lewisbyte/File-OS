#include "File.h"

File::File() {

}

File::File(string _name, FileType _type, FAT &fat) {
    this->name = _name;
    this->type = _type;
    this->size = 0;
    this->index[size] = fat.getBlock();//
}

File::~File() {

}

void File::Serialization() {

}

void File::Deserialization() {

}


bool File::addContent(const char *content, string blocks[], FAT &fat) {
    int len = strlen(content);
    for (int i = 0; i < len; i++) {
        if (blocks[index[size]].length() <= N) {
            blocks[index[size]] += content[i];
        } else {
            index[++size] = fat.getBlock();
            blocks[index[size]] += content[i];
        }
    }
    this->modifyDate = this->getTime();
    return false;
}

void File::release(FAT &fat, string *blocks) {
    for (int i = 0; i < this->size; i++) {
        fat.addBlock(index[i], blocks);
    }
}

string File::toString(string blocks[]) {
    string s;
    for (int i = 0; i <= this->size; i++) {
        s += blocks[index[i]];
    }
    return s;
}


