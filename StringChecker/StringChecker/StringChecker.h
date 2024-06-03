// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа STRINGCHECKER_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции STRINGCHECKER_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef STRINGCHECKER_EXPORTS
#define STRINGCHECKER_API __declspec(dllexport)
#else
#define STRINGCHECKER_API __declspec(dllimport)
#endif

// Этот класс экспортирован из библиотеки DLL
class STRINGCHECKER_API CStringChecker {
public:
	CStringChecker(void);
	// TODO: добавьте сюда свои методы.
};

extern STRINGCHECKER_API int nStringChecker;

STRINGCHECKER_API int fnStringChecker(void);
