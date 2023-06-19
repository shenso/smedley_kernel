#pragma once

#include <cstdint>
#include <limits>

namespace smedley::clausewitz
{

	class CFixedPoint
	{
		int _val;
	};

	static_assert(sizeof(CFixedPoint) == 0x4);

	template <typename T, unsigned char I, unsigned char F = std::numeric_limits<T>::digits - I>
	class fixed_point
	{
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
	private:
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

}