#pragma once

#include <vector>
#include <algorithm>

#define NBUCKET 6  // Number of buckets
#define INTERVAL 10  // Each bucket capacity


namespace AlgoShiz
{
    struct Node
    {
        int data;
        Node* next;
    };

    void _InsertionSort(Node* list)
    {
        if (list == 0 || list->next == 0)
            return;

        Node* k = list->next;
        list->next = 0;
        while (k != 0)
        {
            Node* ptr;
            if (list->data > k->data)
            {
                Node* tmp;
                tmp = k;
                k = k->next;
                tmp->next = list;
                list = tmp;
                continue;
            }

            for (ptr = list; ptr->next != 0; ptr = ptr->next)
                if (ptr->next->data > k->data)
                    break;

            if (ptr->next != 0)
            {
                Node* tmp = k;
                k = k->next;
                tmp->next = ptr->next;
                ptr->next = tmp;
                continue;
            }
            else
            {
                ptr->next = k;
                k = k->next;
                ptr->next->next = 0;
                continue;
            }
        }
    }


    size_t getBucketIndex(int value)
    {
        return value / INTERVAL;
    }


    void BucketSort(int arr[], size_t n)
    {
        Node** buckets = (Node**)malloc(sizeof(Node*) * NBUCKET);

        for (size_t i = 0; i < NBUCKET; ++i)
            buckets[i] = NULL;

        for (size_t i = 0; i < n; ++i)
        {
            Node* current = (Node*)malloc(sizeof(Node));
            size_t pos = getBucketIndex(arr[i]);

            current->data = arr[i];
            current->next = buckets[pos];

            buckets[pos] = current;
        }
        
        for (size_t i = 0; i < NBUCKET; ++i)
            _InsertionSort(buckets[i]);

        Node* tempNode;
        for (size_t j = 0, i = 0; i < NBUCKET; ++i)
        {
            tempNode = buckets[i];
            while (tempNode)
            {
                arr[j++] = tempNode->data;
                tempNode = tempNode->next;
            }
        }

        for (size_t i = 0; i < NBUCKET; ++i)
        {
            tempNode = buckets[i];
            while (tempNode)
            {
                Node* tmp = tempNode;
                tempNode = tempNode->next;
                free(tmp);
            }
        }

        free(buckets);
    }
}
