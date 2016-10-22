#ifndef BOARD_H
#define BOARD_H
template <class T>
struct Board {
	private:
		T** internalArray;
		int size;
	public:
		Board(const int size);
		~Board();
		const int getSize();
		T* operator[] (int index);
		void setElement(const T element, const int x, const int y) throw (int);
};
#endif
