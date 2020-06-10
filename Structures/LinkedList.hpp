#pragma once

#include <iostream>

namespace AlgoShiz
{
    template <typename T>
    class NPNode
    {
    private:
        T value;
        NPNode<T>* prev;
        NPNode<T>* next;
    public:
        NPNode<T>() : value(0), prev(nullptr), next(nullptr) {}
        NPNode<T>(T value, NPNode<T>* prev = nullptr, NPNode<T>* next = nullptr)
            : value(value), prev(prev), next(next) {}

        NPNode<T>* InsertPrev(T newValue)
        {
            NPNode<T>* temp = prev;
            prev = new NPNode<T>(newValue, temp, this);
            return prev;
        }

        NPNode<T>* InsertNext(T newValue)
        {
            NPNode<T>* temp = next;
            next = new NPNode<T>(newValue, this, temp);
            return next;
        }

        NPNode<T>* InsertBack(T newValue)
        {
            NPNode<T>* last = this;
            while (last->next != nullptr)
                last = last->next;

            last->next = new NPNode<T>(newValue, last);
            return last->next;
        }

        NPNode<T>* Find(NPNode<T>* element)
        {
            NPNode<T>* temp = this;
            while (temp != nullptr)
            {
                if (temp == element)
                    return temp;

                temp = temp->next;
            }

            temp = this->prev;
            while (temp != nullptr)
            {
                if (temp == element)
                    return temp;

                temp = temp->prev;
            }

            return nullptr;
        }

        void Remove(NPNode<T>* toRemove)
        {
            NPNode<T>* finded = Find(toRemove);
            if (finded != nullptr)
                finded->prev->next = finded->next;
        }
    };
}
