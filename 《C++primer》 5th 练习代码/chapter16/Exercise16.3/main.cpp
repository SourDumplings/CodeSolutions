/*
 @Date    : 2018-01-11 11:21:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
p658
编译器给出的错误信息：
In file included from main.cpp:13:0:
compare.h: In instantiation of 'int compare(const T&, const T&) [with T = Sales_data]':
main.cpp:21:27:   required from here
compare.h:17:12: error: no match for 'operator<' (operand types are 'const Sales_data' and 'const Sales_data')
     if (v1 < v2) return -1;
            ^
compare.h:17:12: note: candidates are:
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_algobase.h:64:0,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/char_traits.h:39,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:40,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_pair.h:220:5: note: template<class _T1
, class _T2> constexpr bool std::operator<(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)
     operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_pair.h:220:5: note:   template argumen
t deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:17:12: note:   'const Sales_data' is not derived from 'const std::pair<_T1, _T2>'
     if (v1 < v2) return -1;
            ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_algobase.h:67:0,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/char_traits.h:39,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:40,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:298:5: note: template<class
 _Iterator> bool std::operator<(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
     operator<(const reverse_iterator<_Iterator>& __x,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:298:5: note:   template arg
ument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:17:12: note:   'const Sales_data' is not derived from 'const std::reverse_iterator<_Iterator>'
     if (v1 < v2) return -1;
            ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_algobase.h:67:0,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/char_traits.h:39,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:40,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:348:5: note: template<class
 _IteratorL, class _IteratorR> bool std::operator<(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<
_IteratorR>&)
     operator<(const reverse_iterator<_IteratorL>& __x,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:348:5: note:   template arg
ument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:17:12: note:   'const Sales_data' is not derived from 'const std::reverse_iterator<_Iterator>'
     if (v1 < v2) return -1;
            ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_algobase.h:67:0,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/char_traits.h:39,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:40,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:1072:5: note: template<clas
s _IteratorL, class _IteratorR> bool std::operator<(const std::move_iterator<_Iterator>&, const std::move_iterator<_Iter
atorR>&)
     operator<(const move_iterator<_IteratorL>& __x,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:1072:5: note:   template ar
gument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:17:12: note:   'const Sales_data' is not derived from 'const std::move_iterator<_Iterator>'
     if (v1 < v2) return -1;
            ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_algobase.h:67:0,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/char_traits.h:39,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:40,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:1078:5: note: template<clas
s _Iterator> bool std::operator<(const std::move_iterator<_Iterator>&, const std::move_iterator<_Iterator>&)
     operator<(const move_iterator<_Iterator>& __x,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:1078:5: note:   template ar
gument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:17:12: note:   'const Sales_data' is not derived from 'const std::move_iterator<_Iterator>'
     if (v1 < v2) return -1;
            ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/string:52:0,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/locale_classes.h:40,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/ios_base.h:41,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:42,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2588:5: note: template<clas
s _CharT, class _Traits, class _Alloc> bool std::operator<(const std::basic_string<_CharT, _Traits, _Alloc>&, const std:
:basic_string<_CharT, _Traits, _Alloc>&)
     operator<(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2588:5: note:   template ar
gument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:17:12: note:   'const Sales_data' is not derived from 'const std::basic_string<_CharT, _Traits, _Alloc>'
     if (v1 < v2) return -1;
            ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/string:52:0,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/locale_classes.h:40,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/ios_base.h:41,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:42,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2600:5: note: template<clas
s _CharT, class _Traits, class _Alloc> bool std::operator<(const std::basic_string<_CharT, _Traits, _Alloc>&, const _Cha
rT*)
     operator<(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2600:5: note:   template ar
gument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:17:12: note:   'const Sales_data' is not derived from 'const std::basic_string<_CharT, _Traits, _Alloc>'
     if (v1 < v2) return -1;
            ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/string:52:0,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/locale_classes.h:40,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/ios_base.h:41,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:42,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2612:5: note: template<clas
s _CharT, class _Traits, class _Alloc> bool std::operator<(const _CharT*, const std::basic_string<_CharT, _Traits, _Allo
c>&)
     operator<(const _CharT* __lhs,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2612:5: note:   template ar
gument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:17:12: note:   mismatched types 'const _CharT*' and 'Sales_data'
     if (v1 < v2) return -1;
            ^
compare.h:18:17: error: no match for 'operator>' (operand types are 'const Sales_data' and 'const Sales_data')
     else if (v1 > v2) return 1;
                 ^
compare.h:18:17: note: candidates are:
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_algobase.h:64:0,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/char_traits.h:39,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:40,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_pair.h:233:5: note: template<class _T1
, class _T2> constexpr bool std::operator>(const std::pair<_T1, _T2>&, const std::pair<_T1, _T2>&)
     operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_pair.h:233:5: note:   template argumen
t deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:18:17: note:   'const Sales_data' is not derived from 'const std::pair<_T1, _T2>'
     else if (v1 > v2) return 1;
                 ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_algobase.h:67:0,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/char_traits.h:39,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:40,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:310:5: note: template<class
 _Iterator> bool std::operator>(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<_Iterator>&)
     operator>(const reverse_iterator<_Iterator>& __x,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:310:5: note:   template arg
ument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:18:17: note:   'const Sales_data' is not derived from 'const std::reverse_iterator<_Iterator>'
     else if (v1 > v2) return 1;
                 ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_algobase.h:67:0,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/char_traits.h:39,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:40,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:360:5: note: template<class
 _IteratorL, class _IteratorR> bool std::operator>(const std::reverse_iterator<_Iterator>&, const std::reverse_iterator<
_IteratorR>&)
     operator>(const reverse_iterator<_IteratorL>& __x,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:360:5: note:   template arg
ument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:18:17: note:   'const Sales_data' is not derived from 'const std::reverse_iterator<_Iterator>'
     else if (v1 > v2) return 1;
                 ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_algobase.h:67:0,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/char_traits.h:39,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:40,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:1096:5: note: template<clas
s _IteratorL, class _IteratorR> bool std::operator>(const std::move_iterator<_Iterator>&, const std::move_iterator<_Iter
atorR>&)
     operator>(const move_iterator<_IteratorL>& __x,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:1096:5: note:   template ar
gument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:18:17: note:   'const Sales_data' is not derived from 'const std::move_iterator<_Iterator>'
     else if (v1 > v2) return 1;
                 ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_algobase.h:67:0,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/char_traits.h:39,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:40,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:1102:5: note: template<clas
s _Iterator> bool std::operator>(const std::move_iterator<_Iterator>&, const std::move_iterator<_Iterator>&)
     operator>(const move_iterator<_Iterator>& __x,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/stl_iterator.h:1102:5: note:   template ar
gument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:18:17: note:   'const Sales_data' is not derived from 'const std::move_iterator<_Iterator>'
     else if (v1 > v2) return 1;
                 ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/string:52:0,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/locale_classes.h:40,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/ios_base.h:41,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:42,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2625:5: note: template<clas
s _CharT, class _Traits, class _Alloc> bool std::operator>(const std::basic_string<_CharT, _Traits, _Alloc>&, const std:
:basic_string<_CharT, _Traits, _Alloc>&)
     operator>(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2625:5: note:   template ar
gument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:18:17: note:   'const Sales_data' is not derived from 'const std::basic_string<_CharT, _Traits, _Alloc>'
     else if (v1 > v2) return 1;
                 ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/string:52:0,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/locale_classes.h:40,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/ios_base.h:41,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:42,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2637:5: note: template<clas
s _CharT, class _Traits, class _Alloc> bool std::operator>(const std::basic_string<_CharT, _Traits, _Alloc>&, const _Cha
rT*)
     operator>(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2637:5: note:   template ar
gument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:18:17: note:   'const Sales_data' is not derived from 'const std::basic_string<_CharT, _Traits, _Alloc>'
     else if (v1 > v2) return 1;
                 ^
In file included from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/string:52:0,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/locale_classes.h:40,

                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/ios_base.h:41,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ios:42,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/ostream:38,
                 from D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/iostream:39,
                 from main.cpp:12:
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2649:5: note: template<clas
s _CharT, class _Traits, class _Alloc> bool std::operator>(const _CharT*, const std::basic_string<_CharT, _Traits, _Allo
c>&)
     operator>(const _CharT* __lhs,
     ^
D:/codeblocks-16.01mingw-nosetup/MinGW/lib/gcc/mingw32/4.9.2/include/c++/bits/basic_string.h:2649:5: note:   template ar
gument deduction/substitution failed:
In file included from main.cpp:13:0:
compare.h:18:17: note:   mismatched types 'const _CharT*' and 'Sales_data'
     else if (v1 > v2) return 1;
                 ^
 */

#include <iostream>
#include "compare.h"
#include "Sales_data.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Sales_data s1("book1", 3, 30.0), s2("book2", 10, 100);
    cout << compare(s1, s2) << endl;
    return 0;
}
