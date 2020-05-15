#include <queue>
#include <stack>
#include <map>
#include <string>

#include "queue.h"

jensen::Queue::Queue() : size_(0)
{
    queues_ = new jensen::queueTracker_t();
    stacks_ = new jensen::stackTracker_t();
    loadQueue();
}

bool jensen::Queue::loadQueue(std::string &queue) {
    bool createdQueue = false;
    if (queues_->find(queue) == queues_->end()) {
        (*queues_)[queue] = new std::queue<std::string>();
        createdQueue = true;
    }
    if (stacks_->find(queue) == stacks_->end()) {
        (*stacks_)[queue] = new std::stack<std::string>();
        createdQueue = true;
    }
    return createdQueue;
}

jensen::Queue::~Queue()
{
    for (auto element : *queues_)
    {
        delete element.second;
    }
    delete queues_;
}

void jensen::Queue::push(std::string &payload, std::string &queue)
{
    loadQueue(queue);
    (*queues_)[queue]->push(payload);
    size_++;
}

void jensen::Queue::pushFront(std::string &payload, std::string &queue)
{
    loadQueue(queue);
    (*stacks_)[queue]->push(payload);
    size_++;
}

bool jensen::Queue::queueExists(std::string &queue) {
    return (queues_->find(queue) != queues_->end()) && (stacks_->find(queue) == stacks_->end());
}

std::string &jensen::Queue::pop(std::string &queue)
{
    if (!queueExists(queue)) {
        if (!(*stacks_)[queue]->empty()) {
            std::string &value = (*stacks_)[queue]->top();
            (*stacks_)[queue]->pop();
            size_--;
            return value;
        } else if (!(*queues_)[queue]->empty()) {
            std::string &value = (*queues_)[queue]->front();
            (*queues_)[queue]->pop();
            size_--;
            return value;
        }
    }
    throw std::exception();
}

size_t jensen::Queue::size() {
    return size_;
}
