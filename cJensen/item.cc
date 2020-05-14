#include "item.h"
#include <string>
#include <iostream>

jensen::Item::Item()
    : self_created_(true)
{
    payload_ = new std::string("");
}

jensen::Item::Item(std::string *payload)
    : self_created_(false), payload_(payload), next_(nullptr)
{
}

jensen::Item::Item(std::string &payload)
    : self_created_(true), next_(nullptr)
{
    payload_ = new std::string(payload);
}

jensen::Item::~Item()
{
    if (self_created_)
    {
        delete payload_;
    }
}

void jensen::Item::setPayload(std::string *payload)
{
    if (self_created_)
    {
        delete payload_;
    }
    self_created_ = false;
    payload_ = payload;
}

void jensen::Item::setPayload(std::string &payload)
{
    if (self_created_)
    {
        delete payload_;
    }
    self_created_ = true;
    payload_ = new std::string(payload);
}

std::string *jensen::Item::getPayload()
{
    return payload_;
}