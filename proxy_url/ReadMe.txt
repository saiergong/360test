
在test_ProxUrlExtractor_Extract1（）函数中添加了如下测试单元：
"http://www.mytest.com?&&&from&&test=abf&query=http://test.com&&&", "http://test.com"
"http://www.mytest.com?&&&&&&&&&&&&&&&&&&&&&&", ""
"http://www.mytest.com?from=z=========a=b&&query=http://hello.com", "http://hello.com"
"http://www.mytest.com?from=helo&u&test=bac&query=http://hello.com&&", "http:hello.com"
"http://www.mytest.com?a=&c=&&=&query=http://hello.com", "http://hello.com"

解决思路：
可以把后面的字符串看成是一个个由‘&’分割的子串，对于每一个子串，分析有没有‘key=value’模式，如果有，返回sub_url。

时间复杂度：由于只需要从头至尾扫描一遍字符串，切割成子串，然后对子串分析，而子串处理工作基本上就是找出‘=’，然后对key赋值，再去
key集合中查找是否存在，所以时间复杂度为最多为O(2 * 字符串长度) + O(lgn) * m,其中n为key集合大小，m为子串数目。
空间复杂度：由于只需要几个变量保存临时key等，所以为O(字符串长度）


利用gprofile工具分析时间性能如下：
-----------------------------------------------
                0.00    0.00       1/1           main [5]
[82]     0.0    0.00    0.00       1         test_ProxUrlExtractor_Extract1() [82]
                0.00    0.00      19/66          qh::ProxyURLExtractor::Extract(std::set<std::string, std::less<std::string>, std::allocator<std::string> > const&, std::string const&) [30]
                0.00    0.00      19/66          bool std::operator!=<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [39]
                0.00    0.00       4/10          std::set<std::string, std::less<std::string>, std::allocator<std::string> >::insert(std::string const&) [58]
                0.00    0.00       1/2           std::set<std::string, std::less<std::string>, std::allocator<std::string> >::set() [74]
                0.00    0.00       1/2           std::set<std::string, std::less<std::string>, std::allocator<std::string> >::~set() [75]
-----------------------------------------------
                0.00    0.00       1/1           main [5]
[83]     0.0    0.00    0.00       1         test_ProxUrlExtractor_Extract2() [83]
                0.00    0.00      47/66          qh::ProxyURLExtractor::Extract(std::set<std::string, std::less<std::string>, std::allocator<std::string> > const&, std::string const&) [30]
                0.00    0.00      47/66          bool std::operator!=<char, std::char_traits<char>, std::allocator<char> >(std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [39]
                0.00    0.00       6/10          std::set<std::string, std::less<std::string>, std::allocator<std::string> >::insert(std::string const&) [58]
                0.00    0.00       1/2           std::set<std::string, std::less<std::string>, std::allocator<std::string> >::set() [74]
                0.00    0.00       1/2           std::set<std::string, std::less<std::string>, std::allocator<std::string> >::~set() [75]
-----------------------------------------------
                0.00    0.00       1/1           std::_Rb_tree<std::string, std::string, std::_Identity<std::string>, std::less<std::string>, std::allocator<std::string> >::_M_insert_unique(std::string const&) [66]
[84]     0.0    0.00    0.00       1         std::_Rb_tree_iterator<std::string>::operator--() [84]
-----------------------------------------------



















﻿
该项目是一道简单的面试题。

该面试题是我们从实际项目中抽出来的，完成一个项目中的局部的一个小功能。

该功能是从原始url中根据提供的参数key将value部分提取出来。

例如：
http://localhost/query.php?name=360&address=beijing

如果给定的参数是那么“name”,那么提取出来的value是“360”
如果给定的参数是那么“address”,那么提取出来的value是“beijing”

具体到实际应用中，有一个url是
“http://www.microsofttranslator.com/bv.aspx?from=&to=zh-chs&xxx&query=http://hnujug.com/”
我们给定的参数key是“query”，因此提取出来的value为“http://hnujug.com/”


项目当前是可以编译通过的，也有一个基本的实现，部分单元测试是对的，但部分单元测试错的。
请实现这个函数：
	void ProxyURLExtractor::Extract( const KeyItems& keys, const std::string& raw_url, std::string& sub_url )
	使得所有的单元测试都通过。

考察点：
	-	核心功能完备
	-	异常分支流程处理正确
	-	构建更多单元测试
	-	尽量优化性能
	-	最好能性能分析报告(gprofile or google profile)

实现完成之后，将工程代码打包(注意包文件名上带上自己的姓名)发给我们，并回答下面的几个问题：
1. 算法的时间复杂度
2. 算法的空间复杂度
3. 是否有资源泄露：内存泄露、文件句柄打开而没有关闭等等

