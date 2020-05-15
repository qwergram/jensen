#include <string>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>

#ifndef CAYDE_JENSEN_QUEUE_H_
#define CAYDE_JENSEN_QUEUE_H_

namespace jensen
{

    std::string defaultQueue = "main";
    typedef std::map<std::string, std::queue<std::string> *> queueTracker_t;
    typedef std::map<std::string, std::stack<std::string> *> stackTracker_t;

    class Queue
    {
    public:
        Queue();
        ~Queue();

        void push(std::string &payload, std::string &queue = defaultQueue);
        void pushFront(std::string &payload, std::string &queue = defaultQueue);

        std::string &pop(std::string &queue = defaultQueue);

        void clear(std::string &queue = defaultQueue);
        void clearAll();

        size_t size();
        std::map<std::string, size_t> sizes();

    protected:
        bool loadQueue(std::string &queue = defaultQueue);
        bool queueExists(std::string &queue = defaultQueue);

    private:
        queueTracker_t *queues_;
        stackTracker_t *stacks_;
        size_t size_;
    };

} // namespace jensen

#endif // CAYDE_JENSEN_QUEUE_H_