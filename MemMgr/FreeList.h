#pragma once
#include "IAlloc.h"
#include <cstdint>
#include <map>

namespace FL {

	extern const size_t MAX_BLOCK_SIZE;
	extern const size_t BUDGET_SIZE;

	class FreeList : public IAlloc {
	public:
		struct budget {
			budget* next;
			budget* last;
			unsigned int capacity;
			unsigned int remain;
		};
		template<int T>
		struct block {
			uintptr_t size;
			char data[T];
		};
		using block4 = block<4>;
		using block8 = block<8>;
		using block16 = block<16>;
		using block24 = block<24>;
		using block32 = block<32>;
		using block40 = block<40>;
		using block48 = block<48>;
		using block56 = block<56>;
		using block64 = block<64>;
		using block72 = block<72>;
		using block80 = block<80>;
		using block88 = block<88>;
		using block96 = block<96>;
		using block104 = block<104>;
		using block112 = block<112>;
		using block120 = block<120>;
		using block128 = block<128>;
	public:
		FreeList();
		~FreeList();
		void* Alloc(size_t size);
		void Dealloc(void* ptr);
	private:
		void* createBigMem(size_t size);
		// size向上取8的倍数，4例外
		// 比如输入1，返回4；输入7，返回8
		size_t upperRound(size_t size);
		// 初始化管理空间
		void init();
	private:
		/*std::map<uintptr_t, >*/
		budget * m_head = nullptr;
		budget* m_end = nullptr;
		budget* m_cur = nullptr;

		void* m_freeList[17] = { 0 };
	};
}