#include <string>

#ifndef CAYDE_JENSEN_ITEM_H_
#define CAYDE_JENSEN_ITEM_H_

namespace jensen
{

    class Item
    {
    public:
        Item();
        Item(std::string *payload);
        Item(std::string &payload);
        ~Item();
        void setPayload(std::string *payload);
        void setPayload(std::string &payload);
        std::string *getPayload();

    protected:
        bool self_created_;
        std::string *payload_;
        Item *next_;
    };

} // namespace jensen

#endif // CAYDE_JENSEN_ITEM_H_