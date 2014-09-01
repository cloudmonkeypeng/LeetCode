# C++面试常问问题

# 指针
10个指针的数组		int *(a[10]）
指向数组的指针		int (*a)[10]
指像函数的指针		int (*a)(int)


# static


# const
只读


# #define

有问题的写法： #define min(X,Y) ((X) < (Y) ? (X) : (Y))

正确写法： 
#define min(X,Y)  
(__extension__  
({  
   typeof(X) __x=(X), __y=(Y);   
   (__x<__y)?__x:__y;  
}) 
) 

更奇葩的写法：#define min(x,y) ({ typeof(x) _x = (x); typeof(y) _y = (y); (void) (&_x == &_y); _x < _y ? _x : _y; })

#define SECONDS_PER_YEAR (60 * 60 * 24 * 365)UL


# sizeof()
sizeof(char)			//1
sizeof(short)			//2
sizeof(int)				//4
sizeof(float)			//4
sizeof(double)			//8


# 变量声明存储位置



# malloc与new的区别



# 先后关系(优先级问题)！！

y = !x++;

{
	y = !x;

	x++;
} 


*(ptr++) +=123;

{
	*ptr = *ptr +123;

	ptr++;
}


# 函数入出 栈区 等问题



# this指针



# 模板类



# public private protected
