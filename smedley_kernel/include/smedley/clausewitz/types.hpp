#pragma once

#include <cstdint>
#include <limits>
#include "../std/string.hpp"

namespace smedley::clausewitz
{

    class CFixedPoint
    {
    protected:
        int _val;
    };

    static_assert(sizeof(CFixedPoint) == 0x4);

    template <typename T, unsigned char I, unsigned char F = std::numeric_limits<T>::digits - I>
    class fixed_point
    {
    protected:
        T _val;
    };

    static_assert(sizeof(fixed_point<int64_t,48,15>) == 0x8);

    class CDate
    {
    protected:
        int _timestamp;
    public:
        CDate(int timestamp) : _timestamp(timestamp) {}
    };

    class CGregorianDate : public CDate
    {
    };

    template <typename T>
    class CVector2
    {
        T _left;
        T _right;
    };

    template <typename T>
    class CList
    {
    public:
        struct Node
        {
            T data;
            Node *prev;
            Node *next;
            bool is_deleted;
        };
        struct Iterator
        {
        protected:
            Node *_cur;
        };
    protected:
        Node *_head;
        Node *_tail;
        int _size;
        bool _locked;
    };

    static_assert(sizeof(CList<int>) == 0x10);

    template <typename T>
    struct STernaryTrait
    {
        T GetInvalid();
    };

    template <typename T, class Trait = STernaryTrait<T>>
    class CTernary
    {
    public:
        struct Node
        {
            T _data;
            char _key;

            Node *_left;
            Node *_right;
            Node *_next;
        };

        struct LockData
        {
            T _data;
            sstd::string _key;
            bool _used;
        };
    protected:
        Node *_root; // 4
        bool _locked; // 8
        int _size; // c
        LockData **_lock_data; // 10
        clausewitz::CList<LockData *> _lock_list; // 14
    public:
        virtual ~CTernary();
        virtual T Get(sstd::string &key);
        virtual T Get(const char *key);
        virtual void Lock();
        virtual void Unlock();
        virtual void Erase();
        virtual void Add(sstd::string &key, T val);
        virtual void RemoveNode(Node *node);
    };

    static_assert(sizeof(CTernary<int>::Node) == 0x14);
    static_assert(sizeof(CTernary<int>) == 0x24);

    template <typename K, typename V>
    class ClassicHashKeyTraits
    {
    public:
        static unsigned int GetHashValue(const K &);
        static const K &GetKey(const V &);
    };

    template <typename K, typename V, class _Traits = ClassicHashKeyTraits<K, V>>
    class CHashTable
    {
    public:
        struct Node
        {
            V *data;
            Node *next;
        };
    protected:
        int _size;
        int _capacity;
        Node **_buckets;
    public:
        V *Find(const K &key)
        {
            unsigned int hash = _Traits::GetHashValue(key);
            Node *bucket_node = _buckets[hash % _capacity];
            while (bucket_node != nullptr) {
                if (_Traits::GetKey(*bucket_node->data) == key) {
                    return bucket_node->data;
                }

                bucket_node = bucket_node->next;
            }

            return nullptr;
        }
    };

    static_assert(sizeof(CHashTable<sstd::string, CFixedPoint>) == 0xc);
    static_assert(sizeof(CHashTable<sstd::string, CFixedPoint>::Node) == 0x8);

}