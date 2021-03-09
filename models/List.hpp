#ifndef DEF_IUT_CPP_LIST_HPP
#define DEF_IUT_CPP_LIST_HPP

#include <cstdlib>
#include <stdexcept>
#include <ostream>

namespace iut_cpp
{
    template <typename Type>
    class Iterator;

    /**
     * @brief  Base list class.
     */
    template <typename Type>
    class List
    {
        friend Iterator<Type>;

    protected:
        /**
         * @brief  A single node of the list
         */
        template <typename ValueType>
        struct Node
        {
            ValueType _item;
            Node<ValueType> *_previous;
            Node<ValueType> *_next;
            Node()
            {
            }
        };
        typedef Node<Type> node_t;

        Node<Type> *_first;
        Node<Type> *_last;
        int _size;

    public:
        /**
         * @brief  The iterator of this list
         */
        typedef Iterator<Type> iterator;

        /**
         * @brief  Constructor
         */
        List();

        /**
         * @brief  Desctructor
         */
        ~List();

        /**
         * @brief  Returns the size of the list
         * @return the size of the list 
         */
        int size() const;

        /**
         * @brief  Adds a new item to the start of the list
         * @param  item: value to push 
         */
        void push_first(Type const &item);

        /**
         * @brief  Adds a new item to the end of the list
         * @param  item: value to push
         */
        void push_last(Type const &item);

        /**
         * @brief  Removes the first item of the list
         */
        void pop_front();

        /**
         * @brief  Removes the last item of the list
         */
        void pop_back();

        /**
         * @brief  Inserts an item inside the list
         * @param  it: iterator to where to insert the item
         * @param  item: value to insert
         */
        void insert(iterator &it, Type const &item);

        /**
         * @brief  Removes an item from the list
         * @param  it: iterator of the item to remove
         */
        void erase(iterator &it);

        /**
         * @brief  Gets an iterator on the list
         * @return an iterator that points to the first item
         */
        iterator begin() const;

        /**
         * @brief  Gets a reverse iterator on the list
         * @return a reverse iterator that points to the last item
         */
        iterator rbegin() const;

        /**
         * @brief  Gets an iterator on the list pointing to the end
         * @return an iterator that points to the end of the list
         */
        iterator end() const;

        /**
         * @brief  Gets a reverse iterator on the list pointing to the end
         * @return a reverse iterator that points to the end of the list
         */
        iterator rend() const;

        /**
         * @brief  Write the list to the stream
         * @param  stream: stream to write on
         */
        void print(std::ostream &stream) const;
    };

    /**
     * @brief  Iterator class of the list
     */
    template <typename Type>
    class Iterator
    {
        friend List<Type>;

    protected:
        typename List<Type>::node_t *_ptr;
        typename List<Type>::node_t *_next;
        typename List<Type>::node_t *_prev;
        const List<Type> *_list;
        bool _reverse;

        Iterator(const List<Type> *list, typename List<Type>::node_t *ptr, bool reverse);

        void refresh();

    public:
        /**
         * @brief  Dereferencement
         */
        Type *operator->() const;

        /**
         * @brief  Dereferencement
         */
        Type &operator*() const;

        /**
         * @brief  ++iterator
         */
        Iterator<Type> &operator++();

        /**
         * @brief  iterator++
         */
        Iterator<Type> operator++(int);

        /**
         * @brief  --iterator
         */
        Iterator<Type> &operator--();

        /**
         * @brief  iterator--
         */
        Iterator<Type> operator--(int);

        /**
         * @brief  it1 == it 2
         */
        bool operator==(const Iterator<Type> &other) const;

        /**
         * @brief  it1 != it2
         */
        bool operator!=(const Iterator<Type> &other) const;
    };

    template <typename Type>
    List<Type>::List() : _first(nullptr),
                         _last(nullptr),
                         _size(0)
    {
        //? constructor
    }

    template <typename Type>
    List<Type>::~List()
    {
        //? destructor
        node_t *it;
        node_t *next = _first;

        //? we delete every dynamic allocation
        while ((it = next) != nullptr)
        {
            next = it->_next;
            delete it;
        }
    }

    template <typename Type>
    void List<Type>::push_first(Type const &item)
    {
        //? we create a new node and add it to the start of the list
        node_t *node = new node_t();
        node->_item = item;
        node->_next = _first;
        node->_previous = nullptr;

        if (_first != nullptr)
            _first->_previous = node;
        if (_last == nullptr)
            _last = node;

        _first = node;
        ++_size;
    }

    template <typename Type>
    void List<Type>::push_last(Type const &item)
    {
        //? we create a new node and add it to the end of the list
        node_t *node = new node_t();
        node->_item = item;
        node->_previous = _last;
        node->_next = nullptr;

        if (_last != nullptr)
            _last->_next = node;
        if (_first == nullptr)
            _first = node;

        _last = node;
        ++_size;
    }

    template <typename Type>
    void List<Type>::insert(iterator &it, Type const &item)
    {
        if (it._list != this)
            throw std::invalid_argument("Iterator isn't pointing this list.");
        else if (it == end())
            push_last(item);
        else if (it == begin())
            push_first(item);
        else if (it == rend())
            push_first(item);
        else if (it == rbegin())
            push_last(item);
        else
        {
            if (it._reverse)
            {
                //? we insert the value to where the iterator is
                node_t *node = new node_t();
                node->_item = item;

                if (it._ptr->_next != nullptr)
                    it._ptr->_next->_previous = node;

                node->_next = it.ptr->_next;
                it._ptr->_next = node;
                node->_previous = it._ptr;
                ++_size;
            }
            else
            {
                //? if reverse, we have to put it after the iterator
                node_t *node = new node_t();
                node->_item = item;

                if (it._ptr->_previous != nullptr)
                    it._ptr->_previous->_next = node;

                node->_previous = it.ptr->_previous;
                it._ptr->_previous = node;
                node->_next = it._ptr;
                ++_size;
            }
        }
    }

    template <typename Type>
    void List<Type>::erase(iterator &it)
    {
        //? we remove a node
        if (it._list != this)
            throw std::invalid_argument("Iterator isn't pointing this list.");

        if (_first == it._ptr)
            _first = it._ptr->_next;
        if (_last == it._ptr)
            _last = it._ptr->_previous;

        if (it._ptr->_previous != nullptr)
            it._ptr->_previous->_next = it._ptr->_next;

        if (it._ptr->_next != nullptr)
            it._ptr->_next->_previous = it._ptr->_previous;

        delete it._ptr;
        --_size;
    }

    template <typename Type>
    int List<Type>::size() const
    {
        return _size;
    }

    template <typename Type>
    void List<Type>::pop_front()
    {
        auto it = begin();
        erase(it);
    }

    template <typename Type>
    void List<Type>::pop_back()
    {
        auto it = rbegin();
        erase(it);
    }

    template <typename Type>
    typename List<Type>::iterator List<Type>::begin() const
    {
        //? iterator pointing to the first item
        return iterator(this, _first, false);
    }

    template <typename Type>
    typename List<Type>::iterator List<Type>::rbegin() const
    {
        //? reverse iterator pointing to the last item
        return iterator(this, _last, true);
    }

    template <typename Type>
    typename List<Type>::iterator List<Type>::end() const
    {
        //? iterator pointing to nothing
        return iterator(this, nullptr, false);
    }

    template <typename Type>
    typename List<Type>::iterator List<Type>::rend() const
    {
        //? reverse iterator pointing to nothing
        return iterator(this, nullptr, true);
    }

    template <typename Type>
    std::ostream &operator<<(std::ostream &stream, List<Type> const &list)
    {
        list.print(stream);
        return stream;
    }

    template <typename Type>
    void List<Type>::print(std::ostream &stream) const
    {
        //? here we print the list in a stream
        stream << "[";
        bool first = true;
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            if (!first)
                stream << ", ";
            else
                first = false;
            stream << std::endl
                   << "\t" << *it;
        }
        stream << std::endl
               << "]";
    }

    //? iterator constructor
    template <typename Type>
    Iterator<Type>::Iterator(const List<Type> *list, typename List<Type>::node_t *ptr, bool reverse) : _ptr(ptr),
                                                                                                       _next(nullptr),
                                                                                                       _prev(nullptr),
                                                                                                       _list(list),
                                                                                                       _reverse(reverse)
    {
        refresh();
    }

    template <typename Type>
    void Iterator<Type>::refresh()
    {
        //? we refresh the values of the next and previous values of the iterator
        if (_ptr != nullptr)
        {
            if (_reverse)
            {
                _next = _ptr->_previous;
                _prev = _ptr->_next;
            }
            else
            {
                _next = _ptr->_next;
                _prev = _ptr->_previous;
            }
        }
        else
        {
            _next = nullptr;
            _prev = _reverse ? _list->_first : _list->_last;
        }
    }

    template <typename Type>
    Type *Iterator<Type>::operator->() const
    {
        return &_ptr->_item;
    }

    template <typename Type>
    Type &Iterator<Type>::operator*() const
    {
        return *operator->();
    }

    template <typename Type>
    Iterator<Type> &Iterator<Type>::operator++()
    {
        _ptr = _next;
        refresh();
        return *this;
    }

    template <typename Type>
    Iterator<Type> Iterator<Type>::operator++(int)
    {
        Iterator<Type> tmp(*this);
        operator++();
        return tmp;
    }

    template <typename Type>
    Iterator<Type> &Iterator<Type>::operator--()
    {
        _ptr = _prev;
        refresh();
        return *this;
    }

    template <typename Type>
    Iterator<Type> Iterator<Type>::operator--(int)
    {
        Iterator<Type> tmp(*this);
        operator--();
        return tmp;
    }

    template <typename Type>
    bool Iterator<Type>::operator==(const Iterator<Type> &other) const
    {
        return _ptr == other._ptr && _reverse == other._reverse;
    }

    template <typename Type>
    bool Iterator<Type>::operator!=(const Iterator<Type> &other) const
    {
        return !operator==(other);
    }

} // namespace iut_cpp

#endif
