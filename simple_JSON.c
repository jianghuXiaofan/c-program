//  
//  main.c  
//  Test  
//  
  
  
  
/*************************************** 
  
         一些系统函数的简单实现 
  
 ***************************************/  
  
int my_strlen(char *string)  
{  
    int len = 0;  
    while (*string != '\0') {  
        string++;  
        len++;  
    }  
    return len;  
}  
  
const char *my_strstr(const char *str, const char *sub_str)  
{  
    for(int i = 0; str[i] != '\0'; i++)  
    {  
        int tem = i; //tem保留主串中的起始判断下标位置  
        int j = 0;  
        while(str[i++] == sub_str[j++])  
        {  
            if(sub_str[j] == '\0')  
            {  
                return &str[tem];  
            }  
        }  
        i = tem;  
    }  
      
    return "";  
}  
  
  
char* my_strncpy(char* dest, const char* src, int len)  
{  
      
    char* temp=dest;  
    int i=0;  
    while(i++ < len  && (*temp++ = *src++)!='\0')  
    {  
          
    }  
    if(*(temp)!='\0')     *temp='\0';  
    return dest;  
      
}  
  
int my_strcmp(char* str1, char* str2){  
   while(*str1 && *str2 && *str1==*str2)  
   {  
    ++str1;  
     ++str2;  
   }  
   return *str1-*str2;  
}  
  
  
/*************************************** 
  
           JSON相关函数声明 
  
***************************************/  
  
char json_check(char *str); //JSON 校验函数  
char json_get_value(char *json,char *json_key , char *json_value); //JSON获取键值  
char json_check_value(char *str1, char *str2); //JSON 键值对比函数  
  
  
  
  
/*************************************** 
 name:       JSON 校验函数 
 input:      字符串 
 output:     合法JAON 返回1 不合法JSON 返回0 
 description: 
 ***************************************/  
  
char json_check(char *str)  
{  
    char str_length; //定义字符长度变量  
    str_length = my_strlen(str); //计算字符长度  
    if(str[0] == '{' && str[str_length-1] == '}') //通过首尾大括号判断是否为JSON  
    {  
        return 1; //如果字符串为合法JSON 返回1  
    }  
    else  
    {  
        return 0; //如果字符串为合法JSON 返回0  
    }  
}  
  
  
  
/*************************************** 
 name:       JSON 获取键值函数 
 input:      JSON字符串 要获取的键名 获取键值的字符串 
 output:     如果获取成功返回1 获取失败返回0 
 description: 
 ***************************************/  
  
char json_get_value(char *json,char *json_key , char *json_value)  
{  
      
    char *json_key_start; //定义键名开始的位置  
    char *json_key_end; //定义键名结束的位置  
    char json_key_length; //定义键名长度  
      
    char *json_value_start; //定义键值开始的位置  
    char *json_value_end; //定义键值结束的位置  
    char json_value_length; //定义键值长度  
      
    json_key_start = my_strstr(json,json_key); //获取键名开始的位置  
    json_key_length = my_strlen(json_key); //获取键名的长度  
      
      
    json_key_end = json_key_start + json_key_length;  //获取键名结束的位置  
      
      
    if(json_key_start != 0 && *(json_key_start - 1) == '\"' && *(json_key_end) == '\"' && *(json_key_end + 1) == ':' && *(json_key_end + 2) == '\"' )  
          
    {  
        json_value_start = json_key_end + 3; //获取键值开始的位置  
        json_value_end = my_strstr(json_value_start,"\""); //获取键值结束的位置  
        json_value_length = json_value_end - json_value_start; //获取键值的长度  
          
        my_strncpy(json_value,json_value_start,json_value_length); //将键值存入指针数组  
          
        json_value[json_value_length] = '\0'; //指针最后一位补字符串结束符 \0  
          
        return 1; //成功获取键值 返回1  
    }  
    else  
    {  
        json_value[0] = '\0';  
        return 0; //失败获取键值 返回0  
    }  
}  
  
  
  
/*************************************** 
 name:       JSON 键值对比函数 
 input:      JSON 键值 要匹配的字符 
 output:     如果匹配成功返回1 失败返回0 
 description: 
 ***************************************/  
  
char json_check_value(char *str1, char *str2)  
{  
    if(my_strcmp(str1,str2) == 0)  
    {  
        return 1; //匹配成功返回1  
    }  
    else  
    {  
        return 0;//匹配成功返回0  
    }  
}  
  
  
  
  
/*************************************** 
  
            测试方法 
  
 ***************************************/  
  
int main(int argc, const char * argv[]) {  
      
      
      
//    char *json = "{\"test_key\":\"value1\"}";  
//    char rs = json_check(json);  
//    if(rs == 1){  
//        printf("json is valid....\r\n");  
//    }else{  
//        printf("json is invalid....\r\n");  
//    }  
//      
//    unsigned char value[20];  
//    rs =  json_get_value(json,"test_key",&value);  
//    if(rs == 1){  
//        printf("parser test_key success....%s  \r\n",value);  
//    }else{  
//        printf("parser test_key fail....\r\n");  
//    }  
      
      
      
    char *json = "{\"activecode\":\"phonedirect\",\"uuid\":\"058daba0-f32c-11e6-9055-01160c7a67b1\",\"token\":\"5650ea47fc15d1c19132152681714094fd82fd3d\"}";  
    char rs = json_check(json);  
    if(rs == 1){  
       printf("json is valid....\r\n");  
    }else{  
        printf("json is invalid....\r\n");  
    }  
      
    unsigned char value[127];  
    rs =  json_get_value(json,"token",&value);  
    if(rs == 1){  
        printf("parser token success....%s  \r\n",value);  
    }else{  
        printf("parser token fail....\r\n");  
    }  
      
    rs =  json_get_value(json,"uuid",&value);  
    if(rs == 1){  
        printf("parser uuid success....%s  \r\n",value);  
    }else{  
        printf("parser uuid fail....\r\n");  
    }  
  
      
      
      
//    {  
//        "key1": "value1",  
//        "key2": {  
//            "key3": "value3"  
//        }  
//    }  
      
//    char *json = "\"{\"key1\":\"value1\",\"key2\":{\"key3\":\"value3\"}}";  
//    char rs = json_check(json);  
//    if(rs == 1){  
//        printf("json is valid....\r\n");  
//    }else{  
//        printf("json is invalid....\r\n");  
//    }  
//  
//    unsigned char value[127];  
//    rs =  json_get_value(json,"key1",&value);  
//    if(rs == 1){  
//        printf("parser key1 success....%s  \r\n",value);  
//    }else{  
//        printf("parser key1 fail....\r\n");  
//    }  
//      
//    rs =  json_get_value(json,"key2",&value);  
//    if(rs == 1){  
//        printf("parser key2 success....%s  \r\n",value);  
//    }else{  
//        printf("parser key2 fail....\r\n");  
//    }  
//      
//    rs =  json_get_value(json,"key3",&value);  
//    if(rs == 1){  
//        printf("parser key3 success....%s  \r\n",value);  
//    }else{  
//        printf("parser key3 fail....\r\n");  
//    }  
    return 0;  
}  
