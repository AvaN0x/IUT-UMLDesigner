#ifndef DEF_IUT_CPP_QUEUE_HPP
#define DEF_IUT_CPP_QUEUE_HPP

#include <cstdlib>
#include <ostream>

#include "List.hpp"

namespace iut_cpp
{
    /**
     * @brief Queue class.
     */
    template <typename Type>
    class Queue : private List<Type>
    {

    public:
        /**
         * @brief  Constructor
         */
        Queue();

        /**
         * @brief  Adds a new item at the end
         * @param  item: value to push
         */
        void push(Type const &item);

        /**
         * @brief  Returns the size of the queue
         * @return the size of the queue
         */
        int size() const;

        /**
         * @brief  Removes the first item of the queue, and returns it
         */
        Type pop();

        /**
         * @brief  Returns the first item of the queue, without removing it
         */
        Type peek() const;

        /**
         * @brief  Write the queue to the stream
         * @param  stream: stream to write on
         */
        using List<Type>::print;
    };

    template <typename Type>
    Queue<Type>::Queue() : List<Type>()
    {
        //constructor
    }

    template <typename Type>
    void Queue<Type>::push(Type const &item)
    {
        this->push_last(item);
    }

    template <typename Type>
    int Queue<Type>::size() const
    {
        return this->size();
    }

    template <typename Type>
    Type Queue<Type>::pop()
    {
        Type *value = &(*this->begin());
        this->pop_front();
        return *value;
    }

    template <typename Type>
    Type Queue<Type>::peek() const
    {
        return *this->begin();
    }

    template <typename Type>
    std::ostream &operator<<(std::ostream &stream, Queue<Type> const &queue)
    {
        queue.print(stream);
        return stream;
    }

} // namespace iut_cpp

#endif
