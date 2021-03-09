#ifndef DEF_IUT_CPP_STACK_HPP
#define DEF_IUT_CPP_STACK_HPP

#include <cstdlib>
#include <ostream>
#include "List.hpp"

namespace iut_cpp
{
    /**
     * @brief Stack Class.
     */
    template <typename Type>
    class Stack : private List<Type>
    {

    public:
        /**
         * @brief  Constructor
         */
        Stack();

        /**
         * @brief  Adds a new item to the top of the stack
         * @param  item: value to push
         */
        void push(Type const &item);

        /**
         * @brief  Returns the size of the stack
         * @return the size of the stack 
         */
        int size() const;

        /**
         * @brief  Removes the first item of the stack, and returns it
         */
        Type pop();

        /**
         * @brief  Returns the first item of the stack, without removing it
         */
        Type peek() const;

        /**
         * @brief  Write the stack to the stream
         * @param  stream: stream to write on
         */
        using List<Type>::print;
    };

    template <typename Type>
    Stack<Type>::Stack() : List<Type>()
    {
        //constructor
    }

    template <typename Type>
    void Stack<Type>::push(Type const &item)
    {
        this->push_last(item);
    }

    template <typename Type>
    int Stack<Type>::size() const
    {
        return this->size();
    }

    template <typename Type>
    Type Stack<Type>::pop()
    {
        Type *value = &(*this->end());
        this->pop_back();
        return *value;
    }

    template <typename Type>
    Type Stack<Type>::peek() const
    {
        return *this->end();
    }

    template <typename Type>
    std::ostream &operator<<(std::ostream &stream, Stack<Type> const &stack)
    {
        stack.print(stream);
        return stream;
    }

} // namespace iut_cpp

#endif
