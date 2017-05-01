### 函数传值还是传指的问题案例

- 要想改变它本身的值, 必须传入它本身的指针

向函数传参数时，一般而言，传入非const修饰的指针时，就表示，要在函数中修改这个指针的指向内存中的数据，如果是传值，那么无论在函数内部怎么修改这个值，也不会影响到传过来的值，因为传值可以看作只是内存拷贝。说起来有点基础的都懂，但是
请问下面的写法有什么问题


```
void GetVersion(char * pStr)
{
    pStr = (char *)malloc(10);
    strcpy(pStr,"V1.1.1");
}

int main(void)
{
    char * ver = NULL;
    GetVersion(ver);
    printf("ver = %s\n",ver);
    free(ver);
}
```
问题是：
- free的位置不对，会报错。
- 不能实现GetVersion函数的想要的目的。
----------------------------
类似这样的问题是一个新手最容易犯的错误,程序中妄图通过函数
GetVersion 给指针 ver 分配空间，但这种方法根本没有什么作用，原因就是--这是
传值，不是传指针。你或许会和我争论，我分明传的时指针啊？再仔细看，其
实，==你传的是指针其实是在传值==。
正确的应该这么写


```
void GetVersion(char ** pStr)
{
	*pStr = (char *)malloc(20);
	strcpy(*pStr,"V1.0.1");
}

int main(void)
{
	char * ver = NULL;	
	GetVersion(&ver);
	printf("ver = %s\n",ver);
	free(ver);
}
```
