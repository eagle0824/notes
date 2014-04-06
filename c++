1.
	bool 1	true
	bool 0 false
	
	基本内置类型
	bool
	char		'a'
	wchar_t	L'a'
	short
	int
	long		3.14L
	float		3.14f
	double		3.14d
	long double


	初始化
	直接初始化()	int a(10)	直接初始化效率高
	复制初始化=	int a = 10;


	c++ 中初始化不是赋值
	(1)	初始化,创建变量并给它赋初始值
	(2)	赋值,擦除对象当前值,并用新值替代

	变量的定义	用于为变量分配存储空间,还可以为变量指定初始值
	变量的声明	用于向程序表明变量的类型和名字(定义也是声明 extern)，表明变量在其它地方定义，此处仅是声明
	(声明仅一种情况 extern varialble)

	const	变量默认为局部变量只能在本文件使用,要想在其他文件中使用,必须显示的声明为 extern const int a(10)
		非const变量,默认为extern,因此不用显示声明为extern

	引用	变量名前加&来定义	引用必须初始化,引用必须与该引用同类型的对象初始化
	const 引用 	指向const对象的引用

	int val = 10;		
	int &ref = val

	非const引用,只能绑定到与该引用相同类型的对象上
	const引用,可以绑定到不同,但相关的类型的对象或绑定到右值

	typedef 定义类型的同义词	typeof int count;

	emum emum_name{one,two,three};第一个值默认为:0	后面依次加1
	
	class	关键字
	
	class Item{
	public:
		.....
	private:
		int a(10);
		std::string str("aaa");
	};
	struct	关键字
	struct Item{
	
		.....
	private:
		int a(10);
		std::string str("aaa");
	};

	注: class 与 struct区别时,默认访问级别	struct的成员为pulic	class的成员为private
	    class {}最后分号；


	预处理
	避免多重包含
	#ifndef HH
	#define HH
		define.......
	#endif
	
	#include <iostream>	<>标准头文件,在编译器设定的位置查找
	#include "myfile.h"	自定义头文件,首先在源文件所在的位置查找,
	
	注:
	::是运算符中等级最高的，它分为三种:
	1)global scope(全局作用域符），用法（::name)
	2)class scope(类作用域符），用法(class::name)
	3)namespace scope(命名空间作用域符），用法(namespace::name)
	他们都是左关联（left-associativity)
	他们的作用都是为了更明确的调用你想要的变量，如在程序中的某一处你想调用全局变量a，那么就写成::a，
	如果想调用class A中的成员变量a，那么就写成A::a,
	另外一个如果想调用namespace std中的cout成员，你就写成std::cout（相当于using namespace std;
	cout）意思是在这里我想用cout对象是命名空间std中的cout（即就是标准库里边的cout）

2.	c++标准库
	
	#include<string>
	using std::string;	命名空间的using声明,可以在文件中只使用 string 而非 std::string

	string

	size()		返回值为	string::size_type类型,与机器无关的unsigned类型（非int）
	empty()	
	string 对字符的处理cctype	对应c语言中的ctype.h

	vector
	#include<vector>
	using std::vector;

	vector<int> fevc(10);	定义十个int的vector	fevc,每一项初始化为0;
	size()		返回值为	vector<T>::size_type类型
	fevc[i]	读取fevc中index为i的元素，下标操作只能提取确实存在的元素,不能添加元素
	fevc.push_back(i) 添加元素
	
	bitset
	#include<bitset>
	using std::bitset;

	size()		返回值为	size_t		位于cstddef头文件中	相当于c语言中stddef.h

	数组
	数组定义,数组的维数必须用值大于等于1的常量表达式（非const常量以及需要运行时才能获得其值的const常量都不能作为数组的维数使用）
	数组的下标类型为	size_t
	函数sizeof()	获得类型的长度单位为字节
	因此获取数组的长度可以通过以下方式获取		sizeof(arrays)/sizeof(arrays[0])
	int array[10] = {1}; 剩余位初始化的元素，若是内置类型初始化为0，若为类类型调用默认构造函数初始化

	指针
	vector		vector<T> :: iterator iter = vect.begin();iter!=vect.end();iter++	*iter获取某个元素
	vector 下标类型为	vector::size_type index;	vect[index]	获取某个元素
	数组与vector的区别是:数组的长度是固定的,数组一经创建就不能添加新的元素

	指针:用于保存对象,指向另一对象的地址
	string str("hello");	
	string *sp = &str;	//&取地址
	string* sp = &str;	sp是一个指向string对象的指针(从右向左读) 
	定义时 *标识符表示为指针类型,sp是一个指针,指向地址;
	取值时*sp,*为解操作符,*sp表示为指针sp所指向地址,代表的对象
	指针必须是以下三种状态之一:(1)保存一个特定对象的地址;(2)指向某个对象后面的另一个对象(3)或者是0值,表明它不指向任何对象
	void*指针	可以指向任何类型对象的地址
		功能:(1)与另一个指针进行比较;(2)向函数传递void*指针或从函数返回void*指针
(3)给另一个void*指针赋值	不允许使用void*指针操纵它所指向的对象
	
	string s1("some value");
	string *sp1 = &s1;

	string s2("another value");
	string *sp2 = &s2;
	
	*sp1 = "a new value";//通过指针赋值,s1重新赋值
	sp1 = sp2;//给指针赋值,sp1指向sp2指向对象

	指针遍历
	 const size_t sizeNum = 7;

        string hellos[sizeNum] = {"aa","bb","cc","dd","ee","ff","gg"};


        for(string *pbegin = hellos,*pend = hellos + sizeNum;pbegin != pend;pbegin++){
                cout <<  *pbegin << endl;
        }

	const与指针
					const dobule dob = 3.1415;
	(1)指向const对象的指针		const double *sp = &dob	指针可以指向其他const double
	(2)const指针			double *const sp = &dob	指针不可指向其他位置
	(3)指向const对象的const指针	const double *const sp = &dob	指针和指针所指对象均不能改变



	运算符
	~	位求反
	<<	位左移
	>>	位右移
	&	位与	两者均为1		结果为1
	^	位异或	两者仅有一为1		结果为1
	|	位或	两者有一或者两个都为1 	结果为1

	&操作符
	变量的前面表示取变量地址赋值给指针， 如：int a = 0; int *pa = &a;
	类型后面表示引用，引用即变量的替身。  int a = 0; int &ref = a;操作ref就跟操作a是一样的
	还有一种的与预算 如 int a = 0; a &= 0;// 按位与操作

3	c风格字符串(以空字符null结束的字符数组)
	#include<cstring>c++ 头文件 或者#include<string.h>c头文件

4	箭头操作符	->	(解引用操作符和点操作符的替代符号)	
	Item *sp = &item;
	(*sp).foo	等价与	sp->foo

5	定义一个指向string的指针
	typedef string *pstring;

6	if语句与条件操作符   command?exp1:exp2
	command	为0则为false;command不为0则为true	

7 	new 和 delete
	int *sp = new int;	动态创建sp,未初始化
	int *sp = new int();	动态创建sp,已初始化为0
	delete sp;删除sp指向对象所占用内 	delete关键字表示释放指针所指向的内存空间

8	强制转换	
	格式为	cast-name<type>(expression)
	
	type 为转换的目标类型
	cast-name 为 
	(1)static_cast	大数据转换为小数据double转化成int(将隐式转化显示转化)	static_cast<int>(exp)
	(2)dynamic_cast	支持运行时识别指针或引用所指向的对对象
	(3)const_cast		转换掉表达式的const属性
	(4)reinterpret_cast	为操作数的位模式提供较低层次的重新解释


	关于强制类型转换的问题，很多书都讨论过，写的最详细的是C++ 之父的《C++ 的设计和演化》。最好的解决方法就是不要使用C风格的强制类型转换，而是使用标准C++的类型转换符：static_cast, dynamic_cast。标准C++中有四个类型转换符：static_cast、dynamic_cast、reinterpret_cast、和 const_cast。下面对它们一一进行介绍。

	static_cast

	用法：static_cast < type-id > ( expression_r_r )

	该运算符把 expression_r_r转换为type-id类型，但没有运行时类型检查来保证转换的安全性。它主要有如下几种用法：
	用于类层次结构中基类和子类之间指针或引用的转换。进行上行转换（把子类的指针或引用转换成基类表示）是安全的；进行下行转换（把基类指针或引用转换成子类表示）时，由于没有动态类型检查，所以是不安全的。
	用于基本数据类型之间的转换，如把int转换成char，把int转换成enum。这种转换的安全性也要开发人员来保证。
	把空指针转换成目标类型的空指针。
	把任何类型的表达式转换成void类型。
	注意：static_cast不能转换掉expression_r_r的const、volitale、或者__unaligned属性。

	dynamic_cast

	用法：dynamic_cast < type-id > ( expression_r_r )

	该运算符把 expression_r_r转换成type-id类型的对象。Type-id必须是类的指针、类的引用或者void *；如果type-id是类指针类型，那么expression_r_r也必须是一个指针，如果type-id是一个引用，那么 expression_r_r也必须是一个引用。

	dynamic_cast 主要用于类层次间的上行转换和下行转换，还可以用于类之间的交叉转换。

	在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；在进行下行转换时，dynamic_cast具有类型检查的功能，比 static_cast更安全。
	class B{

	public:

	int m_iNum;

	virtual void foo();

	};

	class D:public B{

	public:

	char *m_szName[100];

	};



	void func(B *pb){

	D *pd1 = static_cast<D *>(pb);

	D *pd2 = dynamic_cast<D *>(pb);

	}

	在上面的代码段中，如果pb指向一个D类型的对象，pd1和pd2是一样的，并且对这两个指针执行D类型的任何操作都是安全的；但是，如果pb指向的是一个 B类型的对象，那么pd1将是一个指向该对象的指针，对它进行D类型的操作将是不安全的（如访问m_szName），而pd2将是一个空指针。另外要注意：B要有虚函数，否则会编译出错；static_cast则没有这个限制。这是由于运行时类型检查需要运行时类型信息，而这个信息存储在类的虚函数表（关于虚函数表的概念，详细可见<Inside c++ object model>）中，只有定义了虚函数的类才有虚函数表，没有定义虚函数的类是没有虚函数表的。

	另外，dynamic_cast还支持交叉转换（cross cast）。如下代码所示。
	class A{

	public:

	int m_iNum;

	virtual void f(){}

	};



	class B:public A{

	};



	class D:public A{

	};



	void foo(){

	B *pb = new B;

	pb->m_iNum = 100;

	D *pd1 = static_cast<D *>(pb); //copile error

	D *pd2 = dynamic_cast<D *>(pb); //pd2 is NULL

	delete pb;

	}

	在函数foo中，使用static_cast进行转换是不被允许的，将在编译时出错；而使用 dynamic_cast的转换则是允许的，结果是空指针。

	reinpreter_cast

	用法：reinpreter_cast<type-id> (expression_r_r)

	type-id必须是一个指针、引用、算术类型、函数指针或者成员指针。它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针（先把一个指针转换成一个整数，在把该整数转换成原类型的指针，还可以得到原先的指针值）。

	该运算符的用法比较多。

	const_cast

	用法：const_cast<type_id> (expression_r_r)

	该运算符用来修改类型的const或volatile属性。除了const 或volatile修饰之外， type_id和expression_r_r的类型是一样的。

	常量指针被转化成非常量指针，并且仍然指向原来的对象；常量引用被转换成非常量引用，并且仍然指向原来的对象；常量对象被转换成非常量对象。

	Voiatile 和const类试。举如下一例：
	class B{

	public:

	int m_iNum;

	}

	void foo(){

	const B b1;

	b1.m_iNum = 100; //comile error

	B b2 = const_cast<B>(b1);

	b2. m_iNum = 200; //fine
	}

	上面的代码编译时会报错，因为b1是一个常量对象，不能对它进行改变；使用const_cast把它转换成一个常量对象，就可以对它的数据成员任意改变。注意：b1和b2 是两个不同的对象。

	最容易理解的解释：

   dynamic_cast:   通常在基类和派生类之间转换时使用；
   const_cast:   主要针对const和volatile的转换.   
   static_cast:   一般的转换，如果你不知道该用哪个，就用这个。   
   reinterpret_cast:   用于进行没有任何关联之间的转换，比如一个字符指针转换为一个整形数。




9	常见异常#include<stdexcept>
	exception	runtime_error	range_error	overflow_error	underflow_error	logic_error	domain_error	invalid_argument	legth_error out_of_range

10 	使用预处理器进行调试
	int main(){
	#ifndef NDEBUG	//如果没有定义NDBUG,则打印error.若在文件开头定义#define NDEBUG,则不执行ifned到endif之间代码
	cerr << "Error : " << __FILE__	//FILE文件名
		<< " : line " <<__LINE__<<endl	//当前行号
		<<"	Compiled on " << __DATE__	//文件被编译的时间
		<<" at " << __TIME__ << endl	//文件被编译的日期
		<< "       Word read was :" << word
		<< " : Length too short" <<endl;	
	#endif
	}
	另一个调试技术是,NDEBUG预处理变量和assert预处理宏
	assert位于cassert头文件中
	格式为	assert(expr)

11 	函数	
	非引用型参	getMax(int a,int b);不会改变实参,只会改变函数体内的参数,函数体执行结束,对实参原来值没有影响
	引用型参	getMax(int &a,int &b);改变实参
	(1)使用引用型参返回额外信息
	(2)利用const引用避免重复	const string &s1	实参为大型数据时,避免型参复制,影响效率
	(3)不用修改的引用型参定义为const
	(4)传递指向指针的引用	ptrswap(int *&v1,int *&v2)

12	vector 型参	往往用iterator来代替防止复制vector中的每一个元素
			或将型参声明为引用类型& 	

13 	数组型参
	(1)指针		传递数组名,编译时不匹配数组大小	printValues(const int ia[10])
	(2)引用传递数组	printValues(int (&atrr)[10])	匹配数组大小
	传递给函数数组的处理
	(1)数组中设置结束标示	如c风格字符串null结束
	(2)传入指向第一个和最后一个数组元素的指针	printValues(const int *beg,const int *end)
	(3)显示传递数组大小	printValues(const int ia[],size_t size)

14	内联函数(避免函数调用开销)
	在返回值类型前加关键字inline(或者定义在类内部)
	内联函数必须写在头文件中
	编译器隐式的将在类内定义的成员函数当作内联函数

	mutable 关键字（可变数据成员变量，mutable放在声明之前）
	mutalbe int a;//在任何函数中都可以改变其值（包括const函数）
	隐式转换
	构造函数 A(int a)	可以有int类型值构造一个A对象，有函数method(A &a)则method(4),4隐式转化为A对象
	若要屏蔽此隐式转换，可用explicit来修饰构造函数
	如 explicit A(int a)  method 方法可以如此调用 method(new A(4));


15	c语言中static作用(首先static的最主要功能是隐藏，其次因为static变量存放在静态存储区，所以它具备持久性和默认值0)
	(1)	隐藏	(不同文件中)
	(2)	变量持久化
	(3)	变量默认初始化为0

16	键盘输入文件结束符
	ctrl + z	windows
	ctrl + d	linux ios

17	函数	
	非引用行参	表示对应实参的局部副本,函数对实参没有任何影响,只可能修改行参的值	method(int num)
		指针行参	复制实参指针	改变p,改变复制指针指向的对象,而*p则改变指针指向对象的值,	method(int *p)
				若要保护指针所指向的值,应该声明为const int *p	method(const int *p)
		const行参	不能改变实参的副本		method(const int num)
	引用行参	函数可以修改实参的值	method(int &num1,int &num2)
		使用引用行参,返回额外的信息
		使用const引用,避免复制		method(const string &str)

18	创建对象
	C++在创建对象的时候可以采用两种方式：（例如类名为Test） Test test  或者 Test* pTest = new Test()。
        这两种方法都可以实例化一个对象，但是这两种方法有很大的区别，区别在于对象内容所在的内存空间不同，众所周知，内存的分配方式有三种
      （1）从静态存储区域分配。内存在程序编译的时候就已经分配好，这块内存在程序的整个运行期间都存在。例如全局变量，static 变量。 
      （2）在栈上创建。在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束后在将这些局部变量的内存空间回收。在栈上分配内存空间效率很高，但是分配的内存容量有限。
		test 执行结束后执行析够函数
      （3）从堆上分配的。程序在运行的时候用 malloc 或 new 申请任意多少的内存，程序员自己负责在何时用 free 或 delete 释放内存。
		需要用户删除,否则可能产生内存溢出

19	sleep(3)		秒	当前线程休眠3秒(弃用)
	usleep(3*1000*1000)	微秒	当前线程休眠3秒
	thread_sleep(3)	秒	当前线程休眠3秒
	
	#include <errno.h>
	#include <time.h>
	int thread_sleep (double sleep_time)
	{
		struct timespec tv;
		/* Construct the timespec from the number of whole seconds... */
		tv.tv_sec = (time_t) sleep_time;
		/* ... and the remainder in nanoseconds. */
		tv.tv_nsec = (long) ((sleep_time - tv.tv_sec) * 1e+9);
		while (1)
		{
		  /* Sleep for the time specified in tv. If interrupted by a
		    signal, place the remaining time left to sleep back into tv. */
		  int rval = nanosleep (&tv, &tv);
		  if (rval == 0)
		   /* Completed the entire sleep time; all done. */
		   return 0;
		  else if (errno == EINTR)
		   /* Interrupted by a signal. Try again. */
		   continue;
		  else
		   /* Some other error; bail out. */
		   return rval;
		}
		return 0;
	}


20	数组指针和指针数组的区别
数组指针（也称行指针）
定义 int (*p)[n];
()优先级高，首先说明p是一个指针，指向一个整型的一维数组，这个一维数组的长度是n，也可以说是p的步长。也就是说执行p+1时，p要跨过n个整型数据的长度。

如要将二维数组赋给一指针，应这样赋值：
int a[3][4];
int (*p)[4]; //该语句是定义一个数组指针，指向含4个元素的一维数组。
 p=a;        //将该二维数组的首地址赋给p，也就是a[0]或&a[0][0]
 p++;       //该语句执行过后，也就是p=p+1;p跨过行a[0][]指向了行a[1][]

所以数组指针也称指向一维数组的指针，亦称行指针。

指针数组
定义 int *p[n];
[]优先级高，先与p结合成为一个数组，再由int*说明这是一个整型指针数组，它有n个指针类型的数组元素。这里执行p+1是错误的，这样赋值也是错误的：p=a；因为p是个不可知的表示，只存在p[0]、p[1]、p[2]...p[n-1],而且它们分别是指针变量可以用来存放变量地址。但可以这样 *p=a; 这里*p表示指针数组第一个元素的值，a的首地址的值。
如要将二维数组赋给一指针数组:
int a[3][4];
int *p[3];
for(i=0;i<3;i++)
p[i]=a[i];
这里int *p[3] 表示一个一维数组内存放着三个指针变量，分别是p[0]、p[1]、p[2]
所以要分别赋值。

这样两者的区别就豁然开朗了，数组指针只是一个指针变量，似乎是C语言里专门用来指向二维数组的，它占有内存中一个指针的存储空间。指针数组是多个指针变量，以数组形式存在内存当中，占有多个指针的存储空间。
还需要说明的一点就是，同时用来指向二维数组时，其引用和用数组名引用都是一样的。
比如要表示数组中i行j列一个元素：
*(p[i]+j)、*(*(p+i)+j)、(*(p+i))[j]、p[i][j]
优先级：()>[]>*
