#ifndef INC_METIN_II_COMMON_NONCOPYABLE_TEMPLATE
#define INC_METIN_II_COMMON_NONCOPYABLE_TEMPLATE

class noncopyable
{
	protected:
		noncopyable() {}
		~noncopyable() {}

	private:
		noncopyable(const noncopyable &);
		noncopyable& operator = (const noncopyable &);
};

#endif
//martysama0134's ec11de26810c4b4081710343a364aa44
